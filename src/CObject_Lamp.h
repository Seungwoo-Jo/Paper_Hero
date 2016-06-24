#ifndef __COBJECT_LAMP__
#define __COBJECT_LAMP__

#include "CObject_Enemy.h"

class CObject_Lamp : public CObject_Enemy
{
private:
	CSprite* Stand;
	CSprite* Attack;
	CSprite* Laser;
	CSprite* Hit;
	CSprite* Death;

	CSprite* HitEffect;

	int AttackDelay;

	int AttackCount;
	int HeroKnockbackCount;
	int KnockbackCount;
	int HitCount;

	int tempSpd;

public:
	CObject_Lamp();
	CObject_Lamp(int GHandle, double x, double y, int Width, int Height, unsigned int Type);
	~CObject_Lamp();

	virtual void Update();
	virtual void Render();
	virtual void Control();
};

#endif