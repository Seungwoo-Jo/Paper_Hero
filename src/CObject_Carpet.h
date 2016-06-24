#ifndef __COBJECT_CARPET__
#define __COBJECT_CARPET__

#include "CObject_Enemy.h"

class CObject_Carpet : public CObject_Enemy
{
private:
	CSprite* Stand;
	CSprite* Attack;
	CSprite* Sword;
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
	CObject_Carpet();
	CObject_Carpet(int GHandle, double x, double y, int Width, int Height, unsigned int Type);
	~CObject_Carpet();

	virtual void Update();
	virtual void Render();
	virtual void Control();
};

#endif