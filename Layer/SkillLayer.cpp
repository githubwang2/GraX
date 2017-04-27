#include "Layer/SkillLayer.h"

USING_NS_CC;
using namespace ui;
using namespace cocostudio;

bool SkillLayer::init()
{
	if (!Layer::init())
	{
		return false;
	}

	visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("MenuScene/skill.plist");
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("MenuScene/SkillOpen.plist");

	initSkill();

	initButton("btnArrow1");
	initButton("btnArrow2");
	initButton("btnArrow3");
	initButton("btnFan1");
	initButton("btnFan2");
	initButton("btnFan3");
	initButton("btnRocket1");
	initButton("btnRocket2");
	initButton("btnRocket3");
	initButton("btnRocket4");
	initButton("btnBottle1");
	initButton("btnBottle2");
	initButton("btnBottle3");
	initButton("btnFBottle");
	initButton("btnSnow");
	initButton("btnStar");
	initButton("btnSun");
	initButton("btnAnchor");

	schedule(schedule_selector(SkillLayer::moveSkillBG), 2.0f);

	return true;
}

Button* SkillLayer::initButton(std::string btnName)
{
	auto btn = dynamic_cast<Button*>(skillLayer->getChildByName(btnName));
	btn->addTouchEventListener(this, toucheventselector(SkillLayer::touchButton));
	char buf[20] = { 0 };
	sprintf(buf, btnName.c_str());
	
	btn->setBright(GameState::getSkillDate(buf));
	//btn2->setBright(false);
	//btn2->setTouchEnabled(false);
	return btn;
}


cocos2d::Animation* SkillLayer::initSkillAct(std::string btnName)
{
	char buf[30] = { 0 };
	sprintf(buf,"MenuScene/%s",btnName.c_str());

	Vector<SpriteFrame*>fireFrame;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			SpriteFrame*sf = SpriteFrame::create(buf, Rect(168 * j, 196 * i, 168, 196));
			fireFrame.pushBack(sf);
		}
	}
	Animation*ani = Animation::createWithSpriteFrames(fireFrame, 0.1f);
	
	return ani;
}


void SkillLayer::initSkill()
{
	skillLayer = GUIReader::getInstance()->widgetFromJsonFile("MenuScene/SkillLayer.json");
	skillLayer->setAnchorPoint(Point::ANCHOR_MIDDLE);
	skillLayer->setPosition(visibleSize / 2);
	addChild(skillLayer, 1);

	auto imgStar = dynamic_cast<Widget*>(skillLayer->getChildByName("imgStars"));
	 lblNumOfStars = dynamic_cast<TextAtlas*>(skillLayer->getChildByName("lblStars"));
	char num[32] = { 0 };
	sprintf(num, "%d", GameState::getNumOfStars());
	lblNumOfStars->setStringValue(num);

	auto btnMenu = dynamic_cast<Button*>(skillLayer->getChildByName("btnGameMenu"));
	btnMenu->addTouchEventListener(this, toucheventselector(MenuScene::touchButton));

	auto imgInstruction = dynamic_cast<Widget*>(skillLayer->getChildByName("imgInstruction"));
	auto lblText = dynamic_cast<Text*>(imgInstruction->getChildByName("lblText"));
	//imgInstruction->setVisible(false);
	//lblText->setVisible(false);
	lblText->setString("写点什么好了？");
}

