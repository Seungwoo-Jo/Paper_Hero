#include "CObjectManager.h"
#include "CSceneManager.h"
#include "ResourceManager.h"

#include "CCollision.h"

#include "CScene_Stage4_4.h"
#include "CObject_Bg_stage4_4.h"
#include "CObject_Hero.h"

#include "CObject_Interface.h"
#include "CObject_Status.h"
#include "CObject_Skillwd.h"

#include "CObject_Chat.h"

CScene_Stage4_4::CScene_Stage4_4()
{
	Background = NULL;
	Hero = NULL;

	
}

CScene_Stage4_4::~CScene_Stage4_4()
{

}

void CScene_Stage4_4::Open()
{
	if(p_NowScene != NULL) {
		Hero = p_NowScene->SendHero();
		CObjectManager::GetObjectManager()->RemoveObject(Hero);
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

	AddResourceWithKey(IMAGE_STAGE4_4_BACKGROUND);

	Background = new CObject_Bg_Stage4_4(IMAGE_STAGE4_4_BACKGROUND,	0, 0, MapWidth, 768, TYPE_BACKGRAPH);
	Hero->MoveTo(200, 403);

	Interface =		new CObject_Interface(IMAGE_INTERFACE_STATUS, 20,  20, 287, 266, TYPE_INTERFACE);
	Status =		new CObject_Status(IMAGE_HERO, 0, 0, 0, 0, TYPE_MENU);
	Skillwd =		new CObject_Skillwd(IMAGE_HERO, 0, 0, 0, 0, TYPE_MENU);

	Background	->TakeObjectInfo(Hero);
	Interface   ->TakeObjectInfo(Hero);
	Status		->TakeObjectInfo(Hero);
	Skillwd		->TakeObjectInfo(Hero);

	Background	->SetCamera(&CameraX, &CameraY);
	Hero		->SetCamera(&CameraX, &CameraY);

	Hero->SetSkillList(Skillwd->GetSkillList());

	CObjectManager::GetObjectManager()->AddObject(Background);
	CObjectManager::GetObjectManager()->AddObject(Hero);
	CObjectManager::GetObjectManager()->AddObject(Interface);
}

void CScene_Stage4_4::Close()
{
	DelResourceWithKey(IMAGE_STAGE4_4_BACKGROUND);

	CObjectManager::GetObjectManager()->RemoveObject(Background);
	CObjectManager::GetObjectManager()->RemoveObject(Interface);
	delete Background;
}

CObject* CScene_Stage4_4::SendHero() {
	return Hero;
}

void CScene_Stage4_4::Update()
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
		CScene* temp = CSceneManager::GetSceneManager()->getScene(41);
		if(temp == NULL) {
			return;
		}
		temp->Open();
	}
}

void CScene_Stage4_4::Render()
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

void CScene_Stage4_4::Control()
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