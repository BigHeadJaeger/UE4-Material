#include "Geometry.h"

int Box::boxCount = 0;

void Box::InitData()
{
	meshData.providedTex = true;
	meshData.mesh.request_vertex_texcoords2D();
	float halfW = width * 0.5f;
	float halfH = height * 0.5f;
	float halfD = depth * 0.5f;

	//��ʼ��4*6=24������
	Mesh::VertexHandle vHandles[24];
	vHandles[0] = meshData.mesh.add_vertex(Mesh::Point(-halfW, -halfH, -halfD));
	meshData.mesh.set_texcoord2D(vHandles[0], OpenMesh::Vec2f(0.f, 1.f));
	vHandles[1] = meshData.mesh.add_vertex(Mesh::Point(-halfW, halfH, -halfD));
	meshData.mesh.set_texcoord2D(vHandles[1], OpenMesh::Vec2f(0.f, 0.f));
	vHandles[2] = meshData.mesh.add_vertex(Mesh::Point(halfW, halfH, -halfD));
	meshData.mesh.set_texcoord2D(vHandles[2], OpenMesh::Vec2f(1.f, 0.f));
	vHandles[3] = meshData.mesh.add_vertex(Mesh::Point(halfW, -halfH, -halfD));
	meshData.mesh.set_texcoord2D(vHandles[3], OpenMesh::Vec2f(1.f, 1.f));

	vHandles[4] = meshData.mesh.add_vertex(Mesh::Point(-halfW, -halfH, halfD));
	meshData.mesh.set_texcoord2D(vHandles[4], OpenMesh::Vec2f(0.f, 1.f));
	vHandles[5] = meshData.mesh.add_vertex(Mesh::Point(-halfW, halfH, halfD));
	meshData.mesh.set_texcoord2D(vHandles[5], OpenMesh::Vec2f(0.0, 0.0));
	vHandles[6] = meshData.mesh.add_vertex(Mesh::Point(-halfW, halfH, -halfD));
	meshData.mesh.set_texcoord2D(vHandles[6], OpenMesh::Vec2f(1.f, 0.f));
	vHandles[7] = meshData.mesh.add_vertex(Mesh::Point(-halfW, -halfH, -halfD));
	meshData.mesh.set_texcoord2D(vHandles[7], OpenMesh::Vec2f(1.f, 1.f));

	vHandles[8] = meshData.mesh.add_vertex(Mesh::Point(halfW, -halfH, halfD));
	meshData.mesh.set_texcoord2D(vHandles[8], OpenMesh::Vec2f(0.f, 1.f));
	vHandles[9] = meshData.mesh.add_vertex(Mesh::Point(halfW, halfH, halfD));
	meshData.mesh.set_texcoord2D(vHandles[9], OpenMesh::Vec2f(0.0, 0.0));
	vHandles[10] = meshData.mesh.add_vertex(Mesh::Point(-halfW, halfH, halfD));
	meshData.mesh.set_texcoord2D(vHandles[10], OpenMesh::Vec2f(1.f, 0.f));
	vHandles[11] = meshData.mesh.add_vertex(Mesh::Point(-halfW, -halfH, halfD));
	meshData.mesh.set_texcoord2D(vHandles[11], OpenMesh::Vec2f(1.f, 1.f));

	vHandles[12] = meshData.mesh.add_vertex(Mesh::Point(halfW, -halfH, -halfD));
	meshData.mesh.set_texcoord2D(vHandles[12], OpenMesh::Vec2f(0.f, 1.f));
	vHandles[13] = meshData.mesh.add_vertex(Mesh::Point(halfW, halfH, -halfD));
	meshData.mesh.set_texcoord2D(vHandles[13], OpenMesh::Vec2f(0.0, 0.0));
	vHandles[14] = meshData.mesh.add_vertex(Mesh::Point(halfW, halfH, halfD));
	meshData.mesh.set_texcoord2D(vHandles[14], OpenMesh::Vec2f(1.f, 0.f));
	vHandles[15] = meshData.mesh.add_vertex(Mesh::Point(halfW, -halfH, halfD));
	meshData.mesh.set_texcoord2D(vHandles[15], OpenMesh::Vec2f(1.f, 1.f));

	vHandles[16] = meshData.mesh.add_vertex(Mesh::Point(-halfW, halfH, -halfD));
	meshData.mesh.set_texcoord2D(vHandles[16], OpenMesh::Vec2f(0.f, 1.f));
	vHandles[17] = meshData.mesh.add_vertex(Mesh::Point(-halfW, halfH, halfD));
	meshData.mesh.set_texcoord2D(vHandles[17], OpenMesh::Vec2f(0.0, 0.0));
	vHandles[18] = meshData.mesh.add_vertex(Mesh::Point(halfW, halfH, halfD));
	meshData.mesh.set_texcoord2D(vHandles[18], OpenMesh::Vec2f(1.f, 0.f));
	vHandles[19] = meshData.mesh.add_vertex(Mesh::Point(halfW, halfH, -halfD));
	meshData.mesh.set_texcoord2D(vHandles[19], OpenMesh::Vec2f(1.f, 1.f));

	vHandles[20] = meshData.mesh.add_vertex(Mesh::Point(-halfW, -halfH, halfD));
	meshData.mesh.set_texcoord2D(vHandles[20], OpenMesh::Vec2f(0.f, 1.f));
	vHandles[21] = meshData.mesh.add_vertex(Mesh::Point(-halfW, -halfH, -halfD));
	meshData.mesh.set_texcoord2D(vHandles[21], OpenMesh::Vec2f(0.0, 0.0));
	vHandles[22] = meshData.mesh.add_vertex(Mesh::Point(halfW, -halfH, -halfD));
	meshData.mesh.set_texcoord2D(vHandles[22], OpenMesh::Vec2f(1.f, 0.f));
	vHandles[23] = meshData.mesh.add_vertex(Mesh::Point(halfW, -halfH, halfD));
	meshData.mesh.set_texcoord2D(vHandles[23], OpenMesh::Vec2f(1.f, 1.f));

	//��ʼ��6���棨12�������Σ�
	std::vector<Mesh::VertexHandle>  face_vhandles;
	//����
	face_vhandles.clear();
	face_vhandles.push_back(vHandles[0]);
	face_vhandles.push_back(vHandles[1]);
	face_vhandles.push_back(vHandles[2]);
	meshData.mesh.add_face(face_vhandles);
	face_vhandles.clear();
	face_vhandles.push_back(vHandles[0]);
	face_vhandles.push_back(vHandles[2]);
	face_vhandles.push_back(vHandles[3]);
	meshData.mesh.add_face(face_vhandles);
	//�����
	face_vhandles.clear();
	face_vhandles.push_back(vHandles[4]);
	face_vhandles.push_back(vHandles[5]);
	face_vhandles.push_back(vHandles[6]);
	meshData.mesh.add_face(face_vhandles);
	face_vhandles.clear();
	face_vhandles.push_back(vHandles[4]);
	face_vhandles.push_back(vHandles[6]);
	face_vhandles.push_back(vHandles[7]);
	meshData.mesh.add_face(face_vhandles);
	//����
	face_vhandles.clear();
	face_vhandles.push_back(vHandles[8]);
	face_vhandles.push_back(vHandles[9]);
	face_vhandles.push_back(vHandles[10]);
	meshData.mesh.add_face(face_vhandles);
	face_vhandles.clear();
	face_vhandles.push_back(vHandles[8]);
	face_vhandles.push_back(vHandles[10]);
	face_vhandles.push_back(vHandles[11]);
	meshData.mesh.add_face(face_vhandles);
	//�Ҳ���
	face_vhandles.clear();
	face_vhandles.push_back(vHandles[12]);
	face_vhandles.push_back(vHandles[13]);
	face_vhandles.push_back(vHandles[14]);
	meshData.mesh.add_face(face_vhandles);
	face_vhandles.clear();
	face_vhandles.push_back(vHandles[12]);
	face_vhandles.push_back(vHandles[14]);
	face_vhandles.push_back(vHandles[15]);
	meshData.mesh.add_face(face_vhandles);
	//����
	face_vhandles.clear();
	face_vhandles.push_back(vHandles[16]);
	face_vhandles.push_back(vHandles[17]);
	face_vhandles.push_back(vHandles[18]);
	meshData.mesh.add_face(face_vhandles);
	face_vhandles.clear();
	face_vhandles.push_back(vHandles[16]);
	face_vhandles.push_back(vHandles[18]);
	face_vhandles.push_back(vHandles[19]);
	meshData.mesh.add_face(face_vhandles);
	//����
	face_vhandles.clear();
	face_vhandles.push_back(vHandles[20]);
	face_vhandles.push_back(vHandles[21]);
	face_vhandles.push_back(vHandles[22]);
	meshData.mesh.add_face(face_vhandles);
	face_vhandles.clear();
	face_vhandles.push_back(vHandles[20]);
	face_vhandles.push_back(vHandles[22]);
	face_vhandles.push_back(vHandles[23]);
	meshData.mesh.add_face(face_vhandles);

	//���㷨����
	meshData.mesh.request_vertex_normals();
	meshData.mesh.request_face_normals();
	meshData.mesh.update_normals();
	meshData.mesh.release_face_normals();

}

