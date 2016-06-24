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
	CObject_Hero(int GHandle, double x, double y, int Width, int Height, unsigned int Type);	// 오브젝트의 위치 지정
	~CObject_Hero();

	/* 이하 각 서브클래스에서 구현 */
	virtual void Init();	// 변수들 초기화.
	virtual void Update();	// 변경사항 적용
	virtual void Render();	// DRAW!
	virtual void Control();	// 키 입력
};


#endif