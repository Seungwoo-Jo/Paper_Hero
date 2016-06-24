#ifndef __COBJECT_MOLE__
#define __COBJECT_MOLE__

#include "CObject_Enemy.h"

class CObject_Mole : public CObject_Enemy
{
private:

	CSprite* Move;
	CSprite* Attack;
	CSprite* Hit;
	CSprite* Death;

	CSprite* HitEffect;

	int AttackDelay;

	int AttackCount;
	int HeroKnockbackCount;
	int KnockbackCount;
	int HitCount;

public:
	CObject_Mole();
	CObject_Mole(int GHandle, double x, double y, int Width, int Height, unsigned int Type);
	~CObject_Mole();

	virtual void Update();
	virtual void Render();
	virtual void Control();
};

#endif