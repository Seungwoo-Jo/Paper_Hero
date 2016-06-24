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

	virtual void Open();	// 이 씬이 열렸을 때 해줄 초기화부분
	virtual void Close();	// 이 씬이 닫힐 때 해줄 부분
	
	virtual CObject* SendHero();

	virtual void Update();	// 오브젝트 관련 작업들
	virtual void Render();	// 오브젝트 그리기
	virtual void Control();	// 커맨드 입력받기...?

};

#endif