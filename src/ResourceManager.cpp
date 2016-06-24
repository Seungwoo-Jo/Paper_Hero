#include "ResourceManager.h"
#include "DxLib.h"

ResourceManager* ResourceManager::m_ResMng = NULL;

ResourceManager::ResourceManager() {
	m_ResMap = new std::map<int, int>;
}

ResourceManager::~ResourceManager() {
	InitGraph();
	delete m_ResMap;
}

bool ResourceManager::AddRes(int Key, int Handle)
{
	if(GetRes(Key) == -1) 
	{
		std::pair<std::map<int, int>::iterator, bool> result;
		result = m_ResMap->insert(std::map<int, int>::value_type(Key, Handle));
		//return result.second;
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

bool ResourceManager::AddRes(int Key, char* name)
{
	if(GetRes(Key) == -1) 
	{
		std::pair<std::map<int, int>::iterator, bool> result;
		result = m_ResMap->insert(std::map<int, int>::value_type(Key, LoadGraph(name)));
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

bool ResourceManager::AddRes(int Key)
{
	char* name = NULL;

	if(GetRes(Key) == -1) 
	{
		switch(Key)
		{
		case IMAGE_HERO:						name = "Resource/hero.png";															break;
		case IMAGE_HERO_GUARD:					name = "Resource/Interface/effect_main_defense.png";								break;
		case IMAGE_HERO_EFFECT:					name = "Resource/Interface/hero-effect.png";										break;
		case IMAGE_HERO_SKILL11:				name = "Resource/Skill/effect_skill_stab.png";										break;
		case IMAGE_HERO_SKILL12:				name = "Resource/Skill/effect_skill_spear.png";										break;
		case IMAGE_HERO_SKILL21:				name = "Resource/Skill/effect_skill_tornado.png";									break;
		case IMAGE_HERO_SKILL22:				name = "Resource/Skill/effect_skill_water.png";										break;
		case IMAGE_HERO_SKILL23:				name = "Resource/Skill/effect_skill_summon.png";									break;
		case IMAGE_HERO_SKILL31:				name = "Resource/Skill/effect_skill_armageddon.png";								break;
		case IMAGE_HERO_SKILL32:				name = "Resource/skill/effect_skill_thunderstorm.png";								break;
		case IMAGE_DEAD:						name = "Resource/dead.png";															break;
		case IMAGE_INTERFACE_STATUS:			name = "Resource/Interface/status.png";												break;
		case IMAGE_INTERFACE_SKILL:				name = "Resource/Interface/skill_icon_back.png";									break;
		case IMAGE_INTERFACE_FACE:				name = "Resource/Interface/face/prop_exp_face.png";									break;
		case IMAGE_INTERFACE_CHAT:				name = "Resource/Interface/chat_window.png";										break;
		case IMAGE_INTERFACE_FACE_HERO:			name = "Resource/Interface/chat_hero.png";											break;
		case IMAGE_INTERFACE_FACE_PRINCESS:		name = "Resource/Interface/chat_princess.png";										break;

		case IMAGE_INTERFACE_ICON_SKILL11:		name = "Resource/Interface/skillwindow/icon_skill_stab.png";						break;
		case IMAGE_INTERFACE_ICON_SKILL12:		name = "Resource/Interface/skillwindow/icon_skill_spear.png";						break;
		case IMAGE_INTERFACE_ICON_SKILL21:		name = "Resource/Interface/skillwindow/icon_skill_tornado.png";						break;
		case IMAGE_INTERFACE_ICON_SKILL22:		name = "Resource/Interface/skillwindow/icon_skill_water.png";						break;
		case IMAGE_INTERFACE_ICON_SKILL23:		name = "Resource/Interface/skillwindow/icon_skill_summon.png";						break;
		case IMAGE_INTERFACE_ICON_SKILL31:		name = "Resource/Interface/skillwindow/icon_skill_meteor.png";						break;
		case IMAGE_INTERFACE_ICON_SKILL32:		name = "Resource/Interface/skillwindow/icon_skill_thunderstorm.png";				break;
		case IMAGE_BARRACK_BACKGROUND:			name = "Resource/barrack/bg_barracks.png";											break;
		case IMAGE_BARRACK_STATUS_WINDOW:		name = "Resource/Interface/status/bg_statwindow.png";								break;
		case IMAGE_BARRACK_STATUS_PLUSBTN:		name = "Resource/Interface/status/butt_statwindow_statup.png";						break;
		case IMAGE_BARRACK_STATUS_STATSELECT:	name = "Resource/Interface/status/butt_statwindow_levelup_choiceline.png";			break;
		case IMAGE_BARRACK_SKILL_WINDOW:		name = "Resource/Interface/skillwindow/bg_skillwindow.png";							break;
		case IMAGE_BARRACK_SKILL_SKILLSELECT:	name = "Resource/Interface/skillwindow/butt_skillwindow_skill_choiceline.png";		break;
		case IMAGE_BARRACK_SKILL_LVUPSELECT:	name = "Resource/Interface/skillwindow/butt_skillwindow_level_choiceline.png";		break;
		case IMAGE_BARRACK_SKILL_TYPESELECT:	name = "Resource/Interface/skillwindow/butt_skillwindow_attribute_choiceline.png";	break;
		case IMAGE_BARRACK_SKILL_SKILL:			name = "Resource/Interface/skillwindow/prop_skillwindow_skill.png";					break;
		case IMAGE_ENEMY_HPBAR:					name = "Resource/Monster/HP_Bar.png";												break;
		case IMAGE_ENEMY_HPBACK:				name = "Resource/Monster/HP_Back.png";												break;
		case IMAGE_ENEMY_STAGE1_MINOTAUR:		name = "Resource/Monster/stage1/stage1_minotaur.png";								break;
		case IMAGE_ENEMY_STAGE1_MINOTAUR_BOSS:	name = "Resource/Monster/stage1/stage1_minotaur_boss.png";							break;
		case IMAGE_ENEMY_STAGE1_CANNON:			name = "Resource/Monster/stage1/stage1_cannon.png";									break;
		case IMAGE_ENEMY_STAGE4_MOLE:			name = "Resource/Monster/stage4/stage4_mole.png";									break;
		case IMAGE_ENEMY_STAGE4_CARPET:			name = "Resource/Monster/stage4/stage4_carpet.png";									break;
		case IMAGE_ENEMY_STAGE4_SWORD:			name = "Resource/Monster/stage4/stage4_sword.png";									break;
		case IMAGE_ENEMY_STAGE4_LAMP:			name = "Resource/Monster/stage4/stage4_lamp.png";									break;
		case IMAGE_ENEMY_STAGE4_LASER:			name = "Resource/Monster/stage4/stage4_laser.png";									break;
		case IMAGE_ENEMY_STAGE5_HERO:			name = "Resource/Monster/hero.png";													break;
		case IMAGE_ENEMY_EFFECT_HIT:			name = "Resource/Skill/dummy_skill_01.png";											break;
		case IMAGE_ENEMY_EFFECT_BOOM:			name = "Resource/Monster/stage1/stage1_cannon_boom.png";							break;
		case IMAGE_STAGE_RESULT_BACKGROUND:		name = "Resource/Interface/result/bg_resultwindow.png";								break;
		case IMAGE_STAGE_RESULT_EMPTYSTAR:		name = "Resource/Interface/result/prop_resultwindow_emptystar.png";					break;							
		case IMAGE_STAGE_RESULT_STAR:			name = "Resource/Interface/result/prop_resultwindow_star.png";						break;
		case IMAGE_OBJECT_APPLE:				name = "Resource/stage01/object/object_apple.png";									break;
		case IMAGE_OBJECT_APPLE_BREAK:			name = "Resource/stage01/object/object_apple_break.png";							break;
		case IMAGE_OBJECT_APPLE_BOOM:			name = "Resource/stage01/object/object_apple_boom.png";								break;
		case IMAGE_OBJECT_APPLETREE_STAND:		name = "Resource/stage01/object/object_appletree_stand.png";						break;
		case IMAGE_OBJECT_APPLETREE_POISON:		name = "Resource/stage01/object/object_appletree_poison.png";						break;
		case IMAGE_OBJECT_APPLETREE_HIT:		name = "Resource/stage01/object/object_appletree_hit.png";							break;
		case IMAGE_OBJECT_APPLETREE_DEAD:		name = "Resource/stage01/object/object_appletree_dead.png";							break;
		case IMAGE_OBJECT_ACTIVETREE_STAND:		name = "Resource/stage01/object/object_activetree_stand.png";						break;
		case IMAGE_OBJECT_ACTIVETREE_HIT:		name = "Resource/stage01/object/object_activetree_hit.png";							break;
		case IMAGE_OBJECT_ACTIVETREE_DEAD:		name = "Resource/stage01/object/object_activetree_dead.png";						break;
		case IMAGE_OBJECT_BIRD:					name = "Resource/stage01/object/object_bird.png";									break;
		case IMAGE_OBJECT_WANTED:				name = "Resource/stage01/object/object_wanted.png";									break;
		case IMAGE_OBJECT_WANTED_1:				name = "Resource/stage01/object/object_wanted1.png";								break;
		case IMAGE_OBJECT_WANTED_2:				name = "Resource/stage01/object/object_wanted2.png";								break;	
		case IMAGE_OBJECT_WANTED_3:				name = "Resource/stage01/object/object_wanted3.png";								break;	
		case IMAGE_OBJECT_WANTED_4:				name = "Resource/stage01/object/object_wanted4.png";								break;
		case IMAGE_STAGE1_1_BACKGROUND:			name = "Resource/stage01/stage0101/bg_stage01_01.png";								break;
		case IMAGE_STAGE1_2_BACKGROUND:			name = "Resource/stage01/stage0102/bg_stage01_02.png";								break;
		case IMAGE_STAGE1_2_FOREST:				name = "Resource/stage01/stage0102/bg_stage01_02_forest.png";						break;
		case IMAGE_STAGE1_3_BACKGROUND:			name = "Resource/stage01/stage0103/bg_stage01_03.png";								break;
		case IMAGE_STAGE4_1_BACKGROUND:			name = "Resource/stage04/stage0401/bg_stage04_01.png";								break;
		case IMAGE_STAGE4_2_BACKGROUND:			name = "Resource/stage04/stage0402/bg_stage04_02.png";								break;
		case IMAGE_STAGE4_3_BACKGROUND:			name = "Resource/stage04/stage0403/bg_stage04_03.png";								break;
		case IMAGE_STAGE4_4_BACKGROUND:			name = "Resource/stage04/stage0404/bg_stage04_04.png";								break;
		//case IMAGE_STAGE4_5_BACKGROUND:			name = "Resource/stage04/stage0405/bg_stage04_05.png";								break;
		case IMAGE_STAGE5_4_BACKGROUND:			name = "Resource/stage05/bg_stage05_04.png";										break;
		default:								return FALSE;
		}

		std::pair<std::map<int, int>::iterator, bool> result;
		result = m_ResMap->insert(std::map<int, int>::value_type(Key, LoadGraph(name)));
		name = NULL;
		return result.second;
	}
	else
	{
		return FALSE;
	}
}

int ResourceManager::GetRes(int Key)
{
	std::map<int, int>::iterator it = m_ResMap->find(Key);

	if( it != m_ResMap->end() ) {
		return it->second;
	}
	else {
		return -1;
	}
}

bool ResourceManager::RemoveRes(int Key)
{
	std::map<int, int>::iterator it = m_ResMap->find(Key);
	
	if( it != m_ResMap->end() ) {
		DeleteGraph(it->second);
		m_ResMap->erase(it);
		return TRUE;
	}
	else {
		return FALSE;
	}
}

bool AddResourceWithKey(int Key)
{
	return ResourceManager::getResourceManager()->AddRes(Key);
}

int GetResourceWithKey(int Key)
{
	return ResourceManager::getResourceManager()->GetRes(Key);
}

bool DelResourceWithKey(int Key)
{
	return ResourceManager::getResourceManager()->RemoveRes(Key);
}