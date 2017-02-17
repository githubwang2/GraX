#include "Sprite/Components/ComMove.h"
#include "Sprite/Monster.h"
#include "Scene/MainScene.h"

USING_NS_CC;

ComMove::ComMove(std::vector<Point>path){
	setName("ComMove");
	m_path = path;
}

ComMove*ComMove::create(std::vector<cocos2d::Point> path){
	ComMove*ret = new ComMove(path);
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
		////	方向
		//Animation*animation;
		//Vec2 dis = path.at(i) - path.at(i - 1);
		//int angle = (int)Vec2(dis.x, dis.y).getAngle() * 180 / 3.14;
		//if (45 < angle&&angle < 135)
		//{
		//	animation = ani_up;
		//}
		//else if (-45 < angle&&angle < 45)
		//{
		//	animation = ani_right;
		//}
		//else if (-135 < angle&&angle < -45)
		//{
		//	animation = ani_down;
		//}
		//else
		//{
		//	animation = ani_left;
		//}
		//auto act2 = Repeat::create(Animate::create(animation), time / 0.2f);
		//auto act4 = MoveTo::create(time, path.at(i));
		//act.pushBack(Spawn::create(act4, act2, NULL));
		auto act2 = MoveTo::create(time, path.at(i));
		act.pushBack(act2);
	}

	//--------------怪物走到终点 减血并移除怪物
	act.pushBack(CallFunc::create([=](){
		auto playground = dynamic_cast<MainScene*>(getOwner()->getParent());
		auto curLife=HUDLayer::changeLife(-1);
		if (curLife <= 0){
			//失败 游戏结束
			CCLOG("end");
			playground->endGame(false);
		}
		CCLOG("remove one");
		//playground->removeMonster(getOwner());
	}));

	m_moveActions = Sequence::create(act);
}

void ComMove::onEnter(){
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

