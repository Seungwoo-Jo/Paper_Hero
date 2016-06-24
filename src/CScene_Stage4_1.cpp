#include "CObjectManager.h"
#include "CSceneManager.h"
#include "ResourceManager.h"

#include "CCollision.h"

#include "CScene_Stage4_1.h"
#include "CObject_Bg_stage4_1.h"
#include "CObject_Hero.h"
#include "CObject_Carpet.h"
#include "CObject_Mole.h"
#include "CObject_Cannon.h"
#include "CObject_Interface.h"
#include "CObject_Status.h"
#include "CObject_Skillwd.h"

#include "CObject_Chat.h"
CScene_Stage4_1::CScene_Stage4_1()
{
	Background = NULL;
	Hero = NULL;

	
}

CScene_Stage4_1::~CScene_Stage4_1()
{

}

void CScene_Stage4_1::Open()
{
	if(p_NowScene != NULL) {
		Hero = p_NowScene->SendHero();
		p_NowScene->Close();
	}
	p_NowScene = this;

	MapWidth = 4000;
	CameraX = 0;
	CameraY = 0;
	
	b_NextMap = false;
	b_Status = false;
	b_Skillwd = false;
	b_Escape = false;

	AddResourceWithKey(IMAGE_STAGE4_1_BACKGROUND);
	AddResourceWithKey(IMAGE_ENEMY_STAGE4_MOLE);
	AddResourceWithKey(IMAGE_ENEMY_STAGE4_CARPET);
	AddResourceWithKey(IMAGE_ENEMY_STAGE4_SWORD);

	Background = new CObject_Bg_Stage4_1(IMAGE_STAGE4_1_BACKGROUND,	0, 0, MapWidth, 768, TYPE_BACKGRAPH);
	Hero->MoveTo(200, 403);
	Object[0] =		new CObject_Mole(IMAGE_ENEMY_STAGE4_MOLE, 500, 300, 300, 350, TYPE_ENEMY);
	Object[1] =		new CObject_Mole(IMAGE_ENEMY_STAGE4_MOLE, 650, 300, 300, 350, TYPE_ENEMY);
	Object[2] =		new CObject_Carpet(IMAGE_ENEMY_STAGE4_CARPET, 750, 400, 300, 350, TYPE_ENEMY);
	Object[3] =		new CObject_Mole(IMAGE_ENEMY_STAGE4_MOLE, 1500, 300, 300, 350, TYPE_ENEMY);
	Object[4] =		new CObject_Mole(IMAGE_ENEMY_STAGE4_MOLE, 1650, 300, 300, 350, TYPE_ENEMY);
	Object[5] =		new CObject_Carpet(IMAGE_ENEMY_STAGE4_CARPET, 1750, 400, 300, 350, TYPE_ENEMY);
	Object[6] =		new CObject_Mole(IMAGE_ENEMY_STAGE4_MOLE, 2300, 300, 300, 350, TYPE_ENEMY);
	Object[7] =		new CObject_Mole(IMAGE_ENEMY_STAGE4_MOLE, 2450, 300, 300, 350, TYPE_ENEMY);
	Object[8] =		new CObject_Mole(IMAGE_ENEMY_STAGE4_MOLE, 2600, 300, 300, 350, TYPE_ENEMY);
	Object[9] =		new CObject_Carpet(IMAGE_ENEMY_STAGE4_CARPET, 2700, 400, 300, 350, TYPE_ENEMY);
	Object[10] =	new CObject_Mole(IMAGE_ENEMY_STAGE4_MOLE, 3200, 300, 300, 350, TYPE_ENEMY);
	Object[11] =	new CObject_Mole(IMAGE_ENEMY_STAGE4_MOLE, 3350, 300, 300, 350, TYPE_ENEMY);
	Object[12] =	new CObject_Carpet(IMAGE_ENEMY_STAGE4_CARPET, 3450, 400, 300, 350, TYPE_ENEMY);
	Interface =		new CObject_Interface(IMAGE_INTERFACE_STATUS, 20,  20, 287, 266, TYPE_INTERFACE);
	Status =		new CObject_Status(IMAGE_HERO, 0, 0, 0, 0, TYPE_MENU);
	Skillwd =		new CObject_Skillwd(IMAGE_HERO, 0, 0, 0, 0, TYPE_MENU);

	Background	->TakeObjectInfo(Hero);

	for(int i=0; i<13; i++) {
		Object[i]->TakeObjectInfo(Hero);
		Object[i]->SetCamera(&CameraX, &CameraY);
	}

	Interface   ->TakeObjectInfo(Hero);
	Status		->TakeObjectInfo(Hero);
	Skillwd		->TakeObjectInfo(Hero);

	Background	->SetCamera(&CameraX, &CameraY);
	Hero		->SetCamera(&CameraX, &CameraY);

	CObjectManager::GetObjectManager()->AddObject(Background);
	for(int i=0; i<13; i++) {
		CObjectManager::GetObjectManager()->AddObject(Object[i]);
	}
	CObjectManager::GetObjectManager()->AddObject(Interface);
}

