#include "CState_Enter.h"
#include "ResourceManager.h"

CState_Enter::CState_Enter()
{
	EnterSprite = new CSprite(GetResourceWithKey(IMAGE_HERO), 8, 0, 1400, 8, 1, 1600, 200, 80, TRUE);
	YCount = 0;
	TempY = 0;
}

CState_Enter::~CState_Enter()
{
	delete EnterSprite;
}

CState* CState_Enter::Update()
{
	if(EnterSprite->GetCount() > 2) {
		EnterSprite->SetCount(0);
	}

	if(Master->GetOpacity() <= 150) {
		return Stand;
	}

	TempY = Master->GetWorldY() + YCount;
	

	return Enter;
}


CState* CState_Enter::Render()
{
	if(EnterSprite->GetCount() > 1) {
		Master->SetOpacity(150);
	}
	if(b_Right) {
		EnterSprite->DrawSprite((int)Master->GetDrawX(), (int)Master->GetDrawY(), FALSE);
	}
	else if(b_Left) {
		EnterSprite->DrawTurnSprite((int)Master->GetDrawX(), (int)Master->GetDrawY(), FALSE);
	}
	return Enter;
}

CState* CState_Enter::Control()
{
	return Enter;
}