#include"Layer/SettingLayer.h"

USING_NS_CC;
using namespace ui;
using namespace cocostudio;

bool SettingLayer::init()
{
	if (!Layer::init())
	{
		return false;
	}

	visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	settingLayer = GUIReader::getInstance()->widgetFromJsonFile("MenuScene/SettingLayer.json");
	settingLayer->setAnchorPoint(Point::ANCHOR_MIDDLE);
	settingLayer->setPosition(visibleSize / 2);
	addChild(settingLayer, 1);

	imgMusicOn = dynamic_cast<ImageView*>(settingLayer->getChildByName("imgMusicOn"));
	imgMusicOff = dynamic_cast<ImageView*>(settingLayer->getChildByName("imgMusicOff"));
	imgJP = dynamic_cast<ImageView*>(settingLayer->getChildByName("imgJP"));
	imgCN = dynamic_cast<ImageView*>(settingLayer->getChildByName("imgCN"));

	imgMusicOn->setScale(0,0.5);
	imgMusicOff->setScale(0, 0.5);
	imgCN->setScale(0, 0.5);
	imgJP->setScale(0, 0.5);

	auto btn = dynamic_cast<Widget*>(settingLayer->getChildByName("btnGameMenu"));
	btn->addTouchEventListener(this, toucheventselector(MenuScene::touchButton));

	initSettingButton();

	return true;
}


void SettingLayer::initSettingButton()
{
	music_on = UserDefault::getInstance()->getBoolForKey("music_on_key", true);
	language_jp = UserDefault::getInstance()->getBoolForKey("language_jp_key", true);

	Menu* menu = Menu::create();
	menu->setPosition(Point::ZERO);
	this->addChild(menu, 1);

	auto btnMusicOff = MenuItemFont::create("Music:Off");
	btnMusicOff->setFontSize(40);
	btnMusicOff->setColor(ccc3(0, 153, 153));
	auto btnMusicOn = MenuItemFont::create("Music:On");
	btnMusicOn->setFontSize(40);
	btnMusicOn->setColor(ccc3(0, 153, 153));
	MenuItemToggle*itemMusic;
	if (music_on)
	{
		itemMusic = MenuItemToggle::createWithCallback(CC_CALLBACK_1(SettingLayer::touchButton, this),
			btnMusicOn, btnMusicOff, nullptr);
	}
	else
	{
		itemMusic = MenuItemToggle::createWithCallback(CC_CALLBACK_1(SettingLayer::touchButton, this),
			btnMusicOff, btnMusicOn, nullptr);
	}
	itemMusic->setPosition(Point(330, 350));
	itemMusic->setTag(10);
	menu->addChild(itemMusic, 2);

	auto btnCN = MenuItemFont::create("Language:Chinese");
	btnCN->setFontSize(40);
	btnCN->setColor(ccc3(0, 153, 153));
	auto btnJP = MenuItemFont::create("Language:Japenses");
	btnJP->setFontSize(40);
	btnJP->setColor(ccc3(0, 153, 153));
	MenuItemToggle*itemLanguage;
	if (language_jp)
	{
		itemLanguage = MenuItemToggle::createWithCallback(CC_CALLBACK_1(SettingLayer::touchButton, this),
			btnJP, btnCN, nullptr);
	}
	else
	{
		itemLanguage = MenuItemToggle::createWithCallback(CC_CALLBACK_1(SettingLayer::touchButton, this),
			btnCN, btnJP, nullptr);
	}
	itemLanguage->setPosition(Point(330, 250));
	itemLanguage->setTag(11);
	menu->addChild(itemLanguage, 2);

	if (language_jp&&music_on)
	{
		imgMusicOn->setScale(0.5);
		imgTS = imgMusicOn;
	}
	else if (language_jp&&!music_on)
	{
		imgMusicOff->setScale(0.5);
		imgTS = imgMusicOff;
	}
	else if (!language_jp&&music_on)
	{
		imgCN->setScale(0.5);
		imgTS = imgCN;
	}
	else
	{
		imgJP->setScale(0.5);
		imgTS = imgJP;
	}
}


void SettingLayer::touchButton(Ref *pSender){
	MenuItemToggle*itemToggle = (MenuItemToggle*)pSender;
	int tag = itemToggle->getTag();
	switch (tag)
	{
	case 10:{
			   if (music_on)
			   {
				   UserDefault::getInstance()->setBoolForKey("music_on_key", false);
				   music_on = false;
				   touchEffect(imgMusicOff);
				   SoundsControl::stopBGM();
			   }
			   else
			   {
				   UserDefault::getInstance()->setBoolForKey("music_on_key", true);
				   music_on = true;
				   touchEffect(imgMusicOn);
				   SoundsControl::startBGM();
			   }
			   break;
	}
	case 11:{
				   if (language_jp)
				   {
					   UserDefault::getInstance()->setBoolForKey("language_jp_key", false);
					   language_jp = false;
					   touchEffect(imgCN);
				   }
				   else
				   {
					   UserDefault::getInstance()->setBoolForKey("language_jp_key", true);
					   language_jp = true;
					   touchEffect(imgJP);
				   }
				   break;
	}
	default:
		break;
	}
}

void SettingLayer::touchEffect(ImageView *imgShow)
{
	ScaleTo* scaleToHide = ScaleTo::create(0.3f, 0.0f, 0.5f);
	auto funcScaleToShow = [=](){
		ScaleTo* scaleToShow = ScaleTo::create(0.3f, 0.5f, 0.5f);
		imgShow->runAction(scaleToShow);
	};
	CallFunc* callFuncSpr1 = CallFunc::create(funcScaleToShow);
	Sequence* sequence = Sequence::create(scaleToHide, callFuncSpr1, nullptr);
	imgTS->runAction(sequence);
	imgTS = imgShow;
}
