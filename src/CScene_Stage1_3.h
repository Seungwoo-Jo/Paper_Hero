#ifndef __CSCENE_STAGE1_3__
#define __CSCENE_STAGE1_3__

#include "CScene.h"
#include "CGameManager.h"
#include "CGlobal.h"
#include "CSound.h"

class CScene_Stage1_3 : public CScene
{
private:
	CObject* Background;
	CObject* Hero;

	CObject* Object[23];
	CObject* Stair;

	CObject* Interface;
	CObject* Status;
	CObject* Skillwd;


	bool b_NextMap;
	bool b_Status;
	bool b_Skillwd;
	bool b_Escape;

public:
	CScene_Stage1_3();

	~CScene_Stage1_3();

	virtual void Open();	// 이 씬이 열렸을 때 해줄 초기화부분
	virtual void Close();	// 이 씬이 닫힐 때 해줄 부분
	
	virtual CObject* SendHero();

	virtual void Update();	// 오브젝트 관련 작업들
	virtual void Render();	// 오브젝트 그리기
	virtual void Control();	// 커맨드 입력받기...?

};

#endif