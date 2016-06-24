#include "CState_Skill05.h"
#include "ResourceManager.h"

// ½ºÇÇ¾î
CState_Skill05::CState_Skill05()
{
	AttackSprite = new CSprite(GetResourceWithKey(IMAGE_HERO), 10, 0, 1000, 10, 6, 2000, 200, 70, TRUE);
	SkillSprite = new CSprite(GetResourceWithKey(IMAGE_HERO_SKILL12), 17, 0, 0, 17, 0, 14773, 370, 42, TRUE);
	AttackCount = 0;
	SkillCount = 0;
}

CState_Skill05::~CState_Skill05()
{
	delete AttackSprite;
	AttackSprite = NULL;
}

CState* CState_Skill05::Update()
{
	Master->SetDmg(50);
	Master->SetMove(false);

	if(Master->GetAttack() && (SkillSprite->GetCount() == 9 || SkillSprite->GetCount() == 11 || SkillSprite->GetCount() == 13))
	{
		if(b_Left)
		{
			Master->SetAttackBox((int)Master->GetDrawX()-200, (int)Master->GetDrawY()+0, 500, 200);
		}
		else if(b_Right)
		{
			Master->SetAttackBox((int)Master->GetDrawX()+100, (int)Master->GetDrawY()+0, 500, 200);
		}
	}

	if(Master->GetHit() && !Master->GetGuard()) {
		AttackSprite->SetCount(0);
		SkillSprite->SetCount(0);
		return Hit;
	}
	return Skill05;
}

CState* CState_Skill05::Render()
{
	if(Master->GetBattle())
	{
		if(b_Right)
		{
			AttackSprite->DrawSprite(((int)Master->GetDrawX()), (int)(Master->GetDrawY()));
			SkillSprite->DrawSprite(((int)Master->GetDrawX()+100)-150, (int)(Master->GetDrawY())-125);
		}
		else if(b_Left)
		{
			AttackSprite->DrawTurnSprite(((int)Master->GetDrawX()), (int)(Master->GetDrawY()));
			SkillSprite->DrawTurnSprite(((int)Master->GetDrawX()+100)-869 + 150, (int)(Master->GetDrawY())-125);
		}
	}
	else
	{
		AttackSprite->SetCount(0);
		return Stand;
	}
	return Skill05;
}

CState* CState_Skill05::Control()
{
	AttackCount = AttackSprite->GetCount();

	if(AttackCount >= 8)
	{
		AttackSprite->SetCount(0);
		SkillSprite->SetCount(0);
		if((CheckHitKey(KEY_INPUT_LEFT) || CheckHitKey(KEY_INPUT_RIGHT)))
		{
			if(CheckHitKey(KEY_INPUT_LEFT)) {
				b_Left = true;
				b_Right = false;
				return Stand;
			}
			if(CheckHitKey(KEY_INPUT_RIGHT)) {
				b_Left = false;
				b_Right = true;
				return Stand;
			}
		}

		if((CheckHitKey(KEY_INPUT_LEFT) && CheckHitKey(KEY_INPUT_RIGHT)) || CheckHitKeyAll() == 0) {
			return Stand;
		}
		return Stand;
	}
	return Skill05;
}