void SkillLayer::touchButton( Ref *object,  TouchEventType type)
{
	if (type==TouchEventType::TOUCH_EVENT_ENDED)
	{
		auto widget = dynamic_cast<Widget*>(object);
		auto name = widget->getName();
		//-----------------Arrow--------------------------
		if (name.compare("btnArrow2")==0)
		{
			if (GameState::getSkillDate("btnArrow1"))
			{
				if (GameState::getSkillDate("btnArrow2"))
				{
					return;
				}
				initButton("btnArrow2")->setBright(true);
				GameState::studySkillDate("btnArrow2");
				skillOpenEffect(widget->getPosition());
			}
		}
		else if(name.compare("btnArrow3")==0)
		{
			if (GameState::getSkillDate("btnArrow2"))
			{
				if (GameState::getSkillDate("btnArrow3"))
				{
					return;
				}
				initButton("btnArrow3")->setBright(true);
				GameState::studySkillDate("btnArrow3");
				skillOpenEffect(widget->getPosition());
			}
		}
		//---------------------Fan--------------------
		else if(name.compare("btnFan2") == 0)
		{
			if (GameState::getSkillDate("btnFan1"))
			{
				if (GameState::getSkillDate("btnFan2"))
				{
					return;
				}
				initButton("btnFan2")->setBright(true);
				GameState::studySkillDate("btnFan2");
				skillOpenEffect(widget->getPosition());
			}
		}
		else if (name.compare("btnFan3") == 0)
		{
			if (GameState::getSkillDate("btnFan2"))
			{
				if (GameState::getSkillDate("btnFan3"))
				{
					return;
				}
				initButton("btnFan3")->setBright(true);
				GameState::studySkillDate("btnFan3");
				skillOpenEffect(widget->getPosition());
			}
		}
		//---------------------Bottle--------------------
		else if (name.compare("btnBottle2") == 0)
		{
			if (GameState::getSkillDate("btnBottle1"))
			{
				if (GameState::getSkillDate("btnBottle2"))
				{
					return;
				}
				initButton("btnBottle2")->setBright(true);
				skillOpenEffect(widget->getPosition());
				GameState::studySkillDate("btnBottle2");
			}
		}
		else if (name.compare("btnBottle3") == 0)
		{
			if (GameState::getSkillDate("btnBottle2"))
			{
				if (GameState::getSkillDate("btnBottle3"))
				{
					return;
				}
				initButton("btnBottle3")->setBright(true);
				skillOpenEffect(widget->getPosition());
				GameState::studySkillDate("btnBottle3");
			}
		}
		//---------------------btnRocket--------------------
		else if (name.compare("btnRocket2") == 0)
		{
			if (GameState::getSkillDate("btnRocket1"))
			{
				if (GameState::getSkillDate("btnRocket2"))
				{
					return;
				}
				initButton("btnRocket2")->setBright(true);
				skillOpenEffect(widget->getPosition());
				GameState::studySkillDate("btnRocket2");
			}
		}
		else if (name.compare("btnRocket3") == 0)
		{
			if (GameState::getSkillDate("btnRocket2"))
			{
				if (GameState::getSkillDate("btnRocket3"))
				{
					return;
				}
				initButton("btnRocket3")->setBright(true);
				skillOpenEffect(widget->getPosition());
				GameState::studySkillDate("btnRocket3");
			}
		}
		else if (name.compare("btnRocket4") == 0)
		{
			if (GameState::getSkillDate("btnRocket3"))
			{
				if (GameState::getSkillDate("btnRocket4"))
				{
					return;
				}
				initButton("btnRocket4")->setBright(true);
				skillOpenEffect(widget->getPosition());
				GameState::studySkillDate("btnRocket4");
			}
		}
		//---------------------btnMagic--------------------
		else if (name.compare("btnFBottle") == 0)
		{
			if (GameState::getSkillDate("btnRocket3") && GameState::getSkillDate("btnBottle3"))
			{
				if (GameState::getSkillDate("btnFBottle"))
				{
					return;
				}
				initButton("btnFBottle")->setBright(true);
				skillOpenEffect(widget->getPosition());
				GameState::studySkillDate("btnFBottle");
			}
		}
		else if (name.compare("btnStar") == 0)
		{
			if (GameState::getSkillDate("btnFBottle"))
			{
				if (GameState::getSkillDate("btnStar"))
				{
					return;
				}
				initButton("btnStar")->setBright(true);
				skillOpenEffect(widget->getPosition());
				GameState::studySkillDate("btnStar");
			}
		}
		else if (name.compare("btnSnow") == 0)
		{
			if (GameState::getSkillDate("btnRocket2"))
			{
				if (GameState::getSkillDate("btnSnow"))
				{
					return;
				}
				initButton("btnSnow")->setBright(true);
				skillOpenEffect(widget->getPosition());
				GameState::studySkillDate("btnSnow");
			}
		}
		else if (name.compare("btnSun") == 0)
		{
			if (GameState::getSkillDate("btnSnow"))
			{
				if (GameState::getSkillDate("btnSun"))
				{
					return;
				}
				initButton("btnSun")->setBright(true);
				skillOpenEffect(widget->getPosition());
				GameState::studySkillDate("btnSun");
			}
		}
		else if (name.compare("btnAnchor") == 0)
		{
			if (GameState::getSkillDate("btnSun"))
			{
				if (GameState::getSkillDate("btnAnchor"))
				{
					return;
				}
				initButton("btnAnchor")->setBright(true);
				skillOpenEffect(widget->getPosition());
				GameState::studySkillDate("btnAnchor");
			}
		}
	}
}

