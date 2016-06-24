#ifndef __COBJECT_BG_STAGE5_4__
#define __COBJECT_BG_STAGE5_4__

#include "CObject.h"

class CObject_Bg_Stage5_4 : public CObject
{
private:
	CObject* Hero;

public:
	CObject_Bg_Stage5_4();
	CObject_Bg_Stage5_4(int GHandle, double x, double y, int Width, int Height, unsigned int Type);
	~CObject_Bg_Stage5_4();

	virtual void TakeObjectInfo(CObject* _object);	// ������ �ʱ�ȭ.
	virtual void Update();	// ������� ����
	virtual void Render();	// DRAW!
	virtual void Control();	// Ű �Է�

};

#endif