#include "CState_Move.h"
#include "ResourceManager.h"

CState_Move::CState_Move()
{
	MoveSprite = new CSprite(GetResourceWithKey(IMAGE_HERO), 7, 0, 200, 7, 2, 1400, 200, 125, true);
	WalkSound = new CSound(LoadSoundMem("Resource/Sound/hero_walk.ogg"), 0);
	b_Turn = false;
}

CState_Move::~CState_Move()
{
	delete WalkSound;
	delete MoveSprite;
}

CState* CState_Move::Update()
{
	Master->SetMove(true);
	Master->SetAir(false);

	if(!Master->GetHit())
	{
		if(b_Left) {
			Master->MoveTo( Master->GetWorldX()-(int)Master->GetSpd(), Master->GetWorldY() );
		}
		else if(b_Right) {
			Master->MoveTo( Master->GetWorldX()+(int)Master->GetSpd(), Master->GetWorldY() );
		}
	}
	Master->SetAttack(false);

	Master->SetAttackBox(0, 0, 0, 0);

	if(Master->GetHit() && !Master->GetGuard()) {
		return Hit;
	}

	return Move;
}

CState* CState_Move::Render()
{
	if(b_Turn)
	{
		b_Turn = MoveSprite->TurnAnimation(((int)Master->GetDrawX()), (int)(Master->GetDrawY()), !b_Left, !b_Right, b_Turn);
		return Move;
	}
	else
	{
	}
	int temp = 0;
	if(b_Right)
	{
		temp = MoveSprite->DrawSprite(((int)Master->GetDrawX()), (int)(Master->GetDrawY()));
	}
	else if(b_Left)
	{
		temp = MoveSprite->DrawTurnSprite(((int)Master->GetDrawX()), (int)(Master->GetDrawY()));
	}
	if(temp == 1 || temp == 5)
		WalkSound->PlaySoundA();

	return Move;
}

CState* CState_Move::Control()
{
	if(CheckHitKey(KEY_INPUT_Z))
	{
		Master->SetGuard(true);
		return Guard;
	}


	if(!b_Turn && (CheckHitKey(KEY_INPUT_LEFT) && CheckHitKey(KEY_INPUT_RIGHT)) || CheckHitKeyAll() == 0 || CheckHitKey(KEY_INPUT_TAB)) {
		Master->SetMove(false);
		return Stand;
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

	if(b_Left)
	{
		if(CheckHitKey(KEY_INPUT_RIGHT)) {
			b_Left = false;
			b_Right = true;
			b_Turn = true;
			return Move;
		}
	}
	else if(b_Right)
	{
		if(CheckHitKey(KEY_INPUT_LEFT)) {
			b_Left = true;
			b_Right = false;
			b_Turn = true;
			return Move;
		}
	}

	if(CheckHitKey(KEY_INPUT_UP)) {
		return Enter;
	}

	return Move;
}