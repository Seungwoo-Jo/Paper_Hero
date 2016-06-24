#ifndef __CSCENE_STAGE4_5__
#define __CSCENE_STAGE4_5__

#include "CScene.h"
#include "CGameManager.h"
#include "CGlobal.h"
#include "CSound.h"

class CScene_Stage4_5 : public CScene
{
private:
	CObject* Background;
	CObject* Hero;

	CObject* Stair;

	CObject* Interface;
	CObject* Status;
	CObject* Skillwd;


	bool b_NextMap;
	bool b_Status;
	bool b_Skillwd;
	bool b_Escape;

public:
	CScene_Stage4_5();
	~CScene_Stage4_5();

	virtual void Open();	// �� ���� ������ �� ���� �ʱ�ȭ�κ�
	virtual void Close();	// �� ���� ���� �� ���� �κ�
	
	virtual CObject* SendHero();

	virtual void Update();	// ������Ʈ ���� �۾���
	virtual void Render();	// ������Ʈ �׸���
	virtual void Control();	// Ŀ�ǵ� �Է¹ޱ�...?

};

#endif