#include "CObject_Skillwd.h"
#include "ResourceManager.h"

CObject_Skillwd::CObject_Skillwd()
{

}

CObject_Skillwd::CObject_Skillwd(int GHandle, double x, double y, int Width, int Height, unsigned int Type) : CObject(GHandle, x, y, Width, Height, Type)
{
	SkillList = new SkillInfo[6];

	SelectSound = new CSound(LoadSoundMem("Resource/Sound/skill.select.ogg"), 0);

	for(int i=0; i<9; i++) {
		Skill[i].Tag = 100*(1+(int)(i/3)) + (i%3); // 100 ~ 302
		Skill[i].Enable = true;
	}

	Skill[0].GraphHandle = GetResourceWithKey(IMAGE_INTERFACE_ICON_SKILL11);
	Skill[1].GraphHandle = GetResourceWithKey(IMAGE_INTERFACE_ICON_SKILL12);
	Skill[2].GraphHandle = LoadGraph("Resource/Interface/dummy_skill_icon_07.png");

	Skill[3].GraphHandle = GetResourceWithKey(IMAGE_INTERFACE_ICON_SKILL21);
	Skill[4].GraphHandle = GetResourceWithKey(IMAGE_INTERFACE_ICON_SKILL22);
	Skill[5].GraphHandle = GetResourceWithKey(IMAGE_INTERFACE_ICON_SKILL23);

	Skill[6].GraphHandle = GetResourceWithKey(IMAGE_INTERFACE_ICON_SKILL31);
	Skill[7].GraphHandle = GetResourceWithKey(IMAGE_INTERFACE_ICON_SKILL32);
	Skill[8].GraphHandle = LoadGraph("Resource/Interface/dummy_skill_icon_08.png");

	Skill[0].UseMP = 7;
	Skill[1].UseMP = 8;
	Skill[2].UseMP = 9;
	Skill[3].UseMP = 7;
	Skill[4].UseMP = 8;
	Skill[5].UseMP = 9;
	Skill[6].UseMP = 7;
	Skill[7].UseMP = 8;
	Skill[8].UseMP = 9;

	for(int i=0; i<6; i++) {
		SkillList[i].Tag = -1;
		SkillList[i].GraphHandle = -1;
		SkillList[i].Enable = true;
	}

	Focus = 0;
	TempFocus1 = 1;
	TempFocus2 = 1;
	Direction = NONE;
	Select = 0;

	PushCount = -1;
}

CObject_Skillwd::~CObject_Skillwd()
{
	/*
	for(int i=0; i<9; i++) {
		DeleteGraph(Skill[i].GraphHandle);
	}
	*/
	delete SelectSound;
	delete []SkillList;
}

void CObject_Skillwd::TakeObjectInfo(CObject* _object)
{
	HeroForUI = _object;
}

