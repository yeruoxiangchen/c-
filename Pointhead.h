#pragma once
#include<iostream>
using namespace std;


class Point
{
private:
	int* P;
public:
	Point():P(NULL){}
	//Point(int x):P(&x){}
	Point(const Point& p):P(p.P){}
	Point(int* a) :P(a) {}
	Point operator =(int *x)const;
	void operator =(int *x);
	Point operator++();
	Point operator++(int);
	int operator*()const;
	int operator*();
	int change(int a);
	friend ostream& operator<<(ostream& os, const Point& p);
	friend Point& operator+(int n, Point p);
};
