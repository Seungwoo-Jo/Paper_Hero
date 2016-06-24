#ifndef __CSCENE_STAGE5_4__
#define __CSCENE_STAGE5_4__

#include "CScene.h"
#include "CGameManager.h"
#include "CGlobal.h"
#include "CSound.h"

class CScene_Stage5_4 : public CScene
{
private:
	CObject* Background;
	CObject* Hero;

	CObject* Object[22];

	CObject* Interface;
	CObject* Status;
	CObject* Skillwd;


	bool b_NextMap;
	bool b_Status;
	bool b_Skillwd;
	bool b_Escape;

	bool b_Result;
	int DrawTime;

public:
	CScene_Stage5_4();
	~CScene_Stage5_4();

	virtual void Open();	// �� ���� ������ �� ���� �ʱ�ȭ�κ�
	virtual void Close();	// �� ���� ���� �� ���� �κ�
	
	virtual CObject* SendHero();

	virtual void Update();	// ������Ʈ ���� �۾���
	virtual void Render();	// ������Ʈ �׸���
	virtual void Control();	// Ŀ�ǵ� �Է¹ޱ�...?

};

#endif