#ifndef __CSTATE_SKILL05__
#define __CSTATE_SKILL05__

#include "CState.h"
#include "CSprite.h"

class CState_Skill05 : public CState
{
private:
	int SkillGraph;
	CSprite* AttackSprite;
	CSprite* SkillSprite;
	int AttackCount;
	int SkillCount;

public:
	CState_Skill05();
	~CState_Skill05();

	virtual CState* Update();
	virtual CState* Render();
	virtual CState* Control();
};

#endif