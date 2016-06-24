#ifndef __CSTATE_MOVE__
#define __CSTATE_MOVE__

#include "CState.h"
#include "CSprite.h"
#include "CSound.h"

class CState_Move : public CState
{
private:
	CSprite* MoveSprite;
	CSound* WalkSound;

public:
	CState_Move();
	~CState_Move();

	virtual CState* Update();
	virtual CState* Render();
	virtual CState* Control();
};

#endif