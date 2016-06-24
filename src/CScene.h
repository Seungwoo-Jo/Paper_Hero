#ifndef __CSCENE__
#define __CSCENE__


#include "CObject.h"

class CScene
{
protected:
	static CScene* p_NowScene;
	CObject* Temp;

	int Font;

	int MapWidth;

	int CameraX;
	int CameraY;
	int TempCameraX;
	int TempCameraY;

	bool b_CameraMode;

	int Bright;

	int Time;

public:
	CScene();
	~CScene();

	static CScene* GetNowScene();	// 현재 씬 취득

	virtual void Open();	// 이 씬이 열렸을 때 해줄 초기화부분
	virtual void Close();	// 이 씬이 닫힐 때 해줄 부분
	
	virtual CObject* SendHero();

	virtual void Update();	// 오브젝트 관련 작업들
	virtual void Render();	// 오브젝트 그리기
	virtual void Control();	// 커맨드 입력받기...? 맵같은거 움직여야 하나
};



#endif