#include "CObject_Mole.h"
#include "ResourceManager.h"
#include "CCollision.h"

CObject_Mole::CObject_Mole()
{
}

CObject_Mole::CObject_Mole(int GHandle, double x, double y, int Width, int Height, unsigned int Type) : CObject_Enemy(GHandle, x, y, Width, Height, Type)
{
	GraphHandle = ResourceManager::getResourceManager()->GetRes(GHandle);

	Move	= new CSprite(GraphHandle, 11, 0, 0, 11, 1, 3300, 350, 100, TRUE);
	Attack	= new CSprite(GraphHandle, 9, 0, 350,  9, 2, 3150, 350, 75, TRUE);
	Hit		= new CSprite(GraphHandle, 2, 0, 700, 2, 3, 700, 350, 100, TRUE);

	Death	= new CSprite(GetResourceWithKey(IMAGE_DEAD), 10, 0, 0, 10, 1, 3000, 350, 80, TRUE);
	HitEffect = new CSprite(HitHandle, 4, 0, 0, 4, 1, 2640, 430, 84, TRUE);

	b_left = true;
	b_right = false;

	Center = WorldX + 175;
	
	RecognizeRange = 500;
	AttackRange = 155;
	//PatrolRange = -1;

	SetMove(false);
	SetAttack(false);

	b_FirstAtk = true;
	SetHit(false);

	AttackDelay = 180;
	AttackCount = -1;
	HeroKnockbackCount = -1;
	KnockbackCount = -1;
	HitCount = -1;

	Stat_ST = 36;
	Damage = Stat_ST * 0.5f;
	Stat_HP = 4;
	MaxHP = Stat_HP * 10;
	HP = MaxHP;
	Speed = 2;

	Exp = 100;

}

CObject_Mole::~CObject_Mole()
{
	delete Move;
	delete Attack;
	delete Hit;
	delete HitEffect;
}

