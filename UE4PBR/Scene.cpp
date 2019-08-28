#pragma once
#include "Scene.h"
#include<GLFW\glfw3.h>

void MyScene::Init()
{
	//初始化glew
	glewInit();
	//创建shader程序
	p1.SetShader("test.vert", "test.frag");

	//pShadowTex.SetShader("shadowTex.v", "shadowTex.f");


	//指定光源参数
	lightPos = vec3(-3, 5, 3);
	lightColor = vec3(400.f, 400.f, 400.f);

	//指定相机初始位置
	mainCamera.Init(vec3(0, 2, 4), vec3(0, 0, 0));




	//指定物体PBR材质
	cow.readObjFile("OBJ\\cow.obj");
	cow.getTransform().SetPosition(vec3(0, 0, 0));
	//cow.getTransform().SetScaler(vec3(3.0));
	cow.getShaderData().bUseTexture = false;
	cow.InitVertexBuffer();

	//myBox.InitDirectBox(1, 1, 1);					//顶点、索引信息初始化
	//myBox.InitBuffers();							//缓冲初始化
	//myBox.CoorDataInit(vec3(-0.5, 0.5, 1.0)/*, vec3(3.0, 0.1, 3.0)*/);
	//myBox.TextureUseInfo(true, true, true, true, true, true);				//纹理使用信息初始化
	//myBox.InitTexture(myBox.TAlbedo, "Material\\metalgrid2-dx\\metalgrid2_basecolor.png");		//生成需要的纹理
	//myBox.InitTexture(myBox.TNormal, "Material\\metalgrid2-dx\\metalgrid2_normal-dx.png");
	//myBox.InitTexture(myBox.TAo, "Material\\metalgrid2-dx\\metalgrid2_AO.png");
	//myBox.InitTexture(myBox.TRoughness, "Material\\metalgrid2-dx\\metalgrid2_roughness.png");
	//myBox.InitTexture(myBox.TMetallic, "Material\\metalgrid2-dx\\metalgrid2_metallic.png");
	//myBox.LightUseInfo(true);						//设置是否接收光照
	//myBox.InitMaterial(vec4(0.5f, 0.5f, 0.5f, 1.0f), vec4(0.5, 0.5, 0.5, 1.0f), vec4(0.7f, 0.7f, 0.7f, 1.0f), 7.0f);
	
	/*myGrid.initDirectGrid(1, 1, 10, 10);					//顶点、索引信息初始化
	myGrid.InitBuffers();							//缓冲初始化
	myGrid.CoorDataInit(vec3(0.0, 0.0, 0.0), vec3(4.0, 1, 4.0));
	myGrid.TextureUseInfo(true, true, true, true, true, true);				//纹理使用信息初始化
	myGrid.InitTexture(myGrid.TAlbedo, "Material\\oakfloor\\oakfloor_basecolor.png");		//生成需要的纹理
	myGrid.InitTexture(myGrid.TNormal, "Material\\oakfloor\\oakfloor_normal.png");
	myGrid.InitTexture(myGrid.TAo, "Material\\oakfloor\\oakfloor_AO.png");
	myGrid.InitTexture(myGrid.TRoughness, "Material\\oakfloor\\oakfloor_roughness.png");
	myGrid.LightUseInfo(true);			*/			//设置是否接收光照
	//myBox.InitMaterial(vec4(0.5f, 0.5f, 0.5f, 1.0f), vec4(0.5, 0.5, 0.5, 1.0f), vec4(0.7f, 0.7f, 0.7f, 1.0f), 7.0f);

	//myGrid.initDirectGrid(1, 1, 20, 20);					//顶点、索引信息初始化
	//myGrid.InitBuffers(2.0);							//缓冲初始化
	//myGrid.CoorDataInit(vec3(0.0, 0.0, 0.0), vec3(10.0, 1, 10.0));
	//myGrid.TextureUseInfo(true, true, false, true, true, true);				//纹理使用信息初始化
	//myGrid.InitTexture(myGrid.TAlbedo, "Material\\oakfloor\\oakfloor_basecolor.png");		//生成需要的纹理
	//myGrid.InitTexture(myGrid.TNormal, "Material\\oakfloor\\oakfloor_normal.png");
	//myGrid.InitTexture(myGrid.TAo, "Material\\oakfloor\\oakfloor_AO.png");
	//myGrid.InitTexture(myGrid.TRoughness, "Material\\oakfloor\\oakfloor_roughness.png");
	//myGrid.LightUseInfo(true);						//设置是否接收光照



	//myBucket.InitUseMesh("OBJ\\bucket.obj", true, ObjIndexType::Quad);
	//myBucket.InitBuffers();
	//myBucket.CoorDataInit(vec3(1.0, 0.0, 0.0));
	//myBucket.TextureUseInfo(true, true, false , true, true, true);
	//myBucket.InitTexture(myBucket.TAlbedo, "Material\\oakfloor\\oakfloor_basecolor.png");
	//myBucket.InitTexture(myBucket.TNormal, "Material\\oakfloor\\oakfloor_normal.png");
	//myBucket.InitTexture(myBucket.TAo, "Material\\oakfloor\\oakfloor_AO.png");
	//myBucket.InitTexture(myBucket.TRoughness, "Material\\oakfloor\\oakfloor_roughness.png");
	////myBucket.InitTexture(myBucket.TMetallic, "Material\\bamboo-wood\\bamboo-wood-semigloss-metal.png");
	//myBox.LightUseInfo(true);


	//STInit();
}

void MyScene::InitKeys()
{
	keys.push_back(Key(BTNW));
}

