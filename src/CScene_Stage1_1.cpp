#include "CObjectManager.h"
#include "CSceneManager.h"
#include "ResourceManager.h"

#include "CCollision.h"

#include "CScene_Stage1_1.h"
#include "CObject_Background.h"
#include "CObject_Hero.h"
#include "CObject_Minotaur.h"
#include "CObject_Cannon.h"
#include "CObject_Tree.h"
#include "CObject_Interface.h"
#include "CObject_Status.h"
#include "CObject_Skillwd.h"
#include "CObject_Appletree.h"
#include "CObject_Activetree.h"
#include "CObject_Wanted.h"
#include "CObject_Chat.h"

CScene_Stage1_1::CScene_Stage1_1()
{
	Background = NULL;
	Hero = NULL;

	Func1 = new CGlobal();
	Func2 = new CGlobal();

	b_NextMap = false;
	b_Status = false;
	b_Skillwd = false;
	b_Escape = false;
}

CScene_Stage1_1::~CScene_Stage1_1()
{

}

void CScene_Stage1_1::Open()
{
	if(p_NowScene != NULL) {
		p_NowScene->Close();
	}
	p_NowScene = this;
	
	MapWidth = 2048;
	Background = NULL;
	Hero = NULL;

	Time = 3659;
	Bright = 255;

	CameraX = 0;
	CameraY = 0;

	Func1 = new CGlobal();
	Func2 = new CGlobal();

	b_NextMap = false;
	b_Status = false;
	b_Skillwd = false;
	b_Escape = false;

	for(int i=0; i<5; i++) {
		b_script[i] = false;
	}

	Font = CreateFontToHandle("나눔손글씨 펜", 45, 1, DX_FONTTYPE_ANTIALIASING_EDGE_8X8);
	StoryFont = CreateFontToHandle("나눔손글씨 펜", 20, 1, DX_FONTTYPE_ANTIALIASING_EDGE_8X8);

	// 1-2 재사용 X
	AddResourceWithKey(IMAGE_STAGE1_1_BACKGROUND);

	// 1-2 재사용 O
	AddResourceWithKey(IMAGE_HERO);
	AddResourceWithKey(IMAGE_DEAD);
	AddResourceWithKey(IMAGE_HERO_EFFECT);
	AddResourceWithKey(IMAGE_HERO_GUARD);
	AddResourceWithKey(IMAGE_HERO_SKILL11);
	AddResourceWithKey(IMAGE_HERO_SKILL12);
	AddResourceWithKey(IMAGE_HERO_SKILL21);
	AddResourceWithKey(IMAGE_HERO_SKILL22);
	AddResourceWithKey(IMAGE_HERO_SKILL23);
	AddResourceWithKey(IMAGE_HERO_SKILL31);
	AddResourceWithKey(IMAGE_HERO_SKILL32);

	AddResourceWithKey(IMAGE_ENEMY_STAGE1_MINOTAUR);
	AddResourceWithKey(IMAGE_ENEMY_STAGE1_CANNON);
	AddResourceWithKey(IMAGE_ENEMY_HPBAR);
	AddResourceWithKey(IMAGE_ENEMY_HPBACK);
	AddResourceWithKey(IMAGE_ENEMY_EFFECT_HIT);
	AddResourceWithKey(IMAGE_ENEMY_EFFECT_BOOM);

	AddResourceWithKey(IMAGE_BARRACK_BACKGROUND);
	AddResourceWithKey(IMAGE_BARRACK_STATUS_WINDOW);
	AddResourceWithKey(IMAGE_BARRACK_STATUS_PLUSBTN);
	AddResourceWithKey(IMAGE_BARRACK_STATUS_STATSELECT);
	AddResourceWithKey(IMAGE_BARRACK_SKILL_WINDOW);
	AddResourceWithKey(IMAGE_BARRACK_SKILL_SKILLSELECT);
	AddResourceWithKey(IMAGE_BARRACK_SKILL_LVUPSELECT);
	AddResourceWithKey(IMAGE_BARRACK_SKILL_TYPESELECT);
	AddResourceWithKey(IMAGE_BARRACK_SKILL_SKILL);
	
	AddResourceWithKey(IMAGE_INTERFACE_STATUS);
	AddResourceWithKey(IMAGE_INTERFACE_SKILL);
	AddResourceWithKey(IMAGE_INTERFACE_FACE);
	AddResourceWithKey(IMAGE_INTERFACE_CHAT);
	AddResourceWithKey(IMAGE_INTERFACE_FACE_HERO);
	AddResourceWithKey(IMAGE_INTERFACE_FACE_PRINCESS);
	AddResourceWithKey(IMAGE_INTERFACE_ICON_SKILL11);
	AddResourceWithKey(IMAGE_INTERFACE_ICON_SKILL12);
	AddResourceWithKey(IMAGE_INTERFACE_ICON_SKILL21);
	AddResourceWithKey(IMAGE_INTERFACE_ICON_SKILL22);
	AddResourceWithKey(IMAGE_INTERFACE_ICON_SKILL23);
	AddResourceWithKey(IMAGE_INTERFACE_ICON_SKILL31);
	AddResourceWithKey(IMAGE_INTERFACE_ICON_SKILL32);

	AddResourceWithKey(IMAGE_OBJECT_APPLE);
	AddResourceWithKey(IMAGE_OBJECT_APPLE_BREAK);
	AddResourceWithKey(IMAGE_OBJECT_APPLE_BOOM);
	AddResourceWithKey(IMAGE_OBJECT_APPLETREE_STAND);
	AddResourceWithKey(IMAGE_OBJECT_APPLETREE_HIT);
	AddResourceWithKey(IMAGE_OBJECT_APPLETREE_DEAD);
	AddResourceWithKey(IMAGE_OBJECT_APPLETREE_POISON);
	AddResourceWithKey(IMAGE_OBJECT_ACTIVETREE_STAND);
	AddResourceWithKey(IMAGE_OBJECT_ACTIVETREE_HIT);
	AddResourceWithKey(IMAGE_OBJECT_ACTIVETREE_DEAD);
	AddResourceWithKey(IMAGE_OBJECT_WANTED);
	AddResourceWithKey(IMAGE_OBJECT_WANTED_1);
	AddResourceWithKey(IMAGE_OBJECT_WANTED_2);
	AddResourceWithKey(IMAGE_OBJECT_WANTED_3);
	AddResourceWithKey(IMAGE_OBJECT_WANTED_4);
	
	Background =	new CObject_Background(IMAGE_STAGE1_1_BACKGROUND,	0, 0, MapWidth, 768, TYPE_BACKGRAPH);
	Enemy =			new CObject_Minotaur(IMAGE_ENEMY_STAGE1_MINOTAUR,	1700, 337, 250, 250, TYPE_ENEMY);
	Enemy2 =		new CObject_Cannon(IMAGE_ENEMY_STAGE1_CANNON,		1200, 337, 250, 250, TYPE_ENEMY);
	Hero =			new CObject_Hero(IMAGE_HERO,						   0, 400, 200, 200, TYPE_HERO);
	Hero->MoveTo(0, 400);
	Appletree[0] =	new CObject_Appletree(IMAGE_OBJECT_APPLETREE_STAND,	 1800, 70, 358, 482, TYPE_MIDOBJ);
	Appletree[1] =	new CObject_Appletree(IMAGE_OBJECT_APPLETREE_STAND,	 1650, 55, 358, 482, TYPE_MIDOBJ);
	Appletree[2] =	new CObject_Appletree(IMAGE_OBJECT_APPLETREE_STAND,	 1485, 85, 358, 482, TYPE_MIDOBJ);
	Wanted =		new CObject_Wanted(IMAGE_OBJECT_WANTED_1,			 850, 280, 423, 512, TYPE_ITEM);
	Activetree =	new CObject_Activetree(IMAGE_OBJECT_ACTIVETREE_HIT,	 800, 200, 383, 554, TYPE_MIDOBJ);
	Interface =		new CObject_Interface(IMAGE_INTERFACE_STATUS,		  20,  20, 287, 266, TYPE_INTERFACE);
	Status =		new CObject_Status(IMAGE_HERO, 0, 0, 0, 0, TYPE_MENU);
	Skillwd =		new CObject_Skillwd(IMAGE_HERO, 0, 0, 0, 0, TYPE_MENU);
	Chat =			new CObject_Chat(SCRIPT_STAGE1_1_001, 700, 29, 967, 300, TYPE_CHAT);

	Background	->SetCamera(&CameraX, &CameraY);
	Enemy		->SetCamera(&CameraX, &CameraY);
	Enemy2		->SetCamera(&CameraX, &CameraY);
	Appletree[0]->SetCamera(&CameraX, &CameraY);
	Appletree[1]->SetCamera(&CameraX, &CameraY);
	Appletree[2]->SetCamera(&CameraX, &CameraY);
	Activetree	->SetCamera(&CameraX, &CameraY);
	Hero		->SetCamera(&CameraX, &CameraY);
	Wanted		->SetCamera(&CameraX, &CameraY);

	Interface	->TakeObjectInfo(Hero);
	Status		->TakeObjectInfo(Hero);
	Skillwd		->TakeObjectInfo(Hero);
	Enemy		->TakeObjectInfo(Hero);
	Enemy2		->TakeObjectInfo(Hero);
	Appletree[0]->TakeObjectInfo(Hero);
	Appletree[1]->TakeObjectInfo(Hero);
	Appletree[2]->TakeObjectInfo(Hero);
	Wanted		->TakeObjectInfo(Hero);
	Activetree	->TakeObjectInfo(Hero);

	Enemy->SetExp(100);
	Hero->SetSkillList(Skillwd->GetSkillList());


	BackSound = new CSound(LoadSoundMem("Resource/Sound/Stage1_BGM.mp3"), 0);
	BackSound->SetVolume(100);

	DrawTime = -1;

	CObjectManager::GetObjectManager()->AddObject(Background);
	
	CObjectManager::GetObjectManager()->AddObject(Appletree[1]);
	CObjectManager::GetObjectManager()->AddObject(Appletree[0]);
	CObjectManager::GetObjectManager()->AddObject(Appletree[2]);
	CObjectManager::GetObjectManager()->AddObject(Wanted);
	CObjectManager::GetObjectManager()->AddObject(Activetree);
	CObjectManager::GetObjectManager()->AddObject(Enemy);
	CObjectManager::GetObjectManager()->AddObject(Enemy2);
	
	CObjectManager::GetObjectManager()->AddObject(Hero);
	CObjectManager::GetObjectManager()->AddObject(Interface);
	CObjectManager::GetObjectManager()->AddObject(Chat);
}

