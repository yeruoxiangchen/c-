#include"Pointhead.h"

void Point::operator=(int *x)
{
	this->P = x;
}
Point Point::operator=(int *x)const
{
	Point p; p = x;
	return p;
}
Point Point::operator++()
{
	P++;
	return *this;
}
Point Point::operator++(int)
{
	Point p = *this;
	P++;
	return p;
}
int Point::operator*()
{
	int a = *P;
	return a;
}
int Point::operator*()const
{
	int a = *P;
	return a;
}
int Point:: change(int a)
{
	*(this->P)+=a;
	return *(this->P);
}
ostream& operator<<(ostream& os, const Point& p)
{
	cout << p.P;
	return os;
}
Point& operator+(int n, Point p)
{
	p.P += n;
	return p;
}
