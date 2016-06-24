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
	## Hero & Enemy ����
	- Enemy���� ���� ��ġ���� ����մϴ�.
	- Ư���� Enemy���� ª�� �Ÿ��� Patrol�ϰ� �˴ϴ�.
	- Hero�� Enemy�� Jump�̿��� �������� �Ѿ �� �����ϴ�.
	- Hero�� Enemy���� ���� �̿��� ���� BoundBox�� ��Ƶ� ���ظ� ���� �ʽ��ϴ�.
	- Hero�� Enemy�� ������ ����� �� �ְ� ����ϰ� �Ǹ� ���ذ� ũ�� ���ҵ˴ϴ�.
	- Hero�� �ǰ� �����ð��� �����ϴ�. (But, ���� ���� ����)
	- Hero�� ������ Enemy�� ���ݿ� ���� ����� �˴ϴ�.
	- Enemy�� ���� ���� ���������� Hero�� ���ݿ� ���� ����� �˴ϴ�.
	- Semi-Boss �̻�� Enemy���Դ� Hero�� �������� ������ �Ͼ�� �ʽ��ϴ�.
	- Hero�� �Ϲݰ����� �ƹ��� ���� Enemy�� �־ 1��ü�� �°� �˴ϴ�.
	- Hero�� ��ų������ ��ų���� �ٸ��� ������ ���Դϴ�. (����ؼ� �ڵ� ���)

	## ���� ������ ���
	1. �νĹ����� Hero�� ��� �� ���
	- �ش� �������� �ɾ�(�پ�)���ϴ�.

	2. ���ݹ����� Hero�� ��� �� ���
	- �ش� �������� ������ �մϴ�.

	## �񼱰� ������ ���
	1. Enemy�� Hit���°� �� ���
	- Hero�� ������ ã���ϴ�.
	- �ش�������� �ɾ�(�پ�)���ϴ�.
	
	2. ���ݹ����� Hero�� ��� �� ���
	- ���� �����ϴ�.

	## Link ���谡 ���� ���
	1. Link�� �Ǿ� �ִ� Enemy�� �νĹ����� Hero�� ��� �� ���
	- �ش� Enemy�� ���� Link�Ǿ��ִ� ��� Enemy�� �ش� �������� �ɾ�(�پ�)���ϴ�.

	2. ���ݹ����� Hero�� ��� �� ���
	- ���� �����ϴ�.
	*/

	int Center;				// Enemy�� �߽�
	
	int RecognizeRange;		// ����θ� �ν��ϴ� ����
	int AttackRange;		// Enemy�� �����ϴ� ����
	//int PatrolRange;		// Enemy�� ����(?!)�ϴ� ����

	bool b_FirstAtk;		// ����/�񼱰� �и�

	int HP_Bar;
	int HP_Back;

public:
	CObject_Enemy();
	CObject_Enemy(int GHandle, double x, double y, int Width, int Height, unsigned int Type);	// ������Ʈ�� ��ġ ����
	~CObject_Enemy();

	virtual void TakeObjectInfo(CObject* _object);

	/* ���� �� ����Ŭ�������� ���� */
	virtual void Init();	// ������ �ʱ�ȭ.
	virtual void Update();	// ������� ����
	virtual void Render();	// DRAW!
	virtual void Control();	// Ű �Է�
};


#endif