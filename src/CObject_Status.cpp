#include "CObject_Status.h"
#include "CCollision.h"
#include "ResourceManager.h"

CObject_Status::CObject_Status()
{
	// 특별히 뭘 할건 없다.
}

CObject_Status::CObject_Status(int GHandle, double x, double y, int Width, int Height, unsigned int Type) : CObject(GHandle, x, y, Width, Height, Type)
{
	HeroForUI = NULL;
	Func = new CGlobal();

	Char = new CSprite(GetResourceWithKey(IMAGE_HERO), 13, 0, 0, 13, 1, 2600, 200, 110, TRUE);
	SmallFont = CreateFontToHandle("HY헤드라인M", 17, 1, DX_FONTTYPE_ANTIALIASING_EDGE_8X8);
	LargeFont = CreateFontToHandle("HY헤드라인M", 22, 2, DX_FONTTYPE_ANTIALIASING_EDGE_8X8);
	SetBoundBox(0, 0, 0, 0);

	Focus = 0;
	Select = 0;
	Direction = NONE;
	PushCount = 0;

	b_BtnDown = false;
}

CObject_Status::~CObject_Status()
{
	InitFontToHandle();

	delete Char;
	delete Func;
}

void CObject_Status::TakeObjectInfo(CObject* _object)
{
	if(HeroForUI == NULL) {
		HeroForUI = _object;
	}
}

void CObject_Status::Update()
{
	HeroForUI->MoveTo(0, 0);
	MoveDrawPos(150, 10);
	/*
	if(Direction == LEFT)
	{
		switch(Focus)
		{
		case 1:	Focus = 0;	break;
		case 2:	Focus = 1;	break;
		case 4:	Focus = 3;	break;
		case 5: Focus = 4;	break;
		}
	}
	else if(Direction == RIGHT)
	{
		switch(Focus)
		{
		case 0: Focus = 1;	break;
		case 1: Focus = 2;	break;
		case 3: Focus = 4;	break;
		case 4: Focus = 5;	break;
		}
	}
	else */

	if(Direction == UP)
	{
		switch(Focus)
		{
		case 1: Focus = 0;	break;
		case 2:	Focus = 1;	break;
		case 3: Focus = 2;	break;
		case 4: Focus = 3;	break;
		}
	}
	else if(Direction == DOWN)
	{
		switch(Focus)
		{
		case 0:	Focus = 1;	break;
		case 1: Focus = 2;	break;
		case 2:	Focus = 3;	break;
		case 3: Focus = 4;	break;
		}
	}

	if(b_BtnDown)
	{
		if(HeroForUI->GetStat_PT() > 0)
		{
			switch(Focus)
			{
			case 0:
				HeroForUI->SetStat_ST(HeroForUI->GetStat_ST()+1);
				break;
			case 1:
				HeroForUI->SetStat_AR(HeroForUI->GetStat_AR()+1);
				break;
			case 2:
				HeroForUI->SetStat_HP(HeroForUI->GetStat_HP()+1);
				break;
			case 3:
				HeroForUI->SetStat_MP(HeroForUI->GetStat_MP()+1);
				break;
			case 4:
				HeroForUI->SetStat_SP(HeroForUI->GetStat_SP()+1);
				break;
			case 5:
				break;
			}
			HeroForUI->SetStat_PT(HeroForUI->GetStat_PT() - 1);
			b_BtnDown = false;
		}
	}

	if(PushCount >= 0) {
		PushCount++;
		Direction = NONE;
	}

	if(PushCount >= 10) {
		PushCount = -1;
	}
}

void CObject_Status::Render()
{
	
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
	SetDrawBright(255, 255, 255);
	DrawGraph(0, 0, GetResourceWithKey(IMAGE_BARRACK_BACKGROUND), TRUE);
	DrawGraphF(fDrawX, fDrawY, GetResourceWithKey(IMAGE_BARRACK_STATUS_WINDOW), TRUE);



	if(HeroForUI->GetStat_PT() == 0)
	{

	}
	else
	{
		int plus = GetResourceWithKey(IMAGE_BARRACK_STATUS_PLUSBTN);
		int select = GetResourceWithKey(IMAGE_BARRACK_STATUS_STATSELECT);
		
		DrawGraphF(fDrawX+210, fDrawY+277, plus, TRUE);
		DrawGraphF(fDrawX+210, fDrawY+302, plus, TRUE);
		DrawGraphF(fDrawX+210, fDrawY+328, plus, TRUE);
		DrawGraphF(fDrawX+210, fDrawY+353, plus, TRUE);
		DrawGraphF(fDrawX+210, fDrawY+378, plus, TRUE);
		
		switch(Focus)
		{
		case 0:
			DrawGraphF(fDrawX+210, fDrawY+277, select, TRUE);
			break;
		case 1:
			DrawGraphF(fDrawX+210, fDrawY+302, select, TRUE);
			break;
		case 2:
			DrawGraphF(fDrawX+210, fDrawY+328, select, TRUE);
			break;
		case 3:
			DrawGraphF(fDrawX+210, fDrawY+353, select, TRUE);
			break;
		case 4:
			DrawGraphF(fDrawX+210, fDrawY+378, select, TRUE);
			break;
		}
	}

	DrawFormatStringToHandle(fDrawX+250, fDrawY+211, GetColor(255, 255, 255), LargeFont, "%d", (int)HeroForUI->GetLvl());
	DrawFormatStringToHandle(fDrawX+355, fDrawY+210, GetColor(255, 255, 255), LargeFont, "%d", (int)HeroForUI->GetStat_PT());
	DrawFormatStringToHandle(fDrawX+250, fDrawY+277, GetColor(255, 255, 255), SmallFont, "%d", (int)HeroForUI->GetStat_ST());
	DrawFormatStringToHandle(fDrawX+250, fDrawY+302, GetColor(255, 255, 255), SmallFont, "%d", (int)HeroForUI->GetStat_AR());
	DrawFormatStringToHandle(fDrawX+250, fDrawY+328, GetColor(255, 255, 255), SmallFont, "%d", (int)HeroForUI->GetStat_HP());
	DrawFormatStringToHandle(fDrawX+250, fDrawY+353, GetColor(255, 255, 255), SmallFont, "%d", (int)HeroForUI->GetStat_MP());
	DrawFormatStringToHandle(fDrawX+250, fDrawY+378, GetColor(255, 255, 255), SmallFont, "%d", (int)HeroForUI->GetStat_SP());

	
	//Char->DrawSprite(517, 262);

}

void CObject_Status::Control()
{
	if(PushCount == -1)
	{
		if(CheckHitKey(KEY_INPUT_LEFT))
		{
			PushCount = 0;
			Direction = LEFT;
		}
		else if(CheckHitKey(KEY_INPUT_RIGHT))
		{
			PushCount = 0;
			Direction = RIGHT;
		}
		else if(CheckHitKey(KEY_INPUT_UP))
		{
			PushCount = 0;
			Direction = UP;
		}
		else if(CheckHitKey(KEY_INPUT_DOWN))
		{
			PushCount = 0;
			Direction = DOWN;
		}

		if(CheckHitKey(KEY_INPUT_X))
		{
			PushCount = 0;
			b_BtnDown = true;
		}
	}



}