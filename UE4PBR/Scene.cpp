#pragma once
#include "Scene.h"
#include<GLFW\glfw3.h>


//void MyScene::DrawElement(Object & obj, ShaderProgram & p)
//{
//	glBindVertexArray(obj.VAO);				//��ǰ�����úõ�VAO
//										//��������任����
//	SetUniform("worldViewProj", obj.WorldViewProj, p);
//	SetUniform("world", obj.World, p);
//	SetUniform("worldInvTranspose", obj.WorldInvTranspose, p);
//
//	SetUniform("depthBiasMVP", depthBiasMVP, p);
//
//
//	//���ݲ����϶������ѡ�񣬽���Ҫ����������ɫ��
//	//�Ƚ��Ƿ�ʹ��������shader
//	SetUniform("useTexture", obj.BuseTexture, p);
//	//tempJudge = glGetUniformLocation(p.p, "useTexture");
//	//glUniform1i(tempJudge, obj.BuseTexture);
//	if (obj.BuseTexture)
//	{
//		//������ʹ������������������
//		if (obj.BisTexture)
//		{
//			//����������ͼ
//			SetUniform("useAlbedo", obj.BAlbedo, p);
//			if (obj.BAlbedo)
//			{
//				SetTexture(obj.TAlbedo, 0, GL_TEXTURE0, "albedoMap", p);
//
//			}
//
//			//������ͼ
//			SetUniform("useNormal", obj.BNormal, p);
//			if (obj.BNormal)
//			{
//				SetTexture(obj.TNormal, 1, GL_TEXTURE1, "normalMap", p);
//
//			}
//
//			//��������ͼ
//			SetUniform("useMetallic", obj.BMetallic, p);
//			if (obj.BMetallic)
//			{
//				SetTexture(obj.TMetallic, 2, GL_TEXTURE2, "metallicMap", p);
//
//			}
//			else
//			{
//				//�˴���ʱֱ�ӽ�û�н�����ͼ�Ľ����������ִ���shader
//				SetUniform("metallicN", 0.2f, p);
//			}
//
//			//�ֲ���ͼ
//			SetUniform("useRoughness", obj.BRoughness, p);
//			if (obj.BRoughness)
//			{
//				SetTexture(obj.TRoughness, 3, GL_TEXTURE3, "roughnessMap", p);
//
//			}
//
//			//������ao��ͼ
//			SetUniform("useAO", obj.BAo, p);
//			if (obj.BAo)
//			{
//				SetTexture(obj.TAo, 4, GL_TEXTURE4, "aoMap", p);
//
//			}
//
//
//		}
//
//		//��Ӱ��ͼ����������������ͬһ�����ͣ�����Ҫ����������������꣩
//		SetUniform("useShadowTex", obj.BShadowTex, p);
//		if (obj.BShadowTex)
//		{
//			SetTexture(obj.TShadowTex, 5, GL_TEXTURE5, "shadowTex", p);
//		}
//	}
//
//	//�������Ƿ���չ��մ���shader
//	/*GLuint useLight = glGetUniformLocation(p.p, "useLight");
//	glUniform1i(useLight, obj.BReceiveLight);*/
//	/*if (obj.BReceiveLight)
//	{
//		SetUniform("material.ambient", obj.Material.ambient, p);
//		SetUniform("material.diffuse", obj.Material.diffuse, p);
//		SetUniform("material.specular", obj.Material.specular, p);
//		SetUniform("material.shiness", obj.Material.shiness, p);
//	}*/
//
//
//
//
//	if (obj.indexType == ObjIndexType::Triangles)
//		glDrawElements(GL_TRIANGLES, obj.renderIndex.size(), GL_UNSIGNED_INT, 0);
//	else if (obj.indexType == ObjIndexType::Quad)
//		glDrawElements(GL_QUADS, obj.renderIndex.size(), GL_UNSIGNED_INT, 0);
//
//	glBindVertexArray(0);
//}

