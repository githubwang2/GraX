#include "Layer/DexLayer.h"

USING_NS_CC;
using namespace ui;
using namespace cocostudio;

bool DexLayer::init()
{
	if (!Layer::init())
	{
		return false;
	}
	visibleSize = Director::getInstance()->getVisibleSize();

	m_monstersMessage = new MonstersMessage();
	
	m_isVisible = false;
	m_id = -1;
	m_name = "???";
	m_hp = 0;
	m_speed = 0;

	iniyBG();
	initMonDex();
	initAnimate();
	scheduleUpdate();

	return true;
}

void DexLayer::iniyBG()
{
	auto bg = Sprite::create("MenuScene/DexBG.jpg");
	bg->setPosition(visibleSize / 2);
	addChild(bg, -1);
}

void DexLayer::initMonDex()
{
	dexLayer = GUIReader::getInstance()->widgetFromJsonFile("MenuScene/MonsterDexLayer.json");
	dexLayer->setAnchorPoint(Point::ANCHOR_MIDDLE);
	dexLayer->setPosition(visibleSize / 2);
	addChild(dexLayer, 1);

	auto scrollView = dynamic_cast<ScrollView*>((dexLayer->getChildByName("monImg")));

	auto btnMenu = dynamic_cast<Button*>(dexLayer->getChildByName("btnGameMenu"));
	btnMenu->addTouchEventListener(this, toucheventselector(MenuScene::touchButton));

	monsterID = dynamic_cast<Text*>(dexLayer->getChildByName("monster_id"));
	monsterName = dynamic_cast<Text*>(dexLayer->getChildByName("monster_name"));
	monsterHp = dynamic_cast<Text*>(dexLayer->getChildByName("monster_hp"));
	monsterSpeed = dynamic_cast<Text*>(dexLayer->getChildByName("monster_speed"));
	monsterID->setFontSize(40);
	monsterName->setFontSize(40);
	monsterHp->setFontSize(40);
	monsterSpeed->setFontSize(40);
	monsterID->setColor(ccc3(176, 90, 9));
	monsterName->setColor(ccc3(176, 90, 9));
	monsterHp->setColor(ccc3(176, 90, 9));
	monsterSpeed->setColor(ccc3(176, 90, 9));
	monsterID->setAnchorPoint(Point::ZERO);
	monsterName->setAnchorPoint(Point::ZERO);
	monsterHp->setAnchorPoint(Point::ZERO);
	monsterSpeed->setAnchorPoint(Point::ZERO);

	btnTag = 200;
	for (int i = 0; i < 30; i++)
	{
		initDexBtn(i);
	}
	//自动生成
	//--------------------------------------------
	int btnTag2 = 29;
	int num = m_monstersMessage->getNumOfMonsters();
	for (int i = 30; i < num; i++){
		char imgPath[32] = { 0 };
		sprintf(imgPath, "Monster/m_%d.jpg",i );

		auto btn = Button::create(imgPath);
		auto btnWidh=btn->getContentSize().width;
		auto btnHigh = btn->getContentSize().height;
		btn->setPosition(Point((i)* btnWidh, 0));
		btn->setAnchorPoint(Point::ZERO);
		btn->addTouchEventListener(this, toucheventselector(DexLayer::touchButton));
		scrollView->addChild(btn);
		scrollView->setInnerContainerSize(Size(num * 960 * 960 / btnWidh - 960 + btnWidh, btnHigh));
		btnTag2++;
		btn->setTag(btnTag2);
	}
}

void DexLayer::initDexBtn(int monsterId)
{
	auto btn = dynamic_cast<Button*>(dexLayer->getChildByName("monImg")->getChildByTag(btnTag));
	btn->setPosition(Point(monsterId * 240, 0));
	btn->setAnchorPoint(Point::ZERO);
	char imgPath[32] = { 0 };
	sprintf(imgPath, "Monster/m_%d.jpg", monsterId);
	btn->loadTextures(imgPath,"");
	btn->addTouchEventListener(this, toucheventselector(DexLayer::touchButton));
	btnTag++;
	btn->setTag(monsterId);
}

