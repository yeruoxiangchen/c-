#include"Vect.h"

float Vect::getsize()
{
	return sqrt(x * x + y * y + z * z);
}

int operator *(const Vect& v1, const Vect& v2)
{
	return v1.x * v2.x + v1.y * v2.y + v2.z * v2.z;
}
Vect operator *( int a,const Vect& v)
{
	Vect v0(a * v.x, a * v.y, a * v.z);
	return v0;
}
ostream & operator<<(ostream& os, const Vect& v)
{
	cout << v.x << " " << v.y << " " << v.z << " ";
	return os;
}
istream& operator>>(istream& is,Vect& v)
{
	cin >> v.x >> v.y >> v.z;
	return is;
}
Vect operator +(const Vect& v1, const Vect& v2)
{
	Vect v0(v1.x + v2.x, v1.y - v2.y, v1.z + v2.z);
	return v0;
}
Vect operator -(const Vect& v1, const Vect& v2)
{
	Vect v0(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z);
	return v0;
}
