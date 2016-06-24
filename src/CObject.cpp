#include "ResourceManager.h"
#include "CObject.h"
#include "DxLib.h"
#include <math.h>

CObject::CObject()
{
	fDrawX = 0;
	fDrawY = 0;
}

CObject::CObject(int GHandle, double x, double y, int Width, int Height, unsigned int Type)
{
	GraphHandle = ResourceManager::getResourceManager()->GetRes(GHandle);
	Key = GHandle;
	ObjectType = Type;
	SrcX = 0;
	SrcY = 0;
	this->Width = Width;
	this->Height = Height;
	Bright = NULL;
	TempOpacity = 255;
	Opacity = TempOpacity;

	WorldX = (int)x;
	WorldY = (int)y;
	fDrawX = x;
	fDrawY = y;

	CameraX = NULL;
	CameraY = NULL;

	BoundX = (int)x;
	BoundY = (int)y;
	BoundWidth = Width;
	BoundWidth = Height;

	AttackX = 0;
	AttackY = 0;
	AttackWidth = 0;
	AttackHeight = 0;

	b_left = false;
	b_right = true;

	b_Hit = false;
	b_Attack = false;
	b_Guard = false;
	b_Air = false;
	b_Battle = false;
	b_Move = true;

	Stat_ST = 0.0f;
	Stat_AR = 0.0f;
	Stat_HP = 0.0f;
	Stat_MP = 0.0f;
	Stat_SP = 0.0f;
	Stat_PT = 0.0f;

	MaxHP = 1.0f;
	MaxMP = 1.0f;
	MaxSP = 1.0f;

	Level = 1;
	HP = 1.0f;
	MP = 1.0f;
	SP = 1.0f;

	HP_Empty = -1;
	MP_Empty = -1;
	SP_Empty = -1;

	Speed = 1;
	Damage = 1;
	Exp = 0;

	SkillList = NULL;

	

	Font = -1;
}

CObject::~CObject()
{
	InitFontToHandle();
}

void CObject::MoveTo(int x, int y)
{
	WorldX = x;
	WorldY = y;
}

void CObject::MoveDrawPos(double X, double Y)	// 
{
	fDrawX = X;
	fDrawY = Y;
}

void CObject::MovePosInSrc(int x, int y)
{
	SrcX = x;
	SrcY = y;
}

void CObject::MoveToXSpeed(double x, double y, double speed)
{
	double _x = x - WorldX;
	double _y = y - WorldY;
	double Length = sqrt( (_x*_x) + (_y*_y) );

	double drawx = WorldX+((_x/Length) * speed);
	double drawy = WorldY+((_y/Length) * speed);

	if(drawx != x && drawy != y) {
		MoveTo((int)drawx, (int)drawy);
	}
}

int CObject::GetGraphHandle() {
	return GraphHandle;
}
unsigned int CObject::GetType() {
	return ObjectType;
}
int CObject::GetBright() {
	return *Bright;
}
int CObject::GetOpacity() {
	return Opacity;
}
int CObject::GetWorldX() {
	return WorldX;
}
int CObject::GetWorldY() {
	return WorldY;
}
double CObject::GetDrawX() {
	return fDrawX;
}
double CObject::GetDrawY() {
	return fDrawY;
}
int CObject::GetWidth() {
	return Width;
}
int CObject::GetHeight() {
	return Height;
}
int CObject::GetCameraX() {
	return *CameraX;
}
int CObject::GetCameraY() {
	return *CameraY;
}
int CObject::GetBoundX() {
	return BoundX;
}
int CObject::GetBoundY() {
	return BoundY;
}
int CObject::GetBoundWidth() {
	return BoundWidth;
}
int CObject::GetBoundHeight() {
	return BoundHeight;
}
int CObject::GetAttackX() {
	return AttackX;
}
int CObject::GetAttackY() {
	return AttackY;
}
int CObject::GetAttackWidth() {
	return AttackWidth;
}
int CObject::GetAttackHeight() {
	return AttackHeight;
}
int CObject::GetSkillX() {
	return SkillX;
}
int CObject::GetSkillY() {
	return SkillY;
}
int CObject::GetSkillWidth() {
	return SkillWidth;
}
int CObject::GetSkillHeight() {
	return SkillHeight;
}
int CObject::GetWay() {
	if(b_right)
		return 1;
	else if(b_left)
		return 0;
	else
		return -1;
}

bool CObject::GetHit() {
	return b_Hit;
}
bool CObject::GetAttack() {
	return b_Attack;
}
bool CObject::GetGuard() {
	return b_Guard;
}
bool CObject::GetAir() {
	return b_Air;
}
bool CObject::GetBattle() {
	return b_Battle;
}
bool CObject::GetMove() {
	return b_Move;
}
bool CObject::GetGuardHit() {
	return b_GuardHit;
}
int CObject::GetHP_Empty() {
	return HP_Empty;
}
int CObject::GetMP_Empty() {
	return MP_Empty;
}
int CObject::GetSP_Empty() {
	return SP_Empty;
}

