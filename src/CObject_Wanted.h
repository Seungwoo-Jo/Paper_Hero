#ifndef __COBJECT_WANTED__
#define __COBJECT_WANTED__

#include "CObject.h"

class CObject_Wanted : public CObject
{
private:
	CSprite* Stand;
	CObject* ObjectHero;
	float OpacityCount;
	float ScaleCount;
	float HeightCount;
	int DrawCount;
	float FlipCount;
	float fAngle;
	bool b_SecondFlip;
	bool b_Get;

public:
	CObject_Wanted();
	CObject_Wanted(int GHandle, double x, double y, int Width, int Height, unsigned int Type);
	~CObject_Wanted();

	virtual void TakeObjectInfo(CObject* _object);
	virtual void Update();
	virtual void Render();
	virtual void Control();

};

#endif