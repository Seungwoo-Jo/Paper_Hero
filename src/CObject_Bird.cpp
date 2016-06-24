#include "CObject_Bird.h"
#include "CCollision.h"
#include "ResourceManager.h"

CObject_Bird::CObject_Bird(void)
{
}

CObject_Bird::CObject_Bird(int GHandle, double x, double y, int Width, int Height, unsigned int Type) : CObject_Enemy(GHandle, x, y, Width, Height, Type)
{
	GraphHandle = ResourceManager::getResourceManager()->GetRes(GHandle);
	Stand	= new CSprite(GraphHandle, 3, 0, 0, 3, 1, 300, 100, 65, TRUE);

	b_left = true;
	b_right = false;

	Center = WorldX + 200;
	
	RecognizeRange = 700;
	AttackRange = 400;
	//PatrolRange = -1;

	SetMove(false);
	SetAttack(false);
	SetHit(false);

	AttackDelay = 100;
	AttackCount = -1;
	HeroKnockbackCount = -1;
	KnockbackCount = -1;
	HitCount = -1;

	Stat_ST = 2;
	Damage = Stat_ST * 0.5f;
	Stat_HP = 1;
	MaxHP = Stat_HP * 2;
	HP = MaxHP;
	Speed = 3;

	Exp = 100;

}

CObject_Bird::~CObject_Bird(void)
{
	delete Stand;

}

void CObject_Bird::Update()
{
	Center = WorldX + 50;
	SetAttackBox(0, 0, 0, 0);

	if(GetWorldX() > 4000)	// Hero가 왼쪽에 있을 때
	{
		b_left = true;
		b_right = false;
		Speed *= -1;
		MoveTo(4000, GetWorldY());
	}
	else if(GetWorldX() < 2500)
	{
		b_left = false;
		b_right = true;
		Speed *= -1;
		MoveTo(2500, GetWorldY());
	}

	if(b_left)
	{
		b_Move = true;
		MoveTo(GetWorldX()+(int)GetSpd(), GetWorldY());
	}
	else if(b_right)
	{
		b_Move = true;
		MoveTo(GetWorldX()-(int)GetSpd(), GetWorldY());
	}

	/*
	// 공격범위 내에서의 행동
	if(GetHP() > 0)
	{
		if(HeroForEnemy->GetWorldX()+100 > AtkX && b_left)
		{
			if(AttackCount == -1 ) {
				SetAttack(true);
				AttackCount = 0;
			}
			if(Attack->GetCount() >= 1) {
				SetAttackBox((int)GetDrawX()-15 -(AttackCount*10), (int)GetDrawY()+70, 40, 40);
			}
		}
		else if(HeroForEnemy->GetWorldX()+100 < AtkX && b_right)
		{
			if(AttackCount == -1 ) {
				SetAttack(true);
				AttackCount = 0;
			}
			if(Attack->GetCount() >= 1) {
				SetAttackBox((int)GetDrawX()+220 +(AttackCount*10), (int)GetDrawY()+70, 40, 40);
			}
		}

		if(AttackCount != -1) {
			AttackCount++;
		}
		/*
		if(Attack->GetCount() >= 5) {
			Attack->SetCount(0);
			SetAttack(false);
		}
		
		if(AttackCount > 60) {
			//AttackCount = -1;
			Attack->SetCount(0);
			SetAttack(false);
		}

		if(AttackCount > AttackDelay) {
			AttackCount = -1;
			Attack->SetCount(0);
			SetAttack(false);
		}
	}
	*/



	// 충돌박스 설정
	SetBoundBox((int)GetDrawX()+15, (int)GetDrawY()+15, 30, 30);

	// Hero와의 충돌판정
	/*
	if(GetHP() > 0)
	{
		if(CCollision::GetCollision()->Box_n_Box(
			HeroForEnemy->GetBoundX()-1, HeroForEnemy->GetBoundY(), HeroForEnemy->GetBoundX()+HeroForEnemy->GetBoundWidth()+1, HeroForEnemy->GetBoundY()+HeroForEnemy->GetBoundHeight(),
			GetBoundX(), GetBoundY(), GetBoundX()+GetBoundWidth(), GetBoundY()+GetBoundHeight()))
		{
			if(HeroForEnemy->GetWorldX()+100 < Center)	// Hero가 왼쪽에 있을 때
			{
				HeroForEnemy->MoveTo(GetWorldX()+(int)((GetWidth()-GetBoundWidth())*0.5f) - HeroForEnemy->GetWidth() + (int)(HeroForEnemy->GetWidth() - HeroForEnemy->GetBoundWidth())*0.5f, HeroForEnemy->GetWorldY());
			}
			
			else if(HeroForEnemy->GetWorldX()+100 >= Center)	// Hero가 오른쪽에 있을 때
			{
				HeroForEnemy->MoveTo(GetWorldX() + GetWidth() - (int)((GetWidth()-GetBoundWidth())*0.5f) - (int)((HeroForEnemy->GetWidth()-HeroForEnemy->GetBoundWidth())*0.5f), HeroForEnemy->GetWorldY());
			}
			
		}
	}
	*/

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
			SetAttack(false);
			if(HeroKnockbackCount == -1)
			{
				HeroKnockbackCount = 0;
			}
		}
	}
	/*
	// 넉백
	if(HeroKnockbackCount != -1)
	{
		if(HeroForEnemy->GetWorldX()+100 < Center)		// Hero가 왼쪽에 있을 때
		{
			if(HeroForEnemy->GetGuard()) {
				HeroForEnemy->MoveTo(HeroForEnemy->GetWorldX()-4, HeroForEnemy->GetWorldY());
			}
			else {
				HeroForEnemy->MoveTo(HeroForEnemy->GetWorldX()-6, HeroForEnemy->GetWorldY());
			}
		}
		else if(HeroForEnemy->GetWorldX()+100 > Center)	// Hero가 오른쪽에 있을 때
		{
			if(HeroForEnemy->GetGuard()) {
				HeroForEnemy->MoveTo(HeroForEnemy->GetWorldX()+4, HeroForEnemy->GetWorldY());
			}
			else {
				HeroForEnemy->MoveTo(HeroForEnemy->GetWorldX()+6, HeroForEnemy->GetWorldY());
			}
		}

		if(HeroKnockbackCount >= 30) {
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
			GetBoundX(), GetBoundY(), GetBoundX()+GetBoundWidth(), GetBoundY()+GetBoundHeight()))
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
	
	// 벽
	if(GetWorldX() < -76) {
		WorldX = -76;
	}

	if(GetHP() < 0)
	{
		b_Move = false;
		b_Attack = false;
	}
}

void CObject_Bird::Render()
{
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
	Conversion();

	if(GetHP() > 0)
	{
		
		if(GetHit())
		{
			
		}
		else
		{
			if(b_left)
				Stand->DrawSprite((int)fDrawX, (int)fDrawY);
			else if(b_right)
				Stand->DrawTurnSprite((int)fDrawX, (int)fDrawY);
		}

	}
	else
	{

	}

	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
}

void CObject_Bird::Control()
{

}

