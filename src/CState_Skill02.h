#ifndef __CSTATE_SKILL02__
#define __CSTATE_SKILL02__

#include "CState.h"

class CState_Skill02 : public CState
{
private:
	CSprite* AttackSprite;
	int AttackCount;
	int SkillCount;
	int timer;

public:
	CState_Skill02();
	~CState_Skill02();

	virtual CState* Update();
	virtual CState* Render();
	virtual CState* Control();
};

#endif