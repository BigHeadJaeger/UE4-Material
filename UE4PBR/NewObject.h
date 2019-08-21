#include<string>
#include<OpenMesh/Core/IO/MeshIO.hh>
#include<OpenMesh/Core/Mesh/TriMesh_ArrayKernelT.hh>
using namespace std;
#include"Transform.h"
#include"ShaderProgram.h"
//#include"Mesh.h"

typedef OpenMesh::TriMesh_ArrayKernelT<> Mesh;
#pragma once
//����Object
class Object
{
protected:
	string name;							//object����
	Transform transformation;				//�Ϳռ�λ���йص�transform���
	ShaderProgram shaderProgram;			//��OpenGL��ص���Ⱦ���
	Mesh mesh;
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