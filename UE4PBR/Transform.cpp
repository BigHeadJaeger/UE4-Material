#include "Transform.h"

void Transform::SetMatrix(mat4 camView, mat4 camProj)
{
	world = translate(mat4(1.0), position);
	world = scale(world, scaler);
	if (rotation.x != 0)
		world = rotate(world, rotation.x, vec3(1.0, 0.0, 0.0));
	if (rotation.y != 0)
		world = rotate(world, rotation.y, vec3(0.0, 1.0, 0.0));
	if (rotation.z != 0)
		world = rotate(world, rotation.z, vec3(0.0, 0.0, 1.0));
	worldInvTranspose = transpose(inverse(world));
	worldViewProj = camProj * camView * world;
}

void Transform::MoveByDir(vec3 dir, float distant)
{

}

void Transform::MoveByVector(vec3 displacement)
{

}

void Transform::RotateByAxis(vec3 axis, float angle)
{
}
