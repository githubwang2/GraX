#include "Sprite/Monster.h"
#include "Sprite/Components/ComLife.h"
#include "Sprite/Components/ComMove.h"
#include "GameMap.h"

USING_NS_CC;
using namespace cocostudio;
using namespace ui;

Monster::Monster(int id){
	m_id = id;
	m_hp = 0;
	m_speed = 0;
}

Monster* Monster::create(int id)
{
	Monster*ret = new Monster(id);
	if (ret != nullptr && ret->initMonster())
	{
		ret->autorelease();
	}
	else
	{
		CC_SAFE_DELETE(ret);
	}
	return ret;
}

void Monster::setMonsterMessage(int id)
{
	std::string conversation = FileUtils::getInstance()->getStringFromFile("Monster/monster.json");
	rapidjson::Document doc;
	doc.Parse<rapidjson::kParseDefaultFlags>(conversation.c_str());

	rapidjson::Value & array = doc["monster"];
	if (!array.IsArray())
	{
		return;
	}
	if (m_id >= array.Size())
	{
		CCLOG("no more monster");
		return;
	}
	for (rapidjson::SizeType i = 0; i < array.Size(); i++)
	{
		const rapidjson::Value &p = array[i];
		if (!p.HasMember("entity"))
		{
			continue;
		}
		const rapidjson::Value &valueEnt = p["entity"];
		if (valueEnt.HasMember("id") && valueEnt.HasMember("hp") && valueEnt.HasMember("speed"))
		{
			const rapidjson::Value &monsterID = valueEnt["id"];
			int id = monsterID.GetInt();
			if (id == m_id)
			{
				const rapidjson::Value &monsterHp = valueEnt["hp"];
				int hp = monsterHp.GetInt();
				const rapidjson::Value &monsterSpeed = valueEnt["speed"];
				int speed = monsterSpeed.GetInt();
				m_hp = hp;
				m_speed = speed;
				CCLOG("id%d,speed%d,hp%d", id, m_speed, m_hp);
			}
		}
	}
}


bool Monster::initMonster(){
	if (!Layer::init())
	{
		return false;
	}
	setMonsterMessage(m_id);
	auto monster = Sprite::create();
	//monster->setScale(1.0);
	//monster->runAction(RepeatForever::create(Animate::create(ani_right)));

	GameMap*gameMap = new GameMap();
	auto path = gameMap->getWalkPath("Walk");

	//挂载怪物移动组件
	auto comMove = ComMove::create(path,m_id,m_speed);
	monster->addComponent(comMove);
	comMove->startMove();	

	//挂载怪物HP组件
	auto comLife = ComLife::create(m_hp);
	monster->addComponent(comLife);

	//存入FireManager的m_monsters list中
	GameMainLayer::fileManager->m_monsters.push_back(comMove);
	addChild(monster);
	return true;
}

