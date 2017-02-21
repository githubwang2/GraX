#include "Sprite/Monster.h"
#include "Sprite/Components/ComLife.h"
#include "Sprite/Components/ComMove.h"
#include "GameMap.h"

USING_NS_CC;
using namespace cocostudio;
using namespace ui;

Monster::Monster(int id){
	m_id = id;
	m_hp=30;
	m_speed = 10;
}



Monster* Monster::create(int id)
{
	Monster*ret = new Monster(id);
	if (ret != nullptr && ret->initMonster())
	{
		ret->autorelease();
	}
	else
	{
		CC_SAFE_DELETE(ret);
	}
	return ret;
}


bool Monster::initMonster(){
	if (!Layer::init())
	{
		return false;
	}
	//auto monster = Sprite::create("GameMain/Monster.png");
	auto monster = Sprite::create();
	//monster->setScale(2.0);
	//monster->runAction(RepeatForever::create(Animate::create(ani_right)));

	GameMap*gameMap = new GameMap();
	auto path = gameMap->getWalkPath("Walk");

	//���ع����ƶ����
	auto comMove = ComMove::create(path,m_id);
	monster->addComponent(comMove);
	comMove->startMove();	

	//���ع���HP���
	auto comLife = ComLife::create(m_hp);
	monster->addComponent(comLife);

	////����FireManager��m_monsters list��
	//m_fireManager->m_monsters.push_back(comMove);
	////-----------------------------------------------------------
	////--����ģʽ
	////ÿ����һ������ò������һ��Ϊ0ֹͣ�������
	////������1
	//m_monsterCreateLeft--;
	//if (m_monsterCreateLeft == 0)
	//{
	//	unschedule(schedule_selector(MainScene::addMonster));
	//	runAction(Sequence::create(DelayTime::create(3 + m_curRound),
	//		CallFunc::create([=](){
	//		m_curRound++;
	//		createWaveRusher();
	//	})
	//		, nullptr));
	//}

	addChild(monster);

	return true;
}

void Monster::changeDirection(float dt){
	//this->getPosition
}