void CScene_Stage1_1::Close()
{
	InitFontToHandle();
	delete BackSound;
	delete Func1;
	delete Func2;

	Func1 = NULL;
	Func2 = NULL;

	CameraX = 0;
	CameraY = 0;

	b_NextMap = false;
	b_Status = false;
	b_Skillwd = false;
	b_Escape = false;

	CObjectManager::GetObjectManager()->RemoveObject(Background);
	
	CObjectManager::GetObjectManager()->RemoveObject(Enemy);
	CObjectManager::GetObjectManager()->RemoveObject(Enemy2);
	CObjectManager::GetObjectManager()->RemoveObject(Appletree[0]);
	CObjectManager::GetObjectManager()->RemoveObject(Appletree[1]);
	CObjectManager::GetObjectManager()->RemoveObject(Appletree[2]);
	CObjectManager::GetObjectManager()->RemoveObject(Wanted);
	CObjectManager::GetObjectManager()->RemoveObject(Activetree);
	
	CObjectManager::GetObjectManager()->RemoveObject(Interface);
	CObjectManager::GetObjectManager()->RemoveObject(Chat);

	delete Background;
	delete Enemy;
	delete Enemy2;
	delete Appletree[0];
	delete Appletree[1];
	delete Appletree[2];
	delete Wanted;
	delete Activetree;
	delete Interface;


	DelResourceWithKey(IMAGE_STAGE1_1_BACKGROUND);
}

