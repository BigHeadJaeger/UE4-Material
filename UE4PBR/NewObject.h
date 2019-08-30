#pragma once
#include<string>
using namespace std;
#include"ShaderData.h"
#include"Program.h"
#include"DataConvey.h"

#pragma once
//����Object
class Object
{
protected:
	string name;							//object����
	Transform transformation;				//�Ϳռ�λ���йص�transform���
	ShaderData shaderData;					//��OpenGL��ص���Ⱦ���
	MeshData meshData;

protected:
	////��texture��shader��
	//void SetTexture(GLuint& texId, int num, GLenum texNum, string samplerName, ShaderProgram& p);
	////���ݲ�ͬ���͵�ֵ�����صķ�ʽ����shader��
	//void SetUniform(string valueName, mat4x4& value, ShaderProgram& p);
	//void SetUniform(string valueName, vec4& value, ShaderProgram& p);
	//void SetUniform(string valueName, vec3& value, ShaderProgram& p);
	//void SetUniform(string valueName, float value, ShaderProgram& p);
public:

	Object()
	{

	}

	string getName() { return name; }
	Transform& getTransform() { return transformation; }
	ShaderData& getShaderData() { return shaderData; }
	MeshData& getMeshData() { return meshData; }

	void UpdateMatrix(Camera& camera) { shaderData.UpdateMatrix(transformation, camera); }
	void InitVertexBuffer() { shaderData.InitVertexBuffer(meshData); }

	void InitAlbedo(string texPath) { shaderData.bAlbedo = true; shaderData.InitTexture(shaderData.tAlbedo, texPath); }
	void InitMetallic(string texPath) { shaderData.bMetallic = true; shaderData.InitTexture(shaderData.tMetallic, texPath); }
	void InitRoughness(string texPath) { shaderData.bRoughness = true; shaderData.InitTexture(shaderData.tRoughness, texPath); }
	void InitAo(string texPath) { shaderData.bAo = true; shaderData.InitTexture(shaderData.tAo, texPath); }
	void InitNormal(string texPath) { shaderData.bNormal = true; shaderData.InitTexture(shaderData.tNormal, texPath); }
	void InitShadowTex(string texPath) { shaderData.bShadowTex = true; shaderData.InitTexture(shaderData.tShadowTex, texPath); }

	void Draw(ShaderProgram& p);
};