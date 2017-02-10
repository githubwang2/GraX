#include "Sprite/MonsterBase.h"
#include "Sprite/Components/ComLife.h"
#include"Sprite/Components/ComMove.h"
#include "GameMap.h"

USING_NS_CC;
using namespace cocostudio;
using namespace ui;

MonsterBase::MonsterBase(int id){
	m_id = id;
	m_hp=30;
}

Sprite* MonsterBase::createMonster(){
	auto monster = Sprite::create("Tower/Monster.png");
	//auto monster = Sprite::create();

	initAnimation(m_id);
	monster->runAction(RepeatForever::create(Animate::create(ani_right)));

	GameMap*a = new GameMap();
	auto path = a->getWalkPath("Walk");

	//挂载怪物移动组件
	auto comMove = ComMove::create(path);
	monster->addComponent(comMove);
	comMove->startMove();

	//挂载怪物HP组件
	auto comLife = ComLife::create(m_hp);
	monster->addComponent(comLife);

	////存入FireManager的m_monsters list中
	//m_fireManager->m_monsters.push_back(comMove);
	////-----------------------------------------------------------
	////--无限模式
	////每生成一个怪物，该波怪物减一，为0停止产生怪物。
	////波数加1
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

	return monster;
}

void MonsterBase::changeDirection(float dt){
	
}

void MonsterBase::initAnimation(int id){
	cocos2d::Vector<cocos2d::SpriteFrame*>monster_up_vector;
	cocos2d::Vector<cocos2d::SpriteFrame*>monster_down_vector;
	cocos2d::Vector<cocos2d::SpriteFrame*>monster_left_vector;
	cocos2d::Vector<cocos2d::SpriteFrame*>monster_right_vector;

	char path[30] = { 0 };
	sprintf(path, "Monster/%d.png", id);

	for (int i = 0; i < 4; i++)
	{
		SpriteFrame*sf = SpriteFrame::create(path, Rect(48 * i, 48 * 2, 48, 48));
		monster_up_vector.pushBack(sf);
	}
	ani_up = Animation::createWithSpriteFrames(monster_up_vector, 0.05f);

	for (int i = 0; i < 4; i++)
	{
		SpriteFrame*sf = SpriteFrame::create(path, Rect(48 * i, 0, 48, 48));
		monster_down_vector.pushBack(sf);
	}
	ani_down = Animation::createWithSpriteFrames(monster_down_vector, 0.05f);

	for (int i = 0; i < 4; i++)
	{
		SpriteFrame*sf = SpriteFrame::create(path, Rect(48 * i, 48 * 1, 48, 48));
		monster_left_vector.pushBack(sf);
	}
	ani_left = Animation::createWithSpriteFrames(monster_left_vector, 0.05f);

	for (int i = 0; i < 4; i++)
	{
		SpriteFrame*sf = SpriteFrame::create(path, Rect(48 * i, 48 * 3, 48, 48));
		monster_right_vector.pushBack(sf);
	}
	ani_right = Animation::createWithSpriteFrames(monster_right_vector, 0.05f);

}