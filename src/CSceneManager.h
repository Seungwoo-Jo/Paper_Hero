#ifndef __CSCENEMANAGER__
#define __CSCENEMANAGER__

#include "CScene.h"
#include "CScene_Start.h"
#include <map>

class CSceneManager
{
private:
	static CSceneManager *m_SceneManager;	// �̱����� ���� 1
	std::map<int, CScene*> *m_SceneMap;		// �� ��ȣ, �� �ּ�
	CSceneManager();						// �̱����� ���� 2

public:
	~CSceneManager();
	static CSceneManager* GetSceneManager(void)
	{
		if(m_SceneManager == NULL)
			m_SceneManager = new CSceneManager();
		return m_SceneManager;
	}
	     
	bool AddScene(int SceneNum, CScene* pScene);
	void RemoveScene(int SceneNum);
	CScene* getScene(int SceneNum);
	void RemoveAllScene(void);
};

#endif