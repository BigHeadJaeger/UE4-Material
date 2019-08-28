#pragma once
#include<functional>
#include<glm.hpp>
using namespace glm;
using namespace std;

enum KEYNAME
{
	BTNW,
	BTNA,
	BTNS,
	BTND,
	BTN1,
};

//����״̬����Ϣ
struct Mouse
{
	vec2 cursorPrePos;			//��¼����ǰһλ��
	vec2 cursorNowPos;			//��¼���ڵ�λ��
	bool mouseLeftDown;
	bool mouseRightDown;

	bool isSelect;				//��ʾ��ǰ���Ѿ�ѡ��Ķ���
	bool isCatchPoint;			//��ʾ��ǰ�����϶�����

	int catchObjIndex;			//��ǰ�϶��������index



	Mouse() :cursorPrePos(vec2(0, 0)), mouseLeftDown(false), mouseRightDown(false)
	{
		isCatchPoint = false;
		isSelect = false;
	}
};

//struct KeyBoard
//{
//	bool btnStateW;
//	bool btnStateA;
//	bool btnStateS;
//	bool btnStateD;
//	bool btnState1;
//
//	bool btnStateG;
//
//	KeyBoard()
//	{
//		btnStateW = false;
//		btnStateA = false;
//		btnStateS = false;
//		btnStateD = false;
//		btnState1 = false;
//		btnStateG = false;
//	}
//};
//
//class Interaction
//{
//public:
//	KeyBoard keyBoard;
//	Mouse mouse;
//	
//public:
//	template<typename F>
//	void ExecuteBtnEvent(F funtion)
//};
//enum EventType
//{
//	DOWN,
//	KEEP,
//	UP,
//	NONE
//};
class Key
{
public:
	KEYNAME keyName;
	//bool isDown;
	function<void()> eventFunctionPtr;
	function<void()> outerFunction;
private:
	void EventDown();
	void EventKeep();
	void EventUP();
public:
	Key(KEYNAME name)
	{
		keyName = name;
	}


	//�˺�����update�в���ִ�д�������function
	void Execute();

	//ָ��keyִ��down�¼�������ָ��һ����Ҫ�ⲿ����
	template<typename F>
	void BindDownEvent(F f)
	{
		eventFunctionPtr = bind(EventDown);
		outerFunction = bind(f);
	}
	//template<typename F>
	//void BindDownEvent(F f,float a)
	//{
	//	eventFunctionPtr = bind(EventDown);
	//	//eventType = EventType::DOWN;
	//	outerFunction = bind(f, a);
	//}

	template<typename F>
	void BindKeepEvent(F f)
	{
		eventFunctionPtr = bind(EventDown);
		outerFunction = bind(f);
	}
	//template<typename F>
	//void BindKeepEvent(F f, float a)
	//{
	//	eventFunctionPtr = bind(EventDown);
	//	outerFunction = bind(f, a);
	//}

	template<typename F>
	void BindUpEvent(F f)
	{
		eventFunctionPtr = bind(EventDown);
		outerFunction = bind(f);
	}
	//template<typename F>
	//void BindUpEvent(F f, float a)
	//{
	//	eventFunctionPtr = bind(EventDown);
	//	outerFunction = bind(f, a);
	//}

	//void BindUpEvent() { eventType = EventType::UP; }
	void UnBind()
	{
		eventFunctionPtr = NULL;
		outerFunction = NULL;
	}

	
};


