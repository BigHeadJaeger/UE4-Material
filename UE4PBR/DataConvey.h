//����shader���ݴ��ݵĵ���������
#pragma once
#include<GL/glew.h>
#include<glm.hpp>
#include<gtc\matrix_transform.hpp>
#include<gtc\type_ptr.hpp>
#include<string>
using namespace std;
using namespace glm;

#include"Program.h"
class ConveyTool
{
private:
	ConveyTool(){}
	static ConveyTool* conveyTool;
public:
	static ConveyTool* GetConveyTool()
	{
		if (conveyTool == NULL)
			conveyTool = new ConveyTool();
		return conveyTool;
	}

	//��texture��shader��
	void SetTexture(GLuint& texId, int num, GLenum texNum, string samplerName, ShaderProgram& p);
	//���ݲ�ͬ���͵�ֵ�����صķ�ʽ����shader��
	void SetUniform(string valueName, mat4x4& value, ShaderProgram& p);
	void SetUniform(string valueName, vec4& value, ShaderProgram& p);
	void SetUniform(string valueName, vec3& value, ShaderProgram& p);
	void SetUniform(string valueName, float value, ShaderProgram& p);
};
