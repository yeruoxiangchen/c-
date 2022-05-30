#pragma once
#include<iostream>
using namespace std;

class Vect
{
private:
	float x, y, z;
public:
	Vect() {}
	Vect(double _x, double _y, double _z) :x(_x), y(_y), z(_z) {}
	Vect(const Vect& v) :x(v.x), y(v.y), z(v.z) {}
	double getsize()const;

	friend Vect operator +(const Vect& v1, const Vect& v2);
	friend Vect operator -(const Vect& v1, const Vect& v2);
	friend Vect operator *(int a, const Vect& v);
	friend double operator *(const Vect& v1, const Vect& v2);
	friend ostream& operator<<(ostream& os, const Vect& t);
	friend istream& operator>>(istream& os, Vect& t);
	friend bool operator ==(const Vect& v1, const Vect& v2);
	friend Vect dotmul(const Vect& v1, const Vect& v2);
	double Proj(const Vect& v)const;
};

class Line
{
private:
	Vect dic; Vect dot;
public:
	Line(){}
	Line(Vect _dic,Vect _dot):dic(_dic),dot(_dot){}
	Line(const Line&l):dic(l.dic),dot(l.dot){}

	friend ostream& operator<<(ostream& os, const Line& t);
	friend istream& operator>>(istream& os, Line& t);
	friend double dis(const Line& l1, const Line& l2);
	friend void pos(const Line& l1, const Line& l2);
};

