#include "CObjectManager.h"
#include "CSceneManager.h"
#include "ResourceManager.h"

#include "CSprite.h"
#include "CCollision.h"

#include "CScene_Stage1_2.h"
#include "CObject_Background.h"
#include "CObject_Bg_Stage1_2.h"
#include "CObject_Hero.h"
#include "CObject_Minotaur.h"
#include "CObject_Minotaur_Boss.h"
#include "CObject_Tree.h"
#include "CObject_Bird.h"
#include "CObject_Interface.h"
#include "CObject_Status.h"
#include "CObject_Skillwd.h"
#include "CObject_Appletree.h"
#include "CObject_Wanted.h"

CScene_Stage1_2::CScene_Stage1_2()
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

CScene_Stage1_2::~CScene_Stage1_2()
{

}

void CScene_Stage1_2::Open()
{
	if(p_NowScene != NULL) {
		Hero = p_NowScene->SendHero();
		//CObjectManager::GetObjectManager()->RemoveObject(Hero);
		p_NowScene->Close();
	}
	p_NowScene = this;

	MapWidth = 5000;
	Background = NULL;

	Time = 3659;
	Bright = 255;

	CameraX = 0;
	CameraY = 0;

	Func1 = new CGlobal();
	Func2 = new CGlobal();
	EnemyNum = 0;
	b_Result = false;
	b_NextMap = false;
	b_Status = false;
	b_Skillwd = false;
	b_Escape = false;

	Font = CreateFontToHandle("나눔손글씨 펜", 45, 1, DX_FONTTYPE_ANTIALIASING_EDGE_8X8);

	
	AddResourceWithKey(IMAGE_STAGE1_2_BACKGROUND);
	AddResourceWithKey(IMAGE_STAGE1_2_FOREST);
	AddResourceWithKey(IMAGE_OBJECT_BIRD);
	AddResourceWithKey(IMAGE_STAGE_RESULT_BACKGROUND);
	AddResourceWithKey(IMAGE_STAGE_RESULT_EMPTYSTAR);
	AddResourceWithKey(IMAGE_STAGE_RESULT_STAR);

	Background =	new CObject_Bg_Stage1_2(IMAGE_STAGE1_2_BACKGROUND, 0, 15, MapWidth, 768, TYPE_BACKGRAPH);
	
	for(int i=0; i<9; i++)
	{
		if(i > 5) {
			Enemy[i] = new CObject_Minotaur(IMAGE_ENEMY_STAGE1_MINOTAUR, 1600+(150*i), 337, 250, 250, TYPE_ENEMY);
		}
		else if(i > 2) {
			Enemy[i] = new CObject_Minotaur(IMAGE_ENEMY_STAGE1_MINOTAUR, 2400+(150*i), 337, 250, 250, TYPE_ENEMY);
		}
		else {
			Enemy[i] = new CObject_Minotaur(IMAGE_ENEMY_STAGE1_MINOTAUR, 3600+(150*i), 337, 250, 250, TYPE_ENEMY);
		}
		Enemy[i]->TakeObjectInfo(Hero);
		Enemy[i]->SetBright(&Bright);
		Enemy[i]->SetCamera(&CameraX, &CameraY);
	}

	Hero->MoveTo(150, 373);
	Appletree[0] =	new CObject_Appletree(IMAGE_OBJECT_APPLETREE_STAND,	 648, 60, 358, 482, TYPE_MIDOBJ);
	Appletree[1] =	new CObject_Appletree(IMAGE_OBJECT_APPLETREE_STAND,	 830, 75, 358, 482, TYPE_MIDOBJ);
	Appletree[2] =	new CObject_Appletree(IMAGE_OBJECT_APPLETREE_STAND,	 1090, 65, 358, 482, TYPE_MIDOBJ);
	Appletree[3] =	new CObject_Appletree(IMAGE_OBJECT_APPLETREE_STAND,	 1150, 75, 358, 482, TYPE_MIDOBJ);
	Appletree[4] =	new CObject_Appletree(IMAGE_OBJECT_APPLETREE_STAND,	 1800, 70, 358, 482, TYPE_MIDOBJ);
	Appletree[5] =	new CObject_Appletree(IMAGE_OBJECT_APPLETREE_STAND,	 1950, 65, 358, 482, TYPE_MIDOBJ);
	Appletree[6] =	new CObject_Appletree(IMAGE_OBJECT_APPLETREE_STAND,	 2090, 85, 358, 482, TYPE_MIDOBJ);
	Bird		 =	new CObject_Bird(IMAGE_OBJECT_BIRD, 3500, 200, 60, 60, TYPE_MIDOBJ);
	Wanted[0]	 =	new CObject_Wanted(IMAGE_OBJECT_WANTED_2, 1000, 380, 423, 512, TYPE_ITEM);
	Wanted[1]	 =	new CObject_Wanted(IMAGE_OBJECT_WANTED_3, 2500, 280, 423, 512, TYPE_ITEM);
	Wanted[2]	 =	new CObject_Wanted(IMAGE_OBJECT_WANTED_4, 3500, 380, 423, 512, TYPE_ITEM);
	Interface	 =	new CObject_Interface(IMAGE_INTERFACE_STATUS, 20, 20, 287, 266, TYPE_INTERFACE);

	Background	->TakeObjectInfo(Hero);
	Appletree[0]->TakeObjectInfo(Hero);
	Appletree[1]->TakeObjectInfo(Hero);
	Appletree[2]->TakeObjectInfo(Hero);
	Appletree[3]->TakeObjectInfo(Hero);
	Appletree[4]->TakeObjectInfo(Hero);
	Appletree[5]->TakeObjectInfo(Hero);
	Appletree[6]->TakeObjectInfo(Hero);
	Bird		->TakeObjectInfo(Hero);
	Wanted[0]	->TakeObjectInfo(Hero);
	Wanted[1]	->TakeObjectInfo(Hero);
	Wanted[2]	->TakeObjectInfo(Hero);
	Interface   ->TakeObjectInfo(Hero);

	Background	->SetCamera(&CameraX, &CameraY);
	Hero		->SetCamera(&CameraX, &CameraY);
	Appletree[0]->SetCamera(&CameraX, &CameraY);
	Appletree[1]->SetCamera(&CameraX, &CameraY);
	Appletree[2]->SetCamera(&CameraX, &CameraY);
	Appletree[3]->SetCamera(&CameraX, &CameraY);
	Appletree[4]->SetCamera(&CameraX, &CameraY);
	Appletree[5]->SetCamera(&CameraX, &CameraY);
	Appletree[6]->SetCamera(&CameraX, &CameraY);
	Bird		->SetCamera(&CameraX, &CameraY);
	Wanted[0]	->SetCamera(&CameraX, &CameraY);
	Wanted[1]	->SetCamera(&CameraX, &CameraY);
	Wanted[2]	->SetCamera(&CameraX, &CameraY);

	BackSound = new CSound(LoadSoundMem("Resource/Sound/Stage1_BGM.mp3"), 0);
	BackSound->SetVolume(100);

	DrawTime = -1;

	Wanted[0]	->SetOpacity(0);

	// 나중에는 정렬해야겠다 ;;
	CObjectManager::GetObjectManager()->AddObject(Background);
	
	CObjectManager::GetObjectManager()->AddObject(Appletree[0]);
	CObjectManager::GetObjectManager()->AddObject(Appletree[1]);
	CObjectManager::GetObjectManager()->AddObject(Appletree[2]);
	CObjectManager::GetObjectManager()->AddObject(Appletree[3]);
	CObjectManager::GetObjectManager()->AddObject(Appletree[4]);
	CObjectManager::GetObjectManager()->AddObject(Appletree[5]);
	CObjectManager::GetObjectManager()->AddObject(Appletree[6]);
	for(int i=0; i<9; i++) {
		CObjectManager::GetObjectManager()->AddObject(Enemy[i]);
	}
	CObjectManager::GetObjectManager()->AddObject(Wanted[0]);
	CObjectManager::GetObjectManager()->AddObject(Wanted[1]);
	CObjectManager::GetObjectManager()->AddObject(Wanted[2]);
	CObjectManager::GetObjectManager()->AddObject(Bird);
	CObjectManager::GetObjectManager()->AddObject(Interface);
}

