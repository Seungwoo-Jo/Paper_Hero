#include "CObject_Skill_Tornado.h"
#include "ResourceManager.h"

CObject_Skill_Tornado::CObject_Skill_Tornado()
{

}

CObject_Skill_Tornado::CObject_Skill_Tornado(int GHandle, double x, double y, int Width, int Height, unsigned int Type) : CObject(GHandle, x, y, Width, Height, Type)
{
	SkillSprite = new CSprite(GetResourceWithKey(IMAGE_HERO_SKILL21), 15, 0, 0, 15, 1, 3900, 290, 100, true);
	MaxHP = 90;
	SetHP(90);
	temp = 0;
	Bright = NULL;
}

CObject_Skill_Tornado::~CObject_Skill_Tornado()
{

}

void CObject_Skill_Tornado::TakeObjectInfo(CObject* _object)
{
	Hero = _object;
	CenterX = Hero->GetWorldX()+100;
	HeroY = Hero->GetWorldY();
}

void CObject_Skill_Tornado::Update()
{
	if(GetHP() == GetMaxHP()) {
		if(Hero->GetWay() == 0) {
			b_left = true;
			b_right = false;
		}
		else if(Hero->GetWay() == 1) {
			b_left = false;
			b_right = true;
		}
	}

	Hero->SetSkillBox(0, 0, 0, 0);
	SetBoundBox(0, 0, 0, 0);
	SetHP(GetHP()-1);
	
	tempX = Hero->GetCameraX();
	tempY = Hero->GetCameraY();
	SetCamera(&tempX, &tempY);

	int skillcount = SkillSprite->GetCount();
	Conversion();
	temp += 5;
	if(skillcount == 2 || skillcount == 5 || skillcount == 8)
	{
		if(b_left) {
			Hero->SetSkillBox((int)(fDrawX-Width+100)+20 - temp, (int)fDrawY, 220, 300);
		}
		else if(b_right) {
			Hero->SetSkillBox((int)(fDrawX+100)+20 + temp, (int)fDrawY, 220, 300);
		}
	}
	
	if(GetHP() < 0) {
		temp = 0;
		SkillSprite->SetCount(0);
	}
}

void CObject_Skill_Tornado::Render()
{
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
	
	if(GetHP() > 0)
	{
		if(b_left) {
			SkillSprite->DrawSprite((WorldX-(*CameraX)-Width+100) - temp, fDrawY);
		}
		else if(b_right) {
			SkillSprite->DrawTurnSprite((WorldX-(*CameraX)+100) + temp, fDrawY);
		}
	}

	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
}

void CObject_Skill_Tornado::Control()
{

}