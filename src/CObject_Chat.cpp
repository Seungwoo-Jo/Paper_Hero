#include "CObject_Chat.h"
#include "ResourceManager.h"

CObject_Chat::CObject_Chat()
{

}

CObject_Chat::CObject_Chat(int GHandle, double x, double y, int Width, int Height, unsigned int Type) : CObject(GHandle, x, y, Width, Height, Type)
{
	GraphHandle = GHandle;
	fDrawX = 64;
	fDrawY = 512;

	face = FACE_NONE;
	name = new char[64];
	str1 = new char[64];
	str2 = new char[64];
	str3 = new char[64];

	memset(name, NULL, 64);
	memset(str1, NULL, 64);
	memset(str2, NULL, 64);
	memset(str3, NULL, 64);

	SmallFont  = CreateFontToHandle("��������ڵ�", 20, 2, DX_FONTTYPE_ANTIALIASING_EDGE_8X8);
	MidiumFont = CreateFontToHandle("��������ڵ�", 26, 2, DX_FONTTYPE_ANTIALIASING_EDGE_8X8);
	LargeFont  = CreateFontToHandle("��������ڵ�", 30, 2, DX_FONTTYPE_ANTIALIASING_EDGE_8X8);

	for(int i=0; i<10; i++) {
		b_Script[i] = false;
	}

	SetHP(1);
}

CObject_Chat::~CObject_Chat()
{
	delete []name;
	delete []str1;
	delete []str2;
	delete []str3;

	InitFontToHandle();
}

void CObject_Chat::Update()
{
	switch(GraphHandle)
	{
	case SCRIPT_STAGE1_1_001:
		if(!b_Script[0]) {
			SetHP(4);
			b_Script[0] = true;
		}
		face = FACE_HERO;
		name = "";
		str1 = "\"���� ������ ���� �� ���ָ�... �������� �ʰھ�!!\"";
		str2 = "";
		str3 = "";
		break;
	case SCRIPT_STAGE1_1_002:
		if(!b_Script[1]) {
			SetHP(4);
			b_Script[1] = true;
		}
		face = FACE_PRIN;
		name = "";
		str1 = "(�н�) \"���ͤ�...\"";
		str2 = "";
		str3 = "";
		break;
	case SCRIPT_STAGE1_1_003:
		if(!b_Script[2]) {
			SetHP(4);
			b_Script[2] = true;
		}
		face = FACE_HERO;
		name = "";
		str1 = "\"����!!  �鼳����!!!\"";
		str2 = "";
		str3 = "";
		break;
	case SCRIPT_STAGE1_1_004:
		if(!b_Script[3]) {
			SetHP(4);
			b_Script[3] = true;
		}
		face = FACE_HERO;
		name = "";
		str1 = "\"ã�Ҵ� �� ����̾���.";
		str2 = "���� 3�嵵 ã�ƺ���?\"";
		str3 = "";
		break;
	case SCRIPT_STAGE1_1_005:
		if(!b_Script[4]) {
			SetHP(4);
			b_Script[4] = true;
		}
		face = FACE_HERO;
		name = "";
		str1 = "\"��, ���� �� ��������� ";
		str2 = "����� �ƴ϶� �� ������� �ݾ�!!\"";
		str3 = "";
		break;
		// ���� �߰�
	default:
		break;
	}
}

void CObject_Chat::Render()
{
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
	if(GetHP() > 0)
	{
		DrawGraphF(fDrawX, fDrawY, GetResourceWithKey(IMAGE_INTERFACE_CHAT), TRUE);
		DrawFormatStringToHandle((int)fDrawX+40, (int)fDrawY+40, GetColor(215, 230, 215), MidiumFont, name);
		DrawFormatStringToHandle((int)fDrawX+40, (int)fDrawY+90, GetColor(215, 230, 215), SmallFont, str1);
		DrawFormatStringToHandle((int)fDrawX+40, (int)fDrawY+130, GetColor(215, 230, 215), SmallFont, str2);
		DrawFormatStringToHandle((int)fDrawX+40, (int)fDrawY+170, GetColor(215, 230, 215), SmallFont, str3);

		if(face == FACE_HERO) {
			DrawGraphF(fDrawX, fDrawY-450, GetResourceWithKey(IMAGE_INTERFACE_FACE_HERO), TRUE);
		}
		else if(face == FACE_PRIN) {
			DrawGraphF(fDrawX+500, fDrawY-450, GetResourceWithKey(IMAGE_INTERFACE_FACE_PRINCESS), TRUE);
		}

		
	}
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
}

void CObject_Chat::Control()
{
	
	if(CheckHitKey(KEY_INPUT_RETURN) == 1) {
		this->SetHP(GetHP()-1);
	}
	
}