void CScene_Stage1_2::Close()
{
	InitFontToHandle();
	delete BackSound;
	delete Func1;
	delete Func2;
	delete Background;
	for(int i=0; i<7; i++) {
		delete Appletree[i];
	}
	for(int i=0; i<9; i++) {
		delete Enemy[i];
	}
	for(int i=0; i<3; i++) {
		delete Wanted[i];
	}
	delete Bird;
	delete Interface;

	Func1 = NULL;
	Func2 = NULL;

	CameraX = 0;
	CameraY = 0;

	b_NextMap = false;
	b_Status = false;
	b_Skillwd = false;
	b_Escape = false;

	DelResourceWithKey(IMAGE_STAGE1_2_BACKGROUND);
	DelResourceWithKey(IMAGE_OBJECT_BIRD);

	DeleteGraph(SmokeHnd);

	CObjectManager::GetObjectManager()->RemoveObject(Background);
	
	CObjectManager::GetObjectManager()->RemoveObject(Appletree[0]);
	CObjectManager::GetObjectManager()->RemoveObject(Appletree[1]);
	CObjectManager::GetObjectManager()->RemoveObject(Appletree[2]);
	CObjectManager::GetObjectManager()->RemoveObject(Appletree[3]);
	CObjectManager::GetObjectManager()->RemoveObject(Appletree[4]);
	CObjectManager::GetObjectManager()->RemoveObject(Appletree[5]);
	CObjectManager::GetObjectManager()->RemoveObject(Appletree[6]);
	
	for(int i=0; i<9; i++) {
		CObjectManager::GetObjectManager()->RemoveObject(Enemy[i]);
	}
	
	CObjectManager::GetObjectManager()->RemoveObject(Wanted[0]);
	CObjectManager::GetObjectManager()->RemoveObject(Wanted[1]);
	CObjectManager::GetObjectManager()->RemoveObject(Wanted[2]);
	CObjectManager::GetObjectManager()->RemoveObject(Bird);
	CObjectManager::GetObjectManager()->RemoveObject(Interface);
}

