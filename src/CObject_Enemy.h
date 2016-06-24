#ifndef __COBJECT_ENEMY__
#define __COBJECT_ENEMY__

#include "CObject.h"
#include "CSprite.h"
#include "CGlobal.h"

using namespace std;

class CObject_Enemy : public CObject
{
protected:
	CObject* HeroForEnemy;
	CGlobal* Func;
	int HitHandle;
	/*
	## Hero & Enemy 공통
	- Enemy마다 일정 위치에서 대기합니다.
	- 특수한 Enemy들은 짧은 거리를 Patrol하게 됩니다.
	- Hero는 Enemy를 Jump이외의 수단으로 넘어갈 수 없습니다.
	- Hero는 Enemy에게 공격 이외의 것이 BoundBox에 닿아도 피해를 입지 않습니다.
	- Hero는 Enemy의 공격을 방어할 수 있고 방어하게 되면 피해가 크게 감소됩니다.
	- Hero의 피격 무적시간은 없습니다. (But, 추후 논의 예정)
	- Hero의 공격은 Enemy의 공격에 의해 끊기게 됩니다.
	- Enemy의 공격 또한 마찬가지로 Hero의 공격에 의해 끊기게 됩니다.
	- Semi-Boss 이상급 Enemy에게는 Hero의 공격으로 경직이 일어나지 않습니다.
	- Hero의 일반공격은 아무리 많은 Enemy가 있어도 1개체만 맞게 됩니다.
	- Hero의 스킬공격은 스킬마다 다르게 판정될 것입니다. (고려해서 코딩 요망)

	## 선공 몬스터일 경우
	1. 인식범위에 Hero가 들어 올 경우
	- 해당 방향으로 걸어(뛰어)갑니다.

	2. 공격범위에 Hero가 들어 올 경우
	- 해당 방향으로 공격을 합니다.

	## 비선공 몬스터일 경우
	1. Enemy가 Hit상태가 될 경우
	- Hero의 방향을 찾습니다.
	- 해당방향으로 걸어(뛰어)갑니다.
	
	2. 공격범위에 Hero가 들어 올 경우
	- 위와 같습니다.

	## Link 관계가 있을 경우
	1. Link가 되어 있는 Enemy의 인식범위에 Hero가 들어 올 경우
	- 해당 Enemy를 포함 Link되어있는 모든 Enemy가 해당 방향으로 걸어(뛰어)갑니다.

	2. 공격범위에 Hero가 들어 올 경우
	- 위와 같습니다.
	*/

	int Center;				// Enemy의 중심
	
	int RecognizeRange;		// 히어로를 인식하는 범위
	int AttackRange;		// Enemy가 공격하는 범위
	//int PatrolRange;		// Enemy가 순찰(?!)하는 범위

	bool b_FirstAtk;		// 선공/비선공 분리

	int HP_Bar;
	int HP_Back;

public:
	CObject_Enemy();
	CObject_Enemy(int GHandle, double x, double y, int Width, int Height, unsigned int Type);	// 오브젝트의 위치 지정
	~CObject_Enemy();

	virtual void TakeObjectInfo(CObject* _object);

	/* 이하 각 서브클래스에서 구현 */
	virtual void Init();	// 변수들 초기화.
	virtual void Update();	// 변경사항 적용
	virtual void Render();	// DRAW!
	virtual void Control();	// 키 입력
};


#endif