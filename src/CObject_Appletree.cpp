#include "CObject_Appletree.h"
#include "ResourceManager.h"
#include "CCollision.h"

CObject_Appletree::CObject_Appletree()
{

}

CObject_Appletree::CObject_Appletree(int GHandle, double x, double y, int Width, int Height, unsigned int Type) : CObject_Enemy(GHandle, x, y, Width, Height, Type)
{
	GraphHandle = ResourceManager::getResourceManager()->GetRes(GHandle);
	Stand	= new CSprite(GetResourceWithKey(IMAGE_OBJECT_APPLETREE_STAND), 1, 0, 0, 1, 1, 358, 482, 100, TRUE);
	Hit		= new CSprite(GetResourceWithKey(IMAGE_OBJECT_APPLETREE_HIT), 1, 0, 0, 1, 1, 358, 482, 100, TRUE);
	Death	= new CSprite(GetResourceWithKey(IMAGE_OBJECT_APPLETREE_DEAD), 7, 0, 0, 7, 1, 2506, 482, 65, TRUE);
	Poison	= new CSprite(GetResourceWithKey(IMAGE_OBJECT_APPLETREE_POISON), 8, 0, 0, 8, 1, 3200, 480, 120, TRUE);
	Apple[0]= new CSprite(GetResourceWithKey(IMAGE_OBJECT_APPLE_BREAK), 6, 0, 0, 6, 1, 696, 108, 50, TRUE);
	Apple[1]= new CSprite(GetResourceWithKey(IMAGE_OBJECT_APPLE_BREAK), 6, 0, 0, 6, 1, 696, 108, 50, TRUE);
	Break[0]= new CSprite(GetResourceWithKey(IMAGE_OBJECT_APPLE_BREAK), 6, 0, 0, 6, 1, 696, 108, 64, TRUE);
	Break[1]= new CSprite(GetResourceWithKey(IMAGE_OBJECT_APPLE_BREAK), 6, 0, 0, 6, 1, 696, 108, 64, TRUE);
	Boom[0]	= new CSprite(GetResourceWithKey(IMAGE_OBJECT_APPLE_BOOM), 7, 0, 0, 7, 1, 1610, 230, 128, TRUE);
	Boom[1]	= new CSprite(GetResourceWithKey(IMAGE_OBJECT_APPLE_BOOM), 7, 0, 0, 7, 1, 1610, 230, 128, TRUE);

	b_left = true;
	b_right = false;

	Center = WorldX + 133;
	
	RecognizeRange = 550;
	AttackRange = 225;
	//PatrolRange = -1;

	SetMove(false);
	SetAttack(false);
	SetHit(false);

	AttackDelay = 270;
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

	tempY[0] = (int)fDrawY;
	tempY[1] = (int)fDrawY;
	b_apple[0] = false;
	b_apple[1] = false;

}

CObject_Appletree::~CObject_Appletree()
{
	delete Stand;
	delete Hit;
	delete Death;
	delete Poison;
	delete Apple[0];
	delete Apple[1];
	delete Boom[0];
	delete Boom[1];
	delete Break[0];
	delete Break[1];
}

