#include "DxLib.h"
#include "CSound.h"

CSound::CSound()
{
}

CSound::CSound(int SHandle, int tag = 0)
{
	SoundHandle = SHandle;
	Tag = tag;
}

CSound::~CSound()
{
	DeleteSoundMem(SoundHandle);
}

int CSound::PlaySoundA()
{
	if(CheckSound() == 0)
		return PlaySoundMem(SoundHandle, DX_PLAYTYPE_BACK, TRUE);
	else
		return -1;
}

int CSound::CheckSound()
{
	return CheckSoundMem(SoundHandle);
}

int CSound::StopSound()
{
	return StopSoundMem(SoundHandle);
}

int CSound::SetVolume(int Vol)
{
	return ChangeVolumeSoundMem((int)(((float)Vol/100.0f)*255), SoundHandle);
}

int CSound::SetPan(int Pan)
{
	return ChangePanSoundMem((int)(((float)Pan/100.0f)*255), SoundHandle);
}