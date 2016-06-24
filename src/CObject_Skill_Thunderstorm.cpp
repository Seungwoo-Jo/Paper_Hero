#include "CObject_Skill_Thunderstorm.h"
#include "ResourceManager.h"


CObject_Skill_Thunderstorm::CObject_Skill_Thunderstorm()
{

}

CObject_Skill_Thunderstorm::CObject_Skill_Thunderstorm(int GHandle, double x, double y, int Width, int Height, unsigned int Type) : CObject(GHandle, x, y, Width, Height, Type)
{
	SkillSprite = new CSprite(GetResourceWithKey(IMAGE_HERO_SKILL32), 17, 0, 0, 17, 1, 8704, 512, 85, true);
	MaxHP = 86;
	SetHP(86);
	temp = 0;
	Bright = NULL;

}

CObject_Skill_Thunderstorm::~CObject_Skill_Thunderstorm()
{

}

void CObject_Skill_Thunderstorm::TakeObjectInfo(CObject* _object)
{
	Hero = _object;
	CenterX = Hero->GetWorldX()+100;
	HeroY = Hero->GetWorldY();
}

void CObject_Skill_Thunderstorm::Update()
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
	if(skillcount == 10 || skillcount == 14)
	{
		if(b_left) {
			Hero->SetSkillBox((int)(fDrawX-Width+100)+100, (int)fDrawY, 312, 512);
		}
		else if(b_right) {
			Hero->SetSkillBox((int)(fDrawX+100)+100, (int)fDrawY, 312, 512);
		}
	}
	
	if(GetHP() < 0) {
		SkillSprite->SetCount(0);
	}
}

void CObject_Skill_Thunderstorm::Render()
{
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
	
	if(GetHP() > 0)
	{
		if(b_left) {
			SkillSprite->DrawSprite((WorldX-(*CameraX)-Width+100), fDrawY);
		}
		else if(b_right) {
			SkillSprite->DrawTurnSprite((WorldX-(*CameraX)+100), fDrawY);
		}
	}

	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
}

void CObject_Skill_Thunderstorm::Control()
{

}