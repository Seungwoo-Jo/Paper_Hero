#ifndef __CCOLLISION__
#define __CCOLLISION__

#include "DxLib.h"

class CCollision
{
private:
	static CCollision* m_CCollision;
	CCollision();

public:
	~CCollision();

	static CCollision* GetCollision() {
		if(m_CCollision == NULL)
			m_CCollision = new CCollision();
		return m_CCollision;
	}


	bool Dot_n_Box(int DotX, int DotY, int BoxX1, int BoxY1, int BoxX2, int BoxY2);
	bool Box_n_Box(int Box1X1, int Box1Y1, int Box1X2, int Box1Y2, int Box2X1, int Box2Y1, int Box2X2, int Box2Y2);
};

#endif