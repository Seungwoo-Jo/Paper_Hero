#include "CCollision.h"

CCollision* CCollision::m_CCollision = NULL;

CCollision::CCollision()
{
}

CCollision::~CCollision()
{
	delete m_CCollision;
}

bool CCollision::Dot_n_Box(int DotX, int DotY, int BoxX1, int BoxY1, int BoxX2, int BoxY2)
{
	if( DotX > BoxX1 &&
		DotX < BoxX2 &&
		DotY > BoxY1 &&
		DotY < BoxY2) {
		return true;
	}
	return false;
}

bool CCollision::Box_n_Box(int Box1X1, int Box1Y1, int Box1X2, int Box1Y2, int Box2X1, int Box2Y1, int Box2X2, int Box2Y2)
{
	if(Box1X2 < Box2X1 || Box1X1 > Box2X2) return false;
	if(Box1Y2 < Box2Y1 || Box1Y1 > Box2Y2) return false;

	return true;
}