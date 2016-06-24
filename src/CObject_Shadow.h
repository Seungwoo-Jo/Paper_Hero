#ifndef __COBJECT_SHADOW__
#define __COBJECT_SHADOW__

#include "CObject_Enemy.h"

class CObject_Shadow : public CObject_Enemy
{
private:
	CSprite* Stand;
	CSprite* Move;
	CSprite* Attack;
	CSprite* Hit;
	CSprite* Skill;
	CSprite* Death;

	CSprite* HitEffect;

	int AttackDelay;

	int AttackNum;

	int AttackCount;
	int HeroKnockbackCount;
	int KnockbackCount;
	int HitCount;

	int temp;

public:
	CObject_Shadow();
	CObject_Shadow(int GHandle, double x, double y, int Width, int Height, unsigned int Type);
	~CObject_Shadow();

	virtual void Update();
	virtual void Render();
	virtual void Control();
};

#endif