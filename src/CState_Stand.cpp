#include "CState_Stand.h"
#include "ResourceManager.h"

CState_Stand::CState_Stand()
{
	StandSprite = new CSprite(GetResourceWithKey(IMAGE_HERO), 13, 0, 0, 13, 1, 2600, 200, 110, TRUE);
	BattleSprite = new CSprite(GetResourceWithKey(IMAGE_HERO), 4, 0, 800, 4, 5, 800, 200, 110, TRUE);
	b_Turn = false;
}

CState_Stand::~CState_Stand()
{
	delete StandSprite;
	delete BattleSprite;
	delete Stand;
}

CState* CState_Stand::Update()
{
	Master->SetAir(false);
	Master->SetMove(false);
	Master->SetAttack(false);

	Master->SetAttackBox(0, 0, 0, 0);

	if(Master->GetHit() && !Master->GetGuard()) {
		return Hit;
	}

	return Stand;
}

CState* CState_Stand::Render()
{
	if(Master->GetBattle())
	{
		if(b_Right) {
			BattleSprite->DrawSprite(((int)Master->GetDrawX()), (int)(Master->GetDrawY()+8));
		}
		else if(b_Left) {
			BattleSprite->DrawTurnSprite(((int)Master->GetDrawX()), (int)(Master->GetDrawY()+8));
		}
	}
	else
	{
		if(b_Right) {
			StandSprite->DrawSprite(((int)Master->GetDrawX()), (int)(Master->GetDrawY()));
		}
		else if(b_Left) {
			StandSprite->DrawTurnSprite(((int)Master->GetDrawX()), (int)(Master->GetDrawY()));
		}
	}
	return Stand;
}

CState* CState_Stand::Control()
{
	if(CheckHitKey(KEY_INPUT_Z))
	{
		Master->SetGuard(true);
		return Guard;
	}

	if(!b_Turn && (CheckHitKey(KEY_INPUT_LEFT) && CheckHitKey(KEY_INPUT_RIGHT)) || CheckHitKeyAll() == 0) {
		Master->SetMove(false);
		return Stand;
	}

	if(CheckHitKey(KEY_INPUT_R) == 1)
	{
		return Skill02;
	}

	if(Master->GetBattle())
	{
		if(CheckHitKey(KEY_INPUT_X) == 1) {
			Master->SetAttack(true);
			return Attack;
		}
		else if(CheckHitKey(KEY_INPUT_Q) == 1)
		{
			if(Master->GetSkillList()[0].Tag != -1)
			{
				if(Master->GetMP() >= Master->GetSkillList()[0].UseMP) {
					Master->SetMP(Master->GetMP() - Master->GetSkillList()[0].UseMP);
					Master->SetAttack(true);
					return GetState(Master->GetSkillList()[0].Tag);
				}
				else {
					Master->SetMP_Empty(0);
					return Stand;
				}
			}
		}
		else if(CheckHitKey(KEY_INPUT_W) == 1)
		{
			if(Master->GetSkillList()[1].Tag != -1)
			{
				if(Master->GetMP() >= Master->GetSkillList()[1].UseMP) {
					Master->SetMP(Master->GetMP() - Master->GetSkillList()[1].UseMP);
					Master->SetAttack(true);
					return GetState(Master->GetSkillList()[1].Tag);
				}
				else {
					Master->SetMP_Empty(0);
					return Stand;
				}
			}
		}
		else if(CheckHitKey(KEY_INPUT_E) == 1)
		{
			if(Master->GetSkillList()[2].Tag != -1)
			{
				if(Master->GetMP() >= Master->GetSkillList()[2].UseMP) {
					Master->SetMP(Master->GetMP() - Master->GetSkillList()[2].UseMP);
					Master->SetAttack(true);
					return GetState(Master->GetSkillList()[2].Tag);
				}
				else {
					Master->SetMP_Empty(0);
					return Stand;
				}
			}
		}
		else if(CheckHitKey(KEY_INPUT_A) == 1)
		{
			if(Master->GetSkillList()[3].Tag != -1)
			{
				if(Master->GetMP() >= Master->GetSkillList()[3].UseMP) {
					Master->SetMP(Master->GetMP() - Master->GetSkillList()[3].UseMP);
					Master->SetAttack(true);
					return GetState(Master->GetSkillList()[3].Tag);
				}
				else {
					Master->SetMP_Empty(0);
					return Stand;
				}
			}
		}
		else if(CheckHitKey(KEY_INPUT_S) == 1)
		{
			if(Master->GetSkillList()[4].Tag != -1)
			{
				if(Master->GetMP() >= Master->GetSkillList()[4].UseMP) {
					Master->SetMP(Master->GetMP() - Master->GetSkillList()[4].UseMP);
					Master->SetAttack(true);
					return GetState(Master->GetSkillList()[4].Tag);
				}
				else {
					Master->SetMP_Empty(0);
					return Stand;
				}
			}
		}
		else if(CheckHitKey(KEY_INPUT_D) == 1)
		{
			if(Master->GetSkillList()[5].Tag != -1)
			{
				if(Master->GetMP() >= Master->GetSkillList()[5].UseMP) {
					Master->SetMP(Master->GetMP() - Master->GetSkillList()[5].UseMP);
					Master->SetAttack(true);
					return GetState(Master->GetSkillList()[5].Tag);
				}
				else {
					Master->SetMP_Empty(0);
					return Stand;
				}
			}
		}
	}

	if(CheckHitKey(KEY_INPUT_C) == 1)
	{
		Master->SetAir(true);
		Jump->SetValue(0);
		return Jump;
	}

	if((CheckHitKey(KEY_INPUT_LEFT) || CheckHitKey(KEY_INPUT_RIGHT)))
	{
		if(CheckHitKey(KEY_INPUT_LEFT)) {
			if(b_Right) {
				b_Turn = true;
			}
			b_Left = true;
			b_Right = false;
			return Move;
		}
		else if(CheckHitKey(KEY_INPUT_RIGHT)) {
			if(b_Left) {
				b_Turn = true;
			}
			b_Left = false;
			b_Right = true;
			return Move;
		}
	}

	if(CheckHitKey(KEY_INPUT_UP)) {
		return Enter;
	}

	return Stand;
}