#include<string>
using namespace std;
#include"Transform.h"
#include"ShaderProgram.h"
//#include"Mesh.h"
#pragma once
//ª˘¿‡Object
class Object
{
protected:
	string name;
	Transform transformation;
	ShaderProgram shaderProgram;
public:

	Object()
	{

	}

	//void SetMatrix()
	//{
	//	shaderProgram.Set(transformation);
	//}
};