CObject* CScene_Stage1_1::SendHero()
{
	return Hero;
}

void CScene_Stage1_1::Update()
{
	BackSound->PlaySound();
	CObjectManager::GetObjectManager()->UpdateAllObject();	// 오브젝트 처리

	if(!b_CameraMode)
	{
		TempCameraX = CameraX;
		TempCameraY = CameraY;
		Background->MovePosInSrc(CameraX, CameraY);
		Enemy->MoveDrawPos(Enemy->GetWorldX()-CameraX, Enemy->GetWorldY()-CameraY);
		Enemy2->MoveDrawPos(Enemy2->GetWorldX()-CameraX, Enemy2->GetWorldY()-CameraY);
		for(int i=0; i<3; i++) {
			Appletree[i]->MoveDrawPos(Appletree[i]->GetWorldX()-CameraX, Appletree[i]->GetWorldY()-CameraY);
		}
		Wanted->MoveDrawPos(Wanted->GetWorldX()-CameraX, Wanted->GetWorldY()-CameraY);
		//Activetree->MoveDrawPos(Activetree->GetWorldX()-CameraX, Activetree->GetWorldY()-CameraY);
		Hero->MoveDrawPos(Hero->GetWorldX()-CameraX, Hero->GetWorldY()-CameraY);
		Interface->MoveDrawPos(20.0f, 20.0f);
	}
	/*	별도 카메라 조작시 필요한 코드
	else
	{
		if(TempCameraX < 0) {
			TempCameraX = 0;
		}
		else if(TempCameraX > MapWidth - 1024) {
			TempCameraX = MapWidth - 1024;
		}
		Background->MovePosInSrc(TempCameraX, TempCameraY);
		//Enemy->MoveDrawPos(Enemy->GetWorldX()-TempCameraX, Enemy->GetWorldY()-TempCameraY);
		for(int i=0; i<4; i++) {
			Trees[i]->MoveDrawPos(Trees[i]->GetWorldX()-TempCameraX, Trees[i]->GetWorldY()-TempCameraY);
		}
		Hero->MoveDrawPos(Hero->GetWorldX()-TempCameraX, Hero->GetWorldY()-TempCameraY);
	}
	*/

	if(b_script[2]) {
		if(Wanted->GetHP() <= 0) {
			Chat->SetGraphHandle(SCRIPT_STAGE1_1_004);
			Chat->Update();
			if(Chat->GetHP() <= 0) {
				b_script[3] = true;
			}
		}
	}
	else if(b_script[1]) {
		Chat->SetGraphHandle(SCRIPT_STAGE1_1_003);
		Chat->Update();
		if(Chat->GetHP() <= 0) {
			b_script[2] = true;
		}
	}
	else if(b_script[0]) {
		Chat->SetGraphHandle(SCRIPT_STAGE1_1_002);
		Chat->Update();
		if(Chat->GetHP() <= 0) {
			b_script[1] = true;
		}
	}
	else {
		Chat->SetGraphHandle(SCRIPT_STAGE1_1_001);
		Chat->Update();
		if(Chat->GetHP() <= 0) {
			b_script[0] = true;
		}
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

	/*
	// 오브젝트 투명도!
	for(int i=0; i<4; i++)
	{
		if(CCollision::GetCollision()->Box_n_Box(
			Hero->GetBoundX(), Hero->GetBoundY(), Hero->GetBoundX()+Hero->GetBoundWidth(), Hero->GetBoundY()+Hero->GetBoundHeight(),
			Trees[i]->GetBoundX(), Trees[i]->GetBoundY(), Trees[i]->GetBoundX()+Trees[i]->GetBoundWidth(), Trees[i]->GetBoundY()+Trees[i]->GetBoundHeight() ) )
		{
			Trees[i]->SetOpacity(132);
		}
		else
		{
			Trees[i]->SetOpacity(255);
		}
	}
	*/

	if(Hero->GetWorldX() > MapWidth - 200)
	{
		b_Status = true;
		Hero->MoveTo(0, Hero->GetWorldY());
		Hero->SetMove(false);
	}
	
	//바닥 충돌
	if(Hero->GetWorldY() > 373) {
		Hero->SetAir(false);
		Hero->MoveTo(Hero->GetWorldX(), 373);
	}

	if(b_Status) {
		BackSound->StopSound();
		Status->Update();
	}
	else if(b_Skillwd) {
		BackSound->StopSound();
		Skillwd->Update();
	}

	// 맵 양 끝 충돌
	if( Hero->GetWorldX() < -75){
		Hero->MoveTo(-75, Hero->GetWorldY());
	}
	if( Hero->GetWorldX() > MapWidth - 75 ) {
		Hero->MoveTo(MapWidth - 75, Hero->GetWorldY());
	}

	if( Enemy2->GetWorldX() < -200){
		Enemy2->MoveTo(-200, Enemy2->GetWorldY());
	}
	if( Enemy2->GetWorldX() > MapWidth - 200 ) {
		Enemy2->MoveTo(MapWidth - 200, Enemy2->GetWorldY());
	}

	// 씬 전환
	/*
	if(b_Escape)
	{
		b_Escape = false;
		CScene* temp = CSceneManager::GetSceneManager()->getScene(0);
		if(temp == NULL) {
			return;
		}
		temp->Open();
	}
	*/
	if(b_NextMap)
	{
		b_NextMap = false;
		CScene* temp = CSceneManager::GetSceneManager()->getScene(2);
		if(temp == NULL) {
			return;
		}
		temp->Open();
	}

	clsDx();
	//printfDx("%d %d %d\n", Hero->GetWorldX(), b_Status, b_Skillwd);
}

void CScene_Stage1_1::Render()
{
	if(b_Status) {
		Hero->SetBattle(false);
		Status->Render();
	}
	else if(b_Skillwd) {
		Skillwd->Render();
	}

	else
	{
		CObjectManager::GetObjectManager()->RenderAllObject();	// 오브젝트 처리

		if(Time > 0)
		{
			int temp = 200-(Time/18);
			SetDrawBright(255, 255, 255);
			//DrawFormatStringToHandle(400, 25, GetColor(250, 250-temp, 250-temp), Font, "남은 시간: %d초", Time/60);
		}

	}

}

void CScene_Stage1_1::Control()
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