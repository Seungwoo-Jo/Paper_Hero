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

	virtual void Open();	// �� ���� ������ �� ���� �ʱ�ȭ�κ�
	virtual void Close();	// �� ���� ���� �� ���� �κ�
	
	virtual void Update();	// ������Ʈ ���� �۾���
	virtual void Render();	// ������Ʈ �׸���
	virtual void Control();	// Ŀ�ǵ� �Է¹ޱ�...?
};

#endif