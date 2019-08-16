#pragma once
#include<glm.hpp>
#include<gtc\matrix_transform.hpp>
using namespace glm;
class MyCamera
{
public:
	vec3 eyePos;
	vec3 lookAtPoint;
	vec3 up;
	mat4 view;
	mat4 pro;
	//����ռ����������
	vec3 lookDir;
	vec3 lookRight;
	vec3 lookLeft;
	vec3 lookUp;
public:
	MyCamera();
	void Init(vec3 pos, vec3 point);
	void SetView();
	void SetPro();																				//����͸��ͶӰ����
	void SetOrtho(float left, float right, float bottom, float up, float near, float far);	//��������ͶӰ����
public:
	void Walk(float dis);
	void LRMove(float dis);
	void LRRotate(float dis);
};

