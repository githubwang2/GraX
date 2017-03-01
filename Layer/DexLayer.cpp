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

	m_isVisible = false;
	m_id = -1;
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
	auto bg = Sprite::create("MonsterDexLayer/DexBG.jpg");
	bg->setPosition(visibleSize / 2);
	addChild(bg, -1);
}

void DexLayer::initMonDex()
{
	dexLayer = GUIReader::getInstance()->widgetFromJsonFile("MonsterDexLayer/MonsterDexLayer.json");
	dexLayer->setAnchorPoint(Point::ANCHOR_MIDDLE);
	dexLayer->setPosition(visibleSize / 2);
	addChild(dexLayer, 1);

	auto btnMenu = dynamic_cast<Button*>(dexLayer->getChildByName("btnGameMenu"));
	btnMenu->addTouchEventListener(this, toucheventselector(MenuScene::touchButton));

	btnTag = 200;
	for (int i = 0; i < 30; i++)
	{
		initDexBtn(i);
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

		int id = button->getTag();
		
		std::string conversation = FileUtils::getInstance()->getStringFromFile("Monster/monster.json");
		rapidjson::Document doc;
		doc.Parse<rapidjson::kParseDefaultFlags>(conversation.c_str());
		rapidjson::Value & array = doc["monster"];
		if (!array.IsArray())
		{
			return;
		}
		if (id >= array.Size())
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
				int mId = monsterID.GetInt();
				if (id == mId)
				{
					const rapidjson::Value &monsterHp = valueEnt["hp"];
					int hp = monsterHp.GetInt();
					const rapidjson::Value &monsterSpeed = valueEnt["speed"];
					int speed = monsterSpeed.GetInt();
					m_id = id;
					m_hp = hp;
					m_speed = speed;
				}
			}
		}
	}
	initAnimate();
	addChild(addAnimate(),1);
}

void DexLayer::update(float dt)
{
	auto monsterID = dynamic_cast<Text*>(dexLayer->getChildByName("monster_id"));
	auto monsterHp = dynamic_cast<Text*>(dexLayer->getChildByName("monster_hp"));
	auto monsterSpeed = dynamic_cast<Text*>(dexLayer->getChildByName("monster_speed"));
	char id[8] = { 0 };
	char hp[8] = { 0 };
	char speed[16] = { 0 };
	sprintf(id, "ID:\t%d", m_id);
	sprintf(hp, "HP:\t%d", m_hp);
	sprintf(speed, "speed:\t%d", m_speed);
	monsterID->setString(id);
	monsterHp->setString(hp);
	monsterSpeed->setString(speed);
	monsterID->setFontSize(40);
	monsterHp->setFontSize(40);
	monsterSpeed->setFontSize(40);
	monsterID->setColor(ccc3(176, 90, 9));
	monsterHp->setColor(ccc3(176, 90, 9));
	monsterSpeed->setColor(ccc3(176, 90, 9));
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
	monAni = Layer::create();
	//monAni->removeAllChildren();
	//----------------------------------------------------
	if (m_id < 0)
	{
		return monAni;
	}
	else
	{
		spUp = Sprite::create();
		spDown = Sprite::create();
		spLeft = Sprite::create();
		spRight = Sprite::create();
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

