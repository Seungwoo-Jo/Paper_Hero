#include "CState_Jump.h"
#include "ResourceManager.h"

CState_Jump::CState_Jump()
{
	JumpSprite = new CSprite(GetResourceWithKey(IMAGE_HERO), 7, 0, 200, 7, 2, 1400, 200, 150, true);
	JumpPower = 29.0f;
	JumpTime = 0;
}

CState_Jump::~CState_Jump()
{
	delete JumpSprite;
}

float CState_Jump::GetValue()
{
	return (float)JumpTime;
}

void CState_Jump::SetValue(float x)
{
	JumpTime = (int)x;
}

CState* CState_Jump::Update()
{
	if(JumpTime >= 0 && JumpTime <= 30)
	{
		JumpPower *= 0.92f;
		JumpTime++;
	}
	else if(JumpTime > 30 && JumpTime <= 60)
	{
		JumpPower *= 1.085f;

		if(JumpPower > 0) {
			JumpPower *= -1;
		}
		JumpTime++;
	}
	else 
	{
		JumpTime = -1;
	}

	if(JumpTime != -1) {
		Master->MoveTo(Master->GetWorldX(), Master->GetWorldY()-(int)JumpPower);
	}

	if(!Master->GetAir())
	{
		JumpPower = 29.0f;
		JumpTime = -1;
		if(Master->GetMove()) {
			return Move;
		}
		else {
			return Stand;
		}
	}
	
	if(Master->GetMove() && !Master->GetHit())
	{
		if(b_Left) {
			Master->MoveTo( Master->GetWorldX()-(int)Master->GetSpd(), Master->GetWorldY() );
		}
		else if(b_Right) {
			Master->MoveTo( Master->GetWorldX()+(int)Master->GetSpd(), Master->GetWorldY() );
		}
	}

	return Jump;
}

CState* CState_Jump::Render()
{
	if(b_Turn)
	{
		b_Turn = JumpSprite->TurnAnimation(((int)Master->GetDrawX()), (int)(Master->GetDrawY()), !b_Left, !b_Right, b_Turn);
		return Jump;
	}

	if(b_Right)
	{
		JumpSprite->DrawSprite(((int)Master->GetDrawX()), (int)(Master->GetDrawY()));
	}
	else if(b_Left)
	{
		JumpSprite->DrawTurnSprite(((int)Master->GetDrawX()), (int)(Master->GetDrawY()));
	}
	return Jump;
}

CState* CState_Jump::Control()
{
	Master->SetMove(false);
	if(CheckHitKey(KEY_INPUT_RIGHT)) {
		if(b_Left) {
			b_Turn = true;
		}
		b_Left = false;
		b_Right = true;
		Master->SetMove(true);
	}
	else if(CheckHitKey(KEY_INPUT_LEFT)) {
		if(b_Right) {
			b_Turn = true;
		}
		b_Left = true;
		b_Right = false;
		Master->SetMove(true);
	}
	else
	{
		Master->SetMove(false);
	}

	/*
	if(Master->GetBattle())
	{
		if(CheckHitKey(KEY_INPUT_X) == 1) {
			Master->SetAttack(true);
			return Attack;
		}
		else if(CheckHitKey(KEY_INPUT_1) == 1) {
			if(Master->GetMP() >= 25) {
				Master->SetMP(Master->GetMP() - 25);
				Master->SetAttack(true);
				return Skill01;
			}
			else
			{
				Master->SetMP_Empty(0);
				return Jump;
			}
		}
	}
	*/
	return Jump;
}
