#ifndef __COBJECT_APPLETREE__
#define __COBJECT_APPLETREE__

#include "CObject_Enemy.h"

class CObject_Appletree : public CObject_Enemy
{
private:
	CSprite* Stand;
	CSprite* Hit;
	CSprite* Death;
	CSprite* Poison;
	CSprite* Apple[2];

	CSprite* Boom[2];
	CSprite* Break[2];

	int AttackDelay;
	int AttackCount;
	int HeroKnockbackCount;
	int KnockbackCount;
	int HitCount;

	bool b_Alive;
	bool b_apple[2];

	int tempY[2];
	//bool b_

public:
	CObject_Appletree();
	CObject_Appletree(int GHandle, double x, double y, int Width, int Height, unsigned int Type);
	~CObject_Appletree();

	virtual void Update();
	virtual void Render();
	virtual void Control();
};
#endif