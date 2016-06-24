#ifndef __CSTATE_SKILL01__
#define __CSTATE_SKILL01__

#include "CState.h"
#include "CSprite.h"

class CState_Skill01 : public CState
{
private:
	int SkillGraph;
	CSprite* AttackSprite;
	CSprite* SkillSprite;
	int AttackCount;
	int SkillCount;

public:
	CState_Skill01();
	~CState_Skill01();

	virtual CState* Update();
	virtual CState* Render();
	virtual CState* Control();
};

#endif