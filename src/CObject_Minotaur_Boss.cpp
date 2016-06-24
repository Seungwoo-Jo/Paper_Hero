#include "CObject_Minotaur_Boss.h"
#include "ResourceManager.h"
#include "CObject_Minotaur.h"
#include "CCollision.h"

CObject_Minotaur_Boss::CObject_Minotaur_Boss()
{
}

CObject_Minotaur_Boss::CObject_Minotaur_Boss(int GHandle, double x, double y, int Width, int Height, unsigned int Type) : CObject_Enemy(GHandle, x, y, Width, Height, Type)
{
	GraphHandle = GetResourceWithKey(GHandle);
	Stand	= new CSprite(GraphHandle, 13, 0, 0, 13, 1, 5200, 400, 100, TRUE);
	Move	= new CSprite(GraphHandle, 10, 0, 400, 10, 2, 4000, 400, 100, TRUE);
	Attack	= new CSprite(GraphHandle, 7, 0, 800,  7, 3, 2800, 400, 100, TRUE);
	Hit		= new CSprite(GraphHandle, 2, 0, 1200, 2, 4, 800, 400, 100, TRUE);
	Skill	= new CSprite(GraphHandle, 13, 0, 1600, 13, 5, 5200, 400, 100, TRUE);
	Death	= new CSprite(GetResourceWithKey(IMAGE_DEAD), 10, 0, 0, 10, 1, 3000, 350, 80, TRUE);
	HitEffect = new CSprite(HitHandle, 4, 0, 0, 4, 1, 2640, 430, 84, TRUE);

	b_left = true;
	b_right = false;

	Center = WorldX + 200;
	
	RecognizeRange = 475;
	AttackRange = 165;
	//PatrolRange = -1;

	SetMove(false);
	SetAttack(false);

	b_FirstAtk = true;
	SetHit(false);

	AttackNum = 1;
	AttackDelay = 180;
	AttackCount = -1;
	HeroKnockbackCount = -1;
	KnockbackCount = -1;
	HitCount = -1;

	Stat_ST = 80;
	Damage = Stat_ST * 0.5f;
	Stat_HP = 15;
	MaxHP = Stat_HP * 40;
	HP = MaxHP;
	Speed = 2;

	Exp = 100;

	temp = 0;
}

CObject_Minotaur_Boss::~CObject_Minotaur_Boss()
{
	delete Stand;
	delete Move;
	delete Attack;
	delete Hit;
	delete Skill;
	delete HitEffect;
}

void CObject_Minotaur_Boss::Update()
{
	Center = WorldX + 200;
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

	// ���ݹ��� �������� �ൿ
	if(GetHP() > 0)
	{
		if(HeroForEnemy->GetWorldX()+100 > AtkX && b_left)
		{
			if(AttackCount == -1 ) {
				SetAttack(true);
				AttackNum++;
				AttackCount = 0;
			}
			if(Attack->GetCount() == 3 || Skill->GetCount() == 11) {
				SetAttackBox((int)GetDrawX()+50, (int)GetDrawY()+10, 150, 250);
			}
		}
		else if(HeroForEnemy->GetWorldX()+100 < AtkX && b_right)
		{
			if(AttackCount == -1 ) {
				SetAttack(true);
				AttackNum++;
				AttackCount = 0;
			}
			if(Attack->GetCount() == 3 || Skill->GetCount() == 11) {
				SetAttackBox((int)GetDrawX()+200, (int)GetDrawY()+10, 150, 250);
			}
		}

		if(AttackCount != -1) {
			AttackCount++;
		}

		if(Attack->GetCount() >= 6 || Skill->GetCount() >= 12) {
			Attack->SetCount(0);
			Skill->SetCount(0);
			SetAttack(false);
		}

		if(AttackCount > AttackDelay) {
			AttackCount = -1;
			Attack->SetCount(0);
			Skill->SetCount(0);
			SetAttack(false);
		}
	}




	// �浹�ڽ� ����
	SetBoundBox((int)GetDrawX()+75, (int)GetDrawY()+25, 250, 300);

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
				HeroForEnemy->MoveTo(HeroForEnemy->GetWorldX()-4, HeroForEnemy->GetWorldY());
			}
			else {
				HeroForEnemy->MoveTo(HeroForEnemy->GetWorldX()-6, HeroForEnemy->GetWorldY());
			}
		}
		else if(HeroForEnemy->GetWorldX()+100 > Center)	// Hero�� �����ʿ� ���� ��
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

		if(KnockbackCount >= 10) {
			KnockbackCount = -1;
		}
		else {
			KnockbackCount++;
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

void CObject_Minotaur_Boss::Render()
{
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);

	if(GetHP() > 0)
	{
		// ���� HP�� ���
		DrawRectGraph((int)fDrawX+150,	(int)fDrawY+20,	0,	0,	100,									15,		HP_Back,	TRUE, FALSE);
		DrawRectGraph((int)fDrawX+150,	(int)fDrawY+20,	0,	0,	(int)(100*((float)HP/(float)MaxHP)),	173,	HP_Bar,		TRUE, FALSE);
		
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
			if(AttackNum%3 == 0)
			{
				if( temp >= 22 ) {
					temp -= 11;
				}
				else {
					temp += 2;
				}
				if(b_left)
					Skill->DrawSprite((int)fDrawX, (int)fDrawY);
				else if(b_right)
					Skill->DrawTurnSprite((int)fDrawX, (int)fDrawY);
			}
			else
			{
				temp = 0;
				if(b_left)
					Attack->DrawSprite((int)fDrawX, (int)fDrawY);
				else if(b_right)
					Attack->DrawTurnSprite((int)fDrawX, (int)fDrawY);
			}
		}
		else if(b_Move)
		{
			if(b_left)
				Move->DrawSprite((int)fDrawX, (int)fDrawY);
			else if(b_right)
				Move->DrawTurnSprite((int)fDrawX, (int)fDrawY);
		}
		else
		{
			if(b_left)
				Stand->DrawSprite((int)fDrawX, (int)fDrawY);
			else if(b_right)
				Stand->DrawTurnSprite((int)fDrawX, (int)fDrawY);
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

void CObject_Minotaur_Boss::Control()
{
}