#ifndef __CSCENE_STAGE1_1__
#define __CSCENE_STAGE1_1__

#include "CScene.h"
#include "CGameManager.h"
#include "CGlobal.h"
#include "CSound.h"


class CScene_Stage1_1 : public CScene
{
private:
	CObject* Background;
	CObject* Enemy;
	CObject* Enemy2;
	CObject* Hero;
	CObject* Appletree[3];
	CObject* Wanted;
	CObject* Activetree;
	CObject* Trees[5];
	CObject* Interface;
	CObject* Status;
	CObject* Skillwd;
	CObject* Chat;

	CSound* BackSound;

	int test[15];
	int testnum;
	int StoryFont;

	CGlobal* Func1;
	CGlobal* Func2;

	int StoryBoard;
	int StatusWdw;
	int StatusBtn;
	int StatusTwd;

	int DrawTime;
	int Hero_Knockback;
	bool b_NextMap;
	bool b_Status;
	bool b_Skillwd;
	bool b_Escape;

	bool b_script[5];

public:
	CScene_Stage1_1();
	~CScene_Stage1_1();

	virtual void Open();	// 이 씬이 열렸을 때 해줄 초기화부분
	virtual void Close();	// 이 씬이 닫힐 때 해줄 부분
	
	virtual CObject* SendHero();

	virtual void Update();	// 오브젝트 관련 작업들
	virtual void Render();	// 오브젝트 그리기
	virtual void Control();	// 커맨드 입력받기...?

};

#endif