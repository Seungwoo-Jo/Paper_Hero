#include "CObject_Skill_Water.h"
#include "ResourceManager.h"


CObject_Skill_Water::CObject_Skill_Water()
{

}

CObject_Skill_Water::CObject_Skill_Water(int GHandle, double x, double y, int Width, int Height, unsigned int Type) : CObject(GHandle, x, y, Width, Height, Type)
{
	SkillSprite = new CSprite(GetResourceWithKey(IMAGE_HERO_SKILL22), 11, 0, 0, 11, 1, 8800, 400, 80, true);
	MaxHP = 52;
	SetHP(52);
	temp = 0;

	Bright = NULL;
}

CObject_Skill_Water::~CObject_Skill_Water()
{

}

void CObject_Skill_Water::TakeObjectInfo(CObject* _object)
{
	Hero = _object;
	CenterX = Hero->GetWorldX()+100;
	HeroY = Hero->GetWorldY();
}

void CObject_Skill_Water::Update()
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
	if(skillcount >= 8 && skillcount <= 10)
	{
		if(b_left) {
			Hero->SetSkillBox((int)(fDrawX+100-800), (int)fDrawY, 400, 300);
		}
		else if(b_right) {
			Hero->SetSkillBox((int)(fDrawY+100), (int)fDrawY, 400, 300);
		}
	}
	
	if(GetHP() < 0) {
		SkillSprite->SetCount(0);
	}
}

void CObject_Skill_Water::Render()
{
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
	
	if(GetHP() > 0)
	{
		if(b_left) {
			SkillSprite->DrawTurnSprite((fDrawX+100-800)+400, fDrawY);
		}
		else if(b_right) {
			SkillSprite->DrawSprite((fDrawX+100)-400, fDrawY);
		}
	}

	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
}

void CObject_Skill_Water::Control()
{

}