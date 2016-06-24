#ifndef __COBJECT_ACTIVETREE__
#define __COBJECT_ACTIVETREE__

#include "CObject_Enemy.h"

class CObject_Activetree : public CObject_Enemy
{
private:
	CSprite* Stand;
	CSprite* Hit;
	CSprite* Death;
	CSprite* Wanted;

	int AttackDelay;
	int AttackCount;
	int HeroKnockbackCount;
	int KnockbackCount;
	int HitCount;

	bool b_Alive;
	//bool b_

public:
	CObject_Activetree();
	CObject_Activetree(int GHandle, double x, double y, int Width, int Height, unsigned int Type);
	~CObject_Activetree();

	virtual void Update();
	virtual void Render();
	virtual void Control();
};
#endif