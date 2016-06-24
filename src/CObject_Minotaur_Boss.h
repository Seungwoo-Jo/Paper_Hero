#ifndef __COBJECT_MINOTAUR_BOSS__
#define __COBJECT_MINOTAUR_BOSS__

#include "CObject_Enemy.h"

class CObject_Minotaur_Boss : public CObject_Enemy
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
	CObject_Minotaur_Boss();
	CObject_Minotaur_Boss(int GHandle, double x, double y, int Width, int Height, unsigned int Type);
	~CObject_Minotaur_Boss();

	virtual void Update();
	virtual void Render();
	virtual void Control();
};

#endif