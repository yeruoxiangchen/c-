#include"head.h"

double Vect::getsize()const
{
	return sqrt(x * x + y * y + z * z);
}

double operator *(const Vect& v1, const Vect& v2)
{
	return v1.x * v2.x + v1.y * v2.y + v2.z * v2.z;
}
Vect operator *(int a, const Vect& v)
{
	Vect v0(a * v.x, a * v.y, a * v.z);
	return v0;
}
ostream& operator<<(ostream& os, const Vect& v)
{
	cout << "(" << v.x << " " << v.y << " " << v.z << ")" << " ";
	return os;
}
ostream& operator<<(ostream& os, const Line& l)
{
	cout << "点：" << l.dot << "  向量" << l.dic << " ";
	return os;
}
istream& operator>>(istream& is, Vect& v)
{
	cin >> v.x >> v.y >> v.z;
	return is;
}
istream& operator>>(istream& is, Line& v)
{
	cout << "先输入点坐标，再输入方向向量" << endl;
	cin >> v.dot >> v.dic;
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

bool operator ==(const Vect& v1, const Vect& v2)
{
	return v1.x == v2.x && v1.y == v2.y && v1.z == v2.z;
}
Vect dotmul(const Vect& v1, const Vect& v2)
{
	Vect ansv;
	ansv.x = v1.y * v2.z - v1.z * v2.y;
	ansv.y = -(v1.x * v2.z - v1.z * v2.x);
	ansv.z = v1.x * v2.y - v1.y * v2.x;
	return ansv;
}
double Vect::Proj(const Vect& v)const
{
	return ((*this) * v) / (v.getsize());
}


double dis(const Line& l1, const Line& l2)
{
	Vect L = l1.dot - l2.dot;
	Vect Nvec = dotmul(l1.dic, l2.dic);
	return abs(L.Proj(Nvec));
}

void pos(const Line& l1, const Line& l2)
{
	cout << "两直线";
	if (dis(l1, l2) == 0)
	{
		if (l1.dic == l2.dic)
		{
			cout << "重合" << endl;
			return;
		}
		else
		{
			cout << "共面不平行" << endl;
			return;
		}
	}
	else
	{
		if (l1.dic == l2.dic)
		{
			cout << "平行" << endl;
			return;
		}
		else
		{
			cout << "异面" << endl;
			return;
		}
	}
}