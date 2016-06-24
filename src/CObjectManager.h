#pragma once

#ifndef __COBJECTMANAGER__
#define __COBJECTMANAGER__

#include "CObject.h"
#include <list>

class CObjectManager
{
private:
	static CObjectManager* m_ObjectManager;
	std::list<CObject*> *ObjectList;
	CObjectManager();

	int RenderCount;

public:
	~CObjectManager();
	static CObjectManager* GetObjectManager()
	{
		if(m_ObjectManager == NULL)
			m_ObjectManager = new CObjectManager();
		return m_ObjectManager;
	}

	void AddObject(CObject* obj);
	void RemoveObject(CObject* obj);

	void UpdateAllObject();
	void RenderAllObject();
	void ControlAllObject();

	void RemoveAllObject();

	// µð¹ö±ë¿ë
	void NumberOfObjects();
};



#endif