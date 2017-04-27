#include "MagicMessage.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
USING_NS_CC;
using namespace ui;
using namespace cocostudio;

MagicMessage::MagicMessage(int magicID)
{
	m_magicID = magicID;

	m_magicRange = 0;
	m_magicDamage = 0;
	m_magicReloadTime = 0;
	m_magicBulletDamage = 0;
	m_magicBulletSpeed = 0;
}

int MagicMessage::getMagicRange()
{
	getMessage();
	return m_magicRange;
}

int MagicMessage::getMagicDamage()
{
	getMessage();
	return m_magicDamage;
}

int MagicMessage::getMagicReloadTime()
{
	getMessage();
	return m_magicReloadTime;
}

int MagicMessage::getMagicBulletDamage()
{
	getMessage();
	return m_magicDamage;
}

int MagicMessage::getMagicBulletSpeed()
{
	getMessage();
	return m_magicBulletSpeed;
}

void MagicMessage::getMessage()
{
	std::string conversation = FileUtils::getInstance()->getStringFromFile("Tower/MagicMessage.json");
	rapidjson::Document doc;
	doc.Parse<rapidjson::kParseDefaultFlags>(conversation.c_str());
	rapidjson::Value & array = doc["MagicMessage"];
	if (!array.IsArray())
	{
		return;
	}
	if (m_magicID >= array.Size())
	{
		CCLOG("no more magic%d", m_magicID);
		return;
	}
	/*for (rapidjson::SizeType i = 0; i < array.Size(); i++)
	{*/
	const rapidjson::Value &p = array[m_magicID];
	switch (m_magicID)
	{
	case 0:{

			   const rapidjson::Value &valueEnt = p["sun"];
			   if (valueEnt.HasMember("id") && valueEnt.HasMember("Damage"))
			   {
				   const rapidjson::Value &MagicID = valueEnt["id"];
				   const rapidjson::Value &MagicDamage = valueEnt["Damage"];
				   m_magicRange = MagicDamage.GetInt();
			   }
			   break; }
	case 1:  {
				 if (!p.HasMember("ice"))
				 {
					 return;
				 }
				 const rapidjson::Value &valueEnt = p["ice"];
				 if (valueEnt.HasMember("id") && valueEnt.HasMember("Damage"))
				 {
					 const rapidjson::Value &MagicID = valueEnt["id"];
					 const rapidjson::Value &MagicDamage = valueEnt["Damage"];
					 m_magicRange = MagicDamage.GetInt();
				 }
				 break; }
	case 2:
	{
			  const rapidjson::Value &valueEnt = p["anchor"];
			  if (valueEnt.HasMember("id") && valueEnt.HasMember("Range") &&
				  valueEnt.HasMember("ReloadTime") && valueEnt.HasMember("BulletDamage") &&
				  valueEnt.HasMember("BulletSpeed"))
			  {
				  const rapidjson::Value &MagicID = valueEnt["id"];
				  const rapidjson::Value &MagicRange = valueEnt["Range"];
				  const rapidjson::Value &MagicReloadTime = valueEnt["ReloadTime"];
				  const rapidjson::Value &MagicBulletDamage = valueEnt["BulletDamage"];
				  const rapidjson::Value &MagicBulletSpeed = valueEnt["BulletSpeed"];
				  m_magicRange = MagicRange.GetInt();
				  m_magicReloadTime = MagicReloadTime.GetInt();
				  m_magicBulletDamage = MagicBulletDamage.GetInt();
				  m_magicBulletSpeed = MagicBulletSpeed.GetInt();
			  }
			  break; }
	case 3:
	{
			  const rapidjson::Value &valueEnt = p["fire"];
			  if (valueEnt.HasMember("id") && valueEnt.HasMember("Range") &&
				  valueEnt.HasMember("ReloadTime") && valueEnt.HasMember("BulletDamage") &&
				  valueEnt.HasMember("BulletSpeed"))
			  {
				  const rapidjson::Value &MagicID = valueEnt["id"];
				  const rapidjson::Value &MagicRange = valueEnt["Range"];
				  const rapidjson::Value &MagicReloadTime = valueEnt["ReloadTime"];
				  const rapidjson::Value &MagicBulletDamage = valueEnt["BulletDamage"];
				  const rapidjson::Value &MagicBulletSpeed = valueEnt["BulletSpeed"];
				  m_magicRange = MagicRange.GetInt();
				  m_magicReloadTime = MagicReloadTime.GetInt();
				  m_magicBulletDamage = MagicBulletDamage.GetInt();
				  m_magicBulletSpeed = MagicBulletSpeed.GetInt();
			  }
			  break; }
	case 4:
	{
			  const rapidjson::Value &valueEnt = p["star"];
			  break; }
	default:
		break;
	}
}