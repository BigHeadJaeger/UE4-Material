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
		name = "Sphere" + to_string(sphereCount);
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
	float width;
	float height;
	int m;
	int n;

	static int gridCount;
public:
	Grid()
	{
		gridCount++;
		name = "Grid" + to_string(gridCount);
		width = 1;
		height = 1;
		m = 10;
		n = 10;
	}
	Grid(float _width, float _height, int _m, int _n, string _name)
	{
		name = _name;
		width = _width;
		height = _height;
		m = _m;
		n = _n;
	}
	~Grid()
	{
		gridCount--;
	}
	void InitData();
};