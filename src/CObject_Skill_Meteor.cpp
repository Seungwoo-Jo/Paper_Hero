#include "CObject_Skill_Meteor.h"
#include "ResourceManager.h"

CObject_Skill_Meteor::CObject_Skill_Meteor()
{

}

CObject_Skill_Meteor::CObject_Skill_Meteor(int GHandle, double x, double y, int Width, int Height, unsigned int Type) : CObject(GHandle, x, y, Width, Height, Type)
{
	SkillSprite = new CSprite(GetResourceWithKey(IMAGE_HERO_SKILL31), 14, 0, 0, 14, 1, 9800, 486, 75, true);
	MaxHP = 60;
	SetHP(60);
	MoveDistance = 162;
	temp = MoveDistance/GetHP();
	Bright = NULL;
}

CObject_Skill_Meteor::~CObject_Skill_Meteor()
{

}

void CObject_Skill_Meteor::TakeObjectInfo(CObject* _object)
{
	Hero = _object;
	CenterX = Hero->GetWorldX()+100;
	HeroY = Hero->GetWorldY();
}

void CObject_Skill_Meteor::Update()
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
	if(skillcount == 7 || skillcount == 8)
	{
		if(b_left) {
			Hero->SetSkillBox((int)(fDrawX-Width+100)+30, (int)fDrawY+200, 300, 300);
		}
		else if(b_right) {
			Hero->SetSkillBox((int)(fDrawX+100)+370, (int)fDrawY+200, 300, 300);
		}
	}
	
	if(GetHP() < 0) {
		SkillSprite->SetCount(0);
	}
}

void CObject_Skill_Meteor::Render()
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

void CObject_Skill_Meteor::Control()
{

}