void SkillLayer::skillOpenEffect(cocos2d::Point pos)
{
	Animation * animation = Animation::create();
	char buf[60] = { 0 };
	for (int i = 1; i < 17; i++)
	{
		sprintf(buf, "SkillOpen%d.png", i);
		animation->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(buf));
	}
	animation->setDelayPerUnit(0.1f);
	animation->setRestoreOriginalFrame(true);
	auto sp = Sprite::create();
	Action *act = Sequence::create(Repeat::create(Animate::create(animation), 1), nullptr);
	sp->runAction(act);
	sp->setPosition(pos+Point(-10,10));
	addChild(sp, 1);
}

void SkillLayer::starsNotEnough()
{
	 auto toRed = TintBy::create(0.2f, -127, -255, -127);
	 auto toBigger=ScaleBy::create(0.2f, 1.5);
	 lblNumOfStars->runAction(Sequence::create(toRed, toRed->reverse(), nullptr));
	 lblNumOfStars->runAction(Sequence::create(toBigger, toBigger->reverse(), nullptr));
}

void SkillLayer::moveSkillBG(float dt)
{
	auto sp = Sprite::create();
	Action *act;
	int _rand = rand() % 5;
	switch (_rand)
	{
	case 0:
		act = Sequence::create(
			Animate::create(initSkillAct("AM012A.png")),
			CallFuncN::create(sp, callfuncN_selector(SkillLayer::endMoveSkill)), nullptr);
		break;
	case 1:
		act = Sequence::create(
			Animate::create(initSkillAct("AM013A.png")),
			CallFuncN::create(sp, callfuncN_selector(SkillLayer::endMoveSkill)), nullptr);
		break;
	case 2:
		act = Sequence::create(
			Animate::create(initSkillAct("AM014A.png")),
			CallFuncN::create(sp, callfuncN_selector(SkillLayer::endMoveSkill)), nullptr);
		break;
	case 3:
		act = Sequence::create(
			Animate::create(initSkillAct("AM015A.png")),
			CallFuncN::create(sp, callfuncN_selector(SkillLayer::endMoveSkill)), nullptr);
		break;
	case 4:
		 act= Sequence::create(
			Animate::create(initSkillAct("AM016A.png")),
			CallFuncN::create(sp, callfuncN_selector(SkillLayer::endMoveSkill)), nullptr);
		break;
	default:
		break;
	}
	sp->runAction(act);
	addChild(sp, -1);
	
	int _randX = rand() % 10;
	int _randY = rand() % 10;
	sp->setPosition(_randX * 100, _randY * 80);
	sp->setScale(2.0);

}

void SkillLayer::endMoveSkill(Node*node)
{
	node->removeFromParentAndCleanup(true);
}

