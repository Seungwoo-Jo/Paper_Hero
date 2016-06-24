#include "CState_Skill01.h"
#include "ResourceManager.h"

// ½ã´õ½ºÅè
CState_Skill01::CState_Skill01()
{
	AttackSprite = new CSprite(GetResourceWithKey(IMAGE_HERO), 9, 0, 400, 9, 3, 1800, 200, 75, true);

	AttackCount = 0;
	SkillCount = 0;
}

CState_Skill01::~CState_Skill01()
{
	delete AttackSprite;
	AttackSprite = NULL;
}

CState* CState_Skill01::Update()
{
	Master->SetDmg(50);
	Master->SetMove(false);

	if(Master->GetHit() && !Master->GetGuard()) {
		AttackSprite->SetCount(0);
		SkillSprite->SetCount(0);
		return Hit;
	}

	return Skill01;
}

CState* CState_Skill01::Render()
{
	if(Master->GetBattle())
	{
		if(b_Right)
		{
			AttackSprite->DrawSprite(((int)Master->GetDrawX()), (int)(Master->GetDrawY()));

		}
		else if(b_Left)
		{
			AttackSprite->DrawTurnSprite(((int)Master->GetDrawX()), (int)(Master->GetDrawY()));

		}
	}
	else
	{
		AttackSprite->SetCount(0);
		return Stand;
	}
	return Skill01;
}

CState* CState_Skill01::Control()
{
	AttackCount = AttackSprite->GetCount();

	if(AttackCount >= 8)
	{
		AttackSprite->SetCount(0);
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
	return Skill01;
}