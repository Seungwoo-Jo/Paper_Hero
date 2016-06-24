#include "CObject_Activetree.h"
#include "ResourceManager.h"
#include "CCollision.h"

CObject_Activetree::CObject_Activetree()
{

}

CObject_Activetree::CObject_Activetree(int GHandle, double x, double y, int Width, int Height, unsigned int Type) : CObject_Enemy(GHandle, x, y, Width, Height, Type)
{
	GraphHandle = ResourceManager::getResourceManager()->GetRes(GHandle);
	Stand	= new CSprite(GetResourceWithKey(IMAGE_OBJECT_ACTIVETREE_STAND), 12, 0, 0, 12, 1, 3000, 360, 85, TRUE);
	Hit		= new CSprite(GetResourceWithKey(IMAGE_OBJECT_ACTIVETREE_HIT), 1, 0, 0, 1, 1, 383, 554, 100, TRUE);
	Death	= new CSprite(GetResourceWithKey(IMAGE_OBJECT_ACTIVETREE_DEAD), 9, 0, 0, 9, 1, 2250, 360, 65, TRUE);

	b_left = true;
	b_right = false;

	Center = WorldX + 133;
	
	RecognizeRange = 550;
	AttackRange = 300;
	//PatrolRange = -1;

	SetMove(false);
	SetAttack(false);
	SetHit(false);

	AttackDelay = 180;
	AttackCount = -1;
	HeroKnockbackCount = -1;
	KnockbackCount = -1;
	HitCount = -1;

	Stat_ST = 40;
	Damage = Stat_ST * 0.5f;
	Stat_HP = 8;
	MaxHP = Stat_HP * 3;
	HP = MaxHP;
	Speed = 0;

	Exp = 0;

}

CObject_Activetree::~CObject_Activetree()
{
	delete Stand;
	delete Hit;
	delete Death;
}

