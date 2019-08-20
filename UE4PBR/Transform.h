//object的坐标相关属性类
#pragma once
#include<glm.hpp>
#include<gtc\matrix_transform.hpp>
#include<gtc\type_ptr.hpp>
#include<vector>
#include"Camera.h"
using namespace glm;

class Transform
{
private:
	//物体的坐标转换矩阵
	mat4x4 world;					//世界矩阵
	mat4x4 worldViewProj;			//最终坐标转换矩阵
	mat4x4 worldInvTranspose;		//用来将法向量转换到世界空间

public:
	//物体的坐标属性
	vec3 position;					//物体的位置
	vec3 scaler;					//物体的放大系数
	vec3 rotation;					//物体的旋转
	//float RotateAngle;				//物体旋转的角度

private:


public:
	//构造函数
	Transform(vec3 _pos = vec3(0), vec3 _scaler = vec3(1.0), vec3 _rotation = vec3(0)) :position(_pos), scaler(_scaler), rotation(_rotation)
	{
		world = mat4();
		worldViewProj = mat4();
		worldInvTranspose = mat4();
	}

	void SetMatrix();

	void MoveByDir(vec3 dir, float distant);
	void MoveByVector(vec3 displacement);

	void RotateByAxis(vec3 axis, float angle);
};