#include "CObject_Bg_Stage1_2.h"
#include "ResourceManager.h"
#include "CCollision.h"
#include "Qusy.h"

CObject_Bg_Stage1_2::CObject_Bg_Stage1_2()
{
}

CObject_Bg_Stage1_2::CObject_Bg_Stage1_2(int GHandle, double x, double y, int Width, int Height, unsigned int Type) : CObject(GHandle, x, y, Width, Height, Type)
{
	b_Forest = false;
	b_Hide = false;
	tempY = 0;
}

CObject_Bg_Stage1_2::~CObject_Bg_Stage1_2()
{
}

void CObject_Bg_Stage1_2::TakeObjectInfo(CObject* _object)
{
	Hero = _object;
}

void CObject_Bg_Stage1_2::Update()
{
	SetBoundBox(1160-SrcX, 180-SrcY, 1100, 380);
	if(CCollision::GetCollision()->Box_n_Box(
		Hero->GetBoundX(), Hero->GetBoundY(), Hero->GetBoundX()+Hero->GetBoundWidth(), Hero->GetBoundY()+Hero->GetBoundHeight(),
		GetBoundX(), GetBoundY(), GetBoundX()+GetBoundWidth(), GetBoundY()+GetBoundHeight()))
	{
		b_Forest = TRUE;
	}
	else
	{
		b_Forest = FALSE;
	}
	
	SetBoundBox(1450-SrcX, 200-SrcY, 200, 500);
	// 1450 บฮลอ 200
	if(CCollision::GetCollision()->Box_n_Box(
		Hero->GetBoundX(), Hero->GetBoundY(), Hero->GetBoundX()+Hero->GetBoundWidth(), Hero->GetBoundY()+Hero->GetBoundHeight(),
		GetBoundX(), GetBoundY(), GetBoundX()+GetBoundWidth(), GetBoundY()+GetBoundHeight()))
	{
		if(!b_Hide)
		{

		}
	}

	if(Hero->GetWorldX() < 1200 || Hero->GetWorldX() > 1625) {
		
		Hero->SetOpacity(255);
	}
}

void CObject_Bg_Stage1_2::Render()
{
	int _width = 0;
	int _height = 0;

	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
	GetGraphSize(GraphHandle, &_width, &_height); 

	DrawRectGraph((int)fDrawX, (int)fDrawY, SrcX, SrcY, 1024, 768, GraphHandle, TRUE, FALSE);
	DrawRectGraph((int)fDrawX, (int)fDrawY, (SrcX-_width), SrcY+768, 1024, 768, GraphHandle, TRUE, FALSE);
	
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, Hero->GetOpacity());
	DrawGraphF(1160 - SrcX, 180, GetResourceWithKey(IMAGE_STAGE1_2_FOREST), TRUE);
	
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
}

void CObject_Bg_Stage1_2::Control()
{

}