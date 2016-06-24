#ifndef __COBJECT_BG_STAGE4_1__
#define __COBJECT_BG_STAGE4_1__

#include "CObject.h"

class CObject_Bg_Stage4_1 : public CObject
{
private:
	CObject* Hero;

public:
	CObject_Bg_Stage4_1();
	CObject_Bg_Stage4_1(int GHandle, double x, double y, int Width, int Height, unsigned int Type);
	~CObject_Bg_Stage4_1();

	virtual void TakeObjectInfo(CObject* _object);	// ������ �ʱ�ȭ.
	virtual void Update();	// ������� ����
	virtual void Render();	// DRAW!
	virtual void Control();	// Ű �Է�

};

#endif