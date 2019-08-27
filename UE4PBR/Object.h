////#pragma once
////#include"PublicStruct.h"
////#include<gtc\matrix_transform.hpp>
////#include<gtc\type_ptr.hpp>
//////#include"Generate.h"
////#include<vector>
////#include <fstream>
////#include <sstream>
////#include<iostream>
////#include<GL/glew.h>
////#include<SOIL.h>
//using namespace std;
//
//
//
//class Object
//{
//public:
//	Object();
//	~Object();
//
//	void CoorDataInit(vec3 pos = vec3(0, 0, 0), vec3 scaler = vec3(1.f, 1.f, 1.f), vec3 rot = vec3(0.0, 1.f, 0.0), float angle = 0);
//	void SetObjMat(mat4 camView, mat4 camProj);
//	void InitUseMesh(string fileName, bool texture, ObjIndexType type);	//ͨ��������������
//
//	//ͨ��ָ������ֱ�����ɼ�����
//	void InitDirectBox(float width, float height, float depth);														//ֱ��ͨ�����εķ�ʽ��������
//	void InitDirectSphere(float radius, int slice, int stack);
//	void initDirectGrid(float width, float height, int m, int n);
//
//	void InitBuffers(float TexScaler = 1.0);										//����VAO��VBO
//	void TextureUseInfo(bool useTex = true, bool useAlbedo = false,
//		bool useMetallic = false, bool useRoughness = false, bool useAo = false,
//		bool useNormal = false, bool useShadowTex = false);							//����ָ�������Ƿ�ʹ�������Լ�����ʹ����Щ����
//	void LightUseInfo(bool receive);
//	void InitTexture(GLuint& TexID, string TexPath);		//����������󲢰�����(��ͼƬת��Ϊ�������ݣ����ݲ�ͬ��ID������Ӧ������)
//	void UseATexture(GLuint& TexID, GLuint&ID);				//ʹ��һ���Ѿ����ɺõ��������
//	void InitMaterial(vec4 A, vec4 D, vec4 S, float SH);
//
//private:
//	void ObjNormalize();													//�������ݹ�һ��
//
//public:
//	vector<Point> pointsData;												//���嶥������
//	vector<unsigned> renderIndex;											//������϶��������
//	bool BisTexture;											//ֻ��������ʾ����Ķ�����Ϣ�����������꣬������һ��Ҫʹ������
//	ObjIndexType indexType;
//
//	//�������������
//	mat4x4 World;					//�������
//	mat4x4 WorldViewProj;			//��������ת������
//	mat4x4 WorldInvTranspose;		//������������ת��������ռ�
//	vec3 Scaler;					//����ķŴ�ϵ��
//	vec3 Position;					//�����λ��
//	vec3 Rotation;					//�������ת
//	float RotateAngle;				//������ת�ĽǶ�
//
//
//						//�����VAO��VBO���
//	GLuint VAO;
//	GLuint VertexBuffer;
//	GLuint IndexBuffer;
//
//
//	//�������ͼ��ţ���һ��ȫ����Ҫ��
//	bool BuseTexture;
//	GLuint TAlbedo;					//������ͼ��������ɫ��
//	bool BAlbedo;
//	GLuint TMetallic;				//��������ͼ
//	bool BMetallic;
//	GLuint TRoughness;				//�ֲ���ͼ
//	bool BRoughness;
//	GLuint TAo;						//������ͼ
//	bool BAo;
//	GLuint TNormal;					//������ͼ
//	bool BNormal;
//	GLuint TShadowTex;				//��Ӱ��ͼ
//	bool BShadowTex;
//
//	ObjMaterial Material;			//����������ԣ���ʹ�ü򵥹���ʱ��Ҫָ��
//	bool BReceiveLight;					//�����Ƿ���չ���
//
//private:
//	//ʹ���������������ʱ���¼���±���
//	string modelPath;
//
//	AABB aabb;
//};