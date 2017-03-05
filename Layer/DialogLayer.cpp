#include"Layer/DialogLayer.h"

USING_NS_CC;
using namespace cocostudio;
using namespace ui;

DialogLayer*DialogLayer::createWithJsonFile(const char*fileName){
	DialogLayer*dialogLayer = new DialogLayer();
	if (dialogLayer && dialogLayer->init(fileName))
	{
		dialogLayer->autorelease();
	}
	else
	{
		CC_SAFE_DELETE(dialogLayer);
	}
	return dialogLayer;
}

bool DialogLayer::init(std::string str){
	initStudioUI("DialogLayer/DialogLayer.json");
	
	conversation = FileUtils::getInstance()->getStringFromFile(str);
	m_index = 0;
	//vecLength = 0;

	getDateByIndex(m_index);

	return true;
}
void DialogLayer::getDateByIndex(int index){
	rapidjson::Document doc;
	doc.Parse<rapidjson::kParseDefaultFlags>(conversation.c_str());
	_conVector.clear();
    //_isOver = false;
	rapidjson::Value & array = doc["Conversation"];
	//array�ǲ�������
	if (array.IsArray())
	{
		int i = index;
		int j = 0;
		strVector.clear();

		if (i >= array.Size())		//	˵���Ѿ���ʾ��ȫ
		{
			CCLOG("end Dialog ");
			this->getParent()->removeChild(this);
			//�ٷ���BUG  3.3��ʼ�Ѿ��޸�  
			//releaseUpEvent������� ������setVisible()֮��Ľ�����
			//ò�������� ������UIWidget::releaseUpEvent()��ʱ��,
			//�ȴ����µ�_touchEventCallback,����ھɰ��_touchEventListener& _touchEventSelector
			//Ȼ����_touchEventCallback��ʱ���Ѿ�remove���Լ�.Ȼ��_touchEventListener& _touchEventSelector�ͻ�ָ�����
			//�������������Widget::releaseUpEvent()  ��ʱû�з��ָ�����
			return;
		}
		for (j = 0; j < array[i]["content"].Size(); j++)
		{
			rapidjson::Value &str = array[i]["content"][j];
			mStr = str.GetString();
			//CCLOG("test str %s", mStr.c_str());
			_conVector.push_back(str.GetString());
		/*	if (j == 3)
			{
				pushChineseStr(mStr, strVector);
			}*/
		}
		BG->loadTexture(_conVector[0], TextureResType::LOCAL);
		name->loadTexture(_conVector[1], TextureResType::PLIST);
		icon->loadTexture(_conVector[2], TextureResType::PLIST);
		speetch->setString(_conVector[3]);
	}
	//tempStr = "";
	//schedule(schedule_selector(DialogLayer::MultUpdate));
}

//void DialogLayer::pushChineseStr(std::string str, std::vector<std::string>&strVector){
//	int sum = strlen(str.c_str());
//	for (int  cur = 0; cur < sum; )
//	{
//		std::string lines;
//		char t = str[cur];
//		if ((t&0xE0)==0xE0)				//1110 0000 
//		{
//			lines = lines + t + str[cur + 2];
//			cur += 3;
//		}
//		else if ((t & 0xC0) == 0xC0)	//2 byte
//		{
//			lines = lines + t + str[cur + 1];
//			cur += 1;
//		}
//		else
//		{
//			lines = lines + t ;
//			cur ++;
//		}
//		CCLOG("%s", lines.c_str());
//		strVector.push_back(lines);
//	}
//
//}

//void DialogLayer::MultUpdate(float dt){
//	if (vecLength < (int)strVector.size())
//	{
//		tempStr = tempStr + strVector[vecLength].c_str();
//		speetch->setString(tempStr.c_str());
//		vecLength++;
//	}
//	else
//	{
//		_isOver = true;
//		unschedule(schedule_selector(DialogLayer::MultUpdate));
//	}
//}

//void DialogLayer::showAllContent(){
//	_isOver = true;
//	unschedule(schedule_selector(DialogLayer::MultUpdate));
//	speetch->setString(mStr.c_str());
//}

void DialogLayer::initStudioUI(const char*jsonFile){

	Layout*layout = static_cast<Layout*>(GUIReader::getInstance()->widgetFromJsonFile(jsonFile));
	BG = static_cast<ImageView*>(layout->getChildByName("BG"));
	name = static_cast<ImageView*>(layout->getChildByName("dialogNameBG")->getChildByName("imgName"));
	icon = static_cast<ImageView*>(layout->getChildByName("imgPlayer"));
	speetch = static_cast<Text*>(layout->getChildByName("dialogBG")->getChildByName("lblText"));

	layout->addTouchEventListener(CC_CALLBACK_2(DialogLayer::touchDownAction, this));

	this->addChild(layout);
}

void DialogLayer::touchDownAction(Ref*sender, Widget::TouchEventType controlEvent){
	if (controlEvent == Widget::TouchEventType::ENDED)
	{
		//if (_isOver==true)
		//{
			m_index++;
			getDateByIndex(m_index);
			/*}
			else
			{
			this->showAllContent();
			}*/
	}
}