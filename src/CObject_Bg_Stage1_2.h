#ifndef __COBJECT_BG_STAGE1_2__
#define __COBJECT_BG_STAGE1_2__

#include "CObject.h"

class CObject_Bg_Stage1_2 : public CObject
{
private:
	CObject* Hero;
	bool b_Forest;
	bool b_Hide;
	int tempY;

public:
	CObject_Bg_Stage1_2();
	CObject_Bg_Stage1_2(int GHandle, double x, double y, int Width, int Height, unsigned int Type);
	~CObject_Bg_Stage1_2();

	virtual void TakeObjectInfo(CObject* _object);	// 변수들 초기화.
	virtual void Update();	// 변경사항 적용
	virtual void Render();	// DRAW!
	virtual void Control();	// 키 입력

};

#endif