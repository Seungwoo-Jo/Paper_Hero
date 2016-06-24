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

	int PlaySoundA();		// ����
	int CheckSound();		// ���� ��� üũ
	int StopSound();		// ���� ����
	int SetVolume(int Vol);	// �������� (0 ~ 100)
	int SetPan(int Pan);	// �¿� �뷱�� ���� (-100 ~ +100)

};

#endif