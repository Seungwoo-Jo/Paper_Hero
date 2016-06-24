#include "CState_Hit.h"
#include "ResourceManager.h"

CState_Hit::CState_Hit()
{
	HitSprite = new CSprite(GetResourceWithKey(IMAGE_HERO), 2, 0, 1200, 2, 1, 400, 200, 200, TRUE);
}

CState_Hit::~CState_Hit()
{
	delete HitSprite;
}

CState* CState_Hit::Update()
{
	if(Master->GetHit()) {
		return Hit;
	}
	else {
		return Stand;
	}
}


CState* CState_Hit::Render()
{
	if(b_Right) {
		HitSprite->DrawSprite((int)Master->GetDrawX(), (int)Master->GetDrawY()+5, FALSE);
	}
	else if(b_Left) {
		HitSprite->DrawTurnSprite((int)Master->GetDrawX(), (int)Master->GetDrawY()+5, FALSE);
	}
	return Hit;
}

CState* CState_Hit::Control()
{
	return Hit;
}