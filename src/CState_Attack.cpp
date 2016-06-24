#include "CState_Attack.h"
#include "ResourceManager.h"

CState_Attack::CState_Attack()
{
	AttackSprite = new CSprite(GetResourceWithKey(IMAGE_HERO), 9, 0, 400, 9, 3, 1800, 200, 38, true);
	AttackSound = new CSound(LoadSoundMem("Resource/Sound/hero_basicatk.ogg"), 0);
	Count = 0;
}

CState_Attack::~CState_Attack()
{
	delete AttackSprite;
	delete AttackSound;
}

CState* CState_Attack::Update()
{
	Master->SetDmg(Master->GetStat_ST()/2);
	Master->SetAttackBox(0, 0, 0, 0);
	Master->SetAir(false);
	Master->SetMove(false);

	if(Master->GetBattle())
	{
		if(Master->GetAttack() && Count == 5)
		{
			if(b_Left)
			{
				Master->SetAttackBox((int)Master->GetDrawX(), (int)Master->GetDrawY()+0, 100, 200);
			}
			else if(b_Right)
			{
				Master->SetAttackBox((int)Master->GetDrawX()+100, (int)Master->GetDrawY()+0, 100, 200);
			}
		}
	}
	else
	{
		return Stand;
	}

	if(Master->GetHit() && !Master->GetGuard()) {
		AttackSprite->SetCount(0);
		return Hit;
	}

	return Attack;
}

CState* CState_Attack::Render()
{
	int temp = 0;
	if(b_Right)
	{
		temp = AttackSprite->DrawSprite(((int)Master->GetDrawX()), (int)(Master->GetDrawY()));
	}
	else if(b_Left)
	{
		temp = AttackSprite->DrawTurnSprite(((int)Master->GetDrawX()), (int)(Master->GetDrawY()));
	}

	if(temp == 3) {
		AttackSound->PlaySoundA();
	}

	return Attack;
}

CState* CState_Attack::Control()
{
	if(CheckHitKey(KEY_INPUT_Z))
	{
		AttackSprite->SetCount(0);
		Master->SetGuard(true);
		return Guard;
	}

	Count = AttackSprite->GetCount();
	if(Count >= 8)
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
	return Attack;
}