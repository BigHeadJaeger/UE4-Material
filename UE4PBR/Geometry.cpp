#include "Geometry.h"

int Box::boxCount = 0;

void Box::InitData()
{
	meshData.providedTex = true;
	meshData.mesh.request_vertex_texcoords2D();
	float halfW = width * 0.5f;
	float halfH = height * 0.5f;
	float halfD = depth * 0.5f;

	//初始化4*6=24个顶点
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

	//初始化6个面（12个三角形）
	std::vector<Mesh::VertexHandle>  face_vhandles;
	//背面
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
	//左侧面
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
	//正面
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
	//右侧面
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
	//上面
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
	//下面
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

	//计算法向量
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
	//pointsData.resize(nVerts);
	//renderIndex.resize(nIndices);

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

			//位置坐标
			vHandles[index] = meshData.mesh.add_vertex(Mesh::Point(x, y, z));
			//pointsData[index].vertex = vec3(x, y, z);
			//法线
			//vec3 N = vec3(x, y, z);
			//meshData.mesh.set_normal(vHandles[index],OpenMesh::Vec3f(x, y, z))
			//pointsData[index].normal = N;
			//XMStoreFloat3(&pointsData[index].normal, XMVector3Normalize(N));
			//切线
			/*XMVECTOR T = XMVectorSet(-sin(theta), 0.f, cos(theta), 0.f);
			XMStoreFloat3(&pointsData[index].tangent, XMVector3Normalize(T));*/
			//纹理坐标
			meshData.mesh.set_texcoord2D(vHandles[index], OpenMesh::Vec2f(j * 1.f / slice, i * 1.f / stack));
			//pointsData[index].texcoord = vec2(j*1.f / slice, i*1.f / stack);
		}
	}

	int size = vertsPerRow * nRows;
	//添加顶部和底部两个顶点信息
	vHandles[size] = meshData.mesh.add_vertex(Mesh::Point(0.f, radius, 0.f));
	meshData.mesh.set_texcoord2D(vHandles[size], OpenMesh::Vec2f(0.f, 0.f));
	//pointsData[size].texcoord = vec2(0.f, 0.f);

	vHandles[size + 1] = meshData.mesh.add_vertex(Mesh::Point(0.f, -radius, 0.f));
	meshData.mesh.set_texcoord2D(vHandles[size + 1], OpenMesh::Vec2f(0.f, 1.f));
	//pointsData[size + 1].vertex = vec3(0.f, -radius, 0.f);
	//pointsData[size + 1].normal = vec3(0.f, -1.f, 0.f);
	////pointsData[size + 1].tangent = vec3(1.f, 0.f, 0.f);
	//pointsData[size + 1].texcoord = vec2(0.f, 1.f);

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
		//renderIndex[tmp] = top;
		//renderIndex[tmp + 1] = start1 + i + 1;
		//renderIndex[tmp + 2] = start1 + i;

		//tmp += 3;
	}

	for (int i = 0; i < slice; ++i)
	{
		face_vhandles.clear();
		face_vhandles.push_back(vHandles[bottom]);
		face_vhandles.push_back(vHandles[start2 + i]);
		face_vhandles.push_back(vHandles[start2 + i + 1]);
		meshData.mesh.add_face(face_vhandles);

		//renderIndex[tmp] = bottom;
		//renderIndex[tmp + 1] = start2 + i;
		//renderIndex[tmp + 2] = start2 + i + 1;

		//tmp += 3;
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

			//renderIndex[tmp] = i * vertsPerRow + j;
			//renderIndex[tmp + 1] = (i + 1) * vertsPerRow + j + 1;
			//renderIndex[tmp + 2] = (i + 1) * vertsPerRow + j;
			//renderIndex[tmp + 3] = i * vertsPerRow + j;
			//renderIndex[tmp + 4] = i * vertsPerRow + j + 1;
			//renderIndex[tmp + 5] = (i + 1) * vertsPerRow + j + 1;

			//tmp += 6;
		}
	}

	delete[]vHandles;

	//计算法向量
	meshData.mesh.request_vertex_normals();
	meshData.mesh.request_face_normals();
	meshData.mesh.update_normals();
	meshData.mesh.release_face_normals();
}
