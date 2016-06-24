#ifndef __COBJECT__
#define __COBJECT__

#include "CSprite.h"

enum TYPE {
	TYPE_BACKGRAPH	= 0,	// ���	
	TYPE_BACKOBJ,			// ���� ������Ʈ
	TYPE_ITEM,				// ������
	TYPE_MIDOBJ,			// �߰� ������Ʈ
	TYPE_ENEMY,				// ����
	TYPE_HERO,				// ����	
	TYPE_SKILL,				// ��ų
	TYPE_FRONTOBJ,			// ���� ������Ʈ
	TYPE_INTERFACE,			// UI
	TYPE_MENU,				// �޴�
	TYPE_CHAT
};

struct SkillInfo
{
	int Tag;
	int GraphHandle;
	bool Enable;
	int SkillType;
	int UseMP;
};

class CObject
{
protected:
	/* �׷��� ���� ������ */
	int GraphHandle;	// �׷��� �ڵ�
	int Key;			// Key
	int SrcX;			// ǥ���� �׷����� �»�� x��ǥ
	int SrcY;			// ǥ���� �׷����� �»�� y��ǥ
	int Width;			// ǥ���� �׷����� ���α���
	int Height;			// ǥ���� �׷����� ���α���
	int* Bright;		// ǥ���� �׷����� ���
	int TempOpacity;
	int Opacity;		// ǥ���� �׷����� ������
	int* CameraX;		// ī�޶� X
	int* CameraY;		// ī�޶� Y
	int Font;

	/* ��� �� ���� ���� ������ */
	unsigned int ObjectType;	// ������Ʈ�� ���� (�׸��� ���� ������ ���� & ���� ������ ����)
	int WorldX;					// ����󿡼� ������Ʈ ��ġ �»�� x��ǥ
	int WorldY;					// ����󿡼� ������Ʈ ��ġ �»�� y��ǥ
	double fDrawX;				// ī�޶󿡼� ������Ʈ ��ġ �»�� x��ǥ
	double fDrawY;				// ī�޶󿡼� ������Ʈ ��ġ �»�� y��ǥ
	int BoundX;					// �ٿ��ڽ� �»�� x��ǥ
	int BoundY;					// �ٿ��ڽ� �»�� y��ǥ
	int BoundWidth;				// �ٿ��ڽ� ���� ����
	int BoundHeight;			// �ٿ��ڽ� ���� ����
	int AttackX;				// ���ݹڽ� �»�� x��ǥ
	int AttackY;				// ���ݹڽ� �»�� y��ǥ
	int AttackWidth;			// ���ݹڽ� ���� ����
	int AttackHeight;			// ���ݹڽ� ���� ����
	int SkillX;					// ��ų�ڽ� �»�� X��ǥ
	int SkillY;					// ��ų�ڽ� �»�� Y��ǥ
	int SkillWidth;				// ��ų�ڽ� ���� ����
	int SkillHeight;			// ��ų�ڽ� ���� ����
	
	bool b_left;
	bool b_right;

	/* ��ü ���� ���� ������ */
	bool b_Hit;			// �ǰ� ����
	bool b_Attack;		// Ÿ�� ����
	bool b_Guard;		// ��� ����
	bool b_GuardHit;	// ��� ���� ����
	bool b_Air;			// ����!
	bool b_Battle;		// ������� Ȱ��ȭ ����
	bool b_Move;		// ������ �� �ִ��� ������ üũ��
	int HP_Empty;		// HP�� ���� ��(�׾��� ��)
	int MP_Empty;		// MP�� ���� ��
	int SP_Empty;		// SP�� ���� ��

	/* �ɷ�ġ ���� ������ */
	float Stat_ST;		// ��
	float Stat_AR;		// ���
	float Stat_HP;		// ü��
	float Stat_MP;		// ����
	float Stat_SP;		// ������
	float Stat_EX;		// �ʿ� ����ġ
	float Stat_PT;		// ���� ����Ʈ

	int Level;			// ����
	float Damage;		// ������	= Stat_ST * 2
	float Armor;		// ����	= Stat_AR * ??
	float MaxHP;		// �ִ� HP	= Stat_HP * 20
	float MaxMP;		// �ִ� MP	= Stat_MP * 15
	float MaxSP;		// �ִ� SP	= Stat_SP * 10
	
