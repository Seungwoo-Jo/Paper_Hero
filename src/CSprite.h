#ifndef __CSPRITE__
#define __CSPRITE__

#include <list>
#include "DxLib.h"

using namespace std;

class CSprite
{
private:
	int GHandle;	// ��������Ʈ�� �ִ� �׷��� �ڵ�
	int NumSprite;	// ��������Ʈ �׸� ����
	int SrcX;		// ��������Ʈ�� ���۵Ǵ� �κ��� �»�� X��ǥ
	int SrcY;		// ��������Ʈ�� ���۵Ǵ� �κ��� �»�� Y��ǥ
	int XNum;		// ��������Ʈ ���� ����
	int YNum;		// ��������Ʈ ���� ���� (������ 1)
	int Width;		// ��ü ���α���
	int Height;		// ��ü ���α���
	int SpriteX;	// �׷��ȿ��� ���� �׸� �»�� X��ǥ
	int SpriteY;	// �׷��ȿ��� ���� �׸� �»�� Y��ǥ
	int PieceSizeX;	// �� ������ ���α���	(������ Width / NumSprite)
	int PieceSizeY;	// �� ������ ���α���	(������ Height)
	
	int StartTime;	// 0
	int Delay;		// �� ��������Ʈ�� ����ϴ� �ð�
	int Count;		// ī��Ʈ
	
	float fAngle;

	int test[15];


	bool b_LRTurn;			// �¿���� ����
	int * LRGraphHandle;	// �¿���� �׷��� �����

	bool b_SpriteOn;		// ��������
	int Turning;

public:

	CSprite();
	CSprite( int _GHandle, int NumSprite, int SrcX, int SrcY, int XNum, int YNum, int Width, int Height, int Delay, bool LR );
	~CSprite();

	void SetCount(int count);		// ī��Ʈ ����!
	int GetCount();					// ���°�� �Ѹ��� �ִ°� ��ȯ	

	void SpriteSwitch( bool rp );	// ��������Ʈ �ִϸ��̼��� ���� ���� ����
	void SetDalay( int dly );		// ������ ����
	void SetTurning( int trn );

	// (sx, sy)�� ��������Ʈ �Ѹ�. bRp�� �ݺ����� ����, StopNum�� 
	int DrawSprite(int sx, int sy, bool b_SpriteOn = true, int StopNum = -1);
	int DrawTurnSprite(int sx, int sy, bool b_SpriteOn = true, int StopNum = -1);

	bool TurnAnimation(int sx, int sy, bool left, bool right, bool turn);
	bool ShadowAnimation(int sx, int sy);

};


#endif