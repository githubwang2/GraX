//
//	DialogLayer.h
//
//	TowerWar
//
//	Create by wang2 on	17-1-23
//
#ifndef __TowerWar_DialogLayer__
#define __TowerWar_DialogLayer__

#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include"ui/CocosGUI.h"
USING_NS_CC;
using namespace cocostudio;
using namespace ui;
using namespace rapidjson;

class DialogLayer : public cocos2d::Layer
{
public:

	static DialogLayer*createWithJsonFile(const char*fileName);

	virtual bool init(std::string str);
	void MultUpdate(float dt);
	//��ĳһ���Ի������ݱ�����������
	void getDateByIndex(int index);
	//��ʾ�������� 
	void showAllContent();
	//����cocostudio��ui
	void initStudioUI(const char*jsonFile);
	//�����ص�
	void touchDownAction(Ref*sender, Widget::TouchEventType controlEvent);
	void pushChineseStr(std::string str, std::vector<std::string>&strVector);
private:
	
	bool _isOver;							//	�ַ����Ƿ���ȫ��ʾ
	int m_index;								//	�����±�

	std::string conversation;				//	json�е��ַ���
	std::vector<std::string>_conVector;		//	ÿ���Ի������� 
											//	������3������ ����ͼƬ �������� �Ի�
	Text*speetch;							//	�Ի�����		
	Text *name;								//	��������
	ImageView*icon;							//	����ͷ�� 

	std::string mStr;
	std::string tempStr;					//	
	std::vector<std::string>strVector;		//ÿ��Ԫ�ض���1������
	int vecLength;							//�����ĳ���

	Node*node;
};

#endif 
