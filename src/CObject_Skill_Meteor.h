#ifndef __COBJECT_SKILL_METEOR__
#define __COBJECT_SKILL_METEOR__

#include "CObject.h"

class CObject_Skill_Meteor : public CObject
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
	CObject_Skill_Meteor();
	CObject_Skill_Meteor(int GHandle, double x, double y, int Width, int Height, unsigned int Type);
	~CObject_Skill_Meteor();

	virtual void TakeObjectInfo(CObject* _object);
	virtual void Update();
	virtual void Render();
	virtual void Control();
};

#endif