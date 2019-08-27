#include "NewObject.h"

void Object::SetTexture(GLuint& texId, int num, GLenum texNum, string samplerName, ShaderProgram& p)
{
	GLuint texLocation;
	glActiveTexture(texNum);							//��������Ԫ(����λ��)��
	glBindTexture(GL_TEXTURE_2D, texId);				//���������󶨵���ǰ���������Ԫ��
	//������ָ����������Ӧ�ĸ�����Ԫ
	texLocation = glGetUniformLocation(p.p, samplerName.c_str());	//��ȡ��������location
	glUniform1i(texLocation, num);									//ָ����������Ӧ��ǰ�󶨵�����Ԫ0
}

void Object::SetUniform(string valueName, mat4x4& value, ShaderProgram& p)
{
	GLuint location;
	location = glGetUniformLocation(p.p, valueName.c_str());
	glUniformMatrix4fv(location, 1, GL_FALSE, value_ptr(value));
}

void Object::SetUniform(string valueName, vec4& value, ShaderProgram& p)
{
	GLuint location;
	location = glGetUniformLocation(p.p, valueName.c_str());
	glUniform4fv(location, 1, value_ptr(value));
}

void Object::SetUniform(string valueName, vec3& value, ShaderProgram& p)
{
	GLuint location;
	location = glGetUniformLocation(p.p, valueName.c_str());
	glUniform3fv(location, 1, value_ptr(value));
}

void Object::SetUniform(string valueName, float value, ShaderProgram& p)
{
	GLuint location;
	location = glGetUniformLocation(p.p, valueName.c_str());
	glUniform1f(location, value);
}

void Object::Draw(ShaderProgram&p)
{
	glBindVertexArray(shaderData.VAO);				//��ǰ�����úõ�VAO
									//��������任����
	SetUniform("worldViewProj", shaderData.worldViewProj, p);
	SetUniform("world", shaderData.world, p);
	SetUniform("worldInvTranspose", shaderData.worldInvTranspose, p);

	//SetUniform("depthBiasMVP", depthBiasMVP, p);


	//���ݲ����϶������ѡ�񣬽���Ҫ����������ɫ��
	//�Ƚ��Ƿ�ʹ��������shader
	SetUniform("useTexture", shaderData.bUseTexture, p);
	if (shaderData.bUseTexture)
	{
		//������ʹ������������������
		if (meshData.providedTex)
		{
			//����������ͼ
			SetUniform("useAlbedo", shaderData.bAlbedo, p);
			if (shaderData.bAlbedo)
			{
				SetTexture(shaderData.tAlbedo, 0, GL_TEXTURE0, "albedoMap", p);

			}

			//������ͼ
			SetUniform("useNormal", shaderData.bNormal, p);
			if (shaderData.bNormal)
			{
				SetTexture(shaderData.tNormal, 1, GL_TEXTURE1, "normalMap", p);

			}

			//��������ͼ
			SetUniform("useMetallic", shaderData.bMetallic, p);
			if (shaderData.bMetallic)
			{
				SetTexture(shaderData.tMetallic, 2, GL_TEXTURE2, "metallicMap", p);

			}
			else
			{
				//�˴���ʱֱ�ӽ�û�н�����ͼ�Ľ����������ִ���shader
				SetUniform("metallicN", 0.2f, p);
			}

			//�ֲ���ͼ
			SetUniform("useRoughness", shaderData.bRoughness, p);
			if (shaderData.bRoughness)
			{
				SetTexture(shaderData.tRoughness, 3, GL_TEXTURE3, "roughnessMap", p);

			}

			//������ao��ͼ
			SetUniform("useAO", shaderData.bAo, p);
			if (shaderData.bAo)
			{
				SetTexture(shaderData.tAo, 4, GL_TEXTURE4, "aoMap", p);

			}


		}

		//��Ӱ��ͼ����������������ͬһ�����ͣ�����Ҫ����������������꣩
		SetUniform("useShadowTex", shaderData.bShadowTex, p);
		if (shaderData.bShadowTex)
		{
			SetTexture(shaderData.tShadowTex, 5, GL_TEXTURE5, "shadowTex", p);
		}
	}

	glDrawArrays(GL_TRIANGLES, 0, meshData.mesh.n_faces()*3);

	glBindVertexArray(0);
}
