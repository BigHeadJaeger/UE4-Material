#include "NewObject.h"

void Object::SetTexture(GLuint& texId, int num, GLenum texNum, string samplerName, ShaderProgram& p)
{
	GLuint texLocation;
	glActiveTexture(texNum);							//激活纹理单元(纹理位置)。
	glBindTexture(GL_TEXTURE_2D, texId);				//将纹理对象绑定到当前激活的纹理单元处
	//接下来指定采样器对应哪个纹理单元
	texLocation = glGetUniformLocation(p.p, samplerName.c_str());	//获取采样器的location
	glUniform1i(texLocation, num);									//指定采样器对应当前绑定的纹理单元0
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
	glBindVertexArray(shaderData.VAO);				//绑定前面设置好的VAO
									//传递坐标变换矩阵
	SetUniform("worldViewProj", shaderData.worldViewProj, p);
	SetUniform("world", shaderData.world, p);
	SetUniform("worldInvTranspose", shaderData.worldInvTranspose, p);

	//SetUniform("depthBiasMVP", depthBiasMVP, p);


	//根据参数上对纹理的选择，将需要的纹理传入着色器
	//先将是否使用纹理传入shader
	SetUniform("useTexture", shaderData.bUseTexture, p);
	if (shaderData.bUseTexture)
	{
		//当物体使用纹理且有纹理坐标
		if (meshData.providedTex)
		{
			//基础反射贴图
			SetUniform("useAlbedo", shaderData.bAlbedo, p);
			if (shaderData.bAlbedo)
			{
				SetTexture(shaderData.tAlbedo, 0, GL_TEXTURE0, "albedoMap", p);

			}

			//法线贴图
			SetUniform("useNormal", shaderData.bNormal, p);
			if (shaderData.bNormal)
			{
				SetTexture(shaderData.tNormal, 1, GL_TEXTURE1, "normalMap", p);

			}

			//金属度贴图
			SetUniform("useMetallic", shaderData.bMetallic, p);
			if (shaderData.bMetallic)
			{
				SetTexture(shaderData.tMetallic, 2, GL_TEXTURE2, "metallicMap", p);

			}
			else
			{
				//此处暂时直接将没有金属贴图的金属度用数字传入shader
				SetUniform("metallicN", 0.2f, p);
			}

			//粗糙贴图
			SetUniform("useRoughness", shaderData.bRoughness, p);
			if (shaderData.bRoughness)
			{
				SetTexture(shaderData.tRoughness, 3, GL_TEXTURE3, "roughnessMap", p);

			}

			//环境光ao贴图
			SetUniform("useAO", shaderData.bAo, p);
			if (shaderData.bAo)
			{
				SetTexture(shaderData.tAo, 4, GL_TEXTURE4, "aoMap", p);

			}


		}

		//阴影贴图（与其它的纹理不是同一种类型，不需要物体自身的纹理坐标）
		SetUniform("useShadowTex", shaderData.bShadowTex, p);
		if (shaderData.bShadowTex)
		{
			SetTexture(shaderData.tShadowTex, 5, GL_TEXTURE5, "shadowTex", p);
		}
	}

	glDrawArrays(GL_TRIANGLES, 0, meshData.mesh.n_faces()*3);

	glBindVertexArray(0);
}
