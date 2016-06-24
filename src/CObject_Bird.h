#pragma once
#include "cobject_enemy.h"
class CObject_Bird : public CObject_Enemy
{
private:
	CSprite* Stand;

	int AttackDelay;

	int AttackCount;
	int HeroKnockbackCount;
	int KnockbackCount;
	int HitCount;

	int tempY[2];

public:
	CObject_Bird(void);
	CObject_Bird(int GHandle, double x, double y, int Width, int Height, unsigned int Type);
	~CObject_Bird(void);

	virtual void Update();
	virtual void Render();
	virtual void Control();
};

