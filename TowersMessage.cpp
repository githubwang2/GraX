#include "TowersMessage.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
USING_NS_CC;
using namespace ui;
using namespace cocostudio;

TowersMessage::TowersMessage(int towerID, int towerLevel)
{
	m_towerID = towerID;
	m_towerLevel = towerLevel;

	m_towerRange=0;
	m_towerReloadTime=0;
	m_towerBulletDamage=0;
	m_towerBulletSpeed=0;
	m_towerType = 0;
}

int TowersMessage::getTowerRange()
{
	getMessage();
	return m_towerRange;
}

float TowersMessage::getTowerReloadTime()
{
	getMessage();
	return m_towerReloadTime;
}

int TowersMessage::getTowerType()
{
	getMessage();
	return m_towerType;
}

int TowersMessage::getBulletDamage()
{
	getMessage();
	return m_towerBulletDamage;
}

int TowersMessage::getBulletSpeed()
{
	getMessage();
	return m_towerBulletSpeed;
}

void TowersMessage::getMessage()
{
	std::string conversation;
	switch (m_towerID)
	{
	case 0:
		conversation = FileUtils::getInstance()->getStringFromFile("Tower/TowerFan.json");
		break;
	case 1:
		conversation = FileUtils::getInstance()->getStringFromFile("Tower/TowerArrow.json");
		break;
	case 2:
		conversation = FileUtils::getInstance()->getStringFromFile("Tower/TowerRocket.json");
		break;
	case 3:
		conversation = FileUtils::getInstance()->getStringFromFile("Tower/TowerBottle.json");
		break;
	default:
		break;
	}

	rapidjson::Document doc;
	doc.Parse<rapidjson::kParseDefaultFlags>(conversation.c_str());
	rapidjson::Value & array = doc["towerMessage"];
	if (!array.IsArray())
	{
		return;
	}
	for (rapidjson::SizeType i = 0; i < array.Size(); i++)
	{
		const rapidjson::Value &p = array[i];
		if (!p.HasMember("Tower"))
		{
			continue;
		}
		const rapidjson::Value &valueEnt = p["Tower"];
		if (valueEnt.HasMember("Range") && valueEnt.HasMember("Level")
			&& valueEnt.HasMember("ReloadTime") && valueEnt.HasMember("BulletDamage")
			&& valueEnt.HasMember("BulletSpeed") && valueEnt.HasMember("Type"))
		{
			if (valueEnt["Level"].GetInt() == m_towerLevel - 1)
			{
				const rapidjson::Value &towerRange = valueEnt["Range"];
				const rapidjson::Value &towerReloadTime = valueEnt["ReloadTime"];
				const rapidjson::Value &towerBulletDamage = valueEnt["BulletDamage"];
				const rapidjson::Value &towerBulletSpeed = valueEnt["BulletSpeed"];
				const rapidjson::Value &towerType = valueEnt["Type"];

				m_towerRange = towerRange.GetInt();
				m_towerReloadTime = towerReloadTime.GetDouble();
				m_towerBulletDamage = towerBulletDamage.GetInt();
				m_towerType = towerType.GetInt();
				m_towerBulletSpeed = towerBulletSpeed.GetInt();
			}
		}
	}
}