CObject* CScene_Stage1_2::SendHero()
{
	return Hero;
}

void CScene_Stage1_2::Update()
{
	if(Time > 0) {
		Time--;
	}
	else {
		Time = 0;
	}

	BackSound->PlaySound();
	CObjectManager::GetObjectManager()->UpdateAllObject();	// 오브젝트 처리

	if(!b_CameraMode)
	{
		TempCameraX = CameraX;
		TempCameraY = CameraY;
		Background->MovePosInSrc(CameraX, CameraY);
		for(int i=0; i<9; i++) {
			Enemy[i]->MoveDrawPos(Enemy[i]->GetWorldX()-CameraX, Enemy[i]->GetWorldY()-CameraY);
		}
		Bird->MoveDrawPos(Bird->GetWorldX()-CameraX, Bird->GetWorldY()-CameraY);
		Hero->MoveDrawPos(Hero->GetWorldX()-CameraX, Hero->GetWorldY()-CameraY);
		Interface->MoveDrawPos(20.0f, 20.0f);
	}
	/*
	else
	{
		if(TempCameraX < 0) {
			TempCameraX = 0;
		}
		else if(TempCameraX > MapWidth - 1024) {
			TempCameraX = MapWidth - 1024;
		}
		Background->MovePosInSrc(TempCameraX, TempCameraY);
		Enemy->MoveDrawPos(Enemy->GetWorldX()-TempCameraX, Enemy->GetWorldY()-TempCameraY);
		for(int i=0; i<5; i++) {
			Trees[i]->MoveDrawPos(Trees[i]->GetWorldX()-TempCameraX, Trees[i]->GetWorldY()-TempCameraY);
		}
		Hero->MoveDrawPos(Hero->GetWorldX()-TempCameraX, Hero->GetWorldY()-TempCameraY);
	}
	*/

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
	for(int i=0; i<5; i++)
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
	/*
	// 결과 출력!!!
	if(!b_Result && Boss->GetHP() < 0)
	{
		for(int i=0; i<9; i++) {
			if(Enemy[i]->GetHP() < 0) {
				EnemyNum++;
			}
		}
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
	*/
	

	if(Hero->GetWorldX() > MapWidth - 350)
	{
		b_NextMap = true;
		Hero->MoveTo(0, Hero->GetWorldY());
		Hero->SetMove(false);
	}
	

	//바닥 충돌
	if(Hero->GetWorldY() > 373) {
		Hero->SetAir(false);
		Hero->MoveTo(Hero->GetWorldX(), 373);
	}
	/*
	if(b_Status) {
		BackSound->StopSound();
		Status->Update();
	}
	else if(b_Skillwd) {
		BackSound->StopSound();
		Skillwd->Update();
	}
	*/
	// 맵 양 끝 충돌
	if( Hero->GetWorldX() < -75){
		Hero->MoveTo(-75, Hero->GetWorldY());
	}
	if( Hero->GetWorldX() > MapWidth - 75 ) {
		Hero->MoveTo(MapWidth - 75, Hero->GetWorldY());
	}

	// 씬 전환
	if(b_NextMap)
	{
		b_NextMap = false;
		CScene* temp = CSceneManager::GetSceneManager()->getScene(3);
		if(temp == NULL) {
			return;
		}
		temp->Open();
	}
}

void CScene_Stage1_2::Render()
{
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
	SetDrawBright(Bright, Bright, Bright);
	
	if(b_Status || b_Skillwd)
	{
		if(b_Status) {
			Status->Render();
		}
		if(b_Skillwd) {
			Skillwd->Render();
		}
	}
	else
	{
		CObjectManager::GetObjectManager()->RenderAllObject();	// 오브젝트 처리
		
		int temp = 200-(Time/18);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
		SetDrawBright(255, 255, 255);
		
		/*
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
		else
		{
			//DrawFormatStringToHandle(400, 25, GetColor(250, 250-temp, 250-temp), Font, "남은 시간: %d초", Time/60);
		}
		*/

		SetDrawBright(Bright, Bright, Bright);

	}
}

void CScene_Stage1_2::Control()
{
	if(CheckHitKey(KEY_INPUT_0)) {
		b_NextMap = true;
	}
	/*
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
	*/
	//else
	//{
		CObjectManager::GetObjectManager()->ControlAllObject();	// 오브젝트 처리
	//}
}