void DexLayer::touchButton(Ref *object, TouchEventType type){
	if (type == TOUCH_EVENT_ENDED)
	{
		auto button = dynamic_cast<Button*>(object);

		int tag = button->getTag();

		m_id = tag;
		m_name = m_monstersMessage->getNameOfMonsters(tag);
		m_hp = m_monstersMessage->getHpOfMonsters(tag);
		m_speed = m_monstersMessage->getSpeedOfMonsters(tag);

		initAnimate();

		if (!n == 0)
		{
			monAniLayer->removeAllChildrenWithCleanup(true);
		}
		monAniLayer = addAnimate();
		addChild(monAniLayer);
		n++;
		//-----------------------------
		 
		char id[8] = { 0 };
		char name[32] = { 0 };
		char hp[8] = { 0 };
		char speed[16] = { 0 };
		sprintf(id, "ID:\t%d", m_id);
		sprintf(name, "Name:\t%s", m_name.c_str());
		sprintf(hp, "HP:\t%d", m_hp);
		sprintf(speed, "speed:\t%d", m_speed);
		monsterID->setString(id);
		monsterName->setString(name);
		monsterHp->setString(hp);
		monsterSpeed->setString(speed);
		
	}
}

void DexLayer::update(float dt)
{
}

void DexLayer::initAnimate()
{
	ani_up = nullptr;
	ani_down = nullptr;
	ani_left = nullptr;
	ani_right = nullptr;

	Vector<SpriteFrame*>monster_up_vector;
	Vector<SpriteFrame*>monster_down_vector;
	Vector<SpriteFrame*>monster_left_vector;
	Vector<SpriteFrame*>monster_right_vector;

	char path[30] = { 0 };
	sprintf(path, "Monster/%d.png", m_id);

	for (int i = 0; i < 4; i++)
	{
		SpriteFrame*sf = SpriteFrame::create(path, Rect(48 * i, 48 * 2, 48, 48));
		monster_up_vector.pushBack(sf);
	}
	ani_up = Animation::createWithSpriteFrames(monster_up_vector, 0.1f);

	for (int i = 0; i < 4; i++)
	{
		SpriteFrame*sf = SpriteFrame::create(path, Rect(48 * i, 0, 48, 48));
		monster_down_vector.pushBack(sf);
	}
	ani_down = Animation::createWithSpriteFrames(monster_down_vector, 0.1f);

	for (int i = 0; i < 4; i++)
	{
		SpriteFrame*sf = SpriteFrame::create(path, Rect(48 * i, 48 * 1, 48, 48));
		monster_left_vector.pushBack(sf);
	}
	ani_left = Animation::createWithSpriteFrames(monster_left_vector, 0.1f);

	for (int i = 0; i < 4; i++)
	{
		SpriteFrame*sf = SpriteFrame::create(path, Rect(48 * i, 48 * 3, 48, 48));
		monster_right_vector.pushBack(sf);
	}
	ani_right = Animation::createWithSpriteFrames(monster_right_vector, 0.1f);
	
}

Layer*  DexLayer::addAnimate()
{
	auto monAni = Layer::create();
	//monAni->removeAllChildren();
	//----------------------------------------------------
	if (m_id < 0)
	{
		return monAni;
	}
	else
	{
		auto spUp = Sprite::create();
		auto spDown = Sprite::create();
		auto spLeft = Sprite::create();
		auto spRight = Sprite::create();
		spUp->setScale(2);
		spDown->setScale(2);
		spLeft->setScale(2);
		spRight->setScale(2);

		spUp->setPosition(300, 200);
		spDown->setPosition(400, 200);
		spLeft->setPosition(500, 200);
		spRight->setPosition(600, 200);

		monAni->addChild(spUp, 1);
		monAni->addChild(spDown, 1);
		monAni->addChild(spLeft, 1);
		monAni->addChild(spRight, 1);

		spUp->runAction(RepeatForever::create(Animate::create(ani_up)));
		spDown->runAction(RepeatForever::create(Animate::create(ani_down)));
		spLeft->runAction(RepeatForever::create(Animate::create(ani_left)));
		spRight->runAction(RepeatForever::create(Animate::create(ani_right)));
	}
	return monAni;
}

