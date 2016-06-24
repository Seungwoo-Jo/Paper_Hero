#ifndef __COBJECT_SKILLWD__
#define __COBJECT_SKILLWD__

#include "CSound.h"
#include "CObject.h"
#include "CGlobal.h"

#define LEFT	4
#define RIGHT	6
#define UP		8
#define	DOWN	2
#define NONE	5

#define SKILL_PHYSICAL	1
#define SKILL_MAGICAL	2
#define SKILL_ULTIMATE	3

class CObject_Skillwd : public CObject
{
private:
	CObject* HeroForUI;
	CGlobal* Func;

	SkillInfo Skill[9];

	CSound* SelectSound;
	int back;
	int LevelupSelect;
	int TypeSelect;
	int SkillSelect;

	int SkillWdw;
	int SkillIcon;
	/*
	SkillInfo Skill_Physical[3];
	SkillInfo Skill_Magical[3];
	SkillInfo Skill_Ultimate[3];
	*/
	int Focus;
	int TempFocus1, TempFocus2;
	int Direction;
	int Select;

	int PushCount;

	
public:
	CObject_Skillwd();
	CObject_Skillwd(int GHandle, double x, double y, int Width, int Height, unsigned int Type);
	~CObject_Skillwd();

	virtual void TakeObjectInfo(CObject* _object);
	virtual void Update();
	virtual void Render();
	virtual void Control();
};

#endif