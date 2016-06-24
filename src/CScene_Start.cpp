#include "CObjectManager.h"
#include "CSceneManager.h"
#include "ResourceManager.h"
#include "CObject_Hero.h"
#include "CObject_Enemy.h"
#include "CObject_Background.h"
#include "DxLib.h"

CScene_Start::CScene_Start()
{
	b_Stage1 = false;
}

CScene_Start::~CScene_Start()
{
	b_Stage1 = false;
}

void CScene_Start::Open()
{
	if(p_NowScene != NULL)
		p_NowScene->Close();

	p_NowScene = this;
	
	Count = 0;
	SageLogo = LoadGraph("Resource/intro/sage.png");
	GameTitle = LoadGraph("Resource/intro/bg_titlescreen_screen.png");
	TitleLogo = LoadGraph("Resource/intro/bg_titlescreen_text.png");
	
	Font = CreateFontToHandle("나눔고딕코딩", 25, 4, DX_FONTTYPE_ANTIALIASING_EDGE_8X8);
	BackSound = new CSound(LoadSoundMem("Resource/Sound/Start_BGM.mp3"), 0);
	BackSound->SetVolume(100);
	CObjectManager::GetObjectManager()->AddObject(new CObject_Background(LoadGraph("Resource/background_start.png"), 0, 0, 1024, 768, TYPE_BACKGRAPH));

}

void CScene_Start::Close()
{
	InitFontToHandle();
	DeleteGraph(SageLogo);
	DeleteGraph(GameTitle);
	DeleteGraph(TitleLogo);
	delete BackSound;
	CObjectManager::GetObjectManager()->RemoveAllObject();
}

void CScene_Start::Update()
{
	Count++;
	CObjectManager::GetObjectManager()->UpdateAllObject();	// 오브젝트 처리

	if(Count >= 200)
		BackSound->PlaySound();



	// 이하 기타 처리
	if(b_Stage1)
	{
		b_Stage1 = false;
		CScene* temp = CSceneManager::GetSceneManager()->getScene(1);
		if(temp == NULL) {
			return;
		}
		temp->Open();
	}
}
void CScene_Start::Render()
{
	if(Count >= 0 && Count < 120)
	{
		int temp = 	50+Count*2;
		if(temp >= 255)
			temp = 255;
		SetDrawBright(temp, temp, temp);
		DrawGraph(0, 0, SageLogo, TRUE);
	}
	else if(Count >= 120 && Count < 180)
	{
		SetDrawBright(255-(Count-120)*5, 255-(Count-120)*5, 255-(Count-120)*5);
		DrawGraph3D(512, 384, 0, SageLogo, FALSE);
	}
	else if(Count >= 180)
	{
		SetDrawBright(255, 255, 255);
		int temp = 	15+(Count-180)*4;
		if(temp >= 255)
			temp = 255;
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, temp);
		DrawGraph(0, 0, GameTitle, TRUE);
	}
	
	if(Count >= 240)
	{
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 15+(Count-240)*4 );
		DrawGraph(177, 100, TitleLogo, TRUE);
	}



	//CObjectManager::GetObjectManager()->RenderAllObject();	// 오브젝트 처리
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
	//DrawStringToHandle( 350, 700, "스페이스 바를 눌러주세요.", GetColor(255, 100, 255), Font);

	// 이하 기타 처리
}

void CScene_Start::Control()
{
	CObjectManager::GetObjectManager()->ControlAllObject();	// 오브젝트 처리

	// 이하 기타 처리
	if(CheckHitKey(KEY_INPUT_SPACE) == 1) {
		b_Stage1 = true;
		//printfDx("다음 화면으로\n");
	}

}