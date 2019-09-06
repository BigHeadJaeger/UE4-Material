#pragma once
#include"NewObject.h"

class GeometryObject :public Object
{
public:
	virtual void InitData() = 0;
};

class Box :public GeometryObject
{
protected:
	float width;
	float height;
	float depth;

	static int boxCount;
public:
	Box()
	{
		boxCount++;
		name = "Box" + to_string(boxCount);
		width = 1;
		height = 1;
		depth = 1;
	}

	Box(float _width, float _height, float _depth)
	{
		width = _width;
		height = _height;
		depth = _depth;
	}
	~Box()
	{
		boxCount--;
	}
	void InitData();
};

class Sphere :public GeometryObject
{
public:
	void InitData(float radius, int slice, int stack);
};

class Grid :public GeometryObject
{
public:
	void InitData(float width, float height, int m, int n);
};