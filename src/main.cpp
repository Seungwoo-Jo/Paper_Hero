#include "DxLib.h"
#include "Qusy.h"
#include "CGameManager.h"


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	hInstance = hInstance;
	hPrevInstance = hPrevInstance;
	lpCmdLine = lpCmdLine;
	nCmdShow = nCmdShow;

	// 창모드로 변경(TRUE는 창모드, FALSE는 전체화면
	ChangeWindowMode(FALSE);
	
	SetFullScreenResolutionMode(DX_FSRESOLUTIONMODE_DESKTOP);
	SetFullSceneAntiAliasingMode(4, 3);

	// 해상도 조절 (1024x768 32bit)
	SetGraphMode(1024, 768, 32);
	
	SetWaitVSyncFlag(TRUE);
	SetWindowText("PAPER HERO");
	// 라이브러리 초기화
	if(DxLib_Init()==-1) {
		return-1;			// 에러가 일어나면 즉시 종료
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
		
		Manager->Update();	// 업데이트
		Manager->Render();	// 렌더
		Manager->Control();	// 컨트롤

		ScreenFlip();
	}

	delete Manager;

	// 혹시라도 남아있을 그래픽 삭제
	InitGraph();

	// 라이브러리 사용 종료
	DxLib_End();

	return 0;	//종료
}