void CObject_Appletree::Update()
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

			for(int i=0; i<2; i++)
			{
				if(Break[i]->GetCount() >=1 && Break[i]->GetCount() <= 3) {
					SetAttackBox((int)GetDrawX()+25, (int)GetDrawY()+400, 180, 100);
				}
			}

			b_apple[0] = true;
		}
		else if(HeroForEnemy->GetWorldX()+100 < AtkX && b_right)
		{
			if(AttackCount == -1 ) {
				SetAttack(true);
				AttackCount = 0;
			}
			if(Poison->GetCount() >= 1 && Poison->GetCount() <= 2) {
				SetAttackBox((int)GetDrawX()+30, (int)GetDrawY()+250, 250, 220);
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



	
	// 충돌박스 설정
	SetBoundBox((int)GetDrawX()+100, (int)GetDrawY()+50, 158, 400);
	
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
				HeroForEnemy->MoveTo(GetWorldX() + (int)((GetWidth()-GetBoundWidth())/2) - 115, HeroForEnemy->GetWorldY());
			}
			
			else if(HeroForEnemy->GetWorldX()+100 >= Center)	// Hero가 오른쪽에 있을 때
			{
				HeroForEnemy->MoveTo(GetWorldX() + GetWidth() - (int)((GetWidth()-GetBoundWidth())/2) - (int)((HeroForEnemy->GetWidth()-HeroForEnemy->GetBoundWidth())/2), HeroForEnemy->GetWorldY());
			}
			
		}
	}

	
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
					dmg = (int)(dmg * 0.3f);
					HeroForEnemy->SetGuardHit(TRUE);
				}
			}
			else if(b_right)
			{
				if(HeroForEnemy->GetWay() == 0 && HeroForEnemy->GetGuard()) {
					dmg = (int)(dmg * 0.3f);
					HeroForEnemy->SetGuardHit(TRUE);
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
			b_apple[1] = true;
			Poison->SetCount(0);
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
	/*
	// 벽
	if(GetWorldX() < -76)
	{
		WorldX = -76;
	}
	*/
	if(GetHP() < 0)
	{
		Opacity -= 6;
		b_Move = false;
		b_Attack = false;
	}
}

void CObject_Appletree::Render()
{
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
	Conversion();

	if(GetHP() > 0)
	{
		if(b_Hit)
		{
			Hit->DrawSprite((int)fDrawX, (int)fDrawY, FALSE);
			Stand->SetCount(0);
		}
		
		else if(b_Attack)
		{
			Stand->DrawSprite((int)fDrawX, (int)fDrawY);
			Poison->DrawSprite((int)fDrawX-35, (int)fDrawY+115);
		}
		
		else
		{
			Stand->DrawSprite((int)fDrawX, (int)fDrawY);
		}



		if(!b_apple[0]) {
			Apple[0]->DrawSprite((int)fDrawX+35, (int)fDrawY+100, TRUE, 0);
		}
		else {
			tempY[0] += 11;

			if(tempY[0] > 420) {
				tempY[0] = 420;
				if(Break[0]->GetCount() != 5) {
					Break[0]->DrawSprite((int)fDrawX+35, (int)tempY[0]+100, FALSE);
				}
				else {
				}

				Boom[0]->DrawSprite((int)fDrawX-5, (int)tempY[0]-50, FALSE);
			}
			else {
				Apple[0]->DrawSprite((int)fDrawX+35, (int)tempY[0]+125, TRUE, 0);
			}
		}
		

		if(!b_apple[1]) {
			Apple[1]->DrawSprite((int)fDrawX+95, (int)fDrawY+120, TRUE, 0);
		}
		else {
			tempY[1] += 11;

			if(tempY[1] > 420) {
				tempY[1] = 420;
				if(Break[1]->GetCount() != 5) {
					Break[1]->DrawSprite((int)fDrawX+95, (int)tempY[1]+100, FALSE);
				}
				else {
				}

				Boom[1]->DrawSprite((int)fDrawX+55, (int)tempY[1]-50, FALSE);
			}
			else {
				Apple[1]->DrawSprite((int)fDrawX+95, (int)tempY[1]+145, TRUE, 0);
			}
		}



		/*
		// 데미지 출력
		if(GetHit())
		{
			Hit->DrawSprite((int)fDrawX, (int)fDrawY);

			SetDrawBlendMode(DX_BLENDMODE_ADD, 255-(10*KnockbackCount));
			SetDrawBright(255, 255, 255);
			Func->DrawNum((int)fDrawX+140, (int)fDrawY-20-(KnockbackCount*2), (int)HeroForEnemy->GetDmg());
			SetDrawBright(*Bright, *Bright, *Bright);
		}
		*/
	}
	else
	{
		
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, Opacity);
		Death->DrawSprite((int)fDrawX, (int)fDrawY, FALSE);
	}

	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
}

void CObject_Appletree::Control()
{

}