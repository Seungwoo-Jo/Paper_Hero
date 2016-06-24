#ifndef __QUSY_H__
#define __QUSY_H__

#include "DxLib.h"

#define QUSY_PI		3.1415926535897f

namespace Qusy
{
	int SetResolution(int width, int height, int colordepth, int refreshrate);
	/*
	bool AddResWithKey(int Key);
	int GetResWithKey(int Key);
	bool DelResWithKey(int Key);
	*/
	int DrawImage2D(int GHandle, float fDrawX, float fDrawY, bool Turn);
	int DrawImage2D(int GHandle, float fDrawX, float fDrawY, int fSrcX, int fSrcY, int Width, int Height, bool bTrun);

	int DrawImage3D(int GHandle, VECTOR VDraw, bool bTurn);
	int DrawImage3D(int GHandle, VECTOR VDraw, float fSrcX, float fSrcY, float Width, float Height, bool bTurn);
}

#endif