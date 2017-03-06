#ifndef __TowerWar_DialogLayer__
#define __TowerWar_DialogLayer__

#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "SoundsControl.h"

class DialogLayer : public cocos2d::Layer
{
public:
	//��Ҫ��ȡ�ĶԻ��ļ�λ��
	static DialogLayer*createWithJsonFile(const char*fileName);
	
	virtual bool init(std::string str);
private:
	
	//�ַ���ƴ�� ʹ��һ��һ���ֵ���ʾ
	//void MultUpdate(float dt);
	//��ĳһ���Ի������ݱ�����������
	void getDateByIndex(int index);
	//��ʾ�������� 
	//void showAllContent();
	//����cocostudio��ui
	void initStudioUI(const char*jsonFile);
	//�����ص�
	void touchDownAction(cocos2d::Ref*sender, cocos2d::ui::Widget::TouchEventType controlEvent);

	//void pushChineseStr(std::string str, std::vector<std::string>&strVector);

	//bool		_isOver;						//	�ַ����Ƿ���ȫ��ʾ
	int			m_index;						//	�����±�

	std::string conversation;					//	json�е��ַ���
	std::vector<std::string>_conVector;			//	ÿ���Ի������� 

	cocos2d::ui::ImageView*BG;					//	����
	//	������3������ ����ͼƬ �������� �Ի�
	cocos2d::ui::Text*speetch;					//	�Ի�����		
	cocos2d::ui::ImageView *name;				//	��������
	cocos2d::ui::ImageView*icon;				//	����ͷ�� 

	std::string mStr;							//	���������ַ���
	//std::string tempStr;						//	����ƴ��ʹ�õ��ַ���
	std::vector<std::string>strVector;			//	����ÿ���ֵ�����
	//int vecLength;								//	�����ĳ���

};

#endif 
