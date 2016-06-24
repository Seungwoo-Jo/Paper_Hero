#ifndef __CSPRITE__
#define __CSPRITE__

#include <list>
#include "DxLib.h"

using namespace std;

class CSprite
{
private:
	int GHandle;	// 스프라이트가 있는 그래픽 핸들
	int NumSprite;	// 스프라이트 그림 개수
	int SrcX;		// 스프라이트가 시작되는 부분의 좌상단 X좌표
	int SrcY;		// 스프라이트가 시작되는 부분의 좌상단 Y좌표
	int XNum;		// 스프라이트 가로 개수
	int YNum;		// 스프라이트 세로 개수 (보통은 1)
	int Width;		// 전체 가로길이
	int Height;		// 전체 세로길이
	int SpriteX;	// 그래픽에서 지금 그릴 좌상단 X좌표
	int SpriteY;	// 그래픽에서 지금 그릴 좌상단 Y좌표
	int PieceSizeX;	// 한 조각의 가로길이	(보통은 Width / NumSprite)
	int PieceSizeY;	// 한 조각의 세로길이	(보통은 Height)
	
	int StartTime;	// 0
	int Delay;		// 이 스프라이트를 출력하는 시간
	int Count;		// 카운트
	
	float fAngle;

	int test[15];


	bool b_LRTurn;			// 좌우반전 여부
	int * LRGraphHandle;	// 좌우반전 그래픽 저장용

	bool b_SpriteOn;		// 정지여부
	int Turning;

public:

	CSprite();
	CSprite( int _GHandle, int NumSprite, int SrcX, int SrcY, int XNum, int YNum, int Width, int Height, int Delay, bool LR );
	~CSprite();

	void SetCount(int count);		// 카운트 설정!
	int GetCount();					// 몇번째를 뿌리고 있는가 반환	

	void SpriteSwitch( bool rp );	// 스프라이트 애니메이션을 할지 여부 결정
	void SetDalay( int dly );		// 딜레이 조절
	void SetTurning( int trn );

	// (sx, sy)에 스프라이트 뿌림. bRp는 반복할지 여부, StopNum은 
	int DrawSprite(int sx, int sy, bool b_SpriteOn = true, int StopNum = -1);
	int DrawTurnSprite(int sx, int sy, bool b_SpriteOn = true, int StopNum = -1);

	bool TurnAnimation(int sx, int sy, bool left, bool right, bool turn);
	bool ShadowAnimation(int sx, int sy);

};


#endif