#include "MainScene.h"
#include "Components/Constants.h"

USING_NS_CC;

Scene* MainScene::createScene()
{
	auto scene = Scene::create();
	auto layer = MainScene::create();
	scene->addChild(layer);
	return scene;
}

bool MainScene::init()
{
	if (!Layer::init())
	{
		return false;
	}

	visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	
	CCLOG("isMainScene");

	initBG();
	initTMXTiledMap();
	initHUD();

	//设置可以设置防御塔的区域
	m_bulid = m_tileMap->getLayer("meta");
	m_bulid->setVisible(false);
	//设置怪物的移动路径
	m_pathVec = getWalkPath("Walk");


	//设置初始 波数为1  金钱600  生命30
	m_curRound = 1;
	changeGold(600);
	changeLife(30);

	createWaveRusher();

	return true;
}

void MainScene::initBG(){
	//背景
	auto spriteBG = Sprite::create("Tower/background.png");
	spriteBG->setPosition(visibleSize / 2);
	spriteBG->setScale(visibleSize.width / spriteBG->getContentSize().width,
		visibleSize.height / spriteBG->getContentSize().height);
	addChild(spriteBG, -1);
}

void MainScene::initTMXTiledMap(){
	//瓦片地图
	m_tileMap = TMXTiledMap::create("Tower/TowerTileMap/gate1.tmx");
	addChild(m_tileMap, -1);
}

void MainScene::initHUD(){
	//Hud    
	auto hud = GUIReader::getInstance()->widgetFromJsonFile("Tower/HUD/HUD.json");
	hud->setTag(1);
	addChild(hud, 2);
}

std::vector<Point>MainScene::getWalkPath(const char*key){
	std::vector<Point>pathVec;
	if (!m_tileMap)
	{
		CCLOG("can't find map");
		return pathVec;
	}

	TMXObjectGroup*walk = m_tileMap->getObjectGroup(key);

	if (!walk)
	{
		CCLOG("no such key = %s", key);
		return pathVec;
	}

	ValueVector path = walk->getObjects();

	int myX = 0;
	int myY = 0;
	for (auto pos : path)
	{
		myX = pos.asValueMap()["x"].asInt();
		myY = pos.asValueMap()["y"].asInt();
		CCLOG("find the pos x:%d\ty:%d", myX, myY);
		pathVec.push_back(Point(myX, myY));
	}
	return pathVec;
}

void MainScene::makeMonster(float dt){
	Sprite *monster = Sprite::create("Tower/Monster.png");
	/*auto path = m_pathVec;
	if (path.size() == 0)
	{
	CCLOG("no pos");
	return;
	}
	Vector<FiniteTimeAction*>act;
	auto starPos = path.at(0);
	for (int i = 1; i < path.size(); i++)
	{
	float dur = path.at(i - 1).getDistance(path.at(i));
	float time = dur / monster_speed;
	act.pushBack(MoveTo::create(time, path.at(i)));
	}
	monster->setPosition(starPos);
	auto act2 = Sequence::create(act);
	monster->runAction(act2);
*/
	//挂载怪物移动组件
	auto comMove = ComMove::create(m_pathVec);
	monster->addComponent(comMove);
	comMove->startMove();
	//挂载怪物HP组件
	auto comLife = ComLife::create(monster_hp);
	monster->addComponent(comLife);

	//-----------------------------------------------------------
	//每生成一个怪物，该波怪物减一，为0停止产生怪物。
	//波数加1
	m_monsterCreateLeft--;
	if (m_monsterCreateLeft == 0)
	{
		unschedule(schedule_selector(MainScene::makeMonster));
		runAction(Sequence::create(DelayTime::create(3.0f + m_curRound),
			CallFunc::create([=](){
			m_curRound++;
			createWaveRusher();
		})
			, nullptr));
	}
	addChild(monster, 0);
}

void MainScene::createWaveRusher(){
	//- 波数
	auto hud = dynamic_cast<Widget*>(this->getChildByTag(1));
	auto waveLabel = dynamic_cast<TextAtlas*>(hud->getChildByName("LableWave"));
	char num[32] = { 0 };
	sprintf(num, "%d", m_curRound);
	waveLabel->setStringValue(num);

	m_monsterCreateLeft = 1 + m_curRound * 2;
	schedule(schedule_selector(MainScene::makeMonster), 0.5f);
}

void MainScene::changeGold(int num){
	auto hud = dynamic_cast<Widget*>(this->getChildByTag(1));
	auto gold = dynamic_cast<TextAtlas*>(hud->getChildByName("LabelGold"));
	char numStr[32] = { 0 };
	m_gold += num;
	sprintf(numStr, "%d", m_gold);
	gold->setStringValue(numStr);
}

int MainScene::changeLife(int num){
	auto hud = dynamic_cast<Widget*>(this->getChildByTag(1));
	auto life = dynamic_cast<TextAtlas*>(hud->getChildByName("LableLife"));
	char numStr[32] = { 0 };
	m_curLife += num;
	sprintf(numStr, "%d", m_curLife);
	life->setStringValue(numStr);
	return m_curLife;
}