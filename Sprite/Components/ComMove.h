#ifndef __Tower_ComMove__
#define __Tower_ComMove__
#include "cocos2d.h"


class ComMove:public cocos2d::Component
{
public:
	static ComMove*create(std::vector<cocos2d::Point> path);

	virtual void onEnter() override;
	
	//������ʼ�㲢��ʼ�ƶ�
	void startMove();

private:
	ComMove(std::vector<cocos2d::Point>path);		//�ƶ�·���ϵ����е�
	//�����ƶ�·���ϵ����е� Ϊ��ʼ���Լ������ƶ��Ķ�����ֵ
	void initPath(std::vector<cocos2d::Point> path);
	//��ʼ��
	cocos2d::Point m_startPos;
	//�����ƶ��Ķ���
	cocos2d::Action*m_moveActions;
	//�ƶ�·���ϵ����е�
	std::vector<cocos2d::Point>m_path;

};

#endif