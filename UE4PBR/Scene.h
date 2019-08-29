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
#include<map>
using namespace std;
#include"MeshObject.h"
#include"Interaction.h"

struct DrawMode
{
	bool isLine;
};
class MyScene
{
private:
	//���ֳ�����Ϣ����������ʡ��ƹ⡢��������ĸ��־���

	//Object myBox;
	//Object myGrid;
	//Object myBucket;

	MeshObject cow;
	//�ƹ�
	vec3 lightPos;
	vec3 lightColor;


	//GLuint frameBuffer;					//֡����
	//GLuint depthTex;					//�������
	//mat4 depthMVP;						//����ͶӰ�任����
	//mat4 depthBiasMVP;					//����������������ľ���

public:
	//���
	//MyCamera camera;
	Camera mainCamera;
	//vector<Key> keys;
	map<KEYNAME, Key> keys;

	Mouse mouse;

	DrawMode drawMode;
	//---------------------------------------------------------------------------------

private:
	//void DrawElement(Object & obj, ShaderProgram&p);			//��������(����������������Ĵ��ݺ�����Ĵ��ݣ�����Ϊָ��ʹ����Щ��ͼ)
	//void DrawDepthTexture(Object& obj, ShaderProgram&p);


	//shader����
	ShaderProgram p1;

	ShaderProgram pShadowTex;

public:
	void Init();			//��ʼ��������Ϣ
	void InitKeys();

	void Update();			//��Ҫ����ʱ��������־�����ʱ������shader�У�
	void Draw();			//���Ƴ���

	//void SetDrawMode(bool& mode, bool state) { mode = state; }
private:
	/*void SetBuffers(Object &obj);		//����VAO��VBO
	void SetTexture();		//��������������*/

	//��Ӱ��ͼ
	//void STInit();						//��ʼ��֡�����Լ������󶨣���ʼ��ʱ����һ��
	//void STConstructProj(vec3 Pos);		//�������մ�������Լ�ͶӰ���󣬲��ϸ���

	//void NormalShadowMap();

};