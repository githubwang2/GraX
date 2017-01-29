#include"StageChooseScene.h"


Scene*StageChooseScene::createScene(){
	auto scene = Scene::create();
	auto layer = StageChooseScene::create();
	scene->addChild(layer);
	return scene;
}
bool StageChooseScene::init(){
	if (!Layer::init())
	{
		return false;
	}

	visibleSize = Director::getInstance()->getWinSize();
	taskSize = Size(960, 640);
	int offsetX = (visibleSize.width - taskSize.width) / 2;
	int offsetY = (visibleSize.height - taskSize.height) / 2;
	m_screenOffset = Point(offsetX, offsetY);

	addBackgroundSprite();
	
	

	m_currentPage = 1;
	//
	return true;
}

void StageChooseScene::addBackgroundSprite(){
	auto stageChoose = dynamic_cast<Widget*>(GUIReader::getInstance()
		->widgetFromJsonFile("StageChoose/StageChoose.json"));
	stageChoose->setPosition(Point::ZERO);
	addChild(stageChoose);

	lblStage = dynamic_cast<TextBMFont*>(stageChoose->getChildByName("lblStage"));
	lblStage->setString("aaa");
	//addChild(lblStage);

	auto label = LabelTTF::create("雄大なる緑の大地", "Meiryo", 24);
	label->setPosition(500, 100);
	this->addChild(label);

	loadPageList(stageChoose);
}

void StageChooseScene::loadPageList(Widget*uiRoot){
	m_taskPage = dynamic_cast<PageView*>(uiRoot->getChildByName("ScrollView"));

	char name[32] = { 0 };

	for (int i = 1; i <= STAGE_MAX;++i)
	{
		memset(name, 0, sizeof(name));
		sprintf(name, "stage%d.json", i);
		
	}

	m_currentPage = (int)m_taskPage->getCurPageIndex() + 1;
	CCLOG("m_currentPage");
}

