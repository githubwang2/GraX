#include "LoadingScene.h"


USING_NS_CC;

Scene* LoadingScene::createScene()
{
	auto scene = Scene::create();
	auto layer = LoadingScene::create();
	scene->addChild(layer);
	return scene;
}

bool LoadingScene::init()
{
	if (!Layer::init())
	{
		return false;
	}

	visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	currentNum = 0;  
	totalNum = 500;

	m_pLabelLoading = CCLabelTTF::create("Loading...", "Arial", 25);
	m_pLabelPercent = CCLabelTTF::create("0%", "Arial", 25);

	m_pLabelLoading->setPosition(ccp(visibleSize.width / 2, visibleSize.height / 3 + 50));
	m_pLabelPercent->setPosition(ccp(visibleSize.width / 2, visibleSize.height / 3));

	this->addChild(m_pLabelLoading);
	this->addChild(m_pLabelPercent);



	run();
	load();


	return true;
}

void LoadingScene::run(){
	auto sprite = Sprite::create();
	Animation*animation = Animation::create();
	char buf[32] = { 0 };
	for (int i = 0; i < 12;i++)
	{
		sprintf(buf, "run/%d.png", (i + 1));
		animation->addSpriteFrameWithFile(buf);
		log("path name is:%s", buf);
	}
	
	animation->setDelayPerUnit(0.08f);
	sprite->runAction(RepeatForever::create(Animate::create(animation)));
	sprite->setPosition(visibleSize / 2);
	addChild(sprite, 1);
}

void LoadingScene::load(){
	loadLabel = LabelTTF::create("Loading..", "Arial", 20);//������ʾLoading: ��label
	loadLabel->setPosition(Point(visibleSize.width / 2, visibleSize.height / 2 + 30));
	this->addChild(loadLabel, 1);

	auto loadBg = Sprite::create("loading.png");//��������ͼ
	loadBg->setPosition(Point(visibleSize / 2));
	addChild(loadBg, 0);

	loadProgress = ProgressTimer::create(Sprite::create("sliderProgress.png"));//����һ��������
	loadProgress->setBarChangeRate(Point(1, 0));//���ý������ı仯����
	loadProgress->setType(ProgressTimer::Type::BAR);//���ý�����������
	loadProgress->setMidpoint(Point(0, 1));//���ý��ȵ��˶�����
	loadProgress->setPosition(Point(visibleSize.width / 2, visibleSize.height / 2));
	loadProgress->setPercentage(0.0f);//���ó�ʼֵΪ0
	this->addChild(loadProgress, 2);

	// load textrues
	Director::getInstance()->getTextureCache()->addImageAsync("MenuBk.jpg", CC_CALLBACK_1(LoadingScene::loadingCallBack, this));
	Director::getInstance()->getTextureCache()->addImageAsync("HelloWorld.png", CC_CALLBACK_1(LoadingScene::loadingCallBack, this));
	


}

void LoadingScene::loadingCallBack(cocos2d::Texture2D *texture)
{
	++_numberOfLoadedSprites;

	float newPercent = 100 - ((float)_numberOfSprites - (float)_numberOfLoadedSprites) / ((float)_numberOfSprites / 100);//�����������ǰ�İٷֱ�
	//��Ϊ����ͼƬ�ٶȺܿ죬���Ծ�û��ʹ��ProgressTo��
	//����ProgressFromTo���ֶ��������½�����
	loadProgress->setPercentage(newPercent);//���½�����

	//ͼƬ������ɺ�
	if (_numberOfLoadedSprites == _numberOfSprites)
	{
		loadLabel->setString("all loaded");
	}
}