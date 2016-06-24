#ifndef __CSTATE_ENTER__
#define __CSTATE_ENTER__

#include "CState.h"
#include "CSprite.h"

class CState_Enter : public CState
{
private:
	CSprite* EnterSprite;
	int YCount;
	int TempY;

public:
	CState_Enter();
	~CState_Enter();

	virtual CState* Update();
	virtual CState* Render();
	virtual CState* Control();
};

#endif