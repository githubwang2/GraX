#ifndef __Tower_ComMove__
#define __Tower_ComMove__
#include "cocos2d.h"

class ComMove:public cocos2d::Component
{
public:
	static ComMove*create(std::vector<cocos2d::Point> path,int id,int speed);

	virtual void onEnter() override;
	
	//放置起始点并开始移动
	void startMove();
private:
	ComMove(std::vector<cocos2d::Point> path, int id, int speed);		//移动路径上的所有点
	//根据移动路径上的所有点 为起始点以及所有移动的动作赋值
	void initPath(std::vector<cocos2d::Point> path);
	//起始点
	cocos2d::Point m_startPos;
	//所有移动的动作
	cocos2d::Action*m_moveActions;
	//移动路径上的所有点
	std::vector<cocos2d::Point>m_path;

	int m_id;
	int m_speed;
	void initAnimation();

	cocos2d::Animation*ani_up;
	cocos2d::Animation*ani_down;
	cocos2d::Animation*ani_left;
	cocos2d::Animation*ani_right;
	
};

#endif