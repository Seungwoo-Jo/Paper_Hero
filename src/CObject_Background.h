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

	virtual void Init();	// 변수들 초기화.
	virtual void Update();	// 변경사항 적용
	virtual void Render();	// DRAW!
	virtual void Control();	// 키 입력

};

#endif