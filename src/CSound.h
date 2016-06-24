#ifndef __CSOUND__
#define __CSOUND__

class CSound
{
private:
	int SoundHandle;
	int Tag;

public:
	CSound();
	CSound(int SHandle, int Tag);
	~CSound();

	int PlaySoundA();		// 사운드
	int CheckSound();		// 사운드 재생 체크
	int StopSound();		// 사운드 정지
	int SetVolume(int Vol);	// 볼륨조절 (0 ~ 100)
	int SetPan(int Pan);	// 좌우 밸런스 조절 (-100 ~ +100)

};

#endif