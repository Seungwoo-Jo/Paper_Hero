#include "CObject_Bg_Stage4_2.h"
#include "ResourceManager.h"

CObject_Bg_Stage4_2::CObject_Bg_Stage4_2()
{
}

CObject_Bg_Stage4_2::CObject_Bg_Stage4_2(int GHandle, double x, double y, int Width, int Height, unsigned int Type) : CObject(GHandle, x, y, Width, Height, Type)
{

}

CObject_Bg_Stage4_2::~CObject_Bg_Stage4_2()
{
}

void CObject_Bg_Stage4_2::TakeObjectInfo(CObject* _object)
{
	Hero = _object;
}

void CObject_Bg_Stage4_2::Update()
{

}

void CObject_Bg_Stage4_2::Render()
{
	int _width = 0;
	int _height = 0;

	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
	GetGraphSize(GraphHandle, &_width, &_height); 

	DrawRectGraph((int)fDrawX, (int)fDrawY, SrcX, SrcY, 1024, 768, GraphHandle, TRUE, FALSE);
	DrawRectGraph((int)fDrawX, (int)fDrawY, (SrcX-_width), SrcY+768, 1024, 768, GraphHandle, TRUE, FALSE);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
}

void CObject_Bg_Stage4_2::Control()
{

}