	float HP;			// ���� HP
	float MP;			// ���� MP
	float SP;			// ���� SP
	float Speed;		// �ӵ�
	float Exp;			// ���� ����ġ
	
	SkillInfo* SkillList;

public:
	CObject();
	CObject(int GHandle, double x, double y, int Width, int Height, unsigned int Type);	// ������Ʈ�� ��ġ ����
	~CObject();

	// �̵����� �Լ�
	void MoveTo(int x, int y);				// World��ǥ��(x, y) ��ǥ�� �̵�
	void MoveDrawPos(double x, double y);	// Draw��ǥ�� (x, y)�� �̵�
	void MovePosInSrc(int x, int y);		// ���ҽ� �� �����ǥ �̵�
	void MoveToXSpeed(double x, double y, double speed);	// (x, y) ��ǥ�� speed ��ŭ �̵�. �����ϸ� ����

	// Get ���� �Լ�
	int GetGraphHandle();
	unsigned int GetType();
	int GetBright();
	int GetOpacity();
	int GetWorldX();
	int GetWorldY();
	double GetDrawX();
	double GetDrawY();
	int GetWidth();
	int GetHeight();
	int GetCameraX();
	int GetCameraY();

	int GetBoundX();
	int GetBoundY();
	int GetBoundWidth();
	int GetBoundHeight();

	int GetAttackX();
	int GetAttackY();
	int GetAttackWidth();
	int GetAttackHeight();

	int GetSkillX();
	int GetSkillY();
	int GetSkillWidth();
	int GetSkillHeight();

	int GetWay();

	bool GetHit();
	bool GetAttack();
	bool GetGuard();
	bool GetAir();
	bool GetBattle();
	bool GetMove();
	bool GetGuardHit();
	int GetHP_Empty();
	int GetMP_Empty();
	int GetSP_Empty();

	float GetStat_ST();
	float GetStat_AR();
	float GetStat_HP();
	float GetStat_MP();
	float GetStat_SP();
	float GetStat_EX();
	float GetStat_PT();

	int GetLvl();
	float GetDmg();
	float GetMaxHP();
	float GetMaxMP();
	float GetMaxSP();

	float GetHP();
	float GetMP();
	float GetSP();
	float GetSpd();
	float GetExp();

	SkillInfo* GetSkillList();

	// Set ���� �Լ�
	void SetGraphHandle(int GHandle);
	void SetBright(int* brt);	// ���������� ����
	void SetOpacity(int opct);
	void SetCamera(int* X, int* Y);

	void SetBoundBox(int _BoundX, int _BoundY, int _BoundWidth, int _BoundHeight);
	void SetAttackBox(int _AttackX, int _AttackY, int _AttackWidth, int _AttackHeight);
	void SetSkillBox(int _SkillX, int _SkillY, int _SkillWidth, int _SkillHeight);

	void SetHit(bool hit);
	void SetAttack(bool atk);
	void SetGuard(bool gd);
	void SetAir(bool ar);
	void SetBattle(bool bt);
	void SetMove(bool mv);
	void SetGuardHit(bool gh);
	void SetMP_Empty(int ct);
	void SetSP_Empty(int ct);
	
	void SetStat_ST(float st);
	void SetStat_AR(float ar);
	void SetStat_HP(float hp);
	void SetStat_MP(float mp);
	void SetStat_SP(float sp);
	void SetStat_EX(float ex);
	void SetStat_PT(float pt);

	void SetDmg(float dmg);

	void SetHP(float hp);
	void SetMP(float mp);
	void SetSP(float sp);
	void SetSpd(float spd);
	void SetExp(float exp);

	void SetSkillList(SkillInfo* _skilllist);

	// ��Ÿ �Լ�
	virtual void TakeObjectInfo(CObject* _object);	// 
	void Conversion();
	void DrawBoundBox();
	void DrawAttackBox();
	void DrawSkillBox();

	/* ���� �� ����Ŭ�������� ���� */
	virtual void Init();	// ������ �ʱ�ȭ.
	virtual void Update();	// ������� ����
	virtual void Render();	// DRAW!
	virtual void Control();	// Ű �Է�
};

#endif