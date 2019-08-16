#pragma once

#include<glm.hpp>
using namespace glm;


const double ZERO = 0.000000001;
const double M_INFINITE = 1e10f;

const unsigned int WIDTH = 1200, HEIGHT = 1000;

struct Point
{
	vec3 vertex;
	vec2 texcoord;
	vec3 normal;
};

struct AABB
{
	vec3 minPos;
	vec3 maxPos;
};

enum ObjIndexType
{
	Triangles,
	Quad
};

//����Ĳ�������
struct ObjMaterial
{
	vec4 ambient;
	vec4 diffuse;
	vec4 specular;
	float shiness;
};