//void MyScene::DrawDepthTexture(Object & obj, ShaderProgram & p)
//{
//	glBindVertexArray(obj.VAO);				//��ǰ�����úõ�VAO
//
//	SetUniform("world", obj.World, p);
//	SetUniform("depthMVP", depthMVP, p);
//
//	if (obj.indexType == ObjIndexType::Triangles)
//		glDrawElements(GL_TRIANGLES, obj.renderIndex.size(), GL_UNSIGNED_INT, 0);
//	else if (obj.indexType == ObjIndexType::Quad)
//		glDrawElements(GL_QUADS, obj.renderIndex.size(), GL_UNSIGNED_INT, 0);
//
//	glBindVertexArray(0);
//
//}
//
//void MyScene::SetTexture(GLuint & texId, int num, GLenum texNum, string samplerName, ShaderProgram & p)
//{
//	GLuint texLocation;
//	glActiveTexture(texNum);							//��������Ԫ(����λ��)��
//	glBindTexture(GL_TEXTURE_2D, texId);				//���������󶨵���ǰ���������Ԫ��
//	//������ָ����������Ӧ�ĸ�����Ԫ
//	texLocation = glGetUniformLocation(p.p, samplerName.c_str());	//��ȡ��������location
//	glUniform1i(texLocation, num);									//ָ����������Ӧ��ǰ�󶨵�����Ԫ0
//
//}
//
//void MyScene::SetUniform(string valueName, mat4x4 &value, ShaderProgram&p)
//{
//	GLuint location;
//	location = glGetUniformLocation(p.p, valueName.c_str());
//	glUniformMatrix4fv(location, 1, GL_FALSE, value_ptr(value));
//}
//
//void MyScene::SetUniform(string valueName, vec4 & value, ShaderProgram&p)
//{
//	GLuint location;
//	location = glGetUniformLocation(p.p, valueName.c_str());
//	glUniform4fv(location, 1, value_ptr(value));
//}
//
//void MyScene::SetUniform(string valueName, vec3 & value, ShaderProgram&p)
//{
//	GLuint location;
//	location = glGetUniformLocation(p.p, valueName.c_str());
//	glUniform3fv(location, 1, value_ptr(value));
//}
//
//void MyScene::SetUniform(string valueName, float value, ShaderProgram&p)
//{
//	GLuint location;
//	location = glGetUniformLocation(p.p, valueName.c_str());
//	glUniform1f(location, value);
//}


