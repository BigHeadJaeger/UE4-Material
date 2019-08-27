#pragma once
//��OpenGLshader������صĸ��ֱ����ͷ���
#include<GL/glew.h>
#include<SOIL.h>
#include<OpenMesh/Core/IO/MeshIO.hh>
#include<OpenMesh/Core/Mesh/TriMesh_ArrayKernelT.hh>
#include<string>

#include"Transform.h"
#include"Camera.h"
using namespace std;
typedef OpenMesh::TriMesh_ArrayKernelT<> Mesh;

struct MeshData
{
	Mesh mesh;			//��������
	bool providedTex;	//��¼�ļ��Ƿ�����������
};


class ShaderData
{
private:


public:
	//�������������
	mat4x4 world;					//�������
	mat4x4 worldViewProj;			//��������ת������
	mat4x4 worldInvTranspose;		//������������ת��������ռ�

	//�����VAO��VBO���
	GLuint VAO;
	GLuint VertexBuffer;
	GLuint IndexBuffer;

	//�������ͼ��ţ���һ��ȫ����Ҫ��
	bool bUseTexture;
	GLuint tAlbedo;					//������ͼ��������ɫ��
	bool bAlbedo;
	GLuint tMetallic;				//��������ͼ
	bool bMetallic;
	GLuint tRoughness;				//�ֲ���ͼ
	bool bRoughness;
	GLuint tAo;						//������ͼ
	bool bAo;
	GLuint tNormal;					//������ͼ
	bool bNormal;
	GLuint tShadowTex;				//��Ӱ��ͼ
	bool bShadowTex;

public:
	ShaderData()
	{
		world = mat4(0);
		worldViewProj = mat4(0);
		worldInvTranspose = mat4(0);

		bUseTexture = false;
		bAlbedo = false;
		bMetallic = false;
		bRoughness = false;
		bAo = false;
		bNormal = false;
		bShadowTex = false;
	}

	void SetMatrix(Transform& t, Camera& camera);
	void InitTexture(GLuint& texID, string texPath);		//����������󲢰�����(��ͼƬת��Ϊ�������ݣ����ݲ�ͬ��ID������Ӧ������)
	void InitVertexBuffer(MeshData& mesh);							
};