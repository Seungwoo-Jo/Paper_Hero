#include "CObject_Bg_Stage1_3.h"
#include "ResourceManager.h"
#include "CCollision.h"
#include "Qusy.h"

CObject_Bg_Stage1_3::CObject_Bg_Stage1_3()
{
}

CObject_Bg_Stage1_3::CObject_Bg_Stage1_3(int GHandle, double x, double y, int Width, int Height, unsigned int Type) : CObject(GHandle, x, y, Width, Height, Type)
{

}

CObject_Bg_Stage1_3::~CObject_Bg_Stage1_3()
{
}

void CObject_Bg_Stage1_3::TakeObjectInfo(CObject* _object)
{
	Hero = _object;
}

void CObject_Bg_Stage1_3::Update()
{

}

void CObject_Bg_Stage1_3::Render()
{
	int _width = 0;
	int _height = 0;

	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
	GetGraphSize(GraphHandle, &_width, &_height); 

	DrawRectGraph((int)fDrawX, (int)fDrawY, SrcX, SrcY, 1024, 768, GraphHandle, TRUE, FALSE);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
}

void CObject_Bg_Stage1_3::Control()
{

}