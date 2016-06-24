#ifndef __CGLOBAL__
#define __CGLOBAL__

#include "DxLib.h"

#define NUM_WIDTH	64
#define NUM_HEIGHT	64

class CGlobal
{
private:
	double timeElapsed;	// 흐른 시간
	DWORD lastTime;		// 마지막 시간(temp변수)
	int NumHandle[10];

public:
	CGlobal()
	{
		timeElapsed = 0.0f;
		lastTime = GetNowCount();

		for(int i=0; i<10; i++)
		{
			LoadDivGraph("Resource/Interface/dummy_num.png", 10, 10, 1, NUM_WIDTH, NUM_HEIGHT, NumHandle);
		}
	}

	~CGlobal()
	{
		for(int i=0; i<10; i++)	{
			DeleteGraph(NumHandle[i]);
		}
	}


	bool RunAfterTimeElapsed(double time);
	void DrawNum(int x, int y, int num);
};

#endif