#ifndef __RESOURCEMANAGER_H__
#define __RESOURCEMANAGER_H__

#include <map>

// 리소스 추가하려면 여기에 먼저 KEY를 쓰자!
enum
{
	IMAGE_HERO = 0,
	IMAGE_HERO_GUARD,
	IMAGE_HERO_EFFECT,
	IMAGE_HERO_SKILL11,	// 스탭
	IMAGE_HERO_SKILL12,	// 스피어
	IMAGE_HERO_SKILL21,	// 토네이도
	IMAGE_HERO_SKILL22,	// 물폭탄
	IMAGE_HERO_SKILL23,	// 소환!
	IMAGE_HERO_SKILL31,	// 메테오
	IMAGE_HERO_SKILL32,	// 썬더스톰

	IMAGE_DEAD,

	IMAGE_INTERFACE_STATUS,
	IMAGE_INTERFACE_SKILL,
	IMAGE_INTERFACE_FACE,
	IMAGE_INTERFACE_CHAT,

	IMAGE_INTERFACE_FACE_HERO,
	IMAGE_INTERFACE_FACE_PRINCESS,

	IMAGE_INTERFACE_ICON_SKILL11,
	IMAGE_INTERFACE_ICON_SKILL12,
	IMAGE_INTERFACE_ICON_SKILL21,
	IMAGE_INTERFACE_ICON_SKILL22,
	IMAGE_INTERFACE_ICON_SKILL23,
	IMAGE_INTERFACE_ICON_SKILL31,
	IMAGE_INTERFACE_ICON_SKILL32,

	IMAGE_NPC_01,
	IMAGE_NPC_02,
	IMAGE_NPC_03,
	IMAGE_NPC_04,
	IMAGE_NPC_05,
	IMAGE_NPC_06,
	IMAGE_NPC_07,
	IMAGE_NPC_08,
	IMAGE_NPC_09,
	IMAGE_NPC_10,
	IMAGE_NPC_11,
	IMAGE_NPC_12,
	IMAGE_NPC_13,

	IMAGE_BARRACK_BACKGROUND,
	IMAGE_BARRACK_STATUS_WINDOW,
	IMAGE_BARRACK_STATUS_PLUSBTN,
	IMAGE_BARRACK_STATUS_STATSELECT,
	IMAGE_BARRACK_SKILL_WINDOW,
	IMAGE_BARRACK_SKILL_SKILLSELECT,
	IMAGE_BARRACK_SKILL_LVUPSELECT,
	IMAGE_BARRACK_SKILL_TYPESELECT,
	IMAGE_BARRACK_SKILL_SKILL,

	IMAGE_ENEMY_HPBAR,
	IMAGE_ENEMY_HPBACK,
	IMAGE_ENEMY_STAGE1_MINOTAUR,
	IMAGE_ENEMY_STAGE1_MINOTAUR_BOSS,
	IMAGE_ENEMY_STAGE1_CANNON,
	IMAGE_ENEMY_STAGE4_MOLE,
	IMAGE_ENEMY_STAGE4_CARPET,
	IMAGE_ENEMY_STAGE4_SWORD,
	IMAGE_ENEMY_STAGE4_LAMP,
	IMAGE_ENEMY_STAGE4_LASER,
	IMAGE_ENEMY_STAGE5_HERO,
	IMAGE_ENEMY_EFFECT_HIT,
	IMAGE_ENEMY_EFFECT_BOOM,
	
	IMAGE_OBJECT_APPLE,
	IMAGE_OBJECT_APPLE_BREAK,
	IMAGE_OBJECT_APPLE_BOOM,
	IMAGE_OBJECT_APPLETREE_STAND,
	IMAGE_OBJECT_APPLETREE_POISON,
	IMAGE_OBJECT_APPLETREE_HIT,
	IMAGE_OBJECT_APPLETREE_DEAD,
	IMAGE_OBJECT_ACTIVETREE_STAND,
	IMAGE_OBJECT_ACTIVETREE_HIT,
	IMAGE_OBJECT_ACTIVETREE_DEAD,
	IMAGE_OBJECT_BIRD,
	IMAGE_OBJECT_WANTED,
	IMAGE_OBJECT_WANTED_1,
	IMAGE_OBJECT_WANTED_2,
	IMAGE_OBJECT_WANTED_3,
	IMAGE_OBJECT_WANTED_4,

	IMAGE_STAGE_RESULT_BACKGROUND,
	IMAGE_STAGE_RESULT_EMPTYSTAR,
	IMAGE_STAGE_RESULT_STAR,

	IMAGE_STAGE1_1_BACKGROUND,

	IMAGE_STAGE1_2_BACKGROUND,
	IMAGE_STAGE1_2_FOREST,
	
	IMAGE_STAGE1_3_BACKGROUND,

	IMAGE_STAGE4_1_BACKGROUND,

	IMAGE_STAGE4_2_BACKGROUND,

	IMAGE_STAGE4_3_BACKGROUND,

	IMAGE_STAGE4_4_BACKGROUND,

	IMAGE_STAGE4_5_BACKGROUND,

	IMAGE_STAGE5_4_BACKGROUND,

	SCRIPT_STAGE1_1_001,
	SCRIPT_STAGE1_1_002,
	SCRIPT_STAGE1_1_003,
	SCRIPT_STAGE1_1_004,
	SCRIPT_STAGE1_1_005,
	SCRIPT_STAGE1_1_TREE
};

class ResourceManager
{
private:
	static ResourceManager* m_ResMng;
	std::map<int, int>* m_ResMap;
	ResourceManager();

public:
	~ResourceManager();

	static ResourceManager* getResourceManager() {
		if(m_ResMng != NULL) {
			return m_ResMng;
		}
		else {
			m_ResMng = new ResourceManager();
			return m_ResMng;
		}
	}

	// AddRes #기능: 해당 Key에 리소스 추가 #반환: 성공: 1, 실패: 0
	bool AddRes(int Key, int Handle);
	bool AddRes(int Key, char* name);
	bool AddRes(int Key);

	// GetRes #기능: 리소스 Handle 반환 #반환: 해당 Key의 Handle
	int GetRes(int Key);

	// RemoveRes #기능: 해당 키 리소스 삭제 #반환 성공: 1 실패: 0
	bool RemoveRes(int Key);

};

bool AddResourceWithKey(int Key);
int GetResourceWithKey(int Key);
bool DelResourceWithKey(int Key);

#endif