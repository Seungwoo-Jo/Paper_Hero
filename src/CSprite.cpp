#include "CSprite.h"

CSprite::CSprite()
{
}

CSprite::CSprite( int _GHandle, int NumSprite, int SrcX, int SrcY, int XNum, int YNum, int Width, int Height, int Delay, bool LR )
{
	if(GHandle |= -1)
	{
		this->GHandle		= _GHandle;
		this->NumSprite		= NumSprite;
		this->SrcX			= SrcX;
		this->SrcY			= SrcY;
		this->XNum			= XNum;
		this->YNum			= YNum;
		this->Width			= Width;
		this->Height		= Height;
		this->SpriteX		= SrcX;
		this->SpriteY		= SrcY;
		this->PieceSizeX	= (Width / XNum);
		this->PieceSizeY	= Height;

		this->StartTime		= GetNowCount();
		this->Delay			= Delay;
		this->Count			= 0;
	
		fAngle = 0.0f;

		b_LRTurn = LR;
		b_SpriteOn = true;
		Turning = -1;
		
	}
	else {
		//printfDx("CSprite() Fail. Don't Load Image.\n");
	}

	if(b_LRTurn)
	{
		LRGraphHandle = new int[NumSprite];
		
		for(int i=0; i<NumSprite; i++)
		{
			LRGraphHandle[i] = DerivationGraph(SrcX+(PieceSizeX*i), SrcY, PieceSizeX, PieceSizeY, GHandle);
		}
	}
}

CSprite::~CSprite()
{
	//DeleteGraph(GHandle);

	if(b_LRTurn)
	{
		for(int i=0; i<NumSprite; i++)
		{
			DeleteGraph(LRGraphHandle[i]);
		}
		delete []LRGraphHandle;
	}
}

void CSprite::SetCount(int count)
{
	this->Count = count;
}

int CSprite::GetCount()
{
	return Count;
}

void CSprite::SpriteSwitch( bool rp )
{
	b_SpriteOn = rp;
}

void CSprite::SetDalay( int dly )
{
	Delay = dly;
}

void CSprite::SetTurning( int trn )
{
	Turning = trn;
}

int CSprite::DrawSprite(int sx, int sy, bool b_SpriteOn, int StopNum)
{
	
	if(StopNum != -1)
	{
		SpriteX = SrcX + (PieceSizeX * StopNum);
		SpriteY = SrcY;

		if( DrawGraph(sx, sy, LRGraphHandle[StopNum], TRUE) == -1 ) {
			//printfDx("Sprite Draw Fail\n%d %d %d %d %d %d %d\n", sx, sy, SpriteX, SpriteY, PieceSizeX, PieceSizeY, GHandle);
		}
		return Count;
	}
	

	if( b_SpriteOn )
	{
		SpriteX = SrcX + (PieceSizeX * Count);
		SpriteY = SrcY;

		if( DrawGraph(sx, sy, LRGraphHandle[Count], TRUE) == -1 ) {
			//printfDx("Sprite Draw Fail\n%d %d %d %d %d %d %d", sx, sy, SpriteX, SpriteY, PieceSizeX, PieceSizeY, GHandle);
		}

		if( (StartTime + Delay) < GetNowCount() )
		{
	
			if((XNum-1) > Count) {
				Count++;
			}
			else {
				Count = 0;
				StartTime = GetNowCount();
				return XNum;
			}

			StartTime = GetNowCount();
		}

	}
	else
	{
		if( DrawGraph(sx, sy, LRGraphHandle[Count], TRUE) == -1 ) {
			//printfDx("Sprite Draw Fail\n%d %d %d %d %d %d %d", sx, sy, SpriteX, SpriteY, PieceSizeX, PieceSizeY, GHandle);
		}
		if( (StartTime + Delay) < GetNowCount() )
		{
			if((XNum-1) > Count) {
				Count++;
			}
			else {
				Count = XNum-1;
				StartTime = GetNowCount();
				return XNum;
			}

			SpriteX = SrcX + (PieceSizeX * Count);
			SpriteY = SrcY;

			StartTime = GetNowCount();
		}

		
	}
	return Count;
	
}


