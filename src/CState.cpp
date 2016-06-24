#include "CState.h"
#include "CState_Stand.h"
#include "CState_Move.h"
#include "CState_Jump.h"
#include "CState_Attack.h"
#include "CState_Guard.h"
#include "CState_Hit.h"
#include "CState_Enter.h"
#include "CState_Skill01.h"
#include "CState_Skill02.h"
#include "CState_Skill03.h"
#include "CState_Skill04.h"
#include "CState_Skill05.h"

CObject* CState::Master;
CGlobal* CState::Func;

CState* CState::prev;

CState* CState::Stand;
CState* CState::Move;
CState* CState::Jump;
CState* CState::Attack;
CState* CState::Guard;
CState* CState::Hit;
CState* CState::Enter;
CState* CState::Skill01;
CState* CState::Skill02;
CState* CState::Skill03;
CState* CState::Skill04;
CState* CState::Skill05;

bool CState::b_Left;
bool CState::b_Right;
bool CState::b_Turn;

CObject* CState::TempSkill;

CState::CState()
{
}

CState::~CState()
{
	delete Func;
	delete Stand;
	delete Move;
	delete Jump;
	delete Attack;
	delete Guard;
	delete Hit;
	delete Guard;
	delete Skill01;
	delete Skill02;
	delete Skill03;
	delete Skill04;
	delete Skill05;
	/*
	delete Skill06;
	delete Skill07;
	delete Skill08;
	delete Skill09;
	*/
}

CState* CState::Init(CObject* object)
{
	Master = object;
	Func = new CGlobal();

	prev = NULL;

	Stand = new CState_Stand();
	Move = new CState_Move();
	Jump = new CState_Jump();
	Attack = new CState_Attack();
	Guard = new CState_Guard();
	Hit = new CState_Hit();
	Enter = new CState_Enter();
	Skill01 = new CState_Skill01();
	Skill02 = new CState_Skill02();
	Skill03 = new CState_Skill03();
	Skill04 = new CState_Skill04();
	Skill05 = new CState_Skill05();

	TempSkill = NULL;

	DeleteGraph(Master->GetGraphHandle());

	b_Left = false;
	b_Right = true;

	b_Turn = false;

	HitNum = 0;
	HitMax = 0;

	return Stand;
}

int CState::GetWay()
{
	if(b_Right)
		return 1;
	else if(b_Left)
		return 0;
	else
		return -1;
}

CState* CState::Update()
{
	return NULL;
}

CState* CState::Render()
{
	return NULL;
}

CState* CState::Control()
{
	return NULL;
}