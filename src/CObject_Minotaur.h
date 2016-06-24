#ifndef __COBJECT_MINOTAUR__
#define __COBJECT_MINOTAUR__

#include "CObject_Enemy.h"

class CObject_Minotaur : public CObject_Enemy
{
private:
	CSprite* Stand;
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
	CObject_Minotaur();
	CObject_Minotaur(int GHandle, double x, double y, int Width, int Height, unsigned int Type);
	~CObject_Minotaur();

	virtual void Update();
	virtual void Render();
	virtual void Control();
};

#endif