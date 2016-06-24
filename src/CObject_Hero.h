 #ifndef __COBJECT_HERO__
#define __COBJECT_HERO__

#include "CSound.h"
#include "CObject.h"
#include "CSprite.h"
#include <vector>
#include "CState_Stand.h"
#include "CGlobal.h"

using namespace std;

class CObject_Hero : public CObject
{
private:
	CState* State;
	CSprite* LevelUpSp;
	CSprite* BattleSp;
	CGlobal* Func1;
	CGlobal* Func2;
	CGlobal* Func3;
	CGlobal* Func4;
	CSound* BattleSound;
	CSound* LevelSound;

	int HeroEffectHandle;

	int LevelUp;
	int TurnCount;
	int HitCount;
	int BattleCount;

public:
	CObject_Hero();
	CObject_Hero(int GHandle, double x, double y, int Width, int Height, unsigned int Type);	// ������Ʈ�� ��ġ ����
	~CObject_Hero();

	/* ���� �� ����Ŭ�������� ���� */
	virtual void Init();	// ������ �ʱ�ȭ.
	virtual void Update();	// ������� ����
	virtual void Render();	// DRAW!
	virtual void Control();	// Ű �Է�
};


#endif