void CObject_Mole::Update()
{
	Center = WorldX + 175;
	SetAttackBox(0, 0, 0, 0);
	Conversion();
	if(HeroForEnemy->GetWorldX()+100 < Center && !b_Attack)	// Hero�� ���ʿ� ���� ��
	{
		b_left = true;
		b_right = false;
	}
	else if(HeroForEnemy->GetWorldX()+100 > Center && !b_Attack)
	{
		b_left = false;
		b_right = true;
	}

	// �νĹ��� ����
	int RcnzX = Center;
	if(b_left) {
		RcnzX -= RecognizeRange;
	}
	else if(b_right) {
		RcnzX += RecognizeRange;
	}

	// ���ݹ��� ����
	int AtkX = Center;
	if(b_left) {
		AtkX -= AttackRange;
	}
	else if(b_right) {
		AtkX += AttackRange;
	}

	

	// ���ݹ��� �������� �ൿ
	if(GetHP() > 0)
	{
		if(HeroForEnemy->GetWorldX()+100 > AtkX && b_left)
		{
			if(AttackCount == -1 ) {
				SetAttack(true);
				AttackCount = 0;
			}
			if(Attack->GetCount() > 0) {
				SetAttackBox((int)GetDrawX()+30, (int)GetDrawY()+25, 95, 150);
			}
		}
		else if(HeroForEnemy->GetWorldX()+100 < AtkX && b_right)
		{
			if(AttackCount == -1 ) {
				SetAttack(true);
				AttackCount = 0;
			}
			if(Attack->GetCount() > 0) {
				SetAttackBox((int)GetDrawX()+125, (int)GetDrawY()+25, 95, 150);
			}
		}

		if(AttackCount != -1) {
			AttackCount++;
		}

		if(Attack->GetCount() >= 7) {
			Attack->SetCount(0);
			SetAttack(false);
		}

		if(AttackCount > AttackDelay) {
			AttackCount = -1;
			Attack->SetCount(0);
			SetAttack(false);
		}
	}




	// �浹�ڽ� ����
	SetBoundBox((int)GetDrawX()+50, (int)GetDrawY()+25, 200, 200);

	// Hero���� �浹����
	/*
	if(GetHP() > 0)
	{
		if(CCollision::GetCollision()->Box_n_Box(
			HeroForEnemy->GetBoundX()-1, HeroForEnemy->GetBoundY(), HeroForEnemy->GetBoundX()+HeroForEnemy->GetBoundWidth()+1, HeroForEnemy->GetBoundY()+HeroForEnemy->GetBoundHeight(),
			GetBoundX(), GetBoundY(), GetBoundX()+GetBoundWidth(), GetBoundY()+GetBoundHeight()))
		{
			if(HeroForEnemy->GetWorldX()+100 < Center)	// Hero�� ���ʿ� ���� ��
			{
				HeroForEnemy->MoveTo(GetWorldX()+(int)((GetWidth()-GetBoundWidth())*0.5f) - HeroForEnemy->GetWidth() + (int)(HeroForEnemy->GetWidth() - HeroForEnemy->GetBoundWidth())*0.5f, HeroForEnemy->GetWorldY());
			}
			
			else if(HeroForEnemy->GetWorldX()+100 >= Center)	// Hero�� �����ʿ� ���� ��
			{
				HeroForEnemy->MoveTo(GetWorldX() + GetWidth() - (int)((GetWidth()-GetBoundWidth())*0.5f) - (int)((HeroForEnemy->GetWidth()-HeroForEnemy->GetBoundWidth())*0.5f), HeroForEnemy->GetWorldY());
			}
			
		}
	}
	*/

	// Hero���� ��������
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

			if(HeroKnockbackCount == -1)
			{
				HeroKnockbackCount = 0;
			}
		}
	}

	// �˹�
	if(HeroKnockbackCount != -1)
	{
		if(HeroForEnemy->GetWorldX()+100 < Center)		// Hero�� ���ʿ� ���� ��
		{
			if(HeroForEnemy->GetGuard()) {
				HeroForEnemy->MoveTo(HeroForEnemy->GetWorldX()-5, HeroForEnemy->GetWorldY());
			}
			else {
				HeroForEnemy->MoveTo(HeroForEnemy->GetWorldX()-8, HeroForEnemy->GetWorldY());
			}
		}
		else if(HeroForEnemy->GetWorldX()+100 > Center)	// Hero�� �����ʿ� ���� ��
		{
			if(HeroForEnemy->GetGuard()) {
				HeroForEnemy->MoveTo(HeroForEnemy->GetWorldX()+5, HeroForEnemy->GetWorldY());
			}
			else {
				HeroForEnemy->MoveTo(HeroForEnemy->GetWorldX()+8, HeroForEnemy->GetWorldY());
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

	// Hero���� �ǰ�����
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

		if(KnockbackCount != -1)
		{
			if(HeroForEnemy->GetWorldX()+100 < Center)		// Hero�� ���ʿ� ���� ��
			{
				MoveTo(GetWorldX()+2, GetWorldY());

			}
			else if(HeroForEnemy->GetWorldX()+100 > Center)	// Hero�� �����ʿ� ���� ��
			{
				MoveTo(GetWorldX()-2, GetWorldY());
			}

			if(KnockbackCount >= 20) {
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
				HitEffect->SetCount(0);
			}
		}
	}

// �νĹ��� �������� �ൿ
	if(!GetHit())
	{
		if(b_left)
		{
			if(HeroForEnemy->GetWorldX()+100 > RcnzX && !b_Attack && GetHP() > 0)
			{
				if(Center-100 < HeroForEnemy->GetWorldX()+100) {
					b_Move = false;
				}
				else {
					b_Move = true;
					MoveTo(GetWorldX()-(int)GetSpd(), GetWorldY());
				}
				RecognizeRange = 650;
			}
			else {
				b_Move = false;
			}
		}
		else if(b_right)
		{
			if(HeroForEnemy->GetWorldX()+100 < RcnzX && !b_Attack && GetHP() > 0)
			{
				if(Center+100 > HeroForEnemy->GetWorldX()+100) {
					b_Move = false;
				}
				else {
					b_Move = true;
					MoveTo(GetWorldX()+(int)GetSpd(), GetWorldY());
				}
				RecognizeRange = 650;
			}
			else {
				b_Move = false;
			}
		}
	}

	// ��
	if(GetWorldX() < -76)
	{
		WorldX = -76;
	}

	if(GetHP() < 0)
	{
		b_Move = false;
		b_Attack = false;
	}

}

void CObject_Mole::Render()
{
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);

	if(GetHP() > 0)
	{
		// ���� HP�� ���
		DrawRectGraph((int)fDrawX+100,	(int)fDrawY,	0,	0,	100,									15,		HP_Back,	TRUE, FALSE);
		DrawRectGraph((int)fDrawX+100,	(int)fDrawY,	0,	0,	(int)(100*((float)HP/(float)MaxHP)),	173,	HP_Bar,		TRUE, FALSE);
		
		if(GetHit())
		{
			if(b_left) {
				Hit->DrawSprite((int)fDrawX, (int)fDrawY, FALSE);
				HitEffect->DrawSprite((int)fDrawX-230, (int)fDrawY-100);
			}
			else if(b_right) {
				Hit->DrawTurnSprite((int)fDrawX, (int)fDrawY, FALSE);
				HitEffect->DrawTurnSprite((int)fDrawX-230, (int)fDrawY-100);
			}
		}
		else if(b_Attack)
		{
			if(b_left)
				Attack->DrawSprite((int)fDrawX, (int)fDrawY);
			else if(b_right)
				Attack->DrawTurnSprite((int)fDrawX, (int)fDrawY);
		}
		else if(b_Move)
		{
			if(b_left)
				Move->DrawSprite((int)fDrawX, (int)fDrawY+2);
			else if(b_right)
				Move->DrawTurnSprite((int)fDrawX, (int)fDrawY+2);
		}
		else
		{
			if(b_left)
				Move->DrawSprite((int)fDrawX, (int)fDrawY-5);
			else if(b_right)
				Move->DrawTurnSprite((int)fDrawX, (int)fDrawY-5);
		}

		// ������ ���
		if(GetHit())
		{
			SetDrawBlendMode(DX_BLENDMODE_ADD, 255-(10*KnockbackCount));
			SetDrawBright(255, 255, 255);
			Func->DrawNum((int)fDrawX+140, (int)fDrawY-20-(KnockbackCount*2), (int)HeroForEnemy->GetDmg());
		}

	}
	else
	{
		if(Death->GetCount() < 9)
		{
			if(b_left) {
				Death->DrawSprite(fDrawX, fDrawY, FALSE);
			}
			else if(b_right) {
				Death->DrawTurnSprite(fDrawX, fDrawY, FALSE);
			}
			if(GetHit())
			{
				SetDrawBlendMode(DX_BLENDMODE_ADD, 100);
				Func->DrawNum((int)fDrawX+140, (int)fDrawY-20-(KnockbackCount*2), (int)HeroForEnemy->GetDmg());
			}
		}
		
	}



	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
	
}

void CObject_Mole::Control()
{
}