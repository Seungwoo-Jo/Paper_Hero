#include "CObjectManager.h"
#include "CSceneManager.h"
#include "ResourceManager.h"

#include "CCollision.h"

#include "CScene_Stage5_4.h"
#include "CObject_Bg_stage5_4.h"
#include "CObject_Hero.h"
#include "CObject_Minotaur.h"
#include "CObject_Minotaur_Boss.h"
#include "CObject_Cannon.h"
#include "CObject_Carpet.h"
#include "CObject_Lamp.h"
#include "CObject_Mole.h"
#include "CObject_Shadow.h"
#include "CObject_Interface.h"
#include "CObject_Status.h"
#include "CObject_Skillwd.h"

#include "CObject_Chat.h"

CScene_Stage5_4::CScene_Stage5_4()
{
	Background = NULL;
	Hero = NULL;

	
}

CScene_Stage5_4::~CScene_Stage5_4()
{

}

void CScene_Stage5_4::Open()
{
	if(p_NowScene != NULL) {
		Hero = p_NowScene->SendHero();
		p_NowScene->Close();
	}
	p_NowScene = this;

	MapWidth = 5000;
	CameraX = 0;
	CameraY = 0;
	
	b_NextMap = false;
	b_Status = false;
	b_Skillwd = false;
	b_Escape = false;

	DrawTime = -1;
	b_Result = false;

	AddResourceWithKey(IMAGE_STAGE5_4_BACKGROUND);
	AddResourceWithKey(IMAGE_ENEMY_STAGE1_MINOTAUR);
	AddResourceWithKey(IMAGE_ENEMY_STAGE4_MOLE);
	AddResourceWithKey(IMAGE_ENEMY_STAGE4_CARPET);
	AddResourceWithKey(IMAGE_ENEMY_STAGE1_CANNON);
	AddResourceWithKey(IMAGE_ENEMY_STAGE1_MINOTAUR_BOSS);
	AddResourceWithKey(IMAGE_ENEMY_STAGE4_LAMP);
	AddResourceWithKey(IMAGE_ENEMY_STAGE5_HERO);

	Background = new CObject_Bg_Stage5_4(IMAGE_STAGE5_4_BACKGROUND,	0, 0, MapWidth, 768, TYPE_BACKGRAPH);
	Hero->MoveTo(200, 403);
	Object[0] =		new CObject_Minotaur(IMAGE_ENEMY_STAGE1_MINOTAUR, 500, 380, 250, 250, TYPE_ENEMY);
	Object[1] =		new CObject_Mole(IMAGE_ENEMY_STAGE4_MOLE, 575, 300, 250, 250, TYPE_ENEMY);
	Object[2] =		new CObject_Carpet(IMAGE_ENEMY_STAGE4_CARPET, 650, 380, 250, 250, TYPE_ENEMY);
	Object[3] =		new CObject_Cannon(IMAGE_ENEMY_STAGE1_CANNON, 700, 380, 250, 250, TYPE_ENEMY);

	Object[4] =		new CObject_Minotaur(IMAGE_ENEMY_STAGE1_MINOTAUR, 1000, 380, 250, 250, TYPE_ENEMY);
	Object[5] =		new CObject_Mole(IMAGE_ENEMY_STAGE4_MOLE, 1075, 300, 250, 250, TYPE_ENEMY);
	Object[6] =		new CObject_Carpet(IMAGE_ENEMY_STAGE4_CARPET, 1150, 380, 250, 250, TYPE_ENEMY);
	Object[7] =		new CObject_Cannon(IMAGE_ENEMY_STAGE1_CANNON, 1200, 380, 250, 250, TYPE_ENEMY);

	Object[8] =		new CObject_Minotaur(IMAGE_ENEMY_STAGE1_MINOTAUR, 1500, 380, 250, 250, TYPE_ENEMY);
	Object[9] =		new CObject_Mole(IMAGE_ENEMY_STAGE4_MOLE, 1575, 300, 250, 250, TYPE_ENEMY);
	Object[10] =	new CObject_Carpet(IMAGE_ENEMY_STAGE4_CARPET, 1650, 380, 250, 250, TYPE_ENEMY);
	Object[11] =	new CObject_Cannon(IMAGE_ENEMY_STAGE1_CANNON, 1700, 380, 250, 250, TYPE_ENEMY);

	Object[12] =	new CObject_Shadow(IMAGE_ENEMY_STAGE5_HERO, 2200, 400, 400, 400, TYPE_ENEMY);

	Object[13] =	new CObject_Minotaur(IMAGE_ENEMY_STAGE1_MINOTAUR, 2500, 380, 250, 250, TYPE_ENEMY);
	Object[14] =	new CObject_Mole(IMAGE_ENEMY_STAGE4_MOLE, 2575, 300, 250, 250, TYPE_ENEMY);
	Object[15] =	new CObject_Carpet(IMAGE_ENEMY_STAGE4_CARPET, 2650, 380, 250, 250, TYPE_ENEMY);
	Object[16] =	new CObject_Cannon(IMAGE_ENEMY_STAGE1_CANNON, 2700, 380, 250, 250, TYPE_ENEMY);

	Object[17] =	new CObject_Minotaur(IMAGE_ENEMY_STAGE1_MINOTAUR, 3000, 380, 250, 250, TYPE_ENEMY);
	Object[18] =	new CObject_Mole(IMAGE_ENEMY_STAGE4_MOLE, 3075, 300, 250, 250, TYPE_ENEMY);
	Object[19] =	new CObject_Carpet(IMAGE_ENEMY_STAGE4_CARPET, 3150, 380, 250, 250, TYPE_ENEMY);
	Object[20] =	new CObject_Cannon(IMAGE_ENEMY_STAGE1_CANNON, 3200, 380, 250, 250, TYPE_ENEMY);

	Object[21] =	new CObject_Lamp(IMAGE_ENEMY_STAGE4_LAMP, 3700, 255, 250, 250, TYPE_ENEMY);

	Interface =		new CObject_Interface(IMAGE_INTERFACE_STATUS, 20,  20, 287, 266, TYPE_INTERFACE);
	Status =		new CObject_Status(IMAGE_HERO, 0, 0, 0, 0, TYPE_MENU);
	Skillwd =		new CObject_Skillwd(IMAGE_HERO, 0, 0, 0, 0, TYPE_MENU);

	Background	->TakeObjectInfo(Hero);

	for(int i=0; i<22; i++) {
		Object[i]->TakeObjectInfo(Hero);
		Object[i]->SetCamera(&CameraX, &CameraY);
	}

	Interface   ->TakeObjectInfo(Hero);
	Status		->TakeObjectInfo(Hero);
	Skillwd		->TakeObjectInfo(Hero);

	Background	->SetCamera(&CameraX, &CameraY);

	Hero		->SetCamera(&CameraX, &CameraY);

	CObjectManager::GetObjectManager()->AddObject(Background);
	for(int i=0; i<22; i++) {
		CObjectManager::GetObjectManager()->AddObject(Object[i]);
	}
	CObjectManager::GetObjectManager()->AddObject(Interface);
}

