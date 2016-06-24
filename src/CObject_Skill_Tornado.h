#ifndef __COBJECT_SKILL_TORNADO__
#define __COBJECT_SKILL_TORNADO__

#include "CObject.h"

class CObject_Skill_Tornado : public CObject
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
	CObject_Skill_Tornado();
	CObject_Skill_Tornado(int GHandle, double x, double y, int Width, int Height, unsigned int Type);
	~CObject_Skill_Tornado();

	virtual void TakeObjectInfo(CObject* _object);
	virtual void Update();
	virtual void Render();
	virtual void Control();
};

#endif