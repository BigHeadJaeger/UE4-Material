#pragma once
#include"NewObject.h"


class MeshObject:public Object
{
protected:

public:
	static int meshObjectCount;

	MeshObject()
	{
		meshObjectCount++;
		name = "mesh" + to_string(meshObjectCount);
	}

	MeshObject(string _name)
	{
		name = _name;
	}

	~MeshObject()
	{
		meshObjectCount--;
	}



	void readObjFile(string fileName);

};