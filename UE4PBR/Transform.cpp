#include "Transform.h"

void Transform::SetMatrix()
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
	worldViewProj = Camera::getMainCamera()->pro * Camera::getMainCamera()->view * world;
}

void Transform::MoveByDir(vec3 dir, float distant)
{
	position += distant * dir;
	SetMatrix();
}

void Transform::MoveByVector(vec3 displacement)
{
	position += displacement;
	SetMatrix();
}

void Transform::SetPosition(vec3 _position)
{
	position = _position;
	SetMatrix();
}

void Transform::RotateByAxis(vec3 axis, float angle)
{
	rotation += angle * axis;
	SetMatrix();
}

void Transform::SetRotation(vec3 _rotation)
{
	rotation = _rotation;
	SetMatrix();
}

void Transform::SetScaler(vec3 _scaler)
{
	scaler = _scaler;
	SetMatrix();
}
