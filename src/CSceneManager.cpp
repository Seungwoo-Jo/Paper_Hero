#include "CSceneManager.h"
#include "CScene_Start.h"
#include "CScene_Stage1_1.h"
#include "CScene_Stage1_2.h"
#include "CScene_Stage1_3.h"
#include "CScene_Stage4_1.h"
#include "CScene_Stage4_2.h"
#include "CScene_Stage4_3.h"
#include "CScene_Stage4_4.h"
#include "CScene_Stage4_5.h"
#include "CScene_Stage5_4.h"


using std::map;

CSceneManager* CSceneManager::m_SceneManager = NULL;

CSceneManager::CSceneManager()
{
	m_SceneMap = new map<int, CScene*>();
}

CSceneManager::~CSceneManager()
{
	RemoveAllScene();
	delete m_SceneManager;
}

bool CSceneManager::AddScene(int SceneNum, CScene* pScene)
{
	std::pair<map<int, CScene*>::iterator, bool> result;
	result = m_SceneMap->insert( std::map<int, CScene*>::value_type(SceneNum, pScene));
	return result.second;
}

void CSceneManager::RemoveScene(int SceneNum)
{
	map<int, CScene*>::iterator it = m_SceneMap->find(SceneNum);
	
	if( it != m_SceneMap->end() )
	{
		m_SceneMap->erase(it);
	}
}

CScene* CSceneManager::getScene(int SceneNum)
{
	bool result = true;
	CScene* Scene = NULL;
	map<int, CScene*>::iterator it = m_SceneMap->find(SceneNum);

	if( it != m_SceneMap->end() ) {
		return it->second;
	}
	else {
		switch(SceneNum)
		{
		case 0:		// 시작화면
			Scene = new CScene_Start();
			result = AddScene(0, Scene);
			break;

		case 1:		// 스테이지 1-1
			Scene = new CScene_Stage1_1();
			result = AddScene(1, Scene);
			break;

		case 2:		// 스테이지 1-2
			Scene = new CScene_Stage1_2();
			result = AddScene(2, Scene);
			break;

		case 3:		// 스테이지 1-3
			Scene = new CScene_Stage1_3();
			result = AddScene(3, Scene);
			break;

		case 31:	// 스테이지 4-1
			Scene = new CScene_Stage4_1();
			result = AddScene(31, Scene);
			break;

		case 32:	// 스테이지 4-2
			Scene = new CScene_Stage4_2();
			result = AddScene(32, Scene);
			break;

		case 33:	// 스테이지 4-3
			Scene = new CScene_Stage4_3();
			result = AddScene(33, Scene);
			break;

		case 41:
			Scene = new CScene_Stage5_4();
			result = AddScene(41, Scene);
			break;
			/*
		case 35:	// 스테이지 4-5
			Scene = new CScene_Stage4_5();
			result = AddScene(35, Scene);
			break;
			*/
		case 200:	// 인트로
			
			
		default:
			result = false;
			break;
		}
	}

	if(result) {
		return Scene;
	}

	return NULL;
}

void CSceneManager::RemoveAllScene()
{
	m_SceneMap->clear();
}