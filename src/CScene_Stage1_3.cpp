#include "CObjectManager.h"
#include "CSceneManager.h"
#include "ResourceManager.h"

#include "CCollision.h"

#include "CScene_Stage1_3.h"
#include "CObject_Bg_stage1_3.h"
#include "CObject_Hero.h"
#include "CObject_Minotaur.h"
#include "CObject_Minotaur_Boss.h"
#include "CObject_Cannon.h"
#include "CObject_Tree.h"
#include "CObject_Interface.h"
#include "CObject_Status.h"
#include "CObject_Skillwd.h"
#include "CObject_Appletree.h"
#include "CObject_Activetree.h"
#include "CObject_Wanted.h"
#include "CObject_Chat.h"

CScene_Stage1_3::CScene_Stage1_3()
{
	Background = NULL;
	Hero = NULL;
}

CScene_Stage1_3::~CScene_Stage1_3()
{

}

void CScene_Stage1_3::Open()
{
	if(p_NowScene != NULL) {
		Hero = p_NowScene->SendHero();
		//CObjectManager::GetObjectManager()->RemoveObject(Hero);
		p_NowScene->Close();
	}
	p_NowScene = this;

	MapWidth = 4072;
	CameraX = 0;
	CameraY = 0;
	
	b_NextMap = false;
	b_Status = false;
	b_Skillwd = false;
	b_Escape = false;

	AddResourceWithKey(IMAGE_STAGE1_3_BACKGROUND);
	AddResourceWithKey(IMAGE_ENEMY_STAGE1_MINOTAUR_BOSS);

	Background = new CObject_Bg_Stage1_3(IMAGE_STAGE1_3_BACKGROUND,	0, 0, MapWidth, 768, TYPE_BACKGRAPH);
	Hero->MoveTo(200, 443);
	Object[0] = new CObject_Minotaur_Boss	(IMAGE_ENEMY_STAGE1_MINOTAUR_BOSS,  3200, 297, 400, 400, TYPE_ENEMY);
	Object[1] = new CObject_Minotaur		(IMAGE_ENEMY_STAGE1_MINOTAUR,		 490, 407, 250, 250, TYPE_ENEMY);
	Object[2] = new CObject_Minotaur		(IMAGE_ENEMY_STAGE1_MINOTAUR,		 560, 407, 250, 250, TYPE_ENEMY);
	Object[3] = new CObject_Cannon			(IMAGE_ENEMY_STAGE1_CANNON,			 525, 407, 250, 250, TYPE_ENEMY);
	Object[4] = new CObject_Minotaur		(IMAGE_ENEMY_STAGE1_MINOTAUR,		 790, 407, 250, 250, TYPE_ENEMY);
	Object[5] = new CObject_Minotaur		(IMAGE_ENEMY_STAGE1_MINOTAUR,		 825, 407, 250, 250, TYPE_ENEMY);
	Object[6] = new CObject_Cannon			(IMAGE_ENEMY_STAGE1_CANNON,			 860, 407, 250, 250, TYPE_ENEMY);
	Object[7] = new CObject_Minotaur		(IMAGE_ENEMY_STAGE1_MINOTAUR,		1290, 407, 250, 250, TYPE_ENEMY);
	Object[8] = new CObject_Minotaur		(IMAGE_ENEMY_STAGE1_MINOTAUR,		1325, 407, 250, 250, TYPE_ENEMY);
	Object[9] = new CObject_Cannon			(IMAGE_ENEMY_STAGE1_CANNON,			1360, 407, 250, 250, TYPE_ENEMY);
	Object[10] = new CObject_Minotaur		(IMAGE_ENEMY_STAGE1_MINOTAUR,		1690, 407, 250, 250, TYPE_ENEMY);
	Object[11] = new CObject_Minotaur		(IMAGE_ENEMY_STAGE1_MINOTAUR,		1725, 407, 250, 250, TYPE_ENEMY);
	Object[12] = new CObject_Cannon			(IMAGE_ENEMY_STAGE1_CANNON,			1760, 407, 250, 250, TYPE_ENEMY);
	Object[13] = new CObject_Minotaur		(IMAGE_ENEMY_STAGE1_MINOTAUR,		2090, 407, 250, 250, TYPE_ENEMY);
	Object[14] = new CObject_Minotaur		(IMAGE_ENEMY_STAGE1_MINOTAUR,		2125, 407, 250, 250, TYPE_ENEMY);
	Object[15] = new CObject_Cannon			(IMAGE_ENEMY_STAGE1_CANNON,			2160, 407, 250, 250, TYPE_ENEMY);
	Object[16] = new CObject_Minotaur		(IMAGE_ENEMY_STAGE1_MINOTAUR,		2490, 407, 250, 250, TYPE_ENEMY);
	Object[17] = new CObject_Minotaur		(IMAGE_ENEMY_STAGE1_MINOTAUR,		2525, 407, 250, 250, TYPE_ENEMY);
	Interface =	new CObject_Interface		(IMAGE_INTERFACE_STATUS,			  20,  20, 287, 266, TYPE_INTERFACE);
	Status =	new CObject_Status			(IMAGE_HERO, 0, 0, 0, 0, TYPE_MENU);
	Skillwd =	new CObject_Skillwd			(IMAGE_HERO, 0, 0, 0, 0, TYPE_MENU);

	Background	->TakeObjectInfo(Hero);
	Interface   ->TakeObjectInfo(Hero);
	Status		->TakeObjectInfo(Hero);
	Skillwd		->TakeObjectInfo(Hero);

	for(int i=0; i<18; i++){
		Object[i]->TakeObjectInfo(Hero);
		Object[i]->SetCamera(&CameraX, &CameraY);
	}

	Background	->SetCamera(&CameraX, &CameraY);
	Hero		->SetCamera(&CameraX, &CameraY);

	CObjectManager::GetObjectManager()->AddObject(Background);
	for(int i=0; i<18; i++) {
		CObjectManager::GetObjectManager()->AddObject(Object[i]);
	}
	CObjectManager::GetObjectManager()->AddObject(Interface);
}

void CScene_Stage1_3::Close()
{
	DelResourceWithKey(IMAGE_STAGE1_3_BACKGROUND);
	DelResourceWithKey(IMAGE_ENEMY_STAGE1_MINOTAUR);
	DelResourceWithKey(IMAGE_ENEMY_STAGE1_MINOTAUR_BOSS);

	CObjectManager::GetObjectManager()->RemoveObject(Background);
	for(int i=0; i<18; i++) {
		CObjectManager::GetObjectManager()->RemoveObject(Object[i]);
	}
	CObjectManager::GetObjectManager()->RemoveObject(Interface);
	delete Background;
}

CObject* CScene_Stage1_3::SendHero() {
	return Hero;
}

void CScene_Stage1_3::Update()
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
	
	if(Hero->GetWorldX() > MapWidth - 300)
	{
		b_Status = true;
		Hero->MoveTo(0, Hero->GetWorldY());
	}

	//바닥 충돌
	if(Hero->GetWorldY() > 443) {
		Hero->SetAir(false);
		Hero->MoveTo(Hero->GetWorldX(), 443);
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
	if( Hero->GetWorldX() > MapWidth - 75 ) {
		Hero->MoveTo(MapWidth - 75, Hero->GetWorldY());
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
		CScene* temp = CSceneManager::GetSceneManager()->getScene(31);
		if(temp == NULL) {
			return;
		}
		temp->Open();
	}
}

void CScene_Stage1_3::Render()
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

void CScene_Stage1_3::Control()
{
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