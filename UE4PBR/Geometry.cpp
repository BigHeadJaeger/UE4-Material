#include "Geometry.h"

int Box::boxCount = 0;

void Box::InitData()
{
	meshData.providedTex = true;
	meshData.mesh.request_vertex_texcoords2D();
	float halfW = width * 0.5f;
	float halfH = height * 0.5f;
	float halfD = depth * 0.5f;

	//初始化8个顶点
	Mesh::VertexHandle vHandles[8];
	vHandles[0] = meshData.mesh.add_vertex(Mesh::Point(-halfW, -halfH, halfD));
	meshData.mesh.set_texcoord2D(vHandles[0], OpenMesh::Vec2f(0.0, 0.0));
	vHandles[1] = meshData.mesh.add_vertex(Mesh::Point(halfW, -halfH, halfD));
	meshData.mesh.set_texcoord2D(vHandles[1], OpenMesh::Vec2f(1.0, 0.0));
	vHandles[2] = meshData.mesh.add_vertex(Mesh::Point(halfW, halfH, halfD));
	meshData.mesh.set_texcoord2D(vHandles[2], OpenMesh::Vec2f(1.0, 1.0));
	vHandles[3] = meshData.mesh.add_vertex(Mesh::Point(-halfW, halfH, halfD));
	meshData.mesh.set_texcoord2D(vHandles[3], OpenMesh::Vec2f(0.0, 1.0));
	vHandles[4] = meshData.mesh.add_vertex(Mesh::Point(-halfW, -halfH, -halfD));
	meshData.mesh.set_texcoord2D(vHandles[4], OpenMesh::Vec2f(1.0, 0.0));
	vHandles[5] = meshData.mesh.add_vertex(Mesh::Point(halfW, -halfH, -halfD));
	meshData.mesh.set_texcoord2D(vHandles[5], OpenMesh::Vec2f(0.0, 0.0));
	vHandles[6] = meshData.mesh.add_vertex(Mesh::Point(halfW, halfH, -halfD));
	meshData.mesh.set_texcoord2D(vHandles[6], OpenMesh::Vec2f(0.0, 1.0));
	vHandles[7] = meshData.mesh.add_vertex(Mesh::Point(-halfW, halfH, -halfD));
	meshData.mesh.set_texcoord2D(vHandles[7], OpenMesh::Vec2f(1.0, 1.0));

	//初始化6个面（12个三角形）
	std::vector<Mesh::VertexHandle>  face_vhandles;
	//正面
	face_vhandles.clear();
	face_vhandles.push_back(vHandles[0]);
	face_vhandles.push_back(vHandles[1]);
	face_vhandles.push_back(vHandles[3]);
	meshData.mesh.add_face(face_vhandles);
	face_vhandles.clear();
	face_vhandles.push_back(vHandles[1]);
	face_vhandles.push_back(vHandles[2]);
	face_vhandles.push_back(vHandles[3]);
	meshData.mesh.add_face(face_vhandles);
	//左侧面
	face_vhandles.clear();
	face_vhandles.push_back(vHandles[3]);
	face_vhandles.push_back(vHandles[7]);
	face_vhandles.push_back(vHandles[4]);
	meshData.mesh.add_face(face_vhandles);
	face_vhandles.clear();
	face_vhandles.push_back(vHandles[3]);
	face_vhandles.push_back(vHandles[4]);
	face_vhandles.push_back(vHandles[0]);
	meshData.mesh.add_face(face_vhandles);
	//后面
	face_vhandles.clear();
	face_vhandles.push_back(vHandles[7]);
	face_vhandles.push_back(vHandles[6]);
	face_vhandles.push_back(vHandles[5]);
	meshData.mesh.add_face(face_vhandles);
	face_vhandles.clear();
	face_vhandles.push_back(vHandles[7]);
	face_vhandles.push_back(vHandles[5]);
	face_vhandles.push_back(vHandles[4]);
	meshData.mesh.add_face(face_vhandles);
	//右侧面
	face_vhandles.clear();
	face_vhandles.push_back(vHandles[2]);
	face_vhandles.push_back(vHandles[1]);
	face_vhandles.push_back(vHandles[5]);
	meshData.mesh.add_face(face_vhandles);
	face_vhandles.clear();
	face_vhandles.push_back(vHandles[2]);
	face_vhandles.push_back(vHandles[5]);
	face_vhandles.push_back(vHandles[6]);
	meshData.mesh.add_face(face_vhandles);
	//上面
	face_vhandles.clear();
	face_vhandles.push_back(vHandles[7]);
	face_vhandles.push_back(vHandles[3]);
	face_vhandles.push_back(vHandles[2]);
	meshData.mesh.add_face(face_vhandles);
	face_vhandles.clear();
	face_vhandles.push_back(vHandles[7]);
	face_vhandles.push_back(vHandles[2]);
	face_vhandles.push_back(vHandles[6]);
	meshData.mesh.add_face(face_vhandles);
	//下面
	face_vhandles.clear();
	face_vhandles.push_back(vHandles[0]);
	face_vhandles.push_back(vHandles[4]);
	face_vhandles.push_back(vHandles[5]);
	meshData.mesh.add_face(face_vhandles);
	face_vhandles.clear();
	face_vhandles.push_back(vHandles[0]);
	face_vhandles.push_back(vHandles[5]);
	face_vhandles.push_back(vHandles[1]);
	meshData.mesh.add_face(face_vhandles);

	//自动计算法向量
	meshData.mesh.request_vertex_normals();
	meshData.mesh.request_face_normals();
	meshData.mesh.update_normals();

}
