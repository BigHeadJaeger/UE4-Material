//object���������������
#pragma once
#include<glm.hpp>
#include<gtc\matrix_transform.hpp>
#include<gtc\type_ptr.hpp>
#include<vector>
using namespace glm;

class Transform
{
private:
	//���������ת������
	mat4x4 world;					//�������
	mat4x4 worldViewProj;			//��������ת������
	mat4x4 worldInvTranspose;		//������������ת��������ռ�

public:
	//�������������
	vec3 position;					//�����λ��
	vec3 scaler;					//����ķŴ�ϵ��
	vec3 rotation;					//�������ת
	//float RotateAngle;				//������ת�ĽǶ�

private:
	//���캯��
	Transform()
	{
		world = mat4();
		worldViewProj = mat4();
		worldInvTranspose = mat4();

		position = vec3(0);
		scaler = vec3(1.0);
		rotation = vec3(0);
	}
	Transform(vec3 _pos = vec3(0), vec3 _scaler = vec3(1.0), vec3 _rotation = vec3(0)) :position(_pos), scaler(_scaler), rotation(_rotation) 
	{
		world = mat4();
		worldViewProj = mat4();
		worldInvTranspose = mat4();
	}

public:
	void SetMatrix(mat4 camView, mat4 camProj);

	void MoveByDir(vec3 dir, float distant);
	void MoveByVector(vec3 displacement);

	void RotateByAxis(vec3 axis, float angle);
};