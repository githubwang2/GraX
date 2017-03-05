#include "MonstersMessage.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
USING_NS_CC;
using namespace ui;
using namespace cocostudio;

MonstersMessage::MonstersMessage()
{
	m_numOfMonsters = 0;
	m_hp = 0;
	m_id = 0;
	m_speed = 0;
	getMessage();
}

int MonstersMessage::getNumOfMonsters()
{
	getMessage();
	int num = m_numOfMonsters;
	return num;
}

std::string MonstersMessage::getNameOfMonsters(int id)
{
	m_id = id;
	getMessage();
	std::string name = m_name;
	return name;
}

int MonstersMessage::getSpeedOfMonsters(int id)
{
	m_id = id;
	getMessage();
	int speed = m_speed;
	return speed;
}

int MonstersMessage::getHpOfMonsters(int id)
{
	m_id = id;
	getMessage();
	int hp = m_hp;
	return hp;
}

void MonstersMessage::getMessage()
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
		CCLOG("no more monster%d");
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
			int mId = monsterID.GetInt();
			if (m_id == mId)
			{
				const rapidjson::Value &monsterHp = valueEnt["hp"];
				int hp = monsterHp.GetInt();
				const rapidjson::Value &monsterName = valueEnt["name"];
				std::string name = monsterName.GetString();
				const rapidjson::Value &monsterSpeed = valueEnt["speed"];
				int speed = monsterSpeed.GetInt();
				m_id = mId;
				m_name = name;
				m_hp = hp;
				m_speed = speed;
				m_numOfMonsters = array.Size();
			}
		}
	}
}
