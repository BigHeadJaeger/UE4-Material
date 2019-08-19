#include"Transform.h"
#include"Camera.h"
//#include"Mesh.h"
#pragma once

struct Components
{
	Transform* transformation;
	Camera* camera;
	//Mesh* mesh;
};
//ª˘¿‡Object
class Object
{
private:
	Components components;
public:
	Object()
	{
		components.transformation = new Transform();
	}

	void AddComponent();
};