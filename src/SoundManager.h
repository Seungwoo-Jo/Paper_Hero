#ifndef __CSOUND_MANAGER__
#define __CSOUND_MANAGER__

#include "CSound.h"
#include <map>

enum {
	SOUND_TITLE = 0,

	SOUND_HERO_WALK,
	SOUND_HERO_SLASH,
	SOUND_HERO_BATTLE
};

class SoundManager
{
private:
	static SoundManager* m_SoundManager;
	std::map<int, int>* m_SoundMap;
	SoundManager();

public:
	~SoundManager();
	static SoundManager* GetObjectManager()
	{
		if(m_SoundManager == NULL)
			m_SoundManager = new SoundManager();
		return m_SoundManager;
	}

	bool AddSound(int Key, int handle);
	bool AddSound(int Key, char* name);
	int GetSound(int Key);
	bool RemoveSound(int Key);

	int PlaySoundWithKey(int Key);
	int StopSoundWithKey(int Key);

	int RemoveAllSound();
};

#endif