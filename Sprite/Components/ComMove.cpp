#include "Sprite/Components/ComMove.h"
#include "Sprite/Monster.h"

USING_NS_CC;

ComMove::ComMove(std::vector<Point>path,int id){
	setName("ComMove");
	m_path = path;
	m_id = id;
}

ComMove*ComMove::create(std::vector<cocos2d::Point> path,int id){
	ComMove*ret = new ComMove(path,id);
	if (ret!=nullptr && ret->init())
	{
		ret->autorelease();
	}
	else
	{
		CC_SAFE_DELETE(ret);
	}
	return ret;
}

void ComMove::initPath(std::vector<cocos2d::Point> path)
{
	if (path.size() == 0)
	{
		CCLOG("no pos");
		return;
	}
	Vector<FiniteTimeAction*>act;
	m_startPos = path.at(0);
	for (int i = 1; i < path.size(); i++)
	{
		//	路径	
		float dur = path.at(i - 1).getDistance(path.at(i));
		float time = dur / 100.0f;
		//	方向
		Animation*animation;
		Vec2 dis = path.at(i) - path.at(i - 1);
		int angle = (int)Vec2(dis.x, dis.y).getAngle() * 180 / 3.14;
		if (45 < angle&&angle < 135)
		{
			animation = ani_up;
		}
		else if (-45 < angle&&angle < 45)
		{
			animation = ani_right;
		}
		else if (-135 < angle&&angle < -45)
		{
			animation = ani_down;
		}
		else
		{
			animation = ani_left;
		}
		auto act2 = Repeat::create(Animate::create(animation), time / 0.4f);
		auto act4 = MoveTo::create(time, path.at(i));
		act.pushBack(Spawn::create(act4, act2, NULL));
		//auto act2 = MoveTo::create(time, path.at(i));
		//act.pushBack(act2);
	}

	//--------------怪物走到终点 减血并移除怪物
	act.pushBack(CallFunc::create([=](){
		auto playground = dynamic_cast<GameMainLayer*>(getOwner()->getParent());
		auto curLife = playground->changeLife(-1);
		//if (curLife <= 0){
		//	//失败 游戏结束
		//	CCLOG("end");
		//	playground->endGame(false);
		//}
		CCLOG("remove one");
		getOwner()->removeFromParent();
	}));

	m_moveActions = Sequence::create(act);
}

void ComMove::onEnter(){

	initAnimation();

	initPath(m_path);
}

void ComMove::startMove(){
	auto owner = getOwner();
	if (!m_moveActions)
	{
		CCLOG("no m_moveActions");
		return;
	}
	owner->setPosition(m_startPos);
	owner->runAction(m_moveActions);
}

void ComMove::initAnimation(){
	cocos2d::Vector<cocos2d::SpriteFrame*>monster_up_vector;
	cocos2d::Vector<cocos2d::SpriteFrame*>monster_down_vector;
	cocos2d::Vector<cocos2d::SpriteFrame*>monster_left_vector;
	cocos2d::Vector<cocos2d::SpriteFrame*>monster_right_vector;

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