float CObject::GetStat_ST() {
	return Stat_ST;
}
float CObject::GetStat_AR() {
	return Stat_AR;
}
float CObject::GetStat_HP() {
	return Stat_HP;
}
float CObject::GetStat_MP() {
	return Stat_MP;
}
float CObject::GetStat_SP() {
	return Stat_SP;
}
float CObject::GetStat_EX() {
	return Stat_EX;
}
float CObject::GetStat_PT() {
	return Stat_PT;
}

float CObject::GetMaxHP() {
	return MaxHP;
}
float CObject::GetMaxMP() {
	return MaxMP;
}
float CObject::GetMaxSP() {
	return MaxSP;
}

int CObject::GetLvl() {
	return Level;
}
float CObject::GetDmg() {
	return Damage;
}
float CObject::GetHP() {
	return HP;
}
float CObject::GetMP() {
	return MP;
}
float CObject::GetSP() {
	return SP;
}
float CObject::GetSpd() {
	return Speed;
}
float CObject::GetExp() {
	return Exp;
}

SkillInfo* CObject::GetSkillList() {
	return SkillList;
}

void CObject::SetGraphHandle(int GHandle)
{
	GraphHandle = GHandle;
}

// 밝기는 씬에 있는 수치로 통합관리!
void CObject::SetBright(int* brt) {
	Bright = brt;
}
void CObject::SetOpacity(int opct) {
	TempOpacity = opct;
}
void CObject::SetCamera(int* X, int* Y) {
	CameraX = X;
	CameraY = Y;
}
void CObject::SetBoundBox(int _BoundX, int _BoundY, int _BoundWidth, int _BoundHeight)
{
	BoundX = _BoundX;
	BoundY = _BoundY;
	BoundWidth = _BoundWidth;
	BoundHeight = _BoundHeight;
}
void CObject::SetAttackBox(int _AttackX, int _AttackY, int _AttackWidth, int _AttackHeight)
{
	AttackX = _AttackX;
	AttackY = _AttackY;
	AttackWidth = _AttackWidth;
	AttackHeight = _AttackHeight;
}
void CObject::SetSkillBox(int _SkillX, int _SkillY, int _SkillWidth, int _SkillHeight)
{
	SkillX = _SkillX;
	SkillY = _SkillY;
	SkillWidth = _SkillWidth;
	SkillHeight = _SkillHeight;
}

void CObject::SetHit(bool hit) {
	b_Hit = hit;
}
void CObject::SetAttack(bool atk) {
	b_Attack = atk;
}
void CObject::SetGuard(bool gd) {
	b_Guard = gd;
}
void CObject::SetAir(bool ar) {
	b_Air = ar;
}
void CObject::SetBattle(bool bt) {
	b_Battle = bt;
}
void CObject::SetMove(bool mv) {
	b_Move = mv;
}
void CObject::SetGuardHit(bool gh) {
	b_GuardHit = gh;
}
void CObject::SetMP_Empty(int ct) {
	MP_Empty = ct;
}
void CObject::SetSP_Empty(int ct) {
	SP_Empty = ct;
}

void CObject::SetStat_ST(float st) {
	Stat_ST = st;
}
void CObject::SetStat_AR(float ar) {
	Stat_AR = ar;
}
void CObject::SetStat_HP(float hp) {
	Stat_HP = hp;
}
void CObject::SetStat_MP(float mp) {
	Stat_MP = mp;
}
void CObject::SetStat_SP(float sp) {
	Stat_SP = sp;
}
void CObject::SetStat_EX(float ex) {
	Stat_EX = ex;
}
void CObject::SetStat_PT(float pt) {
	Stat_PT = pt;
}

void CObject::SetDmg(float dmg) {
	Damage = dmg;
}

void CObject::SetHP(float hp) {
	HP = hp;
}
void CObject::SetMP(float mp) {
	MP = mp;
}
void CObject::SetSP(float sp) {
	SP = sp;
}
void CObject::SetSpd(float spd) {
	Speed = spd;
}
void CObject::SetExp(float exp) {
	Exp = exp;
}

void CObject::SetSkillList(SkillInfo* _skilllist) {
	SkillList = _skilllist;
}

void CObject::TakeObjectInfo(CObject* _object) {
	// UI가 쓸거임. 거기서 만들어요. ㅂㅂ
	_object = _object;
}
void CObject::Conversion() {
	MoveDrawPos(this->GetWorldX()-(*CameraX), this->GetWorldY()-(*CameraY));
}
void CObject::DrawBoundBox() {
	DrawBox(BoundX, BoundY, BoundX+BoundWidth, BoundY+BoundHeight, GetColor(255,255,255), FALSE);
}
void CObject::DrawAttackBox() {
	DrawBox(AttackX, AttackY, AttackX+AttackWidth, AttackY+AttackHeight, GetColor(255,50,50), FALSE);
}
void CObject::DrawSkillBox() {
	DrawBox(SkillX, SkillY, SkillX+SkillWidth, SkillY+SkillHeight, GetColor(50,255,50), FALSE);
}

/* 나머지 함수들은 서브클래스에서 */

void CObject::Init() {
}

void CObject::Update() {
}

void CObject::Render() {
}

void CObject::Control() {
}