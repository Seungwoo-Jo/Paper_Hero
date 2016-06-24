#ifndef __CSTATE_HIT__
#define __CSTATE_HIT__

#include "CState.h"
#include "CSprite.h"

class CState_Hit : public CState
{
private:
	CSprite* HitSprite;

public:
	CState_Hit();
	~CState_Hit();

	virtual CState* Update();
	virtual CState* Render();
	virtual CState* Control();
};

#endif