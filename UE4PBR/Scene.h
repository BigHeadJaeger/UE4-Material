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
	//���ֳ�����Ϣ����������ʡ��ƹ⡢��������ĸ��־���

	//����
	/*MyGeometryGenerator::MeshData box;
	mat4x4 boxWorld;					//�������
	mat4x4 boxWorldViewProj;			//��������ת������
	mat4x4 boxWorldInvTranspose;		//������������ת��������ռ�
	//��������ò�����ͼ
	GLuint boxAlbedoT;
	float boxMetallic;
	GLuint boxRoughnessT;
	GLuint boxAoT;
	GLuint boxNormalT;*/


	//sphere
	/*MyGeometryGenerator::MeshData sphere;
	mat4x4 sphereWorld;
	mat4x4 sphereWorldViewProj;			//��������ת������
	mat4x4 sphereWorldInvTranspose;		//������������ת��������ռ�
										//��������ò�����ͼ
	GLuint sphereAlbedoT;
	GLuint sphereMetallicT;
	GLuint sphereRoughnessT;
	float sphereAo;
	GLuint sphereNormalT;*/

	//Object myBox;
	//Object myGrid;
	//Object myBucket;

	MeshObject cow;


	//�ƹ�
	vec3 lightPos;
	vec3 lightColor;


	GLuint frameBuffer;					//֡����
	GLuint depthTex;					//�������
	mat4 depthMVP;						//����ͶӰ�任����
	mat4 depthBiasMVP;					//����������������ľ���

public:
	//���
	//MyCamera camera;
	Camera mainCamera;

	//---------------------------------------------------------------------------------

private:
	//void DrawElement(Object & obj, ShaderProgram&p);			//��������(����������������Ĵ��ݺ�����Ĵ��ݣ�����Ϊָ��ʹ����Щ��ͼ)
	//void DrawDepthTexture(Object& obj, ShaderProgram&p);


	//void SetTexture(GLuint & texId, int num, GLenum texNum, string samplerName, ShaderProgram&p);			//��ǰ�����ɺõ�Texture����shader�еĲ�����


	//���ݲ�ͬ���͵�ֵ�����صķ�ʽ����shader��
	//void SetUniform(string valueName, mat4x4& value, ShaderProgram&p);
	//void SetUniform(string valueName, vec4& value, ShaderProgram&p);
	//void SetUniform(string valueName, vec3& value, ShaderProgram&p);
	//void SetUniform(string valueName, float value, ShaderProgram&p);



	//shader����
	ShaderProgram p1;

	ShaderProgram pShadowTex;

public:
	void Init();			//��ʼ��������Ϣ
	void Update();			//��Ҫ����ʱ��������־�����ʱ������shader�У�
	void Draw();			//���Ƴ���
private:
	/*void SetBuffers(Object &obj);		//����VAO��VBO
	void SetTexture();		//��������������*/

	//��Ӱ��ͼ
	void STInit();						//��ʼ��֡�����Լ������󶨣���ʼ��ʱ����һ��
	void STConstructProj(vec3 Pos);		//�������մ�������Լ�ͶӰ���󣬲��ϸ���

	void NormalShadowMap();

};