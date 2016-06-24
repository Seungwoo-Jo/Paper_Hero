#ifndef __CSTATE_SKILL03__
#define __CSTATE_SKILL03__

#include "CState.h"

class CState_Skill03 : public CState
{
private:
	int SkillGraph;
	CSprite* AttackSprite;
	CSprite* SkillSprite;
	int AttackCount;
	int SkillCount;

public:
	CState_Skill03();
	~CState_Skill03();

	virtual CState* Update();
	virtual CState* Render();
	virtual CState* Control();
};

#endif