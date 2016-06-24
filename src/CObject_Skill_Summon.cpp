#include "CObject_Skill_Summon.h"
#include "ResourceManager.h"


CObject_Skill_Summon::CObject_Skill_Summon()
{

}

CObject_Skill_Summon::CObject_Skill_Summon(int GHandle, double x, double y, int Width, int Height, unsigned int Type) : CObject(GHandle, x, y, Width, Height, Type)
{
	SkillSprite = new CSprite(GetResourceWithKey(IMAGE_HERO_SKILL23), 10, 0, 0, 10, 1, 8000, 500, 90, true);
	MaxHP = 54;
	SetHP(54);
	temp = 0;

	Bright = NULL;
}

CObject_Skill_Summon::~CObject_Skill_Summon()
{

}

void CObject_Skill_Summon::TakeObjectInfo(CObject* _object)
{
	Hero = _object;
	CenterX = Hero->GetWorldX()+100;
	HeroY = Hero->GetWorldY();
}

void CObject_Skill_Summon::Update()
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

	if(skillcount >= 7 && skillcount <= 9)
	{
		if(b_left) {
			Hero->SetSkillBox((int)(fDrawX+100-800)+200, (int)fDrawY, 600, 400);
		}
		else if(b_right) {
			Hero->SetSkillBox((int)(fDrawX+100)-200, (int)fDrawY, 600, 400);
		}
	}
	
	if(GetHP() < 0) {
		SkillSprite->SetCount(0);
	}
}

void CObject_Skill_Summon::Render()
{
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
	
	if(GetHP() > 0)
	{
		if(b_left) {
			SkillSprite->DrawSprite((fDrawX+100-800)+200, fDrawY);
		}
		else if(b_right) {
			SkillSprite->DrawTurnSprite((fDrawX+100)-200, fDrawY);
		}
	}

	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
}

void CObject_Skill_Summon::Control()
{

}