void CScene_Stage4_1::Close()
{
	DelResourceWithKey(IMAGE_STAGE4_1_BACKGROUND);

	CObjectManager::GetObjectManager()->RemoveObject(Background);
	for(int i=0; i<13; i++) {
		CObjectManager::GetObjectManager()->RemoveObject(Object[i]);
	}
	CObjectManager::GetObjectManager()->RemoveObject(Interface);
	
	delete Background;
	delete Interface;
	for(int i=0; i<13; i++) {
		delete Object[i];
	}
}

CObject* CScene_Stage4_1::SendHero() {
	return Hero;
}

void CScene_Stage4_1::Update()
{
	CObjectManager::GetObjectManager()->UpdateAllObject();	// 오브젝트 처리

	if(!b_CameraMode)
	{
		TempCameraX = CameraX;
		TempCameraY = CameraY;

		Background->MovePosInSrc(CameraX, CameraY);

		Hero->MoveDrawPos(Hero->GetWorldX()-CameraX, Hero->GetWorldY()-CameraY);
		Interface->MoveDrawPos(20.0f, 20.0f);
	}
	
	if(Hero->GetDrawX() > 512.0f)
	{
		if(CameraX < MapWidth - 1024) {
			CameraX += (int)Hero->GetSpd();
		}
		else {
			CameraX = MapWidth - 1024;
		}
	}
	else if(Hero->GetDrawX() < 362.0f)
	{
		if(CameraX > 0) {
			CameraX -= (int)Hero->GetSpd();
		}
		else {
			CameraX = 0;
		}
	}

	if(Hero->GetWorldX() > MapWidth - 150)
	{
		b_Status = true;
		Hero->MoveTo(0, Hero->GetWorldY());
	}

	//바닥 충돌
	if(Hero->GetWorldY() > 403) {
		Hero->SetAir(false);
		Hero->MoveTo(Hero->GetWorldX(), 403);
	}

	if(b_Status) {
		//BackSound->StopSound();
		Status->Update();
	}
	else if(b_Skillwd) {
		//BackSound->StopSound();
		Skillwd->Update();
	}


	// 맵 양 끝 충돌
	if( Hero->GetWorldX() < -75){
		Hero->MoveTo(-75, Hero->GetWorldY());
	}
	if( Hero->GetWorldX() > MapWidth - 125 ) {
		Hero->MoveTo(MapWidth - 125, Hero->GetWorldY());
	}
	/*
	if( Enemy2->GetWorldX() < -200){
		Enemy2->MoveTo(-200, Enemy2->GetWorldY());
	}
	if( Enemy2->GetWorldX() > MapWidth - 200 ) {
		Enemy2->MoveTo(MapWidth - 200, Enemy2->GetWorldY());
	}
	*/

	if(b_NextMap)
	{
		b_NextMap = false;
		CScene* temp = CSceneManager::GetSceneManager()->getScene(32);
		if(temp == NULL) {
			return;
		}
		temp->Open();
	}
}

void CScene_Stage4_1::Render()
{
	if(b_Status || b_Skillwd)
	{
		if(b_Status) {
			Hero->SetBattle(false);
			Status->Render();
		}
		else if(b_Skillwd) {
			Skillwd->Render();
		}
	}
	else
	{
		CObjectManager::GetObjectManager()->RenderAllObject();	// 오브젝트 처리
	}
}

void CScene_Stage4_1::Control()
{
	if(CheckHitKey(KEY_INPUT_9)) {
		b_Status = true;
	}
	if(CheckHitKey(KEY_INPUT_0)) {
		b_NextMap = true;
	}
	if(b_Status)
	{
		Status->Control();
		if(CheckHitKey(KEY_INPUT_F1))
		{
			b_Status = false;
			b_Skillwd = true;
		}
	}
	else if(b_Skillwd)
	{
		Skillwd->Control();
		if(CheckHitKey(KEY_INPUT_F2))
		{
			b_Skillwd = false;
			b_NextMap = true;
		}
	}
	else
	{
		CObjectManager::GetObjectManager()->ControlAllObject();	// 오브젝트 처리
	}
}