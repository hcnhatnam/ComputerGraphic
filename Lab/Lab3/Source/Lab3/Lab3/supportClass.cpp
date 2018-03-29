#include "stdafx.h"
#include "supportClass.h"
#include <math.h>

Vector3 Vector3::cross(Vector3 b)//Tích có hướng của 2 vecto
{
	Vector3 c(y*b.z-z*b.y, z*b.x-x*b.z, x*b.y-y*b.x);
	return c;
}
float Vector3::dot(Vector3 b)//Nhân 2 vecto
{
	return x*b.x + y*b.y + z*b.z;
}
void Vector3::normalize()//Vecto đơn vị
{
	float temp = sqrt(x*x + y*y + z*z);
	x = x/temp;
	y = y/temp;
	z = z/temp;
}