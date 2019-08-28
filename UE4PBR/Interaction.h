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

//鼠标的状态和信息
struct Mouse
{
	vec2 cursorPrePos;			//记录光标的前一位置
	vec2 cursorNowPos;			//记录现在的位置
	bool mouseLeftDown;
	bool mouseRightDown;

	bool isSelect;				//表示当前有已经选择的东西
	bool isCatchPoint;			//表示当前正在拖动顶点

	int catchObjIndex;			//当前拖动的物体的index



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


	//此函数在update中不断执行传进来的function
	void Execute();

	//指定key执行down事件，并且指定一个需要外部函数
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


