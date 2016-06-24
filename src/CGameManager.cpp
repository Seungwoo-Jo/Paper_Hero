#include "CGameManager.h"
#include "CObjectManager.h"
#include "CScene_Start.h"
#include <ctime>

CGameManager::CGameManager()
{
	FPS = 0.0f;
	frameCount = 0;
	timeElapsed = 0.0f;
	lastTime = GetNowCount();
	MouseX = 0;
	MouseY = 0;
	m_Scene = NULL;
}

CGameManager::~CGameManager()
{
}

void CGameManager::Init()
{
	SetDrawMode(DX_DRAWMODE_BILINEAR);
	//SetDrawMode(DX_DRAWMODE_NEAREST);
	m_Scene = CSceneManager::GetSceneManager()->getScene(0);
	m_Scene->Open();
}

void CGameManager::Destroy()
{
	// map���� �� ��ü�� delete �������
}

void CGameManager::Update()
{
	/*
	if(RunAfterTimeElapsed(0.05f))
	{
		clsDx();

		printfDx(" Frame per Second: %d\n", (int)FPS);
		CObjectManager::GetObjectManager()->NumberOfObjects();
		GetMousePoint(&MouseX, &MouseY);
		printfDx(" Mouse Point : %d, %d\n", MouseX, MouseY);
	}
	*/
	CScene::GetNowScene()->Update();
}

void CGameManager::Render()
{
	CScene::GetNowScene()->Render();
}

void CGameManager::Control()
{
	CScene::GetNowScene()->Control();
}

bool CGameManager::RunAfterTimeElapsed(double time)
{
	DWORD curTime = GetNowCount();					// ���� �ð�
	double timeDelta = (curTime - lastTime)*0.001f;	// timeDelta(1�������� �帥 �ð�) 1�ʴ����� �ٲ��ش�.
	timeElapsed += timeDelta; 
	bool result = false;

	frameCount++;

	if( timeElapsed >= time )	// �帥�ð��� time �̻��̸� true ��ȯ
	{
		FPS = (double)frameCount/timeElapsed;
		frameCount = 0;
		timeElapsed = 0.0f;
		result = true;
	}
	lastTime = curTime;

	return result;
}