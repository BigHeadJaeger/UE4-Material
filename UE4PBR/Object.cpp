//#include "Object.h"
//
//Object::Object()
//{
//}
//
//Object::~Object()
//{
//}
//
///*void Object::CoorDataInit(mat4x4 world, mat4x4 worldviewproj, mat4x4 worldinvtranspose, vec3 scaler)
//{
//	World = world;
//	WorldViewProj = worldviewproj;
//	WorldInvTranspose = worldinvtranspose;
//	Scaler = scaler;
//}*/
//
//void Object::CoorDataInit(vec3 pos, vec3 scaler, vec3 rot, float angle)
//{
//	Position = pos;
//	Scaler = scaler;
//	Rotation = rot;
//	RotateAngle = angle;
//}
//
//void Object::SetObjMat(mat4 camView, mat4 camProj)
//{
//	World = translate(mat4(1.0), Position);
//	World = scale(World, Scaler);
//	World = rotate(World, RotateAngle, Rotation);
//	WorldInvTranspose = transpose(inverse(World));
//	WorldViewProj = camProj * camView*World;
//	/*mat4x4 boxWorld = translate(mat4(1.0), vec3(0.0, 0.0, 0.0));
//	mat4x4 boxWorldInvTranspose = transpose(inverse(boxWorld));
//	mat4x4 boxWorldViewProj = camera.pro*camera.view*boxWorld;*/
//
//}
//
//void Object::InitUseMesh(string fileName, bool texture, ObjIndexType type)
//{
//	modelPath = fileName;
//
//	indexType = type;
//
//	BisTexture = texture;
//
//	ifstream file;
//	file.open(fileName);
//	if (!file.is_open())
//		cout << "��obj�ļ�ʧ��" << endl;
//
//	string line, flag;				//һ�е����ݺ�һ���п�ͷ�ı�־��
//
//	float x, y, z;					//��������
//	float u, v;						//��������
//	float nx, ny, nz;				//����������
//
//	char temp;
//
//	//���ϵ�������� ���㡢����������������
//	unsigned indexV0, indexV1, indexV2, indexV3;
//	unsigned indexN0, indexN1, indexN2, indexN3;
//	unsigned indexT0, indexT1, indexT2, indexT3;
//
//	//vector<float> vertices;
//	//��ȡobjʱ������ʱ�洢
//	vector<float> normals;
//	vector<float> texcoords;
//
//	//��ʼ��AABB��Χ��
//	aabb.maxPos = vec3(float(-M_INFINITE), float(-M_INFINITE), float(-M_INFINITE));
//	aabb.minPos = vec3(float(M_INFINITE), float(M_INFINITE), float(M_INFINITE));
//
//	while (getline(file, line))
//	{
//		istringstream ist(line);
//		ist >> flag;
//		if (flag == "v")
//		{
//			ist >> x >> y >> z;
//
//			if (x > aabb.maxPos.x)aabb.maxPos.x = x;
//			if (y > aabb.maxPos.y)aabb.maxPos.y = y;
//			if (z > aabb.maxPos.z)aabb.maxPos.z = z;
//
//			if (x < aabb.minPos.x)aabb.minPos.x = x;
//			if (y < aabb.minPos.y)aabb.minPos.y = y;
//			if (z < aabb.minPos.z)aabb.minPos.z = z;
//
//			//�˴��Ƚ�����λ�÷���pointsData���Ա�֤����λ�ð���obj�ļ����У�֮���ٸ��ݸ���������ͼ�������겹ȫ
//			Point temp;
//			temp.vertex = vec3(x, y, z);
//			pointsData.push_back(temp);
//
//			/*vertices.push_back(x);
//			vertices.push_back(y);
//			vertices.push_back(z);*/
//		}
//		else if (flag == "vt")
//		{
//			ist >> u >> v;
//			texcoords.push_back(u);
//			texcoords.push_back(v);
//		}
//		else if (flag == "vn")
//		{
//			ist >> nx >> ny >> nz;
//			normals.push_back(nx);
//			normals.push_back(ny);
//			normals.push_back(nz);
//		}
//		else if (flag == "f")
//		{
//			if (type == ObjIndexType::Triangles)
//			{
//				//��Ϊ�󲿷�obj�ļ�����ÿ�����㶼��3������дһ�飬������ͨ�������ظ�����ͬһ����ֵ(ע�������Ǵ�1��ʼ��)
//				if (BisTexture)			//�����Ƿ�����������
//				{
//					ist >> indexV0 >> temp >> indexT0 >> temp >> indexN0
//						>> indexV1 >> temp >> indexT1 >> temp >> indexN1
//						>> indexV2 >> temp >> indexT2 >> temp >> indexN2;
//					//��Ⱦʱ�õ���˳��
//					renderIndex.push_back(indexV0 - 1);
//					renderIndex.push_back(indexV1 - 1);
//					renderIndex.push_back(indexV2 - 1);
//					//�������������߶�Ӧ��֮ǰֻ���˶���λ�õ�pointsData��
//					pointsData[indexV0 - 1].normal = vec3(normals[3 * (indexN0 - 1)], normals[3 * (indexN0 - 1) + 1], normals[3 * (indexN0 - 1) + 2]);
//					pointsData[indexV1 - 1].normal = vec3(normals[3 * (indexN1 - 1)], normals[3 * (indexN1 - 1) + 1], normals[3 * (indexN1 - 1) + 2]);
//					pointsData[indexV2 - 1].normal = vec3(normals[3 * (indexN2 - 1)], normals[3 * (indexN2 - 1) + 1], normals[3 * (indexN2 - 1) + 2]);
//					//��д����
//					pointsData[indexV0 - 1].texcoord = vec2(texcoords[2 * (indexT0 - 1)], texcoords[2 * (indexT0 - 1) + 1]);
//					pointsData[indexV1 - 1].texcoord = vec2(texcoords[2 * (indexT1 - 1)], texcoords[2 * (indexT1 - 1) + 1]);
//					pointsData[indexV2 - 1].texcoord = vec2(texcoords[2 * (indexT2 - 1)], texcoords[2 * (indexT2 - 1) + 1]);
//
//				}
//				else
//				{
//					ist >> indexV0 >> temp >> temp >> indexN0
//						>> indexV1 >> temp >> temp >> indexN1
//						>> indexV2 >> temp >> temp >> indexN2;
//
//					//��Ⱦʱ�õ���˳��
//					renderIndex.push_back(indexV0 - 1);
//					renderIndex.push_back(indexV1 - 1);
//					renderIndex.push_back(indexV2 - 1);
//					//�������������߶�Ӧ��֮ǰֻ���˶���λ�õ�pointsData��
//					pointsData[indexV0 - 1].normal = vec3(normals[3 * (indexN0 - 1)], normals[3 * (indexN0 - 1) + 1], normals[3 * (indexN0 - 1) + 2]);
//					pointsData[indexV1 - 1].normal = vec3(normals[3 * (indexN1 - 1)], normals[3 * (indexN1 - 1) + 1], normals[3 * (indexN1 - 1) + 2]);
//					pointsData[indexV2 - 1].normal = vec3(normals[3 * (indexN2 - 1)], normals[3 * (indexN2 - 1) + 1], normals[3 * (indexN2 - 1) + 2]);
//				}
//
//			}
//			else if (type == ObjIndexType::Quad)
//			{
//				if (BisTexture)			//�����Ƿ�����������
//				{
//					ist >> indexV0 >> temp >> indexT0 >> temp >> indexN0
//						>> indexV1 >> temp >> indexT1 >> temp >> indexN1
//						>> indexV2 >> temp >> indexT2 >> temp >> indexN2
//						>> indexV3 >> temp >> indexT3 >> temp >> indexN3;
//
//					renderIndex.push_back(indexV0 - 1);
//					renderIndex.push_back(indexV1 - 1);
//					renderIndex.push_back(indexV2 - 1);
//					renderIndex.push_back(indexV3 - 1);
//
//					//�������������߶�Ӧ��֮ǰֻ���˶���λ�õ�pointsData��
//					pointsData[indexV0 - 1].normal = vec3(normals[3 * (indexN0 - 1)], normals[3 * (indexN0 - 1) + 1], normals[3 * (indexN0 - 1) + 2]);
//					pointsData[indexV1 - 1].normal = vec3(normals[3 * (indexN1 - 1)], normals[3 * (indexN1 - 1) + 1], normals[3 * (indexN1 - 1) + 2]);
//					pointsData[indexV2 - 1].normal = vec3(normals[3 * (indexN2 - 1)], normals[3 * (indexN2 - 1) + 1], normals[3 * (indexN2 - 1) + 2]);
//					pointsData[indexV3 - 1].normal = vec3(normals[3 * (indexN3 - 1)], normals[3 * (indexN3 - 1) + 1], normals[3 * (indexN3 - 1) + 2]);
//
//					//��д����
//					pointsData[indexV0 - 1].texcoord = vec2(texcoords[2 * (indexT0 - 1)], texcoords[2 * (indexT0 - 1) + 1]);
//					pointsData[indexV1 - 1].texcoord = vec2(texcoords[2 * (indexT1 - 1)], texcoords[2 * (indexT1 - 1) + 1]);
//					pointsData[indexV2 - 1].texcoord = vec2(texcoords[2 * (indexT2 - 1)], texcoords[2 * (indexT2 - 1) + 1]);
//					pointsData[indexV3 - 1].texcoord = vec2(texcoords[2 * (indexT3 - 1)], texcoords[2 * (indexT3 - 1) + 1]);
//				}
//				else
//				{
//					ist >> indexV0 >> temp >> temp >> indexN0
//						>> indexV1 >> temp >> temp >> indexN1
//						>> indexV2 >> temp >> temp >> indexN2
//						>> indexV3 >> temp >> temp >> indexN3;
//
//					renderIndex.push_back(indexV0 - 1);
//					renderIndex.push_back(indexV1 - 1);
//					renderIndex.push_back(indexV2 - 1);
//					renderIndex.push_back(indexV3 - 1);
//
//					//�������������߶�Ӧ��֮ǰֻ���˶���λ�õ�pointsData��
//					pointsData[indexV0 - 1].normal = vec3(normals[3 * (indexN0 - 1)], normals[3 * (indexN0 - 1) + 1], normals[3 * (indexN0 - 1) + 2]);
//					pointsData[indexV1 - 1].normal = vec3(normals[3 * (indexN1 - 1)], normals[3 * (indexN1 - 1) + 1], normals[3 * (indexN1 - 1) + 2]);
//					pointsData[indexV2 - 1].normal = vec3(normals[3 * (indexN2 - 1)], normals[3 * (indexN2 - 1) + 1], normals[3 * (indexN2 - 1) + 2]);
//					pointsData[indexV3 - 1].normal = vec3(normals[3 * (indexN3 - 1)], normals[3 * (indexN3 - 1) + 1], normals[3 * (indexN3 - 1) + 2]);
//
//				}
//			}
//
//		}
//
//	}
//
//	file.close();
//
//	ObjNormalize();
//}
//
//void Object::InitDirectBox(float width, float height, float depth)
//{
//	BisTexture = true;
//
//	renderIndex.clear();
//	pointsData.clear();
//
//	renderIndex.resize(36);
//	pointsData.resize(24);
//
//	float halfW = width * 0.5f;
//	float halfH = height * 0.5f;
//	float halfD = depth * 0.5f;
//
//	//����
//
//	pointsData[0].vertex = vec3(-halfW, -halfH, -halfD);
//	pointsData[0].normal = vec3(0.f, 0.f, -1.f);
//	//pointsData[0].tangent = vec3(1.f, 0.f, 0.f);
//	pointsData[0].texcoord = vec2(0.f, 1.f);
//	pointsData[1].vertex = vec3(-halfW, halfH, -halfD);
//	pointsData[1].normal = vec3(0.f, 0.f, -1.f);
//	//pointsData[1].tangent = vec3(1.f, 0.f, 0.f);
//	pointsData[1].texcoord = vec2(0.f, 0.f);
//	pointsData[2].vertex = vec3(halfW, halfH, -halfD);
//	pointsData[2].normal = vec3(0.f, 0.f, -1.f);
//	//pointsData[2].tangent = vec3(1.f, 0.f, 0.f);
//	pointsData[2].texcoord = vec2(1.f, 0.f);
//	pointsData[3].vertex = vec3(halfW, -halfH, -halfD);
//	pointsData[3].normal = vec3(0.f, 0.f, -1.f);
//	//pointsData[3].tangent = vec3(1.f, 0.f, 0.f);
//	pointsData[3].texcoord = vec2(1.f, 1.f);
//	//�����
//	pointsData[4].vertex = vec3(-halfW, -halfH, halfD);
//	pointsData[4].normal = vec3(-1.f, 0.f, 0.f);
//	//pointsData[4].tangent = vec3(0.f, 0.f, -1.f);
//	pointsData[4].texcoord = vec2(0.f, 1.f);
//	pointsData[5].vertex = vec3(-halfW, halfH, halfD);
//	pointsData[5].normal = vec3(-1.f, 0.f, 0.f);
//	//pointsData[5].tangent = vec3(0.f, 0.f, -1.f);
//	pointsData[5].texcoord = vec2(0.f, 0.f);
//	pointsData[6].vertex = vec3(-halfW, halfH, -halfD);
//	pointsData[6].normal = vec3(-1.f, 0.f, 0.f);
//	//pointsData[6].tangent = vec3(0.f, 0.f, -1.f);
//	pointsData[6].texcoord = vec2(1.f, 0.f);
//	pointsData[7].vertex = vec3(-halfW, -halfH, -halfD);
//	pointsData[7].normal = vec3(-1.f, 0.f, 0.f);
//	//pointsData[7].tangent = vec3(0.f, 0.f, -1.f);
//	pointsData[7].texcoord = vec2(1.f, 1.f);
//	//����
//	pointsData[8].vertex = vec3(halfW, -halfH, halfD);
//	pointsData[8].normal = vec3(0.f, 0.f, 1.f);
//	//pointsData[8].tangent = vec3(-1.f, 0.f, 0.f);
//	pointsData[8].texcoord = vec2(0.f, 1.f);
//	pointsData[9].vertex = vec3(halfW, halfH, halfD);
//	pointsData[9].normal = vec3(0.f, 0.f, 1.f);
//	//pointsData[9].tangent = vec3(-1.f, 0.f, 0.f);
//	pointsData[9].texcoord = vec2(0.f, 0.f);
//	pointsData[10].vertex = vec3(-halfW, halfH, halfD);
//	pointsData[10].normal = vec3(0.f, 0.f, 1.f);
//	//pointsData[10].tangent = vec3(-1.f, 0.f, 0.f);
//	pointsData[10].texcoord = vec2(1.f, 0.f);
//	pointsData[11].vertex = vec3(-halfW, -halfH, halfD);
//	pointsData[11].normal = vec3(0.f, 0.f, 1.f);
//	//pointsData[11].tangent = vec3(-1.f, 0.f, 0.f);
//	pointsData[11].texcoord = vec2(1.f, 1.f);
//	//�Ҳ���
//	pointsData[12].vertex = vec3(halfW, -halfH, -halfD);
//	pointsData[12].normal = vec3(1.f, 0.f, 0.f);
//	//pointsData[12].tangent = vec3(0.f, 0.f, 1.f);
//	pointsData[12].texcoord = vec2(0.f, 1.f);
//	pointsData[13].vertex = vec3(halfW, halfH, -halfD);
//	pointsData[13].normal = vec3(1.f, 0.f, 0.f);
//	//pointsData[13].tangent = vec3(0.f, 0.f, 1.f);
//	pointsData[13].texcoord = vec2(0.f, 0.f);
//	pointsData[14].vertex = vec3(halfW, halfH, halfD);
//	pointsData[14].normal = vec3(1.f, 0.f, 0.f);
//	//pointsData[14].tangent = vec3(0.f, 0.f, 1.f);
//	pointsData[14].texcoord = vec2(1.f, 0.f);
//	pointsData[15].vertex = vec3(halfW, -halfH, halfD);
//	pointsData[15].normal = vec3(1.f, 0.f, 0.f);
//	//pointsData[15].tangent = vec3(0.f, 0.f, 1.f);
//	pointsData[15].texcoord = vec2(1.f, 1.f);
//	//����
//	pointsData[16].vertex = vec3(-halfW, halfH, -halfD);
//	pointsData[16].normal = vec3(0.f, 1.f, 0.f);
//	//pointsData[16].tangent = vec3(1.f, 0.f, 0.f);
//	pointsData[16].texcoord = vec2(0.f, 1.f);
//	pointsData[17].vertex = vec3(-halfW, halfH, halfD);
//	pointsData[17].normal = vec3(0.f, 1.f, 0.f);
//	//pointsData[17].tangent = vec3(1.f, 0.f, 0.f);
//	pointsData[17].texcoord = vec2(0.f, 0.f);
//	pointsData[18].vertex = vec3(halfW, halfH, halfD);
//	pointsData[18].normal = vec3(0.f, 1.f, 0.f);
//	//pointsData[18].tangent = vec3(1.f, 0.f, 0.f);
//	pointsData[18].texcoord = vec2(1.f, 0.f);
//	pointsData[19].vertex = vec3(halfW, halfH, -halfD);
//	pointsData[19].normal = vec3(0.f, 1.f, 0.f);
//	//pointsData[19].tangent = vec3(1.f, 0.f, 0.f);
//	pointsData[19].texcoord = vec2(1.f, 1.f);
//	//����
//	pointsData[20].vertex = vec3(-halfW, -halfH, halfD);
//	pointsData[20].normal = vec3(0.f, -1.f, 0.f);
//	//pointsData[20].tangent = vec3(1.f, 0.f, 0.f);
//	pointsData[20].texcoord = vec2(0.f, 1.f);
//	pointsData[21].vertex = vec3(-halfW, -halfH, -halfD);
//	pointsData[21].normal = vec3(0.f, -1.f, 0.f);
//	//pointsData[21].tangent = vec3(1.f, 0.f, 0.f);
//	pointsData[21].texcoord = vec2(0.f, 0.f);
//	pointsData[22].vertex = vec3(halfW, -halfH, -halfD);
//	pointsData[22].normal = vec3(0.f, -1.f, 0.f);
//	//pointsData[22].tangent = vec3(1.f, 0.f, 0.f);
//	pointsData[22].texcoord = vec2(1.f, 0.f);
//	pointsData[23].vertex = vec3(halfW, -halfH, halfD);
//	pointsData[23].normal = vec3(0.f, -1.f, 0.f);
//	//pointsData[23].tangent = vec3(1.f, 0.f, 0.f);
//	pointsData[23].texcoord = vec2(1.f, 1.f);
//
//	//��������
//	renderIndex[0] = 0;
//	renderIndex[1] = 1;
//	renderIndex[2] = 2;
//	renderIndex[3] = 0;
//	renderIndex[4] = 2;
//	renderIndex[5] = 3;
//
//	renderIndex[6] = 4;
//	renderIndex[7] = 5;
//	renderIndex[8] = 6;
//	renderIndex[9] = 4;
//	renderIndex[10] = 6;
//	renderIndex[11] = 7;
//
//	renderIndex[12] = 8;
//	renderIndex[13] = 9;
//	renderIndex[14] = 10;
//	renderIndex[15] = 8;
//	renderIndex[16] = 10;
//	renderIndex[17] = 11;
//
//	renderIndex[18] = 12;
//	renderIndex[19] = 13;
//	renderIndex[20] = 14;
//	renderIndex[21] = 12;
//	renderIndex[22] = 14;
//	renderIndex[23] = 15;
//
//	renderIndex[24] = 16;
//	renderIndex[25] = 17;
//	renderIndex[26] = 18;
//	renderIndex[27] = 16;
//	renderIndex[28] = 18;
//	renderIndex[29] = 19;
//
//	renderIndex[30] = 20;
//	renderIndex[31] = 21;
//	renderIndex[32] = 22;
//	renderIndex[33] = 20;
//	renderIndex[34] = 22;
//	renderIndex[35] = 23;
//
//}
//
//void Object::InitDirectSphere(float radius, int slice, int stack)
//{
//	BisTexture = true;
//	float PI = 3.14159265359;
//
//	pointsData.clear();
//	renderIndex.clear();
//
//	int vertsPerRow = slice + 1;
//	int nRows = stack - 1;
//
//	int nVerts = vertsPerRow * nRows + 2;
//	int nIndices = (nRows - 1)*slice * 6 + slice * 6;
//
//	pointsData.resize(nVerts);
//	renderIndex.resize(nIndices);
//
//	for (int i = 1; i <= nRows; ++i)
//	{
//		float phy = PI * i / stack;
//		float tmpRadius = radius * sin(phy);
//		for (int j = 0; j < vertsPerRow; ++j)
//		{
//			float theta = 2 * PI * j / slice;
//			int index = (i - 1)*vertsPerRow + j;
//
//			float x = tmpRadius * cos(theta);
//			float y = radius * cos(phy);
//			float z = tmpRadius * sin(theta);
//
//			//λ������
//			pointsData[index].vertex = vec3(x, y, z);
//			//����
//			vec3 N = vec3(x, y, z);
//			pointsData[index].normal = N;
//			//XMStoreFloat3(&pointsData[index].normal, XMVector3Normalize(N));
//			//����
//			/*XMVECTOR T = XMVectorSet(-sin(theta), 0.f, cos(theta), 0.f);
//			XMStoreFloat3(&pointsData[index].tangent, XMVector3Normalize(T));*/
//			//��������
//			pointsData[index].texcoord = vec2(j*1.f / slice, i*1.f / stack);
//		}
//	}
//
//	int size = vertsPerRow * nRows;
//	//��Ӷ����͵ײ�����������Ϣ
//	pointsData[size].vertex = vec3(0.f, radius, 0.f);
//	pointsData[size].normal = vec3(0.f, 1.f, 0.f);
//	//pointsData[size].tangent = vec3(1.f, 0.f, 0.f);
//	pointsData[size].texcoord = vec2(0.f, 0.f);
//
//	pointsData[size + 1].vertex = vec3(0.f, -radius, 0.f);
//	pointsData[size + 1].normal = vec3(0.f, -1.f, 0.f);
//	//pointsData[size + 1].tangent = vec3(1.f, 0.f, 0.f);
//	pointsData[size + 1].texcoord = vec2(0.f, 1.f);
//
//	int tmp(0);
//	int start1 = 0;
//	int start2 = pointsData.size() - vertsPerRow - 2;
//	int top = size;
//	int bottom = size + 1;
//	for (int i = 0; i < slice; ++i)
//	{
//		renderIndex[tmp] = top;
//		renderIndex[tmp + 1] = start1 + i + 1;
//		renderIndex[tmp + 2] = start1 + i;
//
//		tmp += 3;
//	}
//
//	for (int i = 0; i < slice; ++i)
//	{
//		renderIndex[tmp] = bottom;
//		renderIndex[tmp + 1] = start2 + i;
//		renderIndex[tmp + 2] = start2 + i + 1;
//
//		tmp += 3;
//	}
//
//	for (int i = 0; i < nRows - 1; ++i)
//	{
//		for (int j = 0; j < slice; ++j)
//		{
//			renderIndex[tmp] = i * vertsPerRow + j;
//			renderIndex[tmp + 1] = (i + 1) * vertsPerRow + j + 1;
//			renderIndex[tmp + 2] = (i + 1) * vertsPerRow + j;
//			renderIndex[tmp + 3] = i * vertsPerRow + j;
//			renderIndex[tmp + 4] = i * vertsPerRow + j + 1;
//			renderIndex[tmp + 5] = (i + 1) * vertsPerRow + j + 1;
//
//			tmp += 6;
//		}
//	}
//
//}
//
//void Object::initDirectGrid(float width, float height, int m, int n)
//{
//	BisTexture = true;
//	renderIndex.clear();
//	pointsData.clear();
//
//	int nVertsRow = m + 1;			//x���򶥵���
//	int nVertsCol = n + 1;			//z���򶥵���
//
//	float oX = -width * 0.5f;			//x�������ʼλ��
//	float oZ = height * 0.5f;			//z�������ʼλ��
//
//	float dX = width / m;			//�仯��
//	float dZ = height / n;
//
//	pointsData.resize(nVertsCol*nVertsRow);
//
//	//�����Ͻǿ�ʼ������Ӷ�����Ϣ
//	for (int i = 0; i < nVertsCol; i++)
//	{
//		float tempZ = oZ - dZ * i;
//		for (int j = 0; j < nVertsRow; j++)
//		{
//			int index = i * nVertsRow + j;
//			pointsData[index].vertex.x = oX + dX * j;
//			pointsData[index].vertex.y = 0.f;
//			pointsData[index].vertex.z = tempZ;
//
//			pointsData[index].normal = vec3(0.f, 1.f, 0.f);
//			//pointsData[index].tangent = vec3(1.f, 0.f, 0.f);
//
//			pointsData[index].texcoord = vec2(dX*j, dZ*i);
//		}
//	}
//
//	renderIndex.resize(m*n * 6);			//һ��m*n�����ӣ�һ�����ӷ�Ϊ��������������6������
//	int temp = 0;
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < m; j++)
//		{
//			renderIndex[temp] = i * nVertsRow + j;
//			renderIndex[temp + 1] = i * nVertsRow + j + 1;
//			renderIndex[temp + 2] = (i + 1)*nVertsRow + j;
//			renderIndex[temp + 3] = i * nVertsRow + j + 1;
//			renderIndex[temp + 4] = (i + 1)*nVertsRow + j + 1;
//			renderIndex[temp + 5] = (i + 1)*nVertsRow + j;
//
//			temp += 6;
//		}
//	}
//
//}
//
//void Object::InitBuffers(float TexScaler)
//{
//	//box
//	//����VAO��VAO��¼����һ�λ���������Ҫ����Ϣ
//	glGenVertexArrays(1, &VAO);
//	glBindVertexArray(VAO);
//
//	//���ɶ���buffer(VBO)����
//	//MyGeometryGenerator::GetInstance()->CreateBox(20.0f, 0.3f, 20.0f, box);
//	//ת����һά������
//	std::vector<float> vertexData;
//	for (int i = 0; i < pointsData.size(); i++)
//	{
//		vertexData.push_back(pointsData[i].vertex.x);
//		vertexData.push_back(pointsData[i].vertex.y);
//		vertexData.push_back(pointsData[i].vertex.z);
//		vertexData.push_back(pointsData[i].normal.x);
//		vertexData.push_back(pointsData[i].normal.y);
//		vertexData.push_back(pointsData[i].normal.z);
//		if (BisTexture)
//		{
//			vertexData.push_back(pointsData[i].texcoord.x*TexScaler);		//
//			vertexData.push_back(pointsData[i].texcoord.y*TexScaler);
//		}
//	}
//
//
//	//��������buffer
//	glGenBuffers(1, &VertexBuffer);
//	glBindBuffer(GL_ARRAY_BUFFER, VertexBuffer);					//�Ȱ󶨣�����VAO��ֵʱ���ʹ��͵��ǵ�ǰ�󶨵�buffer
//	glBufferData(GL_ARRAY_BUFFER, vertexData.size() * sizeof(float), &vertexData[0], GL_STATIC_DRAW);		//ָ������
//																											//��������buffer
//	glGenBuffers(1, &IndexBuffer);
//	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IndexBuffer);
//	glBufferData(GL_ELEMENT_ARRAY_BUFFER, renderIndex.size() * sizeof(unsigned), &renderIndex[0], GL_STATIC_DRAW);
//
//	//������buffer�е�����ָ����shader��
//	//ָ��pos����
//	glEnableVertexAttribArray(0);										//��������Ϊ0�Ķ�������
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);		//���������ȡ����ʱ�Ĳ��������һ�������ڵ�ǰ��һ������������ǰ��೤����Ϣ
//																						//ָ��normal����
//	glEnableVertexAttribArray(1);
//	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));		//ÿ8�������е��м������Ƿ���������
//																										//ָ��������������
//	if (BisTexture)
//	{
//		glEnableVertexAttribArray(2);
//		glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
//	}
//
//	glBindVertexArray(0);
//
//
//
//}
//
//void Object::TextureUseInfo(bool useTex, bool useAlbedo, bool useMetallic, bool useRoughness, bool useAo, bool useNormal, bool useShadowTex)
//{
//	BuseTexture = useTex;
//	BAlbedo = useAlbedo;
//	BMetallic = useMetallic;
//	BRoughness = useRoughness;
//	BAo = useAo;
//	BNormal = useNormal;
//	BShadowTex = useShadowTex;
//}
//
//void Object::LightUseInfo(bool receive)
//{
//	BReceiveLight = receive;
//}
//
//void Object::InitTexture(GLuint & TexID, string TexPath)
//{
//	glGenTextures(1, &TexID);
//	glBindTexture(GL_TEXTURE_2D, TexID);		//��ʱ�󶨵���Ĭ������Ԫ0������֮��Ĵ����л�ָ���󶨵������ĸ���Ԫ
//	//ָ����ͼ����
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//	//�ļ���ȡ
//	int width, height;
//	unsigned char* pResult = SOIL_load_image(TexPath.c_str(), &width, &height, 0, SOIL_LOAD_RGB);
//	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, pResult);
//	//����һ��mipmap
//	glGenerateMipmap(GL_TEXTURE_2D);
//	//����󶨲��ͷ�
//	glBindTexture(GL_TEXTURE_2D, 0);
//	SOIL_free_image_data(pResult);
//
//}
//
//void Object::UseATexture(GLuint & TexID, GLuint & ID)
//{
//	TexID = ID;
//}
//
//void Object::InitMaterial(vec4 A, vec4 D, vec4 S, float SH)
//{
//	Material.ambient = A;
//	Material.diffuse = D;
//	Material.specular = S;
//	Material.shiness = SH;
//}
//
//void Object::ObjNormalize()
//{
//	float X, Y, Z;
//	X = max(fabs(aabb.maxPos.x), fabs(aabb.minPos.x));
//	Y = max(fabs(aabb.maxPos.y), fabs(aabb.minPos.y));
//	Z = max(fabs(aabb.maxPos.x), fabs(aabb.minPos.z));
//
//	float result = 1.0f / max(X, max(Y, Z));
//
//	for (int i = 0; i < pointsData.size(); i++)
//	{
//		pointsData[i].vertex *= result;
//		//vertices[i] *= result;
//	}
//}
