#include "CState_Guard.h"
#include "ResourceManager.h"

CState_Guard::CState_Guard()
{
	GuardSprite = new CSprite(GetResourceWithKey(IMAGE_HERO), 4, 0, 600, 4, 1, 800, 200, 120, TRUE);
	GuardEffect = new CSprite(GetResourceWithKey(IMAGE_HERO_GUARD), 4, 0, 0, 4, 1, 408, 147, 50, TRUE);
	GuardEffect->SetCount(4);
}

CState_Guard::~CState_Guard()
{
	delete GuardSprite;
	delete GuardEffect;
}

CState* CState_Guard::Update()
{
	if(Master->GetGuardHit())
	{
		Master->SetGuardHit(FALSE);
		GuardEffect->SetCount(0);
	}

	return Guard;
}


CState* CState_Guard::Render()
{
	int temp = GuardEffect->GetCount();
	if(b_Right) {
		GuardSprite->DrawSprite((int)Master->GetDrawX(), (int)Master->GetDrawY()+10);
		if(temp < 4) {
			GuardEffect->DrawSprite((int)Master->GetDrawX()+100, (int)Master->GetDrawY()+40, FALSE);
		}
	}
	else if(b_Left) {
		GuardSprite->DrawTurnSprite((int)Master->GetDrawX(), (int)Master->GetDrawY()+10);
		if(temp < 4) {
			GuardEffect->DrawTurnSprite((int)Master->GetDrawX()+100-102, (int)Master->GetDrawY()+40, FALSE);
		}
	}
	return Guard;
}

CState* CState_Guard::Control()
{

	if(CheckHitKey(KEY_INPUT_Z))
	{
		Master->SetGuard(true);
		return Guard;
	}
	else
	{
		Master->SetGuard(false);
		return Stand;
	}
}