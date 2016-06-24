#ifndef __CSCENE_STAGE1_2__
#define __CSCENE_STAGE1_2__

#include "CScene.h"
#include "CGameManager.h"
#include "CGlobal.h"
#include "CSound.h"

class CScene_Stage1_2 : public CScene
{
private:
	CObject* Background;
	CObject* Enemy[9];
	CObject* Boss;
	CObject* Hero;
	CObject* Appletree[7];
	CObject* Trees[5];
	CObject* Bird;
	CObject* Interface;
	CObject* Status;
	CObject* Skillwd;
	CObject* Wanted[3];

	CSound* BackSound;

	CSprite* Smoke;

	CGlobal* Func1;
	CGlobal* Func2;
	int EnemyHandle;
	int BossHandle;
	int SmokeHnd;
	int TreesGraph[5];
	int StatusWdw;
	int StatusBtn;
	int StatusTwd;

	int DrawTime;
	int EnemyNum;
	bool b_Result;
	bool b_NextMap;
	bool b_Status;
	bool b_Skillwd;
	bool b_Escape;

public:
	CScene_Stage1_2();
	~CScene_Stage1_2();

	virtual void Open();	// �� ���� ������ �� ���� �ʱ�ȭ�κ�
	virtual void Close();	// �� ���� ���� �� ���� �κ�
	
	virtual CObject* SendHero();

	virtual void Update();	// ������Ʈ ���� �۾���
	virtual void Render();	// ������Ʈ �׸���
	virtual void Control();	// Ŀ�ǵ� �Է¹ޱ�...?

};

#endif