#pragma once
#include<iostream>
using namespace std;

class Vect
{
private:
	int x, y, z;
public:
	Vect() {}
	Vect(int _x, int _y, int _z) :x(_x), y(_y), z(_z) {}
	Vect(const Vect& v) :x(v.x), y(v.y), z(v.z) {}
	float getsize();

	friend Vect operator +(const Vect& v1, const Vect& v2);
	friend Vect operator -(const Vect& v1, const Vect& v2);
	friend Vect operator *(int a , const Vect& v);
	friend int operator *(const Vect& v1, const Vect& v2);
	friend ostream & operator<<(ostream& os, const Vect& t);
	friend istream& operator>>(istream& os, Vect& t);
};

int operator *(const Vect& v1, const Vect& v2);
Vect operator *( int a,const Vect& v);
ostream & operator<<(ostream& os, const Vect& t);
istream& operator>>(istream& os,Vect& t);
Vect operator +(const Vect& v1, const Vect& v2);
Vect operator -(const Vect& v1, const Vect& v2);

