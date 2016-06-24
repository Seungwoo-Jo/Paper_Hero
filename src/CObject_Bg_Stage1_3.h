#ifndef __COBJECT_BG_STAGE1_3__
#define __COBJECT_BG_STAGE1_3__

#include "CObject.h"

class CObject_Bg_Stage1_3 : public CObject
{
private:
	CObject* Background;
	CObject* Hero;
	//CObject* Objects[20];

public:
	CObject_Bg_Stage1_3();
	CObject_Bg_Stage1_3(int GHandle, double x, double y, int Width, int Height, unsigned int Type);
	~CObject_Bg_Stage1_3();

	virtual void TakeObjectInfo(CObject* _object);	// ������ �ʱ�ȭ.
	virtual void Update();	// ������� ����
	virtual void Render();	// DRAW!
	virtual void Control();	// Ű �Է�

};

#endif