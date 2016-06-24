#include "CObjectManager.h"
#include <algorithm>

using namespace std;

CObjectManager* CObjectManager::m_ObjectManager = NULL;

CObjectManager::CObjectManager()
{
	ObjectList = new std::list<CObject*>;
	RenderCount = 0;
}

CObjectManager::~CObjectManager()
{
	RemoveAllObject();
	delete ObjectList;
	InitGraph();
	delete m_ObjectManager;
}

bool ObjectTypeSort(CObject* o1, CObject* o2)
{
	return o1->GetType() < o2->GetType();
}

void CObjectManager::AddObject(CObject* obj)
{
	if(obj != NULL) {
		ObjectList->push_back(obj);
		ObjectList->sort(ObjectTypeSort);
	}
}

void CObjectManager::RemoveObject(CObject* obj)
{
	if(obj != NULL)
	{
		list<CObject*>::iterator pos = find(ObjectList->begin(), ObjectList->end(), obj);
		ObjectList->erase(pos);
	}
}

void CObjectManager::UpdateAllObject()
{
	list<CObject*>::iterator pos = ObjectList->begin();
	//ObjectList->sort(ObjectTypeSort);
	for(pos = ObjectList->begin(); pos != ObjectList->end(); pos++)	{
		(*pos)->Update();
		if((*pos)->GetType() == TYPE_SKILL) {
			if((*pos)->GetHP() < 0) {
				//RemoveObject((*pos));
			}
		}
	}
}

void CObjectManager::RenderAllObject()
{
	RenderCount = 0;

	list<CObject*>::iterator pos = ObjectList->begin();
	for(pos = ObjectList->begin(); pos != ObjectList->end(); pos++)
	{
		//if( (*pos)->GetDrawX()+(*pos)->GetWidth() > 0 && (*pos)->GetDrawX() < 1024) {
			(*pos)->Render();
			//(*pos)->DrawBoundBox();
			//(*pos)->DrawAttackBox();
			//(*pos)->DrawSkillBox();
			//RenderCount++;
		//}
	}
}

void CObjectManager::ControlAllObject()
{
	list<CObject*>::iterator pos = ObjectList->begin();
	for(pos = ObjectList->begin(); pos != ObjectList->end(); pos++)	{
		(*pos)->Control();
	}
}

void CObjectManager::RemoveAllObject()
{
	list<CObject*>::iterator pos = ObjectList->begin();
	for(pos = ObjectList->begin(); pos != ObjectList->end(); pos++)	{
		delete (*pos);
	}

	ObjectList->clear();
}



// µð¹ö±ë¿ë
void CObjectManager::NumberOfObjects()
{
	printfDx(" Number of All Objects: %d\n", ObjectList->size());
	printfDx(" Number of Render Objects: %d\n", RenderCount);
}