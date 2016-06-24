#include "CObject_Enemy.h"
#include "DxLib.h"
#include "CObjectManager.h"
#include "ResourceManager.h"


CObject_Enemy::CObject_Enemy()
{
}

CObject_Enemy::CObject_Enemy(int GHandle, double x, double y, int Width, int Height, unsigned int Type) : CObject(GHandle, x, y, Width, Height, Type)
{
	Func = new CGlobal();
	b_left = true;
	b_right = false;
	b_Hit = false;
	b_Attack = false;

	HitHandle = ResourceManager::getResourceManager()->GetRes(IMAGE_ENEMY_EFFECT_HIT);
	HP_Bar = ResourceManager::getResourceManager()->GetRes(IMAGE_ENEMY_HPBAR);
	HP_Back = ResourceManager::getResourceManager()->GetRes(IMAGE_ENEMY_HPBACK);
}

CObject_Enemy::~CObject_Enemy()
{
}

void CObject_Enemy::TakeObjectInfo(CObject* _object) {
	HeroForEnemy = _object;
}

void CObject_Enemy::Init()
{
}

void CObject_Enemy::Update()
{

}

void CObject_Enemy::Render()
{

}

void CObject_Enemy::Control()
{

}