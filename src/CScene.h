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

	static CScene* GetNowScene();	// ���� �� ���

	virtual void Open();	// �� ���� ������ �� ���� �ʱ�ȭ�κ�
	virtual void Close();	// �� ���� ���� �� ���� �κ�
	
	virtual CObject* SendHero();

	virtual void Update();	// ������Ʈ ���� �۾���
	virtual void Render();	// ������Ʈ �׸���
	virtual void Control();	// Ŀ�ǵ� �Է¹ޱ�...? �ʰ����� �������� �ϳ�
};



#endif