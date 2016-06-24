#ifndef __CSCENE_STAGE4_3__
#define __CSCENE_STAGE4_3__

#include "CScene.h"
#include "CGameManager.h"
#include "CGlobal.h"
#include "CSound.h"

class CScene_Stage4_3 : public CScene
{
private:
	CObject* Background;
	CObject* Hero;

	CObject* Object[10];

	CObject* Interface;
	CObject* Status;
	CObject* Skillwd;


	bool b_NextMap;
	bool b_Status;
	bool b_Skillwd;
	bool b_Escape;

public:
	CScene_Stage4_3();
	~CScene_Stage4_3();

	virtual void Open();	// �� ���� ������ �� ���� �ʱ�ȭ�κ�
	virtual void Close();	// �� ���� ���� �� ���� �κ�
	
	virtual CObject* SendHero();

	virtual void Update();	// ������Ʈ ���� �۾���
	virtual void Render();	// ������Ʈ �׸���
	virtual void Control();	// Ŀ�ǵ� �Է¹ޱ�...?

};

#endif