#ifndef __COBJECT__
#define __COBJECT__

#include "CSprite.h"

enum TYPE {
	TYPE_BACKGRAPH	= 0,	// 배경	
	TYPE_BACKOBJ,			// 뒤쪽 오브젝트
	TYPE_ITEM,				// 아이템
	TYPE_MIDOBJ,			// 중간 오브젝트
	TYPE_ENEMY,				// 적들
	TYPE_HERO,				// 영웅	
	TYPE_SKILL,				// 스킬
	TYPE_FRONTOBJ,			// 앞쪽 오브젝트
	TYPE_INTERFACE,			// UI
	TYPE_MENU,				// 메뉴
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
	/* 그래픽 관련 변수들 */
	int GraphHandle;	// 그래픽 핸들
	int Key;			// Key
	int SrcX;			// 표시할 그래픽의 좌상단 x좌표
	int SrcY;			// 표시할 그래픽의 좌상단 y좌표
	int Width;			// 표시할 그래픽의 가로길이
	int Height;			// 표시할 그래픽의 세로길이
	int* Bright;		// 표시할 그래픽의 밝기
	int TempOpacity;
	int Opacity;		// 표시할 그래픽의 불투명도
	int* CameraX;		// 카메라 X
	int* CameraY;		// 카메라 Y
	int Font;

	/* 출력 및 판정 관련 변수들 */
	unsigned int ObjectType;	// 오브젝트의 종류 (그리는 순서 정렬을 위해 & 각종 판정을 위해)
	int WorldX;					// 월드상에서 오브젝트 위치 좌상단 x좌표
	int WorldY;					// 월드상에서 오브젝트 위치 좌상단 y좌표
	double fDrawX;				// 카메라에서 오브젝트 위치 좌상단 x좌표
	double fDrawY;				// 카메라에서 오브젝트 위치 좌상단 y좌표
	int BoundX;					// 바운드박스 좌상단 x좌표
	int BoundY;					// 바운드박스 좌상단 y좌표
	int BoundWidth;				// 바운드박스 가로 길이
	int BoundHeight;			// 바운드박스 세로 길이
	int AttackX;				// 공격박스 좌상단 x좌표
	int AttackY;				// 공격박스 좌상단 y좌표
	int AttackWidth;			// 공격박스 가로 길이
	int AttackHeight;			// 공격박스 세로 길이
	int SkillX;					// 스킬박스 좌상단 X좌표
	int SkillY;					// 스킬박스 좌상단 Y좌표
	int SkillWidth;				// 스킬박스 가로 길이
	int SkillHeight;			// 스킬박스 세로 길이
	
	bool b_left;
	bool b_right;

	/* 객체 상태 관련 변수들 */
	bool b_Hit;			// 피격 유무
	bool b_Attack;		// 타격 유무
	bool b_Guard;		// 방어 유무
	bool b_GuardHit;	// 방어 성공 유무
	bool b_Air;			// 공중!
	bool b_Battle;		// 전투모드 활성화 유무
	bool b_Move;		// 움직일 수 있는지 없는지 체크함
	int HP_Empty;		// HP가 없을 때(죽었을 때)
	int MP_Empty;		// MP가 없을 때
	int SP_Empty;		// SP가 없을 때

	/* 능력치 관련 변수들 */
	float Stat_ST;		// 힘
	float Stat_AR;		// 방어
	float Stat_HP;		// 체력
	float Stat_MP;		// 마나
	float Stat_SP;		// 지구력
	float Stat_EX;		// 필요 경험치
	float Stat_PT;		// 스탯 포인트

	int Level;			// 레벨
	float Damage;		// 데미지	= Stat_ST * 2
	float Armor;		// 방어력	= Stat_AR * ??
	float MaxHP;		// 최대 HP	= Stat_HP * 20
	float MaxMP;		// 최대 MP	= Stat_MP * 15
	float MaxSP;		// 최대 SP	= Stat_SP * 10
	
	float HP;			// 현재 HP
	float MP;			// 현재 MP
	float SP;			// 현재 SP
	float Speed;		// 속도
	float Exp;			// 현재 경험치
	
	SkillInfo* SkillList;

public:
	CObject();
	CObject(int GHandle, double x, double y, int Width, int Height, unsigned int Type);	// 오브젝트의 위치 지정
	~CObject();

	// 이동관련 함수
	void MoveTo(int x, int y);				// World좌표를(x, y) 좌표로 이동
	void MoveDrawPos(double x, double y);	// Draw좌표를 (x, y)로 이동
	void MovePosInSrc(int x, int y);		// 리소스 내 출력좌표 이동
	void MoveToXSpeed(double x, double y, double speed);	// (x, y) 좌표로 speed 만큼 이동. 도달하면 정지

	// Get 관련 함수
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

	// Set 관련 함수
	void SetGraphHandle(int GHandle);
	void SetBright(int* brt);	// 포인터임을 주의
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

	// 기타 함수
	virtual void TakeObjectInfo(CObject* _object);	// 
	void Conversion();
	void DrawBoundBox();
	void DrawAttackBox();
	void DrawSkillBox();

	/* 이하 각 서브클래스에서 구현 */
	virtual void Init();	// 변수들 초기화.
	virtual void Update();	// 변경사항 적용
	virtual void Render();	// DRAW!
	virtual void Control();	// 키 입력
};

#endif