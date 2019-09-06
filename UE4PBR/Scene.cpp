#pragma once
#include "Scene.h"
#include<GLFW\glfw3.h>

void MyScene::Init()
{
	//��ʼ��glew
	glewInit();
	//����shader����
	char vert[] = "test.vert";
	char frag[] = "test.frag";
	p1.SetShader(vert, frag);

	//pShadowTex.SetShader("shadowTex.v", "shadowTex.f");


	//ָ����Դ����
	lightPos = vec3(-3, 5, 3);
	lightColor = vec3(400.f, 400.f, 400.f);
	

	//ָ�������ʼλ��
	mainCamera.Init(vec3(0, 2, 4), vec3(0, 0, 0));

	//SetDrawMode(drawMode.isLine, false);
	drawMode.isLine = false;

	
	

	//ָ������PBR����
	MeshObject cow("cow");
	//cow.SetName("cow");
	cow.readObjFile("OBJ\\cow.obj");
	cow.GetTransform().SetPosition(vec3(3, 0.5, 0));
	cow.GetTransform().SetScaler(vec3(3.0));
	cow.GetShaderData().bUseTexture = false;
	cow.InitVertexBuffer();

	Box box(1, 1, 1, "b");
	box.InitData();
	box.GetTransform().SetPosition(vec3(0, 0, 0));
	//box.GetTransform().
	box.GetShaderData().bUseTexture = true;
	box.InitAlbedo("Material\\metalgrid2-dx\\metalgrid2_basecolor.png");
	box.InitNormal("Material\\metalgrid2-dx\\metalgrid2_normal-dx.png");
	box.InitAo("Material\\metalgrid2-dx\\metalgrid2_AO.png");
	box.InitRoughness("Material\\metalgrid2-dx\\metalgrid2_roughness.png");
	box.InitMetallic("Material\\metalgrid2-dx\\metalgrid2_metallic.png");
	box.InitVertexBuffer();

	Sphere sphere(0.5, 20, 20, "a");
	sphere.InitData();
	sphere.GetTransform().SetPosition(vec3(0, 1, 0));
	sphere.GetShaderData().bUseTexture = false;
	sphere.InitVertexBuffer();

	Grid grid(10, 10, 10, 10, "c");
	grid.InitData();
	grid.GetTransform().SetPosition(vec3(0, -0.5, 0));
	grid.GetShaderData().bUseTexture = true;
	grid.InitAlbedo("Material\\oakfloor\\oakfloor_basecolor.png");
	grid.InitNormal("Material\\oakfloor\\oakfloor_normal.png");
	grid.InitAo("Material\\oakfloor\\oakfloor_AO.png");
	grid.InitRoughness("Material\\oakfloor\\oakfloor_roughness.png");
	grid.SetUV(0.3, 0.3);
	//grid.InitMetallic("Material\\oakfloor\\metalgrid2_metallic.png");
	grid.InitVertexBuffer();

	objects.insert(pair<string, Object>(cow.GetName(), cow));
	objects.insert(pair<string, Object>(box.GetName(), box));
	objects.insert(pair<string, Object>(sphere.GetName(), sphere));
	objects.insert(pair<string, Object>(grid.GetName(), grid));


	//myBox.InitDirectBox(1, 1, 1);					//���㡢������Ϣ��ʼ��
	//myBox.InitBuffers();							//�����ʼ��
	//myBox.CoorDataInit(vec3(-0.5, 0.5, 1.0)/*, vec3(3.0, 0.1, 3.0)*/);
	//myBox.TextureUseInfo(true, true, true, true, true, true);				//����ʹ����Ϣ��ʼ��
	//myBox.InitTexture(myBox.TAlbedo, "Material\\metalgrid2-dx\\metalgrid2_basecolor.png");		//������Ҫ������
	//myBox.InitTexture(myBox.TNormal, "Material\\metalgrid2-dx\\metalgrid2_normal-dx.png");
	//myBox.InitTexture(myBox.TAo, "Material\\metalgrid2-dx\\metalgrid2_AO.png");
	//myBox.InitTexture(myBox.TRoughness, "Material\\metalgrid2-dx\\metalgrid2_roughness.png");
	//myBox.InitTexture(myBox.TMetallic, "Material\\metalgrid2-dx\\metalgrid2_metallic.png");
	//myBox.LightUseInfo(true);						//�����Ƿ���չ���
	//myBox.InitMaterial(vec4(0.5f, 0.5f, 0.5f, 1.0f), vec4(0.5, 0.5, 0.5, 1.0f), vec4(0.7f, 0.7f, 0.7f, 1.0f), 7.0f);


	//STInit();
}

void MyScene::InitKeys()
{
	keys.insert(pair<KEYNAME, Key>(BTNW, Key(BTNW)));
	keys.insert(pair<KEYNAME, Key>(BTNA, Key(BTNA)));
	keys.insert(pair<KEYNAME, Key>(BTNS, Key(BTNS)));
	keys.insert(pair<KEYNAME, Key>(BTND, Key(BTND)));
	keys.insert(pair<KEYNAME, Key>(BTN1, Key(BTN1)));
	//keys.push_back(Key(BTNW));
}

void MyScene::Update()
{

	//�����ӽǾ���
	mainCamera.SetView();
	//����ͶӰ����
	mainCamera.SetPro();

	ConveyTool* conveyTool = ConveyTool::GetConveyTool();
	conveyTool->SetUniform("eyePos", mainCamera.eyePos, p1);
	conveyTool->SetUniform("lightPos", lightPos, p1);
	conveyTool->SetUniform("lightColor", lightColor, p1);

	//��������object���¾���
	map<string, Object>::iterator objs_it;
	for (objs_it = objects.begin(); objs_it != objects.end(); objs_it++)
	{
		(*objs_it).second.UpdateMatrix(mainCamera);
	}

	//cow.UpdateMatrix(mainCamera);
	//myBox.SetObjMat(camera.view, camera.pro);
	//myBucket.SetObjMat(camera.view, camera.pro);
	//myGrid.SetObjMat(camera.view, camera.pro);

	//��������key����ִ��key��ǰ�󶨵��¼�
	map<KEYNAME, Key>::iterator keys_it;
	for (keys_it = keys.begin(); keys_it != keys.end(); keys_it++)
	{
		keys_it->second.Execute();
	}
}

void MyScene::Draw()
{

	//NormalShadowMap();

	//����ÿһ������ʱ���Ƚ����еĸ������������ؾ��󣬲��ʵ���Ϣ����shader��


	//����,��������������գ�����Ч���Ŀ�����blend�� cull֮��ģ�
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);					//��ά����Ҫ���������޳�

	if (drawMode.isLine)
	{
		glDisable(GL_CULL_FACE);
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	}
	else
	{
		glEnable(GL_CULL_FACE);
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	}

	//glFrontFace(GL_CW);
	//glCullFace(GL_FRONT);

	glUseProgram(p1.p);						//������ɫ������

	map<string, Object>::iterator objs_it;
	for (objs_it = objects.begin(); objs_it != objects.end(); objs_it++)
	{
		(*objs_it).second.Draw(p1);
	}

}