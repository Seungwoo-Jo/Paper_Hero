#ifndef __COBJECT_STATUS__
#define __COBJECT_STATUS__

#include "CObject.h"
#include "CSprite.h"
#include "CGlobal.h"

#define LEFT	4
#define RIGHT	6
#define UP		8
#define	DOWN	2
#define NONE	5

class CObject_Status : public CObject
{
private:
	CObject* HeroForUI;
	CGlobal* Func;
	CSprite* Char;

	int SmallFont;
	int LargeFont;

	int Direction;
	int Focus;
	int Select;
	int PushCount;
	bool b_BtnDown;
	
	bool b_Btn2Down;
	bool b_Btn3Down;
	bool b_Btn4Down;
	bool b_Btn5Down;
	bool b_StatExit;

public:
	CObject_Status();
	CObject_Status(int GHandle, double x, double y, int Width, int Height, unsigned int Type);
	~CObject_Status();

	virtual void TakeObjectInfo(CObject* _object);
	virtual void Update();
	virtual void Render();
	virtual void Control();
};



#endif