#include "CState_Skill04.h"
#include "ResourceManager.h"

// 토네이도
CState_Skill04::CState_Skill04()
{
	AttackSprite = new CSprite(GetResourceWithKey(IMAGE_HERO), 9, 0, 400, 9, 3, 1800, 200, 50, true);
	AttackCount = 0;
}

CState_Skill04::~CState_Skill04()
{
	delete AttackSprite;
	AttackSprite = NULL;
}

CState* CState_Skill04::Update()
{
	Master->SetDmg(60);
	Master->SetMove(false);

	if(Master->GetHit() && !Master->GetGuard()) {
		AttackSprite->SetCount(0);
		return Hit;
	}

	return Skill04;
}

CState* CState_Skill04::Render()
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
	return Skill04;
}

CState* CState_Skill04::Control()
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
	return Skill04;
}