//��OpenGLshader������صĸ��ֱ����ͷ���
#include<GL/glew.h>
#include<SOIL.h>
#include"Transform.h"
#pragma once
class ShaderProgram
{
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
	ShaderProgram()
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

	void SetMatrix(Transform& t);
	void InitTexture(GLuint& texID, string texPath);		//����������󲢰�����(��ͼƬת��Ϊ�������ݣ����ݲ�ͬ��ID������Ӧ������)

};