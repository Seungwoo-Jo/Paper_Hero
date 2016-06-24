#ifndef __COBJECT_TREE__
#define __COBJECT_TREE__


#include "CObject.h"

class CObject_Tree : public CObject
{
private:
	int OpacityCount;

public:
	CObject_Tree();
	CObject_Tree(int GHandle, double x, double y, int Width, int Height, unsigned int Type);
	~CObject_Tree();

	virtual void Update();
	virtual void Render();
	virtual void Control();
};



#endif