void MyScene::Init()
{
	//��ʼ��glew
	glewInit();
	//����shader����
	p1.SetShader("test.vert", "test.frag");

	//pShadowTex.SetShader("shadowTex.v", "shadowTex.f");



	//����VAO��VBO
	//SetBuffers(myBox);

	//ָ����Դ����
	lightPos = vec3(-3, 5, 3);
	lightColor = vec3(400.f, 400.f, 400.f);

	//ָ�������ʼλ��
	mainCamera.Init(vec3(0, 2, 4), vec3(0, 0, 0));




	//ָ������PBR����

	//boxAlbedo = vec3(0.5f, 0.0f, 0.0f);
	//boxAo = 1.0f;
	//boxMetallic = 0.1f;
	//boxRoughness = 0.6f;
	//sphereAo = 1.0f;
	cow.readObjFile("OBJ\\cow.obj");
	cow.getTransform().SetPosition(vec3(0, 0, 0));
	cow.getShaderData().bUseTexture = false;

	myBox.InitDirectBox(1, 1, 1);					//���㡢������Ϣ��ʼ��
	myBox.InitBuffers();							//�����ʼ��
	myBox.CoorDataInit(vec3(-0.5, 0.5, 1.0)/*, vec3(3.0, 0.1, 3.0)*/);
	myBox.TextureUseInfo(true, true, true, true, true, true);				//����ʹ����Ϣ��ʼ��
	myBox.InitTexture(myBox.TAlbedo, "Material\\metalgrid2-dx\\metalgrid2_basecolor.png");		//������Ҫ������
	myBox.InitTexture(myBox.TNormal, "Material\\metalgrid2-dx\\metalgrid2_normal-dx.png");
	myBox.InitTexture(myBox.TAo, "Material\\metalgrid2-dx\\metalgrid2_AO.png");
	myBox.InitTexture(myBox.TRoughness, "Material\\metalgrid2-dx\\metalgrid2_roughness.png");
	myBox.InitTexture(myBox.TMetallic, "Material\\metalgrid2-dx\\metalgrid2_metallic.png");
	myBox.LightUseInfo(true);						//�����Ƿ���չ���
	//myBox.InitMaterial(vec4(0.5f, 0.5f, 0.5f, 1.0f), vec4(0.5, 0.5, 0.5, 1.0f), vec4(0.7f, 0.7f, 0.7f, 1.0f), 7.0f);
	
	/*myGrid.initDirectGrid(1, 1, 10, 10);					//���㡢������Ϣ��ʼ��
	myGrid.InitBuffers();							//�����ʼ��
	myGrid.CoorDataInit(vec3(0.0, 0.0, 0.0), vec3(4.0, 1, 4.0));
	myGrid.TextureUseInfo(true, true, true, true, true, true);				//����ʹ����Ϣ��ʼ��
	myGrid.InitTexture(myGrid.TAlbedo, "Material\\oakfloor\\oakfloor_basecolor.png");		//������Ҫ������
	myGrid.InitTexture(myGrid.TNormal, "Material\\oakfloor\\oakfloor_normal.png");
	myGrid.InitTexture(myGrid.TAo, "Material\\oakfloor\\oakfloor_AO.png");
	myGrid.InitTexture(myGrid.TRoughness, "Material\\oakfloor\\oakfloor_roughness.png");
	myGrid.LightUseInfo(true);			*/			//�����Ƿ���չ���
	//myBox.InitMaterial(vec4(0.5f, 0.5f, 0.5f, 1.0f), vec4(0.5, 0.5, 0.5, 1.0f), vec4(0.7f, 0.7f, 0.7f, 1.0f), 7.0f);

	myGrid.initDirectGrid(1, 1, 20, 20);					//���㡢������Ϣ��ʼ��
	myGrid.InitBuffers(2.0);							//�����ʼ��
	myGrid.CoorDataInit(vec3(0.0, 0.0, 0.0), vec3(10.0, 1, 10.0));
	myGrid.TextureUseInfo(true, true, false, true, true, true);				//����ʹ����Ϣ��ʼ��
	myGrid.InitTexture(myGrid.TAlbedo, "Material\\oakfloor\\oakfloor_basecolor.png");		//������Ҫ������
	myGrid.InitTexture(myGrid.TNormal, "Material\\oakfloor\\oakfloor_normal.png");
	myGrid.InitTexture(myGrid.TAo, "Material\\oakfloor\\oakfloor_AO.png");
	myGrid.InitTexture(myGrid.TRoughness, "Material\\oakfloor\\oakfloor_roughness.png");
	myGrid.LightUseInfo(true);						//�����Ƿ���չ���



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

void MyScene::Update()
{
	//�����ӽǾ���

	mainCamera.SetView();
	//mat4 view = lookAt(eyePos, lookAtPoint, up);



	//����ͶӰ����

	/*mat4 pro;
	pro = perspective(45.0f, ((float)1200) / (1000), 0.1f, 1000.0f);*/
	mainCamera.SetPro();

	cow.SetMatrix(mainCamera);
	//myBox.SetObjMat(camera.view, camera.pro);
	//myBucket.SetObjMat(camera.view, camera.pro);
	//myGrid.SetObjMat(camera.view, camera.pro);

	//����������������ӽǾ���ͶӰ��������ÿһ�������worldviewproj(��������˶����ȼ������������������ת����)

	/*boxWorldViewProj = camera.pro*camera.view*boxWorld;			//���밴�մ�˳�����

	sphereWorldViewProj = camera.pro*camera.view*sphereWorld;*/




	//�������-----
	//��������Ϣ����shader�У������Ҫ���㷴��⣬����Ҫ��eyePos����shader��

	GLuint LP, LC, EP;
	LP = glGetUniformLocation(p1.p, "lightPos");
	LC = glGetUniformLocation(p1.p, "lightColor");
	EP = glGetUniformLocation(p1.p, "eyePos");
	glUniform3f(LP, lightPos.x, lightPos.y, lightPos.z);
	glUniform3f(LC, lightColor.x, lightColor.y, lightColor.z);
	glUniform3f(EP, camera.eyePos.x, camera.eyePos.y, camera.eyePos.z);

	STConstructProj(lightPos);
}

void MyScene::Draw()
{

	NormalShadowMap();

	//����ÿһ������ʱ���Ƚ����еĸ������������ؾ��󣬲��ʵ���Ϣ����shader��


	//����,��������������գ�����Ч���Ŀ�����blend�� cull֮��ģ�
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);					//��ά����Ҫ���������޳�
	//glFrontFace(GL_CW);
	//glCullFace(GL_FRONT);

	glUseProgram(p1.p);						//������ɫ������

	myBox.BShadowTex = true;
	myBox.UseATexture(myBox.TShadowTex, depthTex);
	DrawElement(myBox, p1);

	myBucket.BShadowTex = true;
	myBucket.UseATexture(myBucket.TShadowTex, depthTex);
	DrawElement(myBucket, p1);

	myGrid.BShadowTex = true;
	myGrid.UseATexture(myGrid.TShadowTex, depthTex);
	DrawElement(myGrid, p1);
	//box
}

