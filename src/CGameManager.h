#ifndef __CGAMEMANAGER__
#define __CGAMEMANAGER__

#include "CSceneManager.h"
#include "DxLib.h"

class CGameManager
{
private:
	double FPS;
	DWORD frameCount;	// ������ ī��Ʈ��
	double timeElapsed;	// �帥 �ð�
	DWORD lastTime;		// ������ �ð�(temp����)
	int MouseX;			// ���콺 ��ǥ X
	int MouseY;			// ���콺 ��ǥ Y

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