int CSprite::DrawTurnSprite(int sx, int sy, bool b_SpriteOn, int StopNum)
{
	
	if(StopNum != -1)
	{
		SpriteX = SrcX + (PieceSizeX * StopNum);
		SpriteY = SrcY;
		if( DrawTurnGraph(sx, sy, LRGraphHandle[StopNum], TRUE) == -1 ) {
			//printfDx("Sprite Draw Fail\n%d %d %d %d %d %d %d", sx, sy, SpriteX, SpriteY, PieceSizeX, PieceSizeY, GHandle);
		}
		return Count;
	}
	
	
	if( b_SpriteOn )
	{
		SpriteX = SrcX + (PieceSizeX * Count);
		SpriteY = SrcY;

		if( DrawTurnGraph(sx, sy, LRGraphHandle[Count], TRUE) == -1 ) {
			//printfDx("Sprite Draw Fail\n%d %d %d %d %d %d %d", sx, sy, SpriteX, SpriteY, PieceSizeX, PieceSizeY, LRGraphHandle[Count]);
		}

		if( (StartTime + Delay) < GetNowCount() )
		{
			if((XNum-1) > Count) {
				Count++;
			}
			else {
				Count = 0;
				StartTime = GetNowCount();
				return XNum;
			}

			StartTime = GetNowCount();
		}

	}
	else
	{
		if( DrawTurnGraph(sx, sy, LRGraphHandle[Count], TRUE) == -1 ) {
			//printfDx("Sprite Draw Fail\n%d %d %d %d %d %d %d", sx, sy, SpriteX, SpriteY, PieceSizeX, PieceSizeY, LRGraphHandle[Count]);
		}

		if( (StartTime + Delay) < GetNowCount() )
		{
			if((XNum-1) > Count) {
				Count++;
			}
			else {
				Count = XNum-1;
				StartTime = GetNowCount();
				return XNum;
			}
			StartTime = GetNowCount();
		}
	}

	return Count;
	
}

bool CSprite::TurnAnimation(int sx, int sy, bool left, bool right, bool turn)
{
	if(turn)
	{
		double Turn = cos(fAngle * (3.141592 / 180));

		fAngle += 18.0f;

		if(Turn < 0) {
			Turn *= -1;
		}
	
		if(right)
		{
			if(fAngle >= 0 && fAngle <= 90.0f) {
				DrawRotaGraph3(sx+100, sy+100, 100, 100, Turn, 1.0f, 0.0f, LRGraphHandle[Count], TRUE, FALSE);
			}
			else if(fAngle > 90.0f && fAngle <= 180) {
				DrawRotaGraph3(sx+100, sy+100, 100, 100, Turn, 1.0f, 0.0f, LRGraphHandle[Count], TRUE, TRUE);
			}
		}
		else if(left)
		{		
			if(fAngle >= 0 && fAngle <= 90.0f) {
				DrawRotaGraph3(sx+100, sy+100, 100, 100, Turn, 1.0f, 0.0f, LRGraphHandle[Count], TRUE, TRUE);
			}
			else if(fAngle > 90.0f && fAngle <= 180) {
				DrawRotaGraph3(sx+100, sy+100, 100, 100, Turn, 1.0f, 0.0f, LRGraphHandle[Count], TRUE, FALSE);
			}
		}

		if( (StartTime + Delay) < GetNowCount() )
		{
	
			if((XNum-1) > Count) {
				Count++;
			}
			else
				Count = 0;

			StartTime = GetNowCount();
		}

		if(fAngle >= 180) {
			fAngle = 0.0f;
			return false;
		}
	}
	else
	{
		fAngle = 0.0f;
		return false;
	}

	return true;
}