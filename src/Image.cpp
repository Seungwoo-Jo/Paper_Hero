#include "Qusy.h"

int WindowWidth = 1024;
int WindowHeight = 768;
float AspectRatio = (float)WindowHeight / (float)WindowWidth;

int Qusy::DrawImage2D(int GHandle, float fDrawX, float fDrawY, bool Turn) {
	return DrawGraphF(fDrawX, fDrawY, GHandle, TRUE);
}

int Qusy::DrawImage2D(int GHandle, float fDrawX, float fDrawY, int fSrcX, int fSrcY, int Width, int Height, bool bTurn) {
	return DrawRectGraphF(fDrawX, fDrawY, fSrcX, fSrcY, Width, Height, GHandle, TRUE, bTurn);
}

int Qusy::DrawImage3D(int GHandle, VECTOR VDraw, bool bTurn)
{
	VERTEX3D vertex[6];

	int X, Y;
	GetGraphSize(GHandle, &X, &Y);

	float TexU[2];
	float TexV[2];
	float AspectCalc = Y * (1/AspectRatio);

	if(!bTurn) {
		TexU[0] = 0.0f;
		TexV[0] = 0.0f;
		TexU[1] = 1.0f;
		TexV[1] = 1.0f;
	}
	else {
		TexU[0] = 1.0f;
		TexV[0] = 0.0f;
		TexU[1] = 0.0f;
		TexV[1] = 1.0f;
	}

	vertex[0].pos = VGet(VDraw.x, VDraw.y, VDraw.z);
	vertex[0].dif = GetColorU8(255, 255, 255, 255);
	vertex[0].u = TexU[0];
	vertex[0].v = TexV[0];

	vertex[1].pos = VGet(VDraw.x+X, VDraw.y, VDraw.z);
	vertex[1].dif = GetColorU8(255, 255, 255, 255);
	vertex[1].u = TexU[1];
	vertex[1].v = TexV[0];

	vertex[2].pos = VGet(VDraw.x, VDraw.y-AspectCalc, VDraw.z);
	vertex[2].dif = GetColorU8(255, 255, 255, 255);
	vertex[2].u = TexU[0];
	vertex[2].v = TexV[1];

	vertex[3].pos = VGet(VDraw.x+X, VDraw.y, VDraw.z);
	vertex[3].dif = GetColorU8(255, 255, 255, 255);
	vertex[3].u = TexU[1];
	vertex[3].v = TexV[0];

	vertex[4].pos = VGet(VDraw.x, VDraw.y-AspectCalc, VDraw.z);
	vertex[4].dif = GetColorU8(255, 255, 255, 255);
	vertex[4].u = TexU[0];
	vertex[4].v = TexV[1];

	vertex[5].pos = VGet(VDraw.x+X, VDraw.y-AspectCalc, VDraw.z);
	vertex[5].dif = GetColorU8(255, 255, 255, 255);
	vertex[5].u = TexU[1];
	vertex[5].v = TexV[1];

	return DrawPolygon3D(vertex, 2, GHandle, TRUE);
}

int Qusy::DrawImage3D(int GHandle, VECTOR VDraw, float fSrcX, float fSrcY, float Width, float Height, bool bTurn)
{
	VERTEX3D vertex[6];

	int X, Y;
	GetGraphSize(GHandle, &X, &Y);

	float TexU[2];
	float TexV[2];
	float AspectCalc = Height * (1/AspectRatio);

	if(!bTurn) {
		TexU[0] = fSrcX/X;
		TexV[0] = fSrcY/Y;
		TexU[1] = (fSrcX+Width)/X;
		TexV[1] = (fSrcY+Height)/Y;
	}
	else {
		TexU[0] = (fSrcX+Width)/X;
		TexV[0] = fSrcY/Y;
		TexU[1] = fSrcX/X;
		TexV[1] = (fSrcY+Height)/Y;
	}

	vertex[0].pos = VGet(VDraw.x, VDraw.y, VDraw.z);
	vertex[0].dif = GetColorU8(255, 255, 255, 255);
	vertex[0].u = TexU[0];
	vertex[0].v = TexV[0];

	vertex[1].pos = VGet(VDraw.x+Width, VDraw.y, VDraw.z);
	vertex[1].dif = GetColorU8(255, 255, 255, 255);
	vertex[1].u = TexU[1];
	vertex[1].v = TexV[0];

	vertex[2].pos = VGet(VDraw.x, VDraw.y-AspectCalc, VDraw.z);
	vertex[2].dif = GetColorU8(255, 255, 255, 255);
	vertex[2].u = TexU[0];
	vertex[2].v = TexV[1];

	vertex[3].pos = VGet(VDraw.x+Width, VDraw.y, VDraw.z);
	vertex[3].dif = GetColorU8(255, 255, 255, 255);
	vertex[3].u = TexU[1];
	vertex[3].v = TexV[0];

	vertex[4].pos = VGet(VDraw.x, VDraw.y-AspectCalc, VDraw.z);
	vertex[4].dif = GetColorU8(255, 255, 255, 255);
	vertex[4].u = TexU[0];
	vertex[4].v = TexV[1];

	vertex[5].pos = VGet(VDraw.x+Width, VDraw.y-AspectCalc, VDraw.z);
	vertex[5].dif = GetColorU8(255, 255, 255, 255);
	vertex[5].u = TexU[1];
	vertex[5].v = TexV[1];

	return DrawPolygon3D(vertex, 2, GHandle, TRUE);
}