void CObject_Skillwd::Update()
{
	if(Focus == 1 || Focus == 2 || Focus == 3) {
		TempFocus2 = Focus;
	}
	if(Focus == 4 || Focus == 5 || Focus == 6 || Focus == 7 || Focus == 8 ) {
		TempFocus1 = Focus;
	}

	HeroForUI->MoveTo(0, 0);
	MoveDrawPos(150, 10);

	//방향키로 움직이는거 하드코딩
	if(Direction == LEFT)
	{
		switch(Focus)
		{
		case 1:	Focus = 0;	break;
		case 2:	Focus = 1;	break;
		case 3:	Focus = 2;	break;
		case 4: 
		case 5:
		case 6:
		case 7:
		case 8: Focus = 0;	break;
		default:			break;
		}

	}
	else if(Direction == RIGHT)
	{
		switch(Focus) {
		case 0:	Focus = TempFocus1;	break;
		case 1:	Focus = 2;	break;
		case 2:	Focus = 3;	break;
		default:			break;
		}
	}
	else if(Direction == UP)
	{
		switch(Focus) {
		case 1:	Focus = 0;	break;
		case 2:	Focus = 1;	break;
		case 3:	Focus = 2;	break;
		case 4: Focus = TempFocus2; break;
		case 5:	Focus = 4;	break;
		case 6:	Focus = 5;	break;
		case 7: Focus = 6;	break;
		case 8:	Focus = 7;	break;
		default:			break;
		}
	}
	else if(Direction == DOWN)
	{
		switch(Focus) {
		case 1:	Focus = 4;	break;
		case 2:	Focus = 4;	break;
		case 3: Focus = 4;	break;
		case 4:	Focus = 5;	break;
		case 5:	Focus = 6;	break;
		case 6: Focus = 7;	break;
		case 7:	Focus = 8;	break;
		default:			break;
		}

		SelectSound->PlaySoundA();

	}

	// 스킬 지정! (중복은 X)
	if(Select != 0)
	{
		bool temp = true;
		for(int i=0; i<6; i++)
		{
			if(Skill[Focus].Tag == SkillList[i].Tag) {
				temp = false;
			}
		}

		if(temp)
		{
			if(TempFocus2 == 1)
			{
				if(SkillList[Select-1].Tag == Skill[1].Tag)
				{
					//SkillList[Select-1].Tag = -1;
					//SkillList[Select-1].GraphHandle = -1;
				}
				else
				{
					switch(Focus)
					{
					case 4:
						SkillList[Select-1] = Skill[0];
						break;
					case 5:
						SkillList[Select-1] = Skill[1];
						break;
					case 6:
						//SkillList[Select-1] = Skill[2];
						break;
					case 7:
						break;
					case 8:
						break;
					default:
						break;
					}
				}
			}
			else if(TempFocus2 == 2)
			{
				if(SkillList[Select-1].Tag == Skill[1].Tag)
				{
					//SkillList[Select-1].Tag = -1;
					//SkillList[Select-1].GraphHandle = -1;
				}
				else
				{
					switch(Focus)
					{
					case 4:
						SkillList[Select-1] = Skill[3];
						break;
					case 5:
						SkillList[Select-1] = Skill[4];
						break;
					case 6:
						SkillList[Select-1] = Skill[5];
						break;
					case 7:
						break;
					case 8:
						break;
					default:
						break;
					}
				}
			}
			else if(TempFocus2 == 3)
			{
				if(SkillList[Select-1].Tag == Skill[1].Tag)
				{
					//SkillList[Select-1].Tag = -1;
					//SkillList[Select-1].GraphHandle = -1;
				}
				else
				{
					switch(Focus)
					{
					case 4:
						SkillList[Select-1] = Skill[6];
						break;
					case 5:
						SkillList[Select-1] = Skill[7];
						break;
					case 6:
						//SkillList[Select-1] = Skill[8];
						break;
					case 7:
						break;
					case 8:
						break;
					default:
						break;
					}
				}
			}
		}
	}

	if(PushCount >= 0) {
		PushCount++;
		Direction = NONE;
	}

	if(PushCount >= 10) {
		PushCount = -1;
	}

	HeroForUI->SetSkillList(SkillList);
}

