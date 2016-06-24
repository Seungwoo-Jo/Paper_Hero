#ifndef __CSTATE_SKILL04__
#define __CSTATE_SKILL04__

#include "CState.h"

class CState_Skill04 : public CState
{
private:
	CSprite* AttackSprite;
	int AttackCount;

public:
	CState_Skill04();
	~CState_Skill04();

	virtual CState* Update();
	virtual CState* Render();
	virtual CState* Control();
};

#endif