int Sphere::sphereCount = 0;
void Sphere::InitData()
{
	meshData.providedTex = true;
	meshData.mesh.request_vertex_texcoords2D();

	int vertsPerRow = slice + 1;
	int nRows = stack - 1;

	int nVerts = vertsPerRow * nRows + 2;
	int nIndices = (nRows - 1)*slice * 6 + slice * 6;

	Mesh::VertexHandle* vHandles;
	vHandles = new Mesh::VertexHandle[nVerts];

	for (int i = 1; i <= nRows; ++i)
	{
		float phy = PI * i / stack;
		float tmpRadius = radius * sin(phy);
		for (int j = 0; j < vertsPerRow; ++j)
		{
			float theta = 2 * PI * j / slice;
			int index = (i - 1)*vertsPerRow + j;

			float x = tmpRadius * cos(theta);
			float y = radius * cos(phy);
			float z = tmpRadius * sin(theta);

			//λ������
			vHandles[index] = meshData.mesh.add_vertex(Mesh::Point(x, y, z));
			//��������
			meshData.mesh.set_texcoord2D(vHandles[index], OpenMesh::Vec2f(j * 1.f / slice, i * 1.f / stack));
		}
	}

	int size = vertsPerRow * nRows;
	//��Ӷ����͵ײ�����������Ϣ
	vHandles[size] = meshData.mesh.add_vertex(Mesh::Point(0.f, radius, 0.f));
	meshData.mesh.set_texcoord2D(vHandles[size], OpenMesh::Vec2f(0.f, 0.f));

	vHandles[size + 1] = meshData.mesh.add_vertex(Mesh::Point(0.f, -radius, 0.f));
	meshData.mesh.set_texcoord2D(vHandles[size + 1], OpenMesh::Vec2f(0.f, 1.f));

	int tmp(0);
	int start1 = 0;
	int start2 = nVerts - vertsPerRow - 2;
	int top = size;
	int bottom = size + 1;
	std::vector<Mesh::VertexHandle>  face_vhandles;
	for (int i = 0; i < slice; ++i)
	{
		face_vhandles.clear();
		face_vhandles.push_back(vHandles[top]);
		face_vhandles.push_back(vHandles[start1 + i + 1]);
		face_vhandles.push_back(vHandles[start1 + i]);
		meshData.mesh.add_face(face_vhandles);
	}

	for (int i = 0; i < slice; ++i)
	{
		face_vhandles.clear();
		face_vhandles.push_back(vHandles[bottom]);
		face_vhandles.push_back(vHandles[start2 + i]);
		face_vhandles.push_back(vHandles[start2 + i + 1]);
		meshData.mesh.add_face(face_vhandles);
	}

	for (int i = 0; i < nRows - 1; ++i)
	{
		for (int j = 0; j < slice; ++j)
		{
			face_vhandles.clear();
			face_vhandles.push_back(vHandles[i * vertsPerRow + j]);
			face_vhandles.push_back(vHandles[(i + 1) * vertsPerRow + j + 1]);
			face_vhandles.push_back(vHandles[(i + 1) * vertsPerRow + j]);
			meshData.mesh.add_face(face_vhandles);

			face_vhandles.clear();
			face_vhandles.push_back(vHandles[i * vertsPerRow + j]);
			face_vhandles.push_back(vHandles[i * vertsPerRow + j + 1]);
			face_vhandles.push_back(vHandles[(i + 1) * vertsPerRow + j + 1]);
			meshData.mesh.add_face(face_vhandles);
		}
	}

	delete[]vHandles;

	//���㷨����
	meshData.mesh.request_vertex_normals();
	meshData.mesh.request_face_normals();
	meshData.mesh.update_normals();
	meshData.mesh.release_face_normals();
}

