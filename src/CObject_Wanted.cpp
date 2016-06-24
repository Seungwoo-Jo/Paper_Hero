#include "CObject_Wanted.h"
#include "ResourceManager.h"
#include "CCollision.h"

CObject_Wanted::CObject_Wanted()
{

}

CObject_Wanted::CObject_Wanted(int GHandle, double x, double y, int Width, int Height, unsigned int Type) : CObject(GHandle, x, y, Width, Height, Type)
{
	GraphHandle = GetResourceWithKey(GHandle);
	SetBoundBox((int)fDrawX, (int)fDrawY, Width, Height);

	OpacityCount = -1;
	ScaleCount = -1;
	HeightCount = -1;
	DrawCount = -1;
	fAngle = -1;
	HP = 1;
	b_SecondFlip = false;
	b_Get = false;
}

CObject_Wanted::~CObject_Wanted()
{

}

void CObject_Wanted::TakeObjectInfo(CObject* _object)
{
	ObjectHero = _object;
}

void CObject_Wanted::Update()
{
	SetBoundBox((int)fDrawX+25, (int)fDrawY+25, 33, 50);


	if(CCollision::GetCollision()->Box_n_Box(
		ObjectHero->GetBoundX(), ObjectHero->GetBoundY(), ObjectHero->GetBoundX()+ObjectHero->GetBoundWidth(), ObjectHero->GetBoundY()+ObjectHero->GetBoundHeight(),
		GetBoundX(), GetBoundY(), GetBoundX()+GetBoundWidth(), GetBoundY()+GetBoundHeight()))
	{
		b_Get = true;
		HP--;
	}

	if(b_Get) {
		if(OpacityCount == -1 &&
			ScaleCount == -1 &&
			HeightCount == -1 &&
			DrawCount == -1 )
		{
			OpacityCount = 0;
			ScaleCount = 0;
			HeightCount = 0;
			DrawCount = 0;
		}
	}
	
	if(OpacityCount >= 0) {
		OpacityCount++;
		if(OpacityCount >= 30) {
			OpacityCount = 30;
		}
	}
	
	if(ScaleCount >= 0) {
		ScaleCount++;
		if(ScaleCount >= 90) {
			ScaleCount = 90;
		}
	}
	
	if(HeightCount >= 0) {
		HeightCount++;
		if(HeightCount >= 60) {
			HeightCount = 60;
		}
	}
	
	if(DrawCount >= 0) {
		DrawCount++;
		if(DrawCount >= 180) {
			DrawCount = 180;

			if(fAngle == -1){
				fAngle = 0;
			}
		}
	}

	if(fAngle >= 0) {
		fAngle += 4;
		if(fAngle > 180) {
			fAngle = 180;
		}
		else if(fAngle >= 90) {
			OpacityCount = 0;
			b_SecondFlip = true;
		}
	}
}

void CObject_Wanted::Render()
{
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
	Conversion();

	if(!b_Get)
	{
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, Opacity);
		DrawGraphF(fDrawX, fDrawY, GetResourceWithKey(IMAGE_OBJECT_WANTED), TRUE);
	}
	else
	{
		if(DrawCount < 180)
		{
			SetDrawBlendMode(DX_BLENDMODE_ALPHA, (int)(8.5f*OpacityCount));
			GraphFilter(GraphHandle, DX_GRAPH_FILTER_DOWN_SCALE, 10 - (int)(ScaleCount*0.1f));
			DrawRectGraphF(fDrawX-169, fDrawY-156, 0, 0, 423, (int)(8.533f*HeightCount), GraphHandle, TRUE, FALSE);
		}
		else
		{
			if(!b_SecondFlip)
			{
				double Turn = cos((fAngle+270.0f) * (3.141592 / 180));
				DrawRectExtendGraphF(fDrawX-169, fDrawY-156+(256*Turn), fDrawX+423-169, fDrawY-156+256, 0, 0, 423, 256, GraphHandle, TRUE);
				DrawRectExtendGraphF(fDrawX-169, fDrawY-156+256, fDrawX+423-169, fDrawY-156+512, 0, 256, 423, 256, GraphHandle, TRUE);
			}
			else
			{
				SetDrawBlendMode(DX_BLENDMODE_ALPHA, Opacity - (int)(8.5f*OpacityCount));
				double Turn = cos(fAngle * (3.141592 / 180));
				DrawRectExtendGraphF(fDrawX-169, fDrawY-156+256, fDrawX+212-169, fDrawY-156+512, 0, 256, 212, 256, GraphHandle, TRUE);
				DrawRectExtendGraphF(fDrawX+212-169, fDrawY-156+256, (fDrawX+423-169)+(212*Turn), fDrawY-156+512, 212, 256, 212, 256, GraphHandle, TRUE);
			}
		}
	}
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
}

void CObject_Wanted::Control()
{

}