void CScene_Stage5_4::Close()
{
	DelResourceWithKey(IMAGE_STAGE4_5_BACKGROUND);

	CObjectManager::GetObjectManager()->RemoveObject(Background);
	for(int i=0; i<22; i++) {
		CObjectManager::GetObjectManager()->RemoveObject(Object[i]);
	}
	CObjectManager::GetObjectManager()->RemoveObject(Interface);

	delete Background;
	delete Interface;

	for(int i=0; i<22; i++) {
		delete Object[i];
	}
}

CObject* CScene_Stage5_4::SendHero() {
	return Hero;
}

void CScene_Stage5_4::Update()
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

	if(!b_Result && Object[21]->GetHP() < 0)
	{
		DrawTime = 0;
		b_Result = true;
	}
	
	if(DrawTime != -1)	{
		DrawTime++;
	}

	if(DrawTime > 480) {
		Hero->MoveTo(0, 457);
		b_Result = false;
		b_Status = true;
		DrawTime = -1;
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
	/*
	if(b_Status) {
		//BackSound->StopSound();
		Status->Update();
	}
	else if(b_Skillwd) {
		//BackSound->StopSound();
		Skillwd->Update();
	}
	*/

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
	/*
	if(b_NextMap)
	{
		b_NextMap = false;
		CScene* temp = CSceneManager::GetSceneManager()->getScene(1);
		if(temp == NULL) {
			return;
		}
		temp->Open();
	}
	*/
}

void CScene_Stage5_4::Render()
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
	
	if(b_Result)
	{
		int ap = DrawTime;
		if(ap > 128) {
			ap = 128;
		}
		DrawGraphF(0.0f, 0.0f, GetResourceWithKey(IMAGE_STAGE_RESULT_BACKGROUND), TRUE);
		SetDrawBlendMode(DX_BLENDMODE_ADD, 127+ap);

		DrawGraphF(448.0f + (float)ap*2, 320.0f, GetResourceWithKey(IMAGE_STAGE_RESULT_STAR), TRUE);
		DrawGraphF(448.0f + (float)ap, 320.0f, GetResourceWithKey(IMAGE_STAGE_RESULT_STAR), TRUE);
		DrawGraphF(448.0f			 , 320.0f, GetResourceWithKey(IMAGE_STAGE_RESULT_STAR), TRUE);
		DrawGraphF(448.0f - (float)ap, 320.0f, GetResourceWithKey(IMAGE_STAGE_RESULT_STAR), TRUE);
		DrawGraphF(448.0f - (float)ap*2, 320.0f, GetResourceWithKey(IMAGE_STAGE_RESULT_STAR), TRUE);

		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
	}

}

void CScene_Stage5_4::Control()
{
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