int Grid::gridCount = 0;
void Grid::InitData()
{
	meshData.providedTex = true;
	meshData.mesh.request_vertex_texcoords2D();

	int nVertsRow = m + 1;			//x���򶥵���
	int nVertsCol = n + 1;			//z���򶥵���

	float oX = -width * 0.5f;			//x�������ʼλ��
	float oZ = height * 0.5f;			//z�������ʼλ��

	float dX = width / m;			//�仯��
	float dZ = height / n;

	Mesh::VertexHandle* vHandles;
	vHandles = new Mesh::VertexHandle[nVertsCol * nVertsRow];
	//pointsData.resize(nVertsCol * nVertsRow);

	//�����Ͻǿ�ʼ������Ӷ�����Ϣ
	for (int i = 0; i < nVertsCol; i++)
	{
		float tempZ = oZ - dZ * i;
		for (int j = 0; j < nVertsRow; j++)
		{
			int index = i * nVertsRow + j;
			//����
			vHandles[index] = meshData.mesh.add_vertex(Mesh::Point(oX + dX * j, 0.f, tempZ));
			//����
			meshData.mesh.set_texcoord2D(vHandles[index], OpenMesh::Vec2f(dX * j, dZ * i));
		}
	}

	//һ��m*n�����ӣ�һ�����ӷ�Ϊ��������������6������
	int temp = 0;
	std::vector<Mesh::VertexHandle>  face_vhandles;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			face_vhandles.clear();
			face_vhandles.push_back(vHandles[i * nVertsRow + j]);
			face_vhandles.push_back(vHandles[i * nVertsRow + j + 1]);
			face_vhandles.push_back(vHandles[(i + 1) * nVertsRow + j]);
			meshData.mesh.add_face(face_vhandles);

			face_vhandles.clear();
			face_vhandles.push_back(vHandles[i * nVertsRow + j + 1]);
			face_vhandles.push_back(vHandles[(i + 1) * nVertsRow + j + 1]);
			face_vhandles.push_back(vHandles[(i + 1) * nVertsRow + j]);
			meshData.mesh.add_face(face_vhandles);
		}
	}

	delete[] vHandles;

	//���㷨����
	meshData.mesh.request_vertex_normals();
	meshData.mesh.request_face_normals();
	meshData.mesh.update_normals();
	meshData.mesh.release_face_normals();
}