void MyScene::Update()
{

	//计算视角矩阵
	mainCamera.SetView();
	//计算投影矩阵
	mainCamera.SetPro();

	cow.UpdateMatrix(mainCamera);
	//myBox.SetObjMat(camera.view, camera.pro);
	//myBucket.SetObjMat(camera.view, camera.pro);
	//myGrid.SetObjMat(camera.view, camera.pro);


	//光照相关-----
	//将光照信息传入shader中，如果需要计算反射光，则需要将eyePos传入shader中

	//GLuint LP, LC, EP;
	//LP = glGetUniformLocation(p1.p, "lightPos");
	//LC = glGetUniformLocation(p1.p, "lightColor");
	//EP = glGetUniformLocation(p1.p, "eyePos");
	//glUniform3f(LP, lightPos.x, lightPos.y, lightPos.z);
	//glUniform3f(LC, lightColor.x, lightColor.y, lightColor.z);
	//glUniform3f(EP, camera.eyePos.x, camera.eyePos.y, camera.eyePos.z);

	//STConstructProj(lightPos);
}

void MyScene::Draw()
{

	//NormalShadowMap();

	//绘制每一个物体时，先将类中的该物体的所有相关矩阵，材质等信息传入shader中


	//绘制,包含缓冲区的清空，各种效果的开启（blend、 cull之类的）
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);					//三维物体要开启背面剔除
	glPolygonMode(GL_FRONT, GL_LINE);
	//glFrontFace(GL_CW);
	//glCullFace(GL_FRONT);

	glUseProgram(p1.p);						//启用着色器程序

	cow.Draw(p1);

	//myBox.BShadowTex = true;
	//myBox.UseATexture(myBox.TShadowTex, depthTex);
	//DrawElement(myBox, p1);

	//myBucket.BShadowTex = true;
	//myBucket.UseATexture(myBucket.TShadowTex, depthTex);
	//DrawElement(myBucket, p1);

	//myGrid.BShadowTex = true;
	//myGrid.UseATexture(myGrid.TShadowTex, depthTex);
	//DrawElement(myGrid, p1);
	//box
}

//void MyScene::STInit()
//{
//	//生成并绑定framebuffer
//	glGenFramebuffers(1, &frameBuffer);
//	glBindFramebuffer(GL_FRAMEBUFFER, frameBuffer);
//
//	//生成深度Texture作为渲染对象
//	glGenTextures(1, &depthTex);
//	glBindTexture(GL_TEXTURE_2D, depthTex);
//	glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH_COMPONENT16, WIDTH, HEIGHT, 0, GL_DEPTH_COMPONENT, GL_FLOAT, 0);	//因为是深度值所以格式为深度组件
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_COMPARE_FUNC, GL_LEQUAL);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_COMPARE_MODE, GL_COMPARE_R_TO_TEXTURE);
//
//	glFramebufferTexture2D(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_TEXTURE_2D, depthTex, 0);		//将texture与连接点0用深度附件相连
//
//	glDrawBuffer(GL_NONE);				//关闭颜色的绘制
//
//	if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
//		return;
//
//
//	glBindFramebuffer(GL_FRAMEBUFFER, 0);		//解绑
//
//}
//
//void MyScene::STConstructProj(vec3 Pos)
//{
//	MyCamera lightCam;
//	lightCam.Init(Pos, vec3(0, 0, 0));
//
//	lightCam.SetOrtho(-10, 10, -10, 10, -20, 20);
//	lightCam.SetView();
//
//	depthMVP = lightCam.pro*lightCam.view;
//
//	/*mat4 bias(
//		0.5, 0.0, 0.0, 0.0,
//		0.0, 0.5, 0.0, 0.0,
//		0.0, 0.0, 0.5, 0.0,
//		0.5, 0.5, 0.5, 1.0
//	);*/
//
//	//修正贴图使值在0~1之间
//	mat4 bias = translate(mat4(1.0), vec3(0.5, 0.5, 0.5));
//	bias = scale(bias, vec3(0.5, 0.5, 0.5));
//
//	/*vec4 test(-5,0,5,1);
//	vec4 temp1 = bias*test;*/
//
//	/*glm::mat4 m = translate(mat4(1.0),glm::vec3(0.5f, 0.5f, 0.5f))
//		* scale(mat4(1.0), glm::vec3(0.5f, 0.5f, 0.5f));*/
//
//	depthBiasMVP = bias * depthMVP;
//
//	/*vec4 temp = depthBiasMVP*test;
//
//	SetUniform("testDepthMVP", depthMVP, p1);*/
//
//	//depthMVP = camera.pro*camera.view;
//}
//
//void MyScene::NormalShadowMap()
//{
//	glUseProgram(pShadowTex.p);
//	glBindFramebuffer(GL_FRAMEBUFFER, frameBuffer);
//	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//	glEnable(GL_DEPTH_TEST);
//	glEnable(GL_CULL_FACE);
//
//	glFrontFace(GL_CW);
//
//	/*glEnable(GL_POLYGON_OFFSET_FILL);
//	glPolygonOffset(2.5f, 10.0f);*/
//
//	DrawDepthTexture(myGrid, pShadowTex);
//	DrawDepthTexture(myBox, pShadowTex);
//	DrawDepthTexture(myBucket, pShadowTex);
//	//DrawDepthTexture(Sphere, pShadowTex);
//	//DrawDepthTexture(Neptune, pShadowTex);
//
//	glFrontFace(GL_CCW);
//	//glDisable(GL_POLYGON_OFFSET_FILL);
//	glBindFramebuffer(GL_FRAMEBUFFER, 0);
//
//}
