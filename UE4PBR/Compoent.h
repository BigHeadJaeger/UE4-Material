#pragma once
#include<string>
#include"NewObject.h"
using namespace std;
class Component
{
protected:
	string name;
	bool active;
	Object* objBelong;
public:
	Component()
	{
		name = "NewComponent";
		active = true;
		objBelong = NULL;
	}

	void setActive(bool state)
	{
		active = state;
	}
};