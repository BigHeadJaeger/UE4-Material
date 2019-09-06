#pragma once
#include"NewObject.h"
#include"Const.h"

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

	Box(float _width, float _height, float _depth, string _name)
	{
		name = _name;
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
protected:
	float radius;
	int slice;
	int stack;

	static int sphereCount;
public:
	Sphere()
	{
		sphereCount++;
		name = "sphere" + to_string(sphereCount);
		radius = 1;
		slice = 10;
		stack = 10;
	}
	Sphere(float _radius, int _slice, int _stack, string _name)
	{
		radius = _radius;
		slice = _slice;
		stack = _stack;
		name = _name;
	}
	~Sphere()
	{
		sphereCount--;
	}
	void InitData();
};

class Grid :public GeometryObject
{
public:
	void InitData(float width, float height, int m, int n);
};