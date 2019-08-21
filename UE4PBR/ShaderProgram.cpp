#include "ShaderProgram.h"

void ShaderProgram::SetMatrix(Transform& t)
{
	world = translate(mat4(1.0), t.position);
	world = scale(world, t.scaler);
	if (t.rotation.x != 0)
		world = rotate(world, t.rotation.x, vec3(1.0, 0.0, 0.0));
	if (t.rotation.y != 0)
		world = rotate(world, t.rotation.y, vec3(0.0, 1.0, 0.0));
	if (t.rotation.z != 0)
		world = rotate(world, t.rotation.z, vec3(0.0, 0.0, 1.0));
	worldInvTranspose = transpose(inverse(world));
	worldViewProj = Camera::getMainCamera()->pro * Camera::getMainCamera()->view * world;
}

void ShaderProgram::InitTexture(GLuint& texID, string texPath)
{
	glGenTextures(1, &texID);
	glBindTexture(GL_TEXTURE_2D, texID);		//此时绑定到了默认纹理单元0处，在之后的代码中会指定绑定到具体哪个单元
	//指定贴图方法
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	//文件读取
	int width, height;
	unsigned char* pResult = SOIL_load_image(texPath.c_str(), &width, &height, 0, SOIL_LOAD_RGB);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, pResult);
	//生成一个mipmap
	glGenerateMipmap(GL_TEXTURE_2D);
	//解除绑定并释放
	glBindTexture(GL_TEXTURE_2D, 0);
	SOIL_free_image_data(pResult);
}
