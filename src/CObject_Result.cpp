#include "ResourceManager.h"
#include "CObject_Result.h"

CObject_Result::CObject_Result()
{
	// Ư���� �� �Ұ� ����.
}

CObject_Result::CObject_Result(int GHandle, double x, double y, int Width, int Height, unsigned int Type) : CObject(GHandle, x, y, Width, Height, Type)
{

	Font = CreateFontToHandle("HY������M", 16, 1, DX_FONTTYPE_ANTIALIASING_EDGE_8X8);
	SetBoundBox(0, 0, 0, 0);


}

CObject_Result::~CObject_Result()
{
	InitFontToHandle();

}

void CObject_Result::Update()
{

}

void CObject_Result::Render()
{

}

void CObject_Result::Control()
{

}