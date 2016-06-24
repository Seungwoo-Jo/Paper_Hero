#ifndef __COBJECT_INTERFACE__
#define __COBJECT_INTERFACE__

#include "CObject.h"

class CObject_Interface : public CObject
{
private:
	CObject* HeroForUI;
	int facenum;
	int skill;

public:
	CObject_Interface();
	CObject_Interface(int GHandle, double x, double y, int Width, int Height, unsigned int Type);
	~CObject_Interface();

	virtual void TakeObjectInfo(CObject* _object);

	virtual void Init();
	virtual void Update();
	virtual void Render();
	virtual void Control();
};

#endif