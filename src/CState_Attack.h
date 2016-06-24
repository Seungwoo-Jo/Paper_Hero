#ifndef __CSTATE_ATTACK__
#define __CSTATE_ATTACK__

#include "CSound.h"
#include "CState.h"
#include "CSprite.h"


class CState_Attack : public CState
{
private:
	CSprite* AttackSprite;
	CSound* AttackSound;
	int Count;

public:
	CState_Attack();
	~CState_Attack();

	virtual CState* Update();
	virtual CState* Render();
	virtual CState* Control();
};

#endif