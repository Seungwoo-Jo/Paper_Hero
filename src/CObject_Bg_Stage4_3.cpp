#include "CObject_Bg_Stage4_3.h"
#include "ResourceManager.h"

CObject_Bg_Stage4_3::CObject_Bg_Stage4_3()
{
}

CObject_Bg_Stage4_3::CObject_Bg_Stage4_3(int GHandle, double x, double y, int Width, int Height, unsigned int Type) : CObject(GHandle, x, y, Width, Height, Type)
{

}

CObject_Bg_Stage4_3::~CObject_Bg_Stage4_3()
{
}

void CObject_Bg_Stage4_3::TakeObjectInfo(CObject* _object)
{
	Hero = _object;
}

void CObject_Bg_Stage4_3::Update()
{

}

void CObject_Bg_Stage4_3::Render()
{
	int _width = 0;
	int _height = 0;

	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
	GetGraphSize(GraphHandle, &_width, &_height); 

	DrawRectGraph((int)fDrawX, (int)fDrawY, SrcX, SrcY, 1024, 768, GraphHandle, TRUE, FALSE);
	DrawRectGraph((int)fDrawX, (int)fDrawY, (SrcX-_width), SrcY+768, 1024, 768, GraphHandle, TRUE, FALSE);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
}

void CObject_Bg_Stage4_3::Control()
{

}