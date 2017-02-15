#include"HUDLayer/HUDLayer.h"

USING_NS_CC;
using namespace cocostudio;
using namespace ui;

Widget		*		HUDLayer::m_hud;
TextAtlas	*		HUDLayer::lblGold;
TextAtlas	*		HUDLayer::lblRound;
TextAtlas	*		HUDLayer::lblLife;
TextAtlas	*		HUDLayer::lblAllRound;

int HUDLayer::m_curRound = 0;
int HUDLayer::m_curGold = 0;
int HUDLayer::m_curLife = 0;
int HUDLayer::m_allRound = 0;

void HUDLayer::createHUDLayer()
{
	auto layer = Layer::create();
	m_hud = GUIReader::getInstance()->widgetFromJsonFile("Tower/HUD/HUD.json");

	lblGold = dynamic_cast<TextAtlas*>(m_hud->getChildByName("LabelGold"));
	lblRound = dynamic_cast<TextAtlas*>(m_hud->getChildByName("LabelWave"));
	lblLife = dynamic_cast<TextAtlas*>(m_hud->getChildByName("LabelLife"));
	lblAllRound = dynamic_cast<TextAtlas*>(m_hud->getChildByName("LabelAllWave"));

	m_curRound = 0;
	setInitHUD(0, 0, 0);
	/*lblGold->setStringValue("0");
	lblRound->setStringValue("0");
	lblAllRound->setString("0");
	lblLife->setStringValue("0");*/

	//layer->addChild(hud);
	//return layer;
}

Widget*HUDLayer::getHud(){
	Widget*hud = m_hud;
	return hud;
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

	//m_monsterCreateLeft = 1 + m_curRound * 2;
	//schedule(schedule_selector(Monster::makeMonster), 0.5f);
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