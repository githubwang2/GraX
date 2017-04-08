#include "MonstersMessage.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

USING_NS_CC;
using namespace cocostudio;
using namespace ui;

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

std::string MonstersMessage::getJPNameOfMonsters(int id)
{
	m_id = id;
	getMessage();
	std::string name = m_nameJp;
	return name;
}

std::string MonstersMessage::getCNNameOfMonsters(int id)
{
	m_id = id;
	getMessage();
	std::string name = m_nameCn;
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
		if (valueEnt.HasMember("id") && valueEnt.HasMember("hp") &&
			valueEnt.HasMember("speed") && valueEnt.HasMember("name_jp")
			&& valueEnt.HasMember("name_cn"))
		{
			const rapidjson::Value &monsterID = valueEnt["id"];
			int mId = monsterID.GetInt();
			if (m_id == mId)
			{
				const rapidjson::Value &monsterHp = valueEnt["hp"];
				int hp = monsterHp.GetInt();
				const rapidjson::Value &monsterNameJp = valueEnt["name_jp"];
				std::string name_jp = monsterNameJp.GetString();
				const rapidjson::Value &monsterNameCn = valueEnt["name_cn"];
				std::string name_cn = monsterNameCn.GetString();
				const rapidjson::Value &monsterSpeed = valueEnt["speed"];
				int speed = monsterSpeed.GetInt();
				m_id = mId;
				m_nameCn = name_cn;
				m_nameJp = name_jp;
				m_hp = hp;
				m_speed = speed;
				m_numOfMonsters = array.Size();
			}
		}
		else
		{
			m_id = 999;
			m_nameCn = "Î´½âËø";
			m_nameJp = "¥¢¥ó¥í¥Ã¥¯";
			m_hp = 0;
			m_speed = 0;
		}
	}
}
