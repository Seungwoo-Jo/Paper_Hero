#include "CObject_Tree.h"
#include "ResourceManager.h"

CObject_Tree::CObject_Tree()
{
}

CObject_Tree::CObject_Tree(int GHandle, double x, double y, int Width, int Height, unsigned int Type) : CObject(GHandle, x, y, Width, Height, Type)
{
	OpacityCount = 0;
	SetBoundBox((int)fDrawX+35, (int)fDrawY, Width-70, Height);
}
CObject_Tree::~CObject_Tree()
{
}

void CObject_Tree::Update()
{
	SetBoundBox((int)fDrawX+35, (int)fDrawY, Width-70, Height);
}

void CObject_Tree::Render()
{
	if(Opacity < 255) {
		if(Opacity <= (255 - OpacityCount)){
			OpacityCount += 6;
		}
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255-OpacityCount);
	}
	else {
		if(OpacityCount >= 0){
			OpacityCount -= 3;
			SetDrawBlendMode(DX_BLENDMODE_ALPHA, Opacity-OpacityCount);
		}
		else {
			OpacityCount = 0;
			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
		}
	}

	DrawGraph((int)fDrawX, (int)fDrawY, GraphHandle, TRUE);
	
}

void CObject_Tree::Control()
{
}