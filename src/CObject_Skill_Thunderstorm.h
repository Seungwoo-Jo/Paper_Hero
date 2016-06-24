#ifndef __COBJECT_SKILL_THUNDERSTORM__
#define __COBJECT_SKILL_THUNDERSTORM__

#include "CObject.h"

class CObject_Skill_Thunderstorm : public CObject
{
private:
	CObject* Hero;
	CSprite* SkillSprite;

	int CenterX;
	int HeroY;
	int MoveDistance;
	float temp;

	int tempX;
	int tempY;

public:
	CObject_Skill_Thunderstorm();
	CObject_Skill_Thunderstorm(int GHandle, double x, double y, int Width, int Height, unsigned int Type);
	~CObject_Skill_Thunderstorm();
	
	virtual void TakeObjectInfo(CObject* _object);
	virtual void Update();
	virtual void Render();
	virtual void Control();
};

#endif
