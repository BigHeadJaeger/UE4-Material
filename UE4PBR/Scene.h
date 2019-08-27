#pragma once
//#include<glm.hpp>
//#include<gtc\matrix_transform.hpp>
//#include<gtc\type_ptr.hpp>
//#include<SOIL.h>
//
//#include"Program.h"
//#include"Camera.h"
//#include"Object.h"
//using namespace glm;
#include"MeshObject.h"
class MyScene
{
private:
	//各种场景信息（相机、材质、灯光、各种物体的各种矩阵）

	//物体
	/*MyGeometryGenerator::MeshData box;
	mat4x4 boxWorld;					//世界矩阵
	mat4x4 boxWorldViewProj;			//最终坐标转换矩阵
	mat4x4 boxWorldInvTranspose;		//用来将法向量转换到世界空间
	//物体材质用材质贴图
	GLuint boxAlbedoT;
	float boxMetallic;
	GLuint boxRoughnessT;
	GLuint boxAoT;
	GLuint boxNormalT;*/


	//sphere
	/*MyGeometryGenerator::MeshData sphere;
	mat4x4 sphereWorld;
	mat4x4 sphereWorldViewProj;			//最终坐标转换矩阵
	mat4x4 sphereWorldInvTranspose;		//用来将法向量转换到世界空间
										//物体材质用材质贴图
	GLuint sphereAlbedoT;
	GLuint sphereMetallicT;
	GLuint sphereRoughnessT;
	float sphereAo;
	GLuint sphereNormalT;*/

	//Object myBox;
	//Object myGrid;
	//Object myBucket;

	MeshObject cow;


	//灯光
	vec3 lightPos;
	vec3 lightColor;


	GLuint frameBuffer;					//帧缓冲
	GLuint depthTex;					//深度纹理
	mat4 depthMVP;						//正交投影变换矩阵
	mat4 depthBiasMVP;					//用于纹理的修正过的矩阵

public:
	//相机
	//MyCamera camera;
	Camera mainCamera;

	//---------------------------------------------------------------------------------

private:
	//void DrawElement(Object & obj, ShaderProgram&p);			//绘制物体(里面包括物体各矩阵的传递和纹理的传递，参数为指定使用哪些贴图)
	//void DrawDepthTexture(Object& obj, ShaderProgram&p);


	//void SetTexture(GLuint & texId, int num, GLenum texNum, string samplerName, ShaderProgram&p);			//将前面生成好的Texture传入shader中的采样器


	//根据不同类型的值用重载的方式传入shader中
	//void SetUniform(string valueName, mat4x4& value, ShaderProgram&p);
	//void SetUniform(string valueName, vec4& value, ShaderProgram&p);
	//void SetUniform(string valueName, vec3& value, ShaderProgram&p);
	//void SetUniform(string valueName, float value, ShaderProgram&p);



	//shader程序
	ShaderProgram p1;

	ShaderProgram pShadowTex;

public:
	void Init();			//初始化各种信息
	void Update();			//需要动画时，计算各种矩阵（暂时不传入shader中）
	void Draw();			//绘制场景
private:
	/*void SetBuffers(Object &obj);		//设置VAO和VBO
	void SetTexture();		//生成纹理并绑定数据*/

	//阴影贴图
	void STInit();						//初始化帧缓冲以及纹理并绑定，初始化时调用一次
	void STConstructProj(vec3 Pos);		//构建光照处的相机以及投影矩阵，不断更新

	void NormalShadowMap();

};