void MyScene::STInit()
{
	//���ɲ���framebuffer
	glGenFramebuffers(1, &frameBuffer);
	glBindFramebuffer(GL_FRAMEBUFFER, frameBuffer);

	//�������Texture��Ϊ��Ⱦ����
	glGenTextures(1, &depthTex);
	glBindTexture(GL_TEXTURE_2D, depthTex);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH_COMPONENT16, WIDTH, HEIGHT, 0, GL_DEPTH_COMPONENT, GL_FLOAT, 0);	//��Ϊ�����ֵ���Ը�ʽΪ������
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_COMPARE_FUNC, GL_LEQUAL);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_COMPARE_MODE, GL_COMPARE_R_TO_TEXTURE);

	glFramebufferTexture2D(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_TEXTURE_2D, depthTex, 0);		//��texture�����ӵ�0����ȸ�������

	glDrawBuffer(GL_NONE);				//�ر���ɫ�Ļ���

	if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
		return;


	glBindFramebuffer(GL_FRAMEBUFFER, 0);		//���

}

void MyScene::STConstructProj(vec3 Pos)
{
	MyCamera lightCam;
	lightCam.Init(Pos, vec3(0, 0, 0));

	lightCam.SetOrtho(-10, 10, -10, 10, -20, 20);
	lightCam.SetView();

	depthMVP = lightCam.pro*lightCam.view;

	/*mat4 bias(
		0.5, 0.0, 0.0, 0.0,
		0.0, 0.5, 0.0, 0.0,
		0.0, 0.0, 0.5, 0.0,
		0.5, 0.5, 0.5, 1.0
	);*/

	//������ͼʹֵ��0~1֮��
	mat4 bias = translate(mat4(1.0), vec3(0.5, 0.5, 0.5));
	bias = scale(bias, vec3(0.5, 0.5, 0.5));

	/*vec4 test(-5,0,5,1);
	vec4 temp1 = bias*test;*/

	/*glm::mat4 m = translate(mat4(1.0),glm::vec3(0.5f, 0.5f, 0.5f))
		* scale(mat4(1.0), glm::vec3(0.5f, 0.5f, 0.5f));*/

	depthBiasMVP = bias * depthMVP;

	/*vec4 temp = depthBiasMVP*test;

	SetUniform("testDepthMVP", depthMVP, p1);*/

	//depthMVP = camera.pro*camera.view;
}

void MyScene::NormalShadowMap()
{
	glUseProgram(pShadowTex.p);
	glBindFramebuffer(GL_FRAMEBUFFER, frameBuffer);
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);

	glFrontFace(GL_CW);

	/*glEnable(GL_POLYGON_OFFSET_FILL);
	glPolygonOffset(2.5f, 10.0f);*/

	DrawDepthTexture(myGrid, pShadowTex);
	DrawDepthTexture(myBox, pShadowTex);
	DrawDepthTexture(myBucket, pShadowTex);
	//DrawDepthTexture(Sphere, pShadowTex);
	//DrawDepthTexture(Neptune, pShadowTex);

	glFrontFace(GL_CCW);
	//glDisable(GL_POLYGON_OFFSET_FILL);
	glBindFramebuffer(GL_FRAMEBUFFER, 0);

}
