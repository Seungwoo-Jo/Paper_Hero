#include "CObject_Interface.h"
#include "ResourceManager.h"

CObject_Interface::CObject_Interface()
{

}

CObject_Interface::CObject_Interface(int GHandle, double x, double y, int Width, int Height, unsigned int Type) : CObject(GHandle, x, y, Width, Height, Type)
{
	// 특별히 뭘 할건 없다.
	HeroForUI = NULL;
	GraphHandle = ResourceManager::getResourceManager()->GetRes(IMAGE_INTERFACE_STATUS);
	skill = ResourceManager::getResourceManager()->GetRes(IMAGE_INTERFACE_SKILL);
	fDrawX = x;
	fDrawY = y;
	SetBoundBox(0, 0, 0, 0);

	facenum = 0;
}

CObject_Interface::~CObject_Interface()
{
}

void CObject_Interface::TakeObjectInfo(CObject* _object)
{
	if(HeroForUI == NULL) {
		HeroForUI = _object;
	}
}

void CObject_Interface::Init()
{

}

void CObject_Interface::Update()
{
	fDrawX = 20;
	fDrawY = 20;

	MaxHP = HeroForUI->GetMaxHP();
	MaxMP = HeroForUI->GetMaxMP();
	MaxSP = HeroForUI->GetMaxSP();
	HP = HeroForUI->GetHP();
	MP = HeroForUI->GetMP();
	SP = HeroForUI->GetSP();

	if(HeroForUI->GetStat_EX() * 0.9f < HeroForUI->GetExp()) {
		facenum = 5;
	}
	else if(HeroForUI->GetStat_EX() * 0.7f < HeroForUI->GetExp()) {
		facenum = 4;
	}
	else if(HeroForUI->GetStat_EX() * 0.5f < HeroForUI->GetExp()) {
		facenum = 3;
	}
	else if(HeroForUI->GetStat_EX() * 0.3f < HeroForUI->GetExp()) {
		facenum = 2;
	}
	else if(HeroForUI->GetStat_EX() * 0.1f < HeroForUI->GetExp()) {
		facenum = 1;
	}
	else {
		facenum = 0;
	}

}

void CObject_Interface::Render()
{
	
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
	SetDrawBright(255, 255, 255);
	DrawRectGraph((int)fDrawX,		(int)fDrawY,	0,	0,		287,									169,	GraphHandle, TRUE, FALSE);
	DrawRectGraph((int)fDrawX+118,	(int)fDrawY+14,	0,	169,	(int)(145*((float)HP/(float)MaxHP)),	18,		GraphHandle, TRUE, FALSE);
	DrawRectGraph((int)fDrawX+118,	(int)fDrawY+44,	0,	187,	(int)(114*((float)MP/(float)MaxMP)),	15,		GraphHandle, TRUE, FALSE);
	DrawRectGraph((int)fDrawX+118,	(int)fDrawY+69,	0,	202,	(int)(111*((float)SP/(float)MaxSP)),	15,		GraphHandle, TRUE, FALSE);

	for(int i=0; i<6; i++) {
		DrawGraph((int)0+(62*(i%3)), (int)fDrawY+625+(62*(i/3)), skill, TRUE);
		
		
		if(HeroForUI->GetSkillList()[i].GraphHandle != -1) {
			DrawGraph(0+(62*(i%3)), (int)fDrawY+625+(62*(i/3)), HeroForUI->GetSkillList()[i].GraphHandle, TRUE);
		}
		
	}

	switch(facenum)
	{
	case 0:
		DrawRectGraph((int)fDrawX+5, (int)fDrawY-9, 0, 0, 80, 128, GetResourceWithKey(IMAGE_INTERFACE_FACE), TRUE, FALSE);
		break;
	case 1:
		DrawRectGraph((int)fDrawX+5, (int)fDrawY-9, 80, 0, 80, 128, GetResourceWithKey(IMAGE_INTERFACE_FACE), TRUE, FALSE);
		break;
	case 2:
		DrawRectGraph((int)fDrawX+5, (int)fDrawY-9, 160, 0, 80, 128, GetResourceWithKey(IMAGE_INTERFACE_FACE), TRUE, FALSE);
		break;
	case 3:
		DrawRectGraph((int)fDrawX+5, (int)fDrawY-9, 240, 0, 80, 128, GetResourceWithKey(IMAGE_INTERFACE_FACE), TRUE, FALSE);
		break;
	case 4:
		DrawRectGraph((int)fDrawX+5, (int)fDrawY-9, 320, 0, 80, 128, GetResourceWithKey(IMAGE_INTERFACE_FACE), TRUE, FALSE);
		break;
	case 5:
		DrawRectGraph((int)fDrawX+5, (int)fDrawY-9, 400, 0, 80, 128, GetResourceWithKey(IMAGE_INTERFACE_FACE), TRUE, FALSE);
		break;
	default:
		break;
	}

}

void CObject_Interface::Control()
{

}