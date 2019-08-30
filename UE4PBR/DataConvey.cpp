#include "DataConvey.h"

void ConveyTool::SetTexture(GLuint& texId, int num, GLenum texNum, string samplerName, ShaderProgram& p)
{
	GLuint texLocation;
	glActiveTexture(texNum);							//��������Ԫ(����λ��)��
	glBindTexture(GL_TEXTURE_2D, texId);				//���������󶨵���ǰ���������Ԫ��
	//������ָ����������Ӧ�ĸ�����Ԫ
	texLocation = glGetUniformLocation(p.p, samplerName.c_str());	//��ȡ��������location
	glUniform1i(texLocation, num);									//ָ����������Ӧ��ǰ�󶨵�����Ԫ0
}

void ConveyTool::SetUniform(string valueName, mat4x4& value, ShaderProgram& p)
{
	GLuint location;
	location = glGetUniformLocation(p.p, valueName.c_str());
	glUniformMatrix4fv(location, 1, GL_FALSE, value_ptr(value));
}

void ConveyTool::SetUniform(string valueName, vec4& value, ShaderProgram& p)
{
	GLuint location;
	location = glGetUniformLocation(p.p, valueName.c_str());
	glUniform4fv(location, 1, value_ptr(value));
}

void ConveyTool::SetUniform(string valueName, vec3& value, ShaderProgram& p)
{
	GLuint location;
	location = glGetUniformLocation(p.p, valueName.c_str());
	glUniform3fv(location, 1, value_ptr(value));
}

void ConveyTool::SetUniform(string valueName, float value, ShaderProgram& p)
{
	GLuint location;
	location = glGetUniformLocation(p.p, valueName.c_str());
	glUniform1f(location, value);
}


ConveyTool* ConveyTool::conveyTool = NULL;