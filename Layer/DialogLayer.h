#ifndef __TowerWar_DialogLayer__
#define __TowerWar_DialogLayer__

#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "SoundsControl.h"

class DialogLayer : public cocos2d::Layer
{
public:
	//需要读取的对话文件位置
	static DialogLayer*createWithJsonFile(const char*fileName);
	
	virtual bool init(std::string str);
private:
	
	//字符串拼接 使其一个一个字的显示
	//void MultUpdate(float dt);
	//将某一个对话的内容保存在容器中
	void getDateByIndex(int index);
	//显示所有文字 
	//void showAllContent();
	//加载cocostudio的ui
	void initStudioUI(const char*jsonFile);
	//案件回调
	void touchDownAction(cocos2d::Ref*sender, cocos2d::ui::Widget::TouchEventType controlEvent);

	//void pushChineseStr(std::string str, std::vector<std::string>&strVector);

	//bool		_isOver;						//	字符串是否完全显示
	int			m_index;						//	数组下标

	std::string conversation;					//	json中的字符串
	std::vector<std::string>_conVector;			//	每个对话的数组 

	cocos2d::ui::ImageView*BG;					//	背景
	//	数组中3个内容 人物图片 人物名字 对话
	cocos2d::ui::Text*speetch;					//	对话内容		
	cocos2d::ui::ImageView *name;				//	人物名字
	cocos2d::ui::ImageView*icon;				//	人物头像 

	std::string mStr;							//	保存整个字符串
	//std::string tempStr;						//	用于拼接使用的字符串
	std::vector<std::string>strVector;			//	保存每个字的容器
	//int vecLength;								//	容器的长度

};

#endif 
