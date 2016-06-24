#ifndef __CSTATE_STAND__
#define __CSTATE_STAND__

#include "CState.h"
#include "CSprite.h"

class CState_Stand : public CState
{
private:
	CSprite* StandSprite;
	CSprite* BattleSprite;

public:
	CState_Stand();
	~CState_Stand();

	virtual CState* Update();
	virtual CState* Render();
	virtual CState* Control();
};

#endif