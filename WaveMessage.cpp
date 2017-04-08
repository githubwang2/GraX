#include "WaveMessage.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
USING_NS_CC;
using namespace ui;
using namespace cocostudio;

WavesMessage::WavesMessage(int pStage, int pLevel)
{
	m_stage = pStage;
	m_level = pLevel;

	m_beginHp = 0;
	m_beginGold = 0;

	m_curNo = 1;
	m_id = 0;
	m_num = 0;
	m_monster_interval = 0;
	m_wave_inteval = 0;

	getBeginMessage();
	getMessage();
}

void WavesMessage::updataLevelMessage()
{
	m_id = vecId.at(m_curNo);
	m_num = vecNum.at(m_curNo);
	m_monster_interval = vecMonsterInterval.at(m_curNo);
	m_wave_inteval = vecWaveInterval.at(m_curNo);
}

void WavesMessage::setCurNo(int curNo)
{
	updataLevelMessage();
	m_curNo = curNo;
}

int WavesMessage::getCurMonsterId()
{
	updataLevelMessage();
	return m_id;
}

int WavesMessage::getCurMonsterNum()
{
	updataLevelMessage();
	return m_num;
}

float WavesMessage::getMonsterInterval()
{
	updataLevelMessage();
	return m_monster_interval;
}

float WavesMessage::getWaveInteval()
{
	return m_wave_inteval;
}

void WavesMessage::getMessage()
{
	char buf[64] = { 0 };
	sprintf(buf, "GameMain/stage%d/level%d-%d/wave.json",
		m_stage,m_stage,m_level);
	std::string conversation = FileUtils::getInstance()->getStringFromFile(buf);
	rapidjson::Document doc;
	doc.Parse<rapidjson::kParseDefaultFlags>(conversation.c_str());
	rapidjson::Value & array = doc["levelMessage"];
	if (!array.IsArray())
	{
		return;
	}
	if (m_curNo >= array.Size() + 1)//∂‡º”¡Àhud
	{
		CCLOG("no more wave");
		return;
	}
	m_numOfWav = array.Size() - 1;
	for (rapidjson::SizeType i = 0; i < array.Size(); i++)
	{
		const rapidjson::Value &p = array[i];
		if (!p.HasMember("wave"))
		{
			continue;
		}
		const rapidjson::Value &valueEnt = p["wave"];
		if (valueEnt.HasMember("No") && valueEnt.HasMember("id") && valueEnt.HasMember("num")
			&& valueEnt.HasMember("monster_interval") && valueEnt.HasMember("wave_inteval"))
		{
			//const rapidjson::Value &WaveNo = valueEnt["No"];
			/*int mNo = WaveNo.GetInt();
			if (m_no == mNo)
			{*/
			const rapidjson::Value &monsterID = valueEnt["id"];
			int id = monsterID.GetInt();
			const rapidjson::Value &monstersNum = valueEnt["num"];
			int num = monstersNum.GetInt();
			const rapidjson::Value &monsterInterval = valueEnt["monster_interval"];
			float monster_interval = monsterInterval.GetDouble();
			const rapidjson::Value &waveInteval = valueEnt["wave_inteval"];
			float wave_inteval = waveInteval.GetDouble();

			vecId.push_back(id);
			vecNum.push_back(num);
			vecMonsterInterval.push_back(monster_interval);
			vecWaveInterval.push_back(wave_inteval);
			/*m_id = id;
				m_num = num;
				m_monster_interval = monster_interval;
				m_wave_inteval = wave_inteval;*/
			//}
		}
	}
}

void WavesMessage::getBeginMessage()
{
	char buf[64] = { 0 };
	sprintf(buf, "GameMain/stage%d/level%d-%d/wave.json",
		m_stage, m_stage, m_level);
	std::string conversation = FileUtils::getInstance()->getStringFromFile(buf);
	rapidjson::Document doc;
	doc.Parse<rapidjson::kParseDefaultFlags>(conversation.c_str());
	rapidjson::Value & array = doc["levelMessage"];
	if (!array.IsArray())
	{
		return;
	}
	rapidjson::SizeType index = 0;
	const rapidjson::Value &p = array[index];
	if (!p.HasMember("HUD"))
	{
		CCLOG("NO HUD");
		return;
	}
	const rapidjson::Value &valueEnt = p["HUD"];
	if (valueEnt.HasMember("beginHp") && valueEnt.HasMember("beginGold"))
	{
		const rapidjson::Value &beginHp = valueEnt["beginHp"];
		m_beginHp = beginHp.GetInt();
		const rapidjson::Value &beginGold = valueEnt["beginGold"];
		m_beginGold = beginGold.GetInt();
	}
}