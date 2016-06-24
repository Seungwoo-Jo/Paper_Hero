#ifndef __COBJECT_CHAT__
#define __COBJECT_CHAT__

#include "CObject.h"

enum
{
	FACE_NONE = 0,
	FACE_HERO,
	FACE_PRIN,
};

class CObject_Chat : public CObject
{
private:
	CHAR* name;
	CHAR* str1;
	CHAR* str2;
	CHAR* str3;

	int face;

	int SmallFont;
	int MidiumFont;
	int LargeFont;

	bool b_Script[10];

public:
	CObject_Chat();
	CObject_Chat(int GHandle, double x, double y, int Width, int Height, unsigned int Type);
	~CObject_Chat();
	
	virtual void Update();
	virtual void Render();
	virtual void Control();
};

#endif