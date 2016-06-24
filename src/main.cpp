#include "DxLib.h"
#include "Qusy.h"
#include "CGameManager.h"


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	hInstance = hInstance;
	hPrevInstance = hPrevInstance;
	lpCmdLine = lpCmdLine;
	nCmdShow = nCmdShow;

	// â���� ����(TRUE�� â���, FALSE�� ��üȭ��
	ChangeWindowMode(FALSE);
	
	SetFullScreenResolutionMode(DX_FSRESOLUTIONMODE_DESKTOP);
	SetFullSceneAntiAliasingMode(4, 3);

	// �ػ� ���� (1024x768 32bit)
	SetGraphMode(1024, 768, 32);
	
	SetWaitVSyncFlag(TRUE);
	SetWindowText("PAPER HERO");
	// ���̺귯�� �ʱ�ȭ
	if(DxLib_Init()==-1) {
		return-1;			// ������ �Ͼ�� ��� ����
	}

	CGameManager * Manager = new CGameManager();
	Manager->Init();

	SetDrawScreen(DX_SCREEN_BACK);

	VECTOR camera = {335.0f, -390.0f, -380.0f};
	SetUseLighting(TRUE);
	SetLightEnable(TRUE);
	ChangeLightTypeSpot(camera, VGet(0, 0, 1), QUSY_PI/1.25, QUSY_PI/2.5, 2500.0f, 0.65f, 0.0f, 0.0f);

	SetCameraPositionAndTargetAndUpVec(camera, VGet(camera.x,camera.y, camera.z+1), VGet(0,1,0));
	SetCameraNearFar(20.0f, 4096.0f);
	SetupCamera_Perspective(QUSY_PI/2.0f);

	while(ProcessMessage() != -1)
	{
		ClearDrawScreen();
		
		Manager->Update();	// ������Ʈ
		Manager->Render();	// ����
		Manager->Control();	// ��Ʈ��

		ScreenFlip();
	}

	delete Manager;

	// Ȥ�ö� �������� �׷��� ����
	InitGraph();

	// ���̺귯�� ��� ����
	DxLib_End();

	return 0;	//����
}