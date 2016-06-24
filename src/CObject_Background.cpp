#include "CObject_Background.h"
#include "Qusy.h"

CObject_Background::CObject_Background()
{
}

CObject_Background::CObject_Background(int GHandle, double x, double y, int Width, int Height, unsigned int Type) : CObject(GHandle, x, y, Width, Height, Type)
{
}

CObject_Background::~CObject_Background()
{
}

void CObject_Background::Init()
{
}

void CObject_Background::Update()
{
}

void CObject_Background::Render()
{
	int _width = 0;
	int _height = 0;

	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
	GetGraphSize(GraphHandle, &_width, &_height); 

	if( _width < 1024 && _height < 768 )
	{
		DrawExtendGraph((int)fDrawX, (int)fDrawY, 1024, 768, GraphHandle, TRUE);
	}
	else if( _height < 768 )
	{
		DrawExtendGraph((int)fDrawX, (int)fDrawY, _width, 768, GraphHandle, TRUE);
	}
	/*
	else if( _width < 1024 )
	{
		DrawExtendGraph((int)fDrawX, (int)fDrawY, 1024, 768, GraphHandle, TRUE);
	}
	*/
	else
	{
		DrawRectGraph((int)fDrawX, (int)fDrawY, SrcX, SrcY, 1024, 768, GraphHandle, TRUE, FALSE);
	}
}

void CObject_Background::Control()
{
}