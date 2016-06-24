#include "CState_Skill03.h"
#include "ResourceManager.h"

// ½ºÅÇ
CState_Skill03::CState_Skill03()
{
	AttackSprite = new CSprite(GetResourceWithKey(IMAGE_HERO), 10, 0, 1000, 10, 6, 2000, 200, 65, true);
	SkillSprite = new CSprite(GetResourceWithKey(IMAGE_HERO_SKILL11), 13, 0, 0, 13, 1, 6500, 500, 50, true);
	
	AttackCount = 0;
	SkillCount = 0;
}

CState_Skill03::~CState_Skill03()
{
	delete SkillSprite;
	SkillSprite = NULL;
}

CState* CState_Skill03::Update()
{
	Master->SetDmg(15);
	Master->SetMove(false);

	if(Master->GetAttack() && (SkillSprite->GetCount() == 2 || SkillSprite->GetCount() == 6 || SkillSprite->GetCount() == 10))
	{
		if(b_Left)
		{
			Master->SetAttackBox((int)Master->GetDrawX()-200, (int)Master->GetDrawY()+0, 300, 200);
		}
		else if(b_Right)
		{
			Master->SetAttackBox((int)Master->GetDrawX()+100, (int)Master->GetDrawY()+0, 300, 200);
		}
	}

	if(b_Left) {
		Master->MoveTo(Master->GetWorldX()-4, Master->GetWorldY());
	}
	else if(b_Right) {
		Master->MoveTo(Master->GetWorldX()+4, Master->GetWorldY());
	}

	if(Master->GetHit() && !Master->GetGuard()) {
		AttackSprite->SetCount(0);
		SkillSprite->SetCount(0);
		return Hit;
	}

	return Skill03;
}

CState* CState_Skill03::Render()
{
	if(Master->GetBattle())
	{
		if(b_Right)
		{
			AttackSprite->DrawSprite(((int)Master->GetDrawX()), (int)(Master->GetDrawY()));
			SkillSprite->DrawSprite(((int)Master->GetDrawX()+20), (int)(Master->GetDrawY()-100), TRUE);
		}
		else if(b_Left)
		{
			AttackSprite->DrawTurnSprite(((int)Master->GetDrawX()), (int)(Master->GetDrawY()));
			SkillSprite->DrawTurnSprite(((int)Master->GetDrawX()-280), (int)(Master->GetDrawY()-100), TRUE);
		}
	}
	else
	{
		return Stand;
	}
	return Skill03;
}

CState* CState_Skill03::Control()
{
	AttackCount = AttackSprite->GetCount();
	SkillCount = SkillSprite->GetCount();

	if(AttackCount >= 9)
	{
		AttackSprite->SetCount(0);
		SkillSprite->SetCount(0);
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
	
	return Skill03;
}