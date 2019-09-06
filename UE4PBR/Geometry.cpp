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
