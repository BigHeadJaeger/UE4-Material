#include<string>

using namespace std;
#include"ShaderProgram.h"
//#include"Mesh.h"


#pragma once
//基类Object
class Object
{
protected:
	string name;							//object名称
	Transform transformation;				//和空间位置有关的transform组件
	ShaderProgram shaderProgram;			//和OpenGL相关的渲染组件
	MeshData meshData;
public:

	Object()
	{

	}

	Transform& getTransform() { return transformation; }
	ShaderProgram& getShaderProgram() { return shaderProgram; }

	void SetMatrix()
	{
		shaderProgram.SetMatrix(transformation);
	}

	void SetAlbedo(string texPath) { shaderProgram.InitTexture(shaderProgram.tAlbedo, texPath); }
	void SetMetallic(string texPath) { shaderProgram.InitTexture(shaderProgram.tMetallic, texPath); }
	void SetRoughness(string texPath){ shaderProgram.InitTexture(shaderProgram.tRoughness, texPath); }
	void SetAo(string texPath){ shaderProgram.InitTexture(shaderProgram.tAo, texPath); }
	void SetNormal(string texPath){ shaderProgram.InitTexture(shaderProgram.tNormal, texPath); }
	void SetShadowTex(string texPath){ shaderProgram.InitTexture(shaderProgram.tShadowTex, texPath); }
};