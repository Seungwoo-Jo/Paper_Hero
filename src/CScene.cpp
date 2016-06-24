#include "CScene.h"
#include "CObject_Hero.h"
#include "CObject_Status.h"
#include "CObject_Skillwd.h"
#include "ResourceManager.h"

CScene* CScene::p_NowScene;

CScene::CScene()
{
	CameraX = 0;
	CameraY = 0;
	TempCameraX = 0;
	TempCameraY = 0;

	b_CameraMode = false;
	Font = -1;

	Bright = 255;

	Time = 3600;
}

CScene::~CScene()
{
	InitFontToHandle();
}

CScene* CScene::GetNowScene()
{
	return p_NowScene;
}

void CScene::Open()
{
	// ����Ŭ���� ����
}

void CScene::Close()
{
	// ����Ŭ���� ����
}

CObject* CScene::SendHero()
{
	return Temp;
}

void CScene::Update()
{
	// ����Ŭ���� ����
}

void CScene::Render()
{
	// ����Ŭ���� ����
}

void CScene::Control()
{
	// ����Ŭ���� ����
}