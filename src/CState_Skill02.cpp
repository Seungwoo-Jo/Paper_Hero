#include "CState_Skill02.h"
#include "ResourceManager.h"

// ╦чев©ю
CState_Skill02::CState_Skill02()
{
	AttackSprite = new CSprite(GetResourceWithKey(IMAGE_HERO), 9, 0, 400, 9, 3, 1800, 200, 75, true);
	
	AttackCount = 0;
	SkillCount = 0;
	timer = 0;
	
}

CState_Skill02::~CState_Skill02()
{
	delete AttackSprite;
}

CState* CState_Skill02::Update()
{
	Master->SetDmg(1000);

	Master->SetMove(false);
	timer++;

	if(Master->GetHit() && !Master->GetGuard()) {
		AttackSprite->SetCount(0);
		return Hit;
	}
	return Skill02;
}

CState* CState_Skill02::Render()
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
		return Stand;
	}
	return Skill02;
}

CState* CState_Skill02::Control()
{
	AttackCount = AttackSprite->GetCount();

	if(AttackCount >= 8)
	{
		AttackSprite->SetCount(0);
		for(int i=0; i<9; i++) {
		}
		if((CheckHitKey(KEY_INPUT_LEFT) || CheckHitKey(KEY_INPUT_RIGHT)))
		{
			if(CheckHitKey(KEY_INPUT_LEFT)) {
				b_Left = true;
				b_Right = false;
				return Move;
			}
			if(CheckHitKey(KEY_INPUT_RIGHT)) {
				b_Left = false;
				b_Right = true;
				return Move;
			}
		}

		if((CheckHitKey(KEY_INPUT_LEFT) && CheckHitKey(KEY_INPUT_RIGHT)) || CheckHitKeyAll() == 0) {
			return Stand;
		}
		
		return Stand;
	}
	return Skill02;
}