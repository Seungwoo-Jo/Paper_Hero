#include "SoundManager.h"
#include <algorithm>
#include "DxLib.h"

using namespace std;

SoundManager* SoundManager::m_SoundManager = NULL;

SoundManager::SoundManager()
{
}

SoundManager::~SoundManager()
{
}

bool SoundManager::AddSound(int Key, int handle)
{
	if(GetSound(Key) == -1) 
	{
		std::pair<std::map<int, int>::iterator, bool> result;
		result = m_SoundMap->insert(std::map<int, int>::value_type(Key, handle));
		//return result.second;
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

bool SoundManager::AddSound(int Key, char* name)
{
	if(GetSound(Key) == -1) 
	{
		std::pair<std::map<int, int>::iterator, bool> result;
		result = m_SoundMap->insert(std::map<int, int>::value_type(Key, LoadSoundMem(name)));
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}
int SoundManager::GetSound(int Key)
{
	std::map<int, int>::iterator it = m_SoundMap->find(Key);

	if( it != m_SoundMap->end() ) {
		return it->second;
	}
	else {
		return -1;
	}
}

bool SoundManager::RemoveSound(int Key)
{
	std::map<int, int>::iterator it = m_SoundMap->find(Key);
	
	if( it != m_SoundMap->end() ) {
		DeleteSoundMem(it->second);
		m_SoundMap->erase(it);
		return TRUE;
	}
	else {
		return FALSE;
	}
}

int SoundManager::PlaySoundWithKey(int Key)
{
	return PlaySoundMem(GetSound(Key), DX_PLAYTYPE_BACK);
}

int SoundManager::StopSoundWithKey(int Key)
{
	return StopSoundMem(GetSound(Key));
}

int SoundManager::RemoveAllSound()
{
	return InitSoundMem();
}