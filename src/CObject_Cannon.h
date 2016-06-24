#ifndef __COBJECT_CANNON__
#define __COBJECT_CANNON__

#include "CObject_Enemy.h"

class CObject_Cannon : public CObject_Enemy
{
private:
	CSprite* Stand;
	CSprite* Move;
	CSprite* Attack;
	CSprite* Ball;
	CSprite* Hit;
	CSprite* Death;
	CSprite* Boom;

	CSprite* HitEffect;

	int AttackDelay;

	int AttackCount;
	int HeroKnockbackCount;
	int KnockbackCount;
	int HitCount;
	bool b_boom;

public:
	CObject_Cannon();
	CObject_Cannon(int GHandle, double x, double y, int Width, int Height, unsigned int Type);
	~CObject_Cannon();

	virtual void Update();
	virtual void Render();
	virtual void Control();
};

#endif