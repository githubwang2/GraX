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

	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("MenuScene/Skill.plist");

	initSkillBG();

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

void SkillLayer::initSkillBG()
{
	skillLayer = GUIReader::getInstance()->widgetFromJsonFile("MenuScene/SkillLayer.json");
	skillLayer->setAnchorPoint(Point::ANCHOR_MIDDLE);
	skillLayer->setPosition(visibleSize / 2);
	addChild(skillLayer, 1);

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
				initButton("btnArrow2")->setBright(true);
				GameState::studySkillDate("btnArrow2");
			}
		}
		else if(name.compare("btnArrow3")==0)
		{
			if (GameState::getSkillDate("btnArrow2"))
			{
				initButton("btnArrow3")->setBright(true);
				GameState::studySkillDate("btnArrow3");
			}
		}
		//---------------------Fan--------------------
		else if(name.compare("btnFan2") == 0)
		{
			if (GameState::getSkillDate("btnFan1"))
			{
				initButton("btnFan2")->setBright(true);
				GameState::studySkillDate("btnFan2");
			}
		}
		else if (name.compare("btnFan3") == 0)
		{
			if (GameState::getSkillDate("btnFan2"))
			{
				initButton("btnFan3")->setBright(true);
				GameState::studySkillDate("btnFan3");
			}
		}
		//---------------------Bottle--------------------
		else if (name.compare("btnBottle2") == 0)
		{
			if (GameState::getSkillDate("btnBottle1"))
			{
				initButton("btnBottle2")->setBright(true);
				GameState::studySkillDate("btnBottle2");
			}
		}
		else if (name.compare("btnBottle3") == 0)
		{
			if (GameState::getSkillDate("btnBottle2"))
			{
				initButton("btnBottle3")->setBright(true);
				GameState::studySkillDate("btnBottle3");
			}
		}
		//---------------------btnRocket--------------------
		else if (name.compare("btnRocket2") == 0)
		{
			if (GameState::getSkillDate("btnRocket1"))
			{
				initButton("btnRocket2")->setBright(true);
				GameState::studySkillDate("btnRocket2");
			}
		}
		else if (name.compare("btnRocket3") == 0)
		{
			if (GameState::getSkillDate("btnRocket2"))
			{
				initButton("btnRocket3")->setBright(true);
				GameState::studySkillDate("btnRocket3");
			}
		}
		else if (name.compare("btnRocket4") == 0)
		{
			if (GameState::getSkillDate("btnRocket3"))
			{
				initButton("btnRocket4")->setBright(true);
				GameState::studySkillDate("btnRocket4");
			}
		}
		//---------------------btnMagic--------------------
		else if (name.compare("btnFBottle") == 0)
		{
			if (GameState::getSkillDate("btnRocket3") && GameState::getSkillDate("btnBottle3"))
			{
				initButton("btnFBottle")->setBright(true);
				GameState::studySkillDate("btnFBottle");
			}
		}
		else if (name.compare("btnStar") == 0)
		{
			if (GameState::getSkillDate("btnFBottle"))
			{
				initButton("btnStar")->setBright(true);
				GameState::studySkillDate("btnStar");
			}
		}
		else if (name.compare("btnSnow") == 0)
		{
			if (GameState::getSkillDate("btnRocket2"))
			{
				initButton("btnSnow")->setBright(true);
				GameState::studySkillDate("btnSnow");
			}
		}
		else if (name.compare("btnSun") == 0)
		{
			if (GameState::getSkillDate("btnSnow"))
			{
				initButton("btnSun")->setBright(true);
				GameState::studySkillDate("btnSun");
			}
		}
		else if (name.compare("btnAnchor") == 0)
		{
			if (GameState::getSkillDate("btnSun"))
			{
				initButton("btnAnchor")->setBright(true);
				GameState::studySkillDate("btnAnchor");
			}
		}
	}
}



