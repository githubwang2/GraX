#include"Layer/HUDLayer.h"

#include "Scene/GameMainScene.h"

USING_NS_CC;
using namespace cocostudio;
using namespace ui;

bool HUDLayer::init()
{
	if (!Layer::init())
	{
		return false;
	}

	m_hud = GUIReader::getInstance()->widgetFromJsonFile("GameMain/HUD/HUD.json");

	auto btnMenu = dynamic_cast<Button*>(m_hud->getChildByName("btnMenu"));
	btnMenu->addTouchEventListener(this, toucheventselector(GameMainScene::touchButton));

	lblGold = dynamic_cast<TextAtlas*>(m_hud->getChildByName("LabelGold"));
	lblRound = dynamic_cast<TextAtlas*>(m_hud->getChildByName("LabelWave"));
	lblLife = dynamic_cast<TextAtlas*>(m_hud->getChildByName("LabelLife"));
	lblAllRound = dynamic_cast<TextAtlas*>(m_hud->getChildByName("LabelAllWave"));

	m_curRound = 1;
	m_allRound = 1;
	m_curGold = 0;		
	m_curLife = 0;
	//setInitHUD(0, 0, 0);
	/*lblGold->setStringValue("0");
	lblRound->setStringValue("0");
	lblAllRound->setString("0");
	lblLife->setStringValue("0");*/
	addChild(m_hud);

	return true;
}

void HUDLayer::setInitHUD(int gold, int allRound, int life){
	m_allRound = allRound;
	char num[32] = { 0 };
	sprintf(num, "%d", m_allRound);
	lblAllRound->setStringValue(num);
	changeGold(gold);
	changeLife(life);
}

void HUDLayer::createWaveRusher(){
	char num[32] = { 0 };
	sprintf(num, "%d", m_curRound);
	lblRound->setStringValue(num);
	m_curRound++;
}
 
int  HUDLayer::changeGold(int num){

	char numStr[32] = { 0 };
	m_curGold += num;
	sprintf(numStr, "%d", m_curGold);
	lblGold->setStringValue(numStr);
	return m_curGold;
}
 
int HUDLayer::changeLife(int num){
	
	char numStr[32] = { 0 };
	m_curLife += num;
	sprintf(numStr, "%d", m_curLife);
	lblLife->setStringValue(numStr);
	return m_curLife;
}

void HUDLayer::goldWarn()
{
	auto toRed = TintBy::create(0.5f, -127, -255, -127);
	lblGold->runAction(Sequence::create(toRed, toRed->reverse(), nullptr));
}