void CObject_Skillwd::Render()
{
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
	SetDrawBright(255, 255, 255);
	DrawGraphF(0, 0, GetResourceWithKey(IMAGE_BARRACK_BACKGROUND), TRUE);
	DrawGraphF(fDrawX, fDrawY, GetResourceWithKey(IMAGE_BARRACK_SKILL_WINDOW), TRUE); // 15 320
	
	// 오른쪽 스킬 리스트
	if(TempFocus2 == 1) 
	{
		DrawRectGraph((int)(fDrawX+409), (int)(fDrawY+286), 0, 0, 242, 73, GetResourceWithKey(IMAGE_BARRACK_SKILL_SKILL), TRUE, FALSE);
		DrawRectGraph((int)(fDrawX+409), (int)(fDrawY+364), 0, 73, 242, 73, GetResourceWithKey(IMAGE_BARRACK_SKILL_SKILL), TRUE, FALSE);
	}
	else if(TempFocus2 == 2)
	{
		DrawRectGraph((int)(fDrawX+409), (int)(fDrawY+286), 242, 0, 242, 73, GetResourceWithKey(IMAGE_BARRACK_SKILL_SKILL), TRUE, FALSE);
		DrawRectGraph((int)(fDrawX+409), (int)(fDrawY+364), 242, 73, 242, 73, GetResourceWithKey(IMAGE_BARRACK_SKILL_SKILL), TRUE, FALSE);
		DrawRectGraph((int)(fDrawX+409), (int)(fDrawY+442), 242, 146, 242, 73, GetResourceWithKey(IMAGE_BARRACK_SKILL_SKILL), TRUE, FALSE);
	}
	else if(TempFocus2 == 3)
	{
		DrawRectGraph((int)(fDrawX+409), (int)(fDrawY+286), 484, 0, 242, 73, GetResourceWithKey(IMAGE_BARRACK_SKILL_SKILL), TRUE, FALSE);
		DrawRectGraph((int)(fDrawX+409), (int)(fDrawY+364), 484, 73, 242, 73, GetResourceWithKey(IMAGE_BARRACK_SKILL_SKILL), TRUE, FALSE);
	}

	switch(Focus)
	{
	case 0:	DrawGraph((int)(fDrawX+173), (int)(fDrawY+426), GetResourceWithKey(IMAGE_BARRACK_SKILL_LVUPSELECT),  TRUE);	break;
	case 1:	DrawGraph((int)(fDrawX+406), (int)(fDrawY+195), GetResourceWithKey(IMAGE_BARRACK_SKILL_TYPESELECT),  TRUE);	break;
	case 2:	DrawGraph((int)(fDrawX+491), (int)(fDrawY+195), GetResourceWithKey(IMAGE_BARRACK_SKILL_TYPESELECT),  TRUE);	break;
	case 3:	DrawGraph((int)(fDrawX+576), (int)(fDrawY+195), GetResourceWithKey(IMAGE_BARRACK_SKILL_TYPESELECT),  TRUE);	break;
	case 4:	DrawGraph((int)(fDrawX+409), (int)(fDrawY+286), GetResourceWithKey(IMAGE_BARRACK_SKILL_SKILLSELECT), TRUE);	break;
	case 5:	DrawGraph((int)(fDrawX+409), (int)(fDrawY+364), GetResourceWithKey(IMAGE_BARRACK_SKILL_SKILLSELECT), TRUE);	break;
	case 6:	DrawGraph((int)(fDrawX+409), (int)(fDrawY+442), GetResourceWithKey(IMAGE_BARRACK_SKILL_SKILLSELECT), TRUE);	break;
	case 7:	DrawGraph((int)(fDrawX+409), (int)(fDrawY+521), GetResourceWithKey(IMAGE_BARRACK_SKILL_SKILLSELECT), TRUE);	break;
	case 8:	DrawGraph((int)(fDrawX+409), (int)(fDrawY+600), GetResourceWithKey(IMAGE_BARRACK_SKILL_SKILLSELECT), TRUE);	break;
	default:	break;
	}

	if(SkillList[0].GraphHandle!=-1)	DrawGraph(fDrawX+127, fDrawY+542, SkillList[0].GraphHandle, TRUE);
	if(SkillList[1].GraphHandle!=-1)	DrawGraph(fDrawX+212, fDrawY+542, SkillList[1].GraphHandle, TRUE);
	if(SkillList[2].GraphHandle!=-1)	DrawGraph(fDrawX+296, fDrawY+542, SkillList[2].GraphHandle, TRUE);
	if(SkillList[3].GraphHandle!=-1)	DrawGraph(fDrawX+127, fDrawY+619, SkillList[3].GraphHandle, TRUE);
	if(SkillList[4].GraphHandle!=-1)	DrawGraph(fDrawX+212, fDrawY+619, SkillList[4].GraphHandle, TRUE);
	if(SkillList[5].GraphHandle!=-1)
		DrawGraph(fDrawX+296, fDrawY+619, SkillList[5].GraphHandle, TRUE);
}

void CObject_Skillwd::Control()
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
	}
	if     (CheckHitKey(KEY_INPUT_Q))	Select = 1;
	else if(CheckHitKey(KEY_INPUT_W))	Select = 2;
	else if(CheckHitKey(KEY_INPUT_E))	Select = 3;
	else if(CheckHitKey(KEY_INPUT_A))	Select = 4;
	else if(CheckHitKey(KEY_INPUT_S))	Select = 5;
	else if(CheckHitKey(KEY_INPUT_D))	Select = 6;
	else								Select = 0;
	
}