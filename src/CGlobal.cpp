#include "CGlobal.h"

bool CGlobal::RunAfterTimeElapsed(double time)
{
	DWORD curTime = GetNowCount();					// 현재 시간
	double timeDelta = (curTime - lastTime)*0.001f;	// timeDelta(1번생성후 흐른 시간) 1초단위로 바꿔준다.
	timeElapsed += timeDelta; 
	bool result = false;

	if( timeElapsed >= time )	// 흐른시간이 time 이상이면 true 반환
	{
		timeElapsed = 0.0f;
		result = true;
	}
	lastTime = curTime;

	return result;
}

void CGlobal::DrawNum(int sx, int sy, int Num)
{
	int BeamWidth = 0;

	//Num이 십진수에서 몇 자리가 될지 조사
	for( int i = 10 ; Num >= i ; i *= 10 ) {
		BeamWidth ++ ;
	}
	//화면 왼쪽 위에 그래픽으로 묘화
	//x는 숫자 그래픽을 그려직사각형의 왼쪽 끝의 좌표입니다
	int x = BeamWidth * NUM_WIDTH ;	
	for( int i = 0 ; i <= BeamWidth ; i ++ )
	{
		//숫자의 묘화(투과 색 있음)
		//NumHandle배열에는 요소 번호 0에는 『 0』의 그래픽 식별 번호가
		//1에는 『 1』의 그래픽 식별 번호가 들어 있으므로,
		//DrawGraph(0 , 0 , NumHandle[0], TRUE)이라고 하면
		//『 0』의 그래픽을 묘화 할 수 있는 것을 잊지 않다
		DrawGraph( x+sx , sy , NumHandle[ Num % 10 ], TRUE ) ;

		//묘화 X좌표를 이동
		x -= NUM_WIDTH ;

		//가장 밑의 틀이 묘화가 끝났기 때문에 한 자리 내리
		Num /= 10 ;
	}
}