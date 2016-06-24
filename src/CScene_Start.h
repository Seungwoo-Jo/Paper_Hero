#ifndef __CSCENE_START__
#define __CSCENE_START__

#include "CScene.h"
#include "CSound.h"

class CScene_Start : public CScene
{
private:
	CSound* BackSound;
	bool b_Stage1;
	int temp;
	int Count;
	int SageLogo;
	int GameTitle;
	int TitleLogo;

public:
	CScene_Start();
	~CScene_Start();

	virtual void Open();	// 이 씬이 열렸을 때 해줄 초기화부분
	virtual void Close();	// 이 씬이 닫힐 때 해줄 부분
	
	virtual void Update();	// 오브젝트 관련 작업들
	virtual void Render();	// 오브젝트 그리기
	virtual void Control();	// 커맨드 입력받기...?
};

#endif