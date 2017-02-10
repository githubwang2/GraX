#include "Sprite/Monster.h"

#include "GameMap.h"

USING_NS_CC;
using namespace cocostudio;
using namespace ui;

Monster::Monster(int id){
	Sprite *monster = Sprite::create("Tower/Monster.png");
	//Sprite*monster = Sprite::create();
	GameMap*a = new GameMap();
	auto path = a->getWalkPath("Walk");
	if (path.size()==0)
	{
	return;
	}
	Vector<FiniteTimeAction*>act;
	//----------------
	Vector<FiniteTimeAction*>dir;
	//-------------
	auto starPos = path.at(0);
	for (int i = 1; i < path.size(); i++)
	{
		float dur = path.at(i - 1).getDistance(path.at(i));
		float time = dur / 100.0f;
		act.pushBack(MoveTo::create(time, path.at(i)));
		initAnimation(1);
		Animation*aa;
		//----------------------------------------------------------
			Vec2 dis = path.at(i) - path.at(i - 1);
			int a = Vec2(dis.y, dis.x).getAngle();
			CCLOG("dis.x%f,dis.y%f", dis.x, dis.y);
			CCLOG("aaaaaaaaaaaaaaa%d", a);
			if (a <= 2)
			{
				aa = ani_up;
			}
			else
			{
				aa = ani_down;
			}
		dir.pushBack(Repeat::create(Animate::create(aa), time/0.4f));
		//----------------------------------------------------
	}
	monster->setPosition(starPos);
	Action*act3 = Sequence::create(act);
	Action*dir3 = Sequence::create(dir);
	//monster->runAction(Spawn::create(left, act3, NULL));
	monster->runAction(dir3);
	monster->runAction(act3);
	addChild(monster, 1);
	//monster->runAction(act2);
	//------------------------------------------
	
	
	//------------------------------------------
	

	////挂载怪物HP组件
	//auto comLife = ComLife::create(monster_hp);
	//monster->addComponent(comLife);
	////挂载怪物移动组件
	//auto comMove = ComMove::create(m_pathVec);
	//monster->addComponent(comMove);
	//comMove->startMove();
	////存入FireManager的m_monsters list中
	//m_fireManager->m_monsters.push_back(comMove);
	////-----------------------------------------------------------
	////每生成一个怪物，该波怪物减一，为0停止产生怪物。
	////波数加1
	//m_monsterCreateLeft--;
	//if (m_monsterCreateLeft == 0)
	//{
	//	unschedule(schedule_selector(TowerScene::makeMonster));
	//	runAction(Sequence::create(DelayTime::create(3 + m_curRound),
	//		CallFunc::create([=](){
	//		m_curRound++;
	//		createWaveRusher();
	//	})
	//		, nullptr));
	//}
	//make();
	
}

void Monster::initAnimation(int id){
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