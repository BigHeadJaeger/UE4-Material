#pragma once
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
	map<string, Object> objects;
	//MeshObject cow;
	//�ƹ�
	vec3 lightPos;
	vec3 lightColor;

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

	//shader����
	ShaderProgram p1;

	ShaderProgram pShadowTex;

public:
	void Init();			//��ʼ��������Ϣ
	void InitKeys();

	void Update();			//��Ҫ����ʱ��������־�����ʱ������shader�У�
	void Draw();			//���Ƴ���
private:
};