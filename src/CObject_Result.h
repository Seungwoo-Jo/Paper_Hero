#ifndef __COBJECT_RESULT__
#define __COBJECT_RESULT__

#include "CObject.h"

class CObject_Result	: public CObject
{
private:

public:
	CObject_Result();
	CObject_Result(int GHandle, double x, double y, int Width, int Height, unsigned int Type);
	~CObject_Result();

	virtual void Update();
	virtual void Render();
	virtual void Control();
};

#endif