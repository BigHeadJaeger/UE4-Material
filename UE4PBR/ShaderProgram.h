//与OpenGLshader配置相关的各种变量和方法
#include<GL/glew.h>
#include"Transform.h"
#pragma once
class ShaderProgram
{
protected:
	//物体的坐标属性
	mat4x4 world;					//世界矩阵
	mat4x4 worldViewProj;			//最终坐标转换矩阵
	mat4x4 worldInvTranspose;		//用来将法向量转换到世界空间

	//物体的VAO、VBO编号
	GLuint VAO;
	GLuint VertexBuffer;
	GLuint IndexBuffer;

	//物体的贴图编号（不一定全都需要）
	bool bUseTexture;
	GLuint tAlbedo;					//反射贴图（基础颜色）
	bool bAlbedo;
	GLuint tMetallic;				//金属度贴图
	bool bMetallic;
	GLuint tRoughness;				//粗糙贴图
	bool bRoughness;
	GLuint tAo;						//环境贴图
	bool bAo;
	GLuint tNormal;					//法线贴图
	bool bNormal;
	GLuint tShadowTex;				//阴影贴图
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
};