void CObject_Activetree::Update()
{
	Center = WorldX + GetWidth()/2;
	SetAttackBox(0, 0, 0, 0);

	if(HeroForEnemy->GetWorldX()+100 < Center && !b_Attack)	// Hero가 왼쪽에 있을 때
	{
		b_left = true;
		b_right = false;
	}
	else if(HeroForEnemy->GetWorldX()+100 > Center && !b_Attack)
	{
		b_left = false;
		b_right = true;
	}

	// 인식범위 설정
	int RcnzX = Center;
	if(b_left) {
		RcnzX -= RecognizeRange;
	}
	else if(b_right) {
		RcnzX += RecognizeRange;
	}
	/*
	// 공격범위 설정
	int AtkX = Center;
	if(b_left) {
		AtkX -= AttackRange;
	}
	else if(b_right) {
		AtkX += AttackRange;
	}

	// 인식범위 내에서의 행동따윈 필요없다.

	// 공격범위 내에서의 행동
	if(GetHP() > 0)
	{
		if(HeroForEnemy->GetWorldX()+100 > AtkX && b_left)
		{
			if(AttackCount == -1 ) {
				SetAttack(true);
				AttackCount = 0;
			}
			if(Poison->GetCount() >= 1 && Poison->GetCount() <= 2) {
				SetAttackBox((int)GetDrawX()+30, (int)GetDrawY()+250, 191, 220);
			}
		}
		else if(HeroForEnemy->GetWorldX()+100 < AtkX && b_right)
		{
			if(AttackCount == -1 ) {
				SetAttack(true);
				AttackCount = 0;
			}
			if(Poison->GetCount() >= 1 && Poison->GetCount() <= 2) {
				SetAttackBox((int)GetDrawX()+30, (int)GetDrawY()+250, 191, 220);
			}
		}

		if(AttackCount != -1) {
			AttackCount++;
		}
		
		if(Poison->GetCount() >= 6) {
			Poison->SetCount(0);
			SetAttack(false);
		}
		

		if(AttackCount > AttackDelay) {
			AttackCount = -1;
			Poison->SetCount(0);
			SetAttack(false);
		}
	}
	*/

	
	// 충돌박스 설정
	SetBoundBox((int)GetDrawX()+50, (int)GetDrawY()+50, 150, 260);
	
	// Hero와의 충돌판정
	if(GetHP() > 0)
	{
		if(CCollision::GetCollision()->Box_n_Box(
			HeroForEnemy->GetBoundX()-1, HeroForEnemy->GetBoundY(), HeroForEnemy->GetBoundX()+HeroForEnemy->GetBoundWidth()+1, HeroForEnemy->GetBoundY()+HeroForEnemy->GetBoundHeight(),
			GetBoundX(), GetBoundY(), GetBoundX()+GetBoundWidth(), GetBoundY()+GetBoundHeight()))
		{
			if(HeroForEnemy->GetWorldX()+100 < Center)	// Hero가 왼쪽에 있을 때
			{
				//HeroForEnemy->MoveTo(GetWorldX() + (int)((GetWidth()-GetBoundWidth())/2) - HeroForEnemy->GetWidth() + (int)((HeroForEnemy->GetWidth() - HeroForEnemy->GetBoundWidth())/2), HeroForEnemy->GetWorldY());
				HeroForEnemy->MoveTo(GetWorldX() + (int)((GetWidth()-GetBoundWidth())/2) - 185, HeroForEnemy->GetWorldY());
			}
			
			else if(HeroForEnemy->GetWorldX()+100 >= Center)	// Hero가 오른쪽에 있을 때
			{
				HeroForEnemy->MoveTo(GetWorldX() + GetWidth() - (int)((GetWidth()-GetBoundWidth())/2) - (int)((HeroForEnemy->GetWidth()-HeroForEnemy->GetBoundWidth())/2), HeroForEnemy->GetWorldY());
			}
			
		}
	}

	/*
	// Hero에게 공격판정
	if(CCollision::GetCollision()->Box_n_Box(
		HeroForEnemy->GetBoundX(), HeroForEnemy->GetBoundY(), HeroForEnemy->GetBoundX()+HeroForEnemy->GetBoundWidth(), HeroForEnemy->GetBoundY()+HeroForEnemy->GetBoundHeight(),
		GetAttackX(), GetAttackY(), GetAttackX()+GetAttackWidth(), GetAttackY()+GetAttackHeight()))
	{
		if(!HeroForEnemy->GetHit())
		{
			int dmg = (int)GetDmg();
			if(b_left)
			{
				if(HeroForEnemy->GetWay() == 1 && HeroForEnemy->GetGuard()) {
					dmg = (int)(dmg * 0.5f);
				}
			}
			else if(b_right)
			{
				if(HeroForEnemy->GetWay() == 0 && HeroForEnemy->GetGuard()) {
					dmg = (int)(dmg * 0.5f);
				}
			}
			HeroForEnemy->SetHP(HeroForEnemy->GetHP() - dmg);
			HeroForEnemy->SetHit(true);
			//SetAttack(false);
			if(HeroKnockbackCount == -1)
			{
				HeroKnockbackCount = 0;
			}
		}
	}
	
	// 넉백
	if(HeroKnockbackCount != -1)
	{
		if(HeroForEnemy->GetWorldX()+100 < Center)		// Hero가 왼쪽에 있을 때
		{
			if(HeroForEnemy->GetGuard()) {
				HeroForEnemy->MoveTo(HeroForEnemy->GetWorldX()-2, HeroForEnemy->GetWorldY());
			}
			else {
				HeroForEnemy->MoveTo(HeroForEnemy->GetWorldX()-3, HeroForEnemy->GetWorldY());
			}
		}
		else if(HeroForEnemy->GetWorldX()+100 > Center)	// Hero가 오른쪽에 있을 때
		{
			if(HeroForEnemy->GetGuard()) {
				HeroForEnemy->MoveTo(HeroForEnemy->GetWorldX()+2, HeroForEnemy->GetWorldY());
			}
			else {
				HeroForEnemy->MoveTo(HeroForEnemy->GetWorldX()+3, HeroForEnemy->GetWorldY());
			}
		}

		if(HeroKnockbackCount >= 15) {
			HeroKnockbackCount = -1;
			Hit->SetCount(0);
		}
		else {
			HeroKnockbackCount++;
		}
	}
	*/
	// Hero에게 피격판정
	if(GetHP() > 0)
	{
		if(CCollision::GetCollision()->Box_n_Box(
			HeroForEnemy->GetAttackX(), HeroForEnemy->GetAttackY(), HeroForEnemy->GetAttackX()+HeroForEnemy->GetAttackWidth(), HeroForEnemy->GetAttackY()+HeroForEnemy->GetAttackHeight(),
			GetBoundX(), GetBoundY(), GetBoundX()+GetBoundWidth(), GetBoundY()+GetBoundHeight()) ||
			CCollision::GetCollision()->Box_n_Box(
			HeroForEnemy->GetSkillX(), HeroForEnemy->GetSkillY(), HeroForEnemy->GetSkillX()+HeroForEnemy->GetSkillWidth(), HeroForEnemy->GetSkillY()+HeroForEnemy->GetSkillHeight(),
			GetBoundX(), GetBoundY(), GetBoundX()+GetBoundWidth(), GetBoundY()+GetBoundHeight()) )
		{
			SetHit(true);
			if(HitCount == -1) {
				HitCount = 0;

				SetHP(GetHP() - HeroForEnemy->GetDmg());
			}

			if(KnockbackCount == -1) {
				KnockbackCount = 0;
			}
		}
		/*
		if(KnockbackCount != -1)
		{
			if(HeroForEnemy->GetWorldX()+100 < Center)		// Hero가 왼쪽에 있을 때
			{
				MoveTo(GetWorldX()+2, GetWorldY());

			}
			else if(HeroForEnemy->GetWorldX()+100 > Center)	// Hero가 오른쪽에 있을 때
			{
				MoveTo(GetWorldX()-2, GetWorldY());
			}

			if(KnockbackCount >= 10) {
				KnockbackCount = -1;
			}
			else {
				KnockbackCount++;
			}
		}

		if(GetHP() <= 0)
		{
			HeroForEnemy->SetExp(HeroForEnemy->GetExp() + GetExp());
		}
		*/
		if(HitCount >= 0)
		{
			HitCount++;
			if(HitCount >= 20) {
				HitCount = -1;
				SetHit(false);
				//HitEffect->SetCount(0);
			}
		}
	}

	if(GetHP() < 0)
	{
		Opacity -= 4;
		b_Move = false;
		b_Attack = false;
	}
}

void CObject_Activetree::Render()
{
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
	Conversion();
	//DrawRotaGraphF(fDrawX+85, fDrawY+190, 0.225f, 0.0f, GetResourceWithKey(IMAGE_OBJECT_WANTED), TRUE);

	if(GetHP() > 0)
	{
		if(b_Hit)
		{
			Hit->DrawSprite((int)fDrawX, (int)fDrawY, FALSE);
			Stand->SetCount(0);
		}
		else
		{
			Stand->DrawSprite((int)fDrawX, (int)fDrawY);
		}
	}
	else
	{
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, Opacity);
		Death->DrawSprite((int)fDrawX, (int)fDrawY, FALSE);
	}

	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
}

void CObject_Activetree::Control()
{

}