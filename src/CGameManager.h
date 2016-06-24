#ifndef __CGAMEMANAGER__
#define __CGAMEMANAGER__

#include "CSceneManager.h"
#include "DxLib.h"

class CGameManager
{
private:
	double FPS;
	DWORD frameCount;	// 프레임 카운트수
	double timeElapsed;	// 흐른 시간
	DWORD lastTime;		// 마지막 시간(temp변수)
	int MouseX;			// 마우스 좌표 X
	int MouseY;			// 마우스 좌표 Y

	CScene* m_Scene;

public:
	CGameManager();
	~CGameManager();

	void Init();
	void Destroy();
	void Update();
	void Render();
	void Control();

	bool RunAfterTimeElapsed(double time);
};

#endif