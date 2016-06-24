#ifndef __CSTATE_GUARD__
#define __CSTATE_GUARD__

#include "CState.h"
#include "CSprite.h"

class CState_Guard : public CState
{
private:
	CSprite* GuardSprite;
	CSprite* GuardEffect;

public:
	CState_Guard();
	~CState_Guard();

	virtual CState* Update();
	virtual CState* Render();
	virtual CState* Control();
};

#endif