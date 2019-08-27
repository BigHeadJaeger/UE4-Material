#include "ShaderData.h"

void ShaderData::SetMatrix(Transform& t, Camera& camera)
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
	worldViewProj = camera.pro * camera.view * world;
}

void ShaderData::InitTexture(GLuint& texID, string texPath)
{
	glGenTextures(1, &texID);					//����һ������ID
	glBindTexture(GL_TEXTURE_2D, texID);		//��ʱ�󶨵���Ĭ��������Ԫ0������֮��Ĵ����л�ָ���󶨵������ĸ���Ԫ
	//ָ����ͼ����
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	//ͼƬ�ļ���ȡ
	int width, height;
	unsigned char* pResult = SOIL_load_image(texPath.c_str(), &width, &height, 0, SOIL_LOAD_RGB);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, pResult);
	//����һ��mipmap
	glGenerateMipmap(GL_TEXTURE_2D);
	//����󶨲��ͷ�
	glBindTexture(GL_TEXTURE_2D, 0);
	SOIL_free_image_data(pResult);
}

void ShaderData::InitVertexBuffer(MeshData& meshData)
{
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	//���ɶ���buffer(VBO)����
	//MyGeometryGenerator::GetInstance()->CreateBox(20.0f, 0.3f, 20.0f, box);
	//ת����һά������
	std::vector<float> vertexData;
	for (Mesh::FaceIter f_it = meshData.mesh.faces_begin(); f_it != meshData.mesh.faces_end(); f_it++)
	{
		for (Mesh::FaceVertexCCWIter fv_ccwit = meshData.mesh.fv_ccwbegin(*f_it); fv_ccwit != meshData.mesh.fv_ccwend(*f_it); fv_ccwit++)
		{
			vertexData.push_back(meshData.mesh.point(*fv_ccwit).data()[0]);
			vertexData.push_back(meshData.mesh.point(*fv_ccwit).data()[1]);
			vertexData.push_back(meshData.mesh.point(*fv_ccwit).data()[2]);
			vertexData.push_back(meshData.mesh.normal(*fv_ccwit).data()[0]);
			vertexData.push_back(meshData.mesh.normal(*fv_ccwit).data()[1]);
			vertexData.push_back(meshData.mesh.normal(*fv_ccwit).data()[2]);
			if (meshData.providedTex)
			{
				vertexData.push_back(meshData.mesh.texcoord2D(*fv_ccwit).data[0]);
				vertexData.push_back(meshData.mesh.texcoord2D(*fv_ccwit).data[1]);
			}
		}
	}

	//��������buffer
	glGenBuffers(1, &VertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, VertexBuffer);					//�Ȱ󶨣�����VAO��ֵʱ���ʹ��͵��ǵ�ǰ�󶨵�buffer
	glBufferData(GL_ARRAY_BUFFER, vertexData.size() * sizeof(float), &vertexData[0], GL_STATIC_DRAW);		//ָ������
																											//��������buffer
	//glGenBuffers(1, &IndexBuffer);
	//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IndexBuffer);
	//glBufferData(GL_ELEMENT_ARRAY_BUFFER, renderIndex.size() * sizeof(unsigned), &renderIndex[0], GL_STATIC_DRAW);

	//������buffer�е�����ָ����shader��
	//ָ��pos����
	glEnableVertexAttribArray(0);										//��������Ϊ0�Ķ�������
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);		//���������ȡ����ʱ�Ĳ��������һ�������ڵ�ǰ��һ������������ǰ��೤����Ϣ
																						//ָ��normal����
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));		//ÿ8�������е��м������Ƿ���������
																										//ָ��������������
	if (meshData.providedTex)
	{
		glEnableVertexAttribArray(2);
		glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
	}

	glBindVertexArray(0);

}