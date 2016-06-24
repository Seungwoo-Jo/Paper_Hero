#include "CObject_Hero.h"
#include "ResourceManager.h"
#include "DxLib.h"

CObject_Hero::CObject_Hero()
{

}

CObject_Hero::CObject_Hero(int GHandle, double x, double y, int Width, int Height, unsigned int Type) : CObject(GHandle, x, y, Width, Height, Type)
{
	State = new CState();
	State = State->Init(this);
	
	HeroEffectHandle = GetResourceWithKey(IMAGE_HERO_EFFECT);

	LevelUpSp = new CSprite(HeroEffectHandle, 10, 0, 0 ,10, 1, 6000, 330, 75, TRUE);
	BattleSp = new CSprite(HeroEffectHandle, 5, 0, 330, 5, 2, 3300, 220, 67, TRUE);

	Func1 = new CGlobal();
	Func2 = new CGlobal();
	Func3 = new CGlobal();
	Func4 = new CGlobal();
	
	BattleSound = new CSound(LoadSoundMem("Resource/Sound/hero_battle.ogg"), 0);
	LevelSound = new CSound(LoadSoundMem("Resource/Sound/hero_levelup.ogg"), 0);

	Stat_ST = 20;
	Stat_AR = 0;
	Stat_HP = 5;
	Stat_MP = 10;
	Stat_SP = 20;
	Stat_EX = 100;

	Damage = Stat_ST / 2;
	Armor = Stat_AR * 2;
	MaxHP = Stat_HP * 40;
	MaxMP = Stat_MP * 20;
	MaxSP = Stat_SP * 10;

	HP = MaxHP;
	MP = MaxMP;
	SP = MaxSP;
	Speed = 5.0f;
	Exp = 0.0f;

	MP_Empty = -1;
	SP_Empty = -1;
	LevelUp = -1;

	TurnCount = 0;
	HitCount = -1;
	BattleCount = -1;

	Font = CreateFontToHandle("나눔고딕코딩", 20, 1, DX_FONTTYPE_ANTIALIASING_EDGE_8X8);
}

CObject_Hero::~CObject_Hero()
{
	delete State;
	delete Func1;
	delete Func2;
	delete Func3;
	delete Func4;

	delete BattleSound;
	delete LevelSound;

	State = NULL;
	Func1 = NULL;
	Func2 = NULL;

	DeleteFontToHandle(Font);
}

void CObject_Hero::Init()
{
}

void CObject_Hero::Update()
{
	//SetDmg(GetStat_ST() * 0.5f);
	MaxHP = Stat_HP * 20;
	MaxMP = Stat_MP * 20;
	MaxSP = Stat_SP * 10;

	// 중력......
	WorldY += 2;
	
	if(State->GetWay() == 1) {
		b_left = false;
		b_right = true;
	}
	else {
		b_left = true;
		b_right = false;
	}

	SetBoundBox( (int)fDrawX+85, (int)fDrawY+20, 30, 150 );

	

	if(TempOpacity < 255) {
		Opacity -= 8;
	}

	if(Opacity < 255) {
		Opacity += 4;

		
	}

	if(Opacity >= 255) {
		Opacity = 255;
	}
	if(Opacity <= 150) {
		Opacity = 150;
	}


	if(Stat_EX <= Exp)
	{
		LevelUpSp->SetCount(0);
		LevelUp = 0;
		Level += 1;
		Exp = 0;
		Stat_EX = 100 * Level * 1.25f;
		Stat_PT += 5.0f;
	}
	if(LevelUp >= 45) {
		LevelUp = -1;
	}

	// SP 자동회복
	if(Func1->RunAfterTimeElapsed(0.04f))	// 1/25초마다 작업
	{
		if(HP < MaxHP)
		{
			SetHP(HP + 0.4f);

			if(HP > MaxHP) {
				SetHP(MaxHP);
			}
		}
		if(MP < MaxMP)
		{
			SetMP(MP + 0.1f);

			if(MP > MaxMP) {
				SetMP(MaxMP);
			}
		}
		if(b_Battle)
		{
			if(SP > 0) {
				SetSP(SP - 0.25f);
			}
			else {
				b_Battle = false;
			}
		}
		else 
		{
			if(SP < MaxSP)
			{
				SetSP(SP + 1.5f);

				if(SP > MaxSP) {
					SetSP(MaxSP);
				}
			}
		}
		
	}

	if(GetHit())
	{
		if(HitCount == -1) {
			HitCount = 0;
		}
		if(HitCount < 25) {
			HitCount++;
		}
		else {
			HitCount = -1;
			SetHit(false);
		}
	}

	if(BattleCount >= 0)
	{
		BattleCount++;

		if(BattleCount >= 20) {
			BattleSp->SetCount(0);
			BattleCount = -1;
		}
	}

	State = State->Update();

}

void CObject_Hero::Render()
{
	Conversion();

	if(BattleCount >= 0)
	{
		SetDrawBlendMode(DX_BLENDMODE_ADD, 255-(BattleCount*7));
		BattleSp->DrawSprite((int)fDrawX-230, (int)fDrawY+50, FALSE);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
	}

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, Opacity);
	State = State->Render();
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);

	SetFontCacheUsePremulAlphaFlag(Font);
	
	SetDrawBright(255, 255, 255);
	if(MP_Empty >= 0)
	{
		SetDrawBlendMode(DX_BLENDMODE_ADD, 255-(MP_Empty*4));
		DrawFormatStringToHandle((int)fDrawX+10, (int)fDrawY-40, GetColor(255, 255, 255),Font, "마나가 부족합니다.");
		MP_Empty++;
		if(MP_Empty >= 60) {
			MP_Empty = -1;
		}
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
	}
	if(SP_Empty >= 0)
	{
		SetDrawBlendMode(DX_BLENDMODE_ADD, 255-(SP_Empty*4));
		DrawFormatStringToHandle((int)fDrawX-25, (int)fDrawY-40, GetColor(255, 255, 255),Font, "전투게이지가 부족합니다.");
		SP_Empty++;
		if(SP_Empty >= 60) {
			SP_Empty = -1;
		}
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
	}
	if(LevelUp >= 0)
	{
		LevelUpSp->DrawSprite((int)fDrawX-220, (int)fDrawY-299);
		LevelSound->PlaySoundA();
		LevelUp++;
	}

	//clsDx();
	//printfDx("%d, %.2f", WorldX, fDrawX);

}

void CObject_Hero::Control()
{
	if(CheckHitKey(KEY_INPUT_1) == 1) {
		SetHP(GetMaxHP());
		SetMP(GetMaxMP());
		SetSP(GetMaxSP());
	}
	if(CheckHitKey(KEY_INPUT_F) == 1) 
	{
			
		if(Func2->RunAfterTimeElapsed(0.5f))
		{
			if(GetBattle())
			{
				SetBattle(false);
			}
			else
			{
				if(BattleCount == -1){
					BattleSp->SetCount(0);
					BattleCount = 0;
				}
				if(GetSP() >= 20*(MaxSP/100)) {
					BattleSound->PlaySoundA();
					SetBattle(true);
					
					SP_Empty = -1;
				}
				else
				{
					SP_Empty = 0;
				}
			}
		}
		
	}

	if(GetHit())
	{
	}
	else {
		State = State->Control();
	}

}