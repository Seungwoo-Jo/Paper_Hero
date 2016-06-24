#ifndef __CSTATE__
#define __CSTATE__

#include "CObjectManager.h"
#include "ResourceManager.h"
#include "CObject_Skill_Thunderstorm.h"
#include "CObject_Skill_Meteor.h"
#include "CObject_Skill_Tornado.h"
#include "CObject_Skill_Summon.h"
#include "CObject_Skill_Water.h"
#include "CGlobal.h"

class CState
{
protected:
	static CObject* Master;
	static CGlobal* Func;

	static CState* prev;

	static CState* Stand;
	static CState* Move;
	static CState* Jump;
	static CState* Attack;
	static CState* Guard;
	static CState* Hit;
	static CState* Enter;
	static CState* Skill01;
	static CState* Skill02;
	static CState* Skill03;
	static CState* Skill04;
	static CState* Skill05;

	static bool b_Left;
	static bool b_Right;
	static bool b_Turn;

	int HitNum;
	int HitMax;

	bool First;
	static CObject* TempSkill;

public:
	CState();
	~CState();

	CState* Init(CObject* object);
	
	static CState* GetState(int num)
	{
		switch(num)
		{
		case 0:
			return Stand;
			break;
		case 1:
			return Move;
			break;
		case 2:
			return Jump;
			break;
		case 3:
			return Attack;
			break;
		case 4:
			return Guard;
			break;
		case 5:
			return Hit;
			break;

		case 302:
			//break;
		case 102:
			break;

		case 100:
			return Skill03;
			break;
		
		case 101:
			return Skill05;
			break;
		case 200:
			TempSkill = new CObject_Skill_Tornado(IMAGE_HERO_SKILL21, Master->GetWorldX(), Master->GetWorldY()-60, 512, 512, TYPE_SKILL);
			TempSkill->TakeObjectInfo(Master);
			TempSkill->SetHP(TempSkill->GetMaxHP());
			CObjectManager::GetObjectManager()->AddObject(TempSkill);
			return Skill04;
			break;
		case 201:
			TempSkill = new CObject_Skill_Water(IMAGE_HERO_SKILL22, Master->GetWorldX(), Master->GetWorldY()-140, 512, 512, TYPE_SKILL);
			TempSkill->TakeObjectInfo(Master);
			TempSkill->SetHP(TempSkill->GetMaxHP());
			CObjectManager::GetObjectManager()->AddObject(TempSkill);
			return Skill04;
			break;
		case 202:
			TempSkill = new CObject_Skill_Summon(IMAGE_HERO_SKILL23, Master->GetWorldX(), Master->GetWorldY()-180, 512, 512, TYPE_SKILL);
			TempSkill->TakeObjectInfo(Master);
			TempSkill->SetHP(TempSkill->GetMaxHP());
			CObjectManager::GetObjectManager()->AddObject(TempSkill);
			return Skill04;
			break;
		case 300:
			TempSkill = new CObject_Skill_Meteor(IMAGE_HERO_SKILL31, Master->GetWorldX(), Master->GetWorldY()-280, 512, 512, TYPE_SKILL);
			TempSkill->TakeObjectInfo(Master);
			TempSkill->SetHP(TempSkill->GetMaxHP());
			CObjectManager::GetObjectManager()->AddObject(TempSkill);
			return Skill02;
			break;
		case 301:
			TempSkill = new CObject_Skill_Thunderstorm(IMAGE_HERO_SKILL32, Master->GetWorldX(), Master->GetWorldY()-310, 512, 512, TYPE_SKILL);
			TempSkill->TakeObjectInfo(Master);
			TempSkill->SetHP(TempSkill->GetMaxHP());
			CObjectManager::GetObjectManager()->AddObject(TempSkill);
			return Skill01;
			break;
		}
		return NULL;
	}
	

	int GetWay();

	virtual float GetValue() { return NULL; }
	virtual void SetValue(float x) { x = 0; }

	virtual CState* Update();
	virtual CState* Render();
	virtual CState* Control();
};

#endif