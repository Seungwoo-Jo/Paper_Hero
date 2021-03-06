#ifndef __COBJECT_SKILL_WATER__
#define __COBJECT_SKILL_WATER__

#include "CObject.h"

class CObject_Skill_Water : public CObject
{
private:
	CObject* Hero;
	CSprite* SkillSprite;

	int CenterX;
	int HeroY;
	float temp;

	int tempX;
	int tempY;

public:
	CObject_Skill_Water();
	CObject_Skill_Water(int GHandle, double x, double y, int Width, int Height, unsigned int Type);
	~CObject_Skill_Water();
	
	virtual void TakeObjectInfo(CObject* _object);
	virtual void Update();
	virtual void Render();
	virtual void Control();
};

#endif
