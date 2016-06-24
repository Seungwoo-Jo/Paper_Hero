#ifndef __COBJECT_BACKGROUND__
#define __COBJECT_BACKGROUND__

#include "CObject.h"

class CObject_Background : public CObject
{
private:

public:
	CObject_Background();
	CObject_Background(int GHandle, double x, double y, int Width, int Height, unsigned int Type);
	~CObject_Background();

	virtual void Init();	// ������ �ʱ�ȭ.
	virtual void Update();	// ������� ����
	virtual void Render();	// DRAW!
	virtual void Control();	// Ű �Է�

};

#endif