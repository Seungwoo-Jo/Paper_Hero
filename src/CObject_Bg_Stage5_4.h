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

	virtual void TakeObjectInfo(CObject* _object);	// 변수들 초기화.
	virtual void Update();	// 변경사항 적용
	virtual void Render();	// DRAW!
	virtual void Control();	// 키 입력

};

#endif