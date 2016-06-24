#ifndef __CSTATE_JUMP__
#define __CSTATE_JUMP__

#include "CState.h"

class CState_Jump : public CState
{
private:
	CSprite* JumpSprite;
	float JumpPower;
	int JumpTime;

public:
	CState_Jump();
	~CState_Jump();

	virtual float GetValue();
	virtual void SetValue(float x);
	virtual CState* Update();
	virtual CState* Render();
	virtual CState* Control();
};

#endif