#include<iostream>
using namespace std;


class Point
{
private:
	int x, y;
public:
	Point() {}
	Point(int _x, int _y) :x(_x), y(_y) {}
	Point(const Point& p) :x(p.x), y(p.y) {}
	void reset(int x, int y);
	void show();
};


class Carbody
{
private:
	int  length, width;
	Point leftdown;
public:
	Carbody() {}
	Carbody(int _length, int _width,const Point& _leftdown) :length(_length), width(_width),leftdown(_leftdown) {}
	Carbody(const Carbody& c) :length(c.length), width(c.width), leftdown(c.leftdown) {}
	void reset(int length, int width, const Point& leftdown);
	void show();
};

class Carcircle
{
private:
	int r;
	Point center;
public:
	Carcircle() {}
	Carcircle(int _r, const Point& _center) :r(_r), center(_center) {}
	Carcircle(const Carcircle&c) :r(c.r), center(c.center) {}
	void reset(int r, const Point& center);
	void show();
};

class Car 
{
private:
	Carbody body;
	Carcircle circle1;
	Carcircle circle2;
public:
	Car (){}
	Car(const Carbody&_cbody,const Carcircle &_circle1, const Carcircle& _circle2):body(_cbody),circle1(_circle1),circle2(_circle2){}
	Car(const Car& car):body(car.body),circle1(car.circle1),circle2(car.circle2){}
	void reset(const Carbody& _body, const Carcircle& _circle1, const Carcircle& _circle2);
	void show();
};

void Car::reset(const Carbody& _body, const Carcircle &_circle1, const Carcircle& _circle2)
{
	body = _body;
	circle1 = _circle1;
	circle2 = _circle2;
}
void Car::show()
{
	body.show();
	circle1.show();
	circle2.show();
}
void Point::reset(int x,int y)
{
	this->x = x;
	this->y = y;
}
void Point::show()
{
	cout << " x=" << x << " y=" << y << endl;
}
void Carbody::reset(int length, int width, const Point& leftdown)
{
	this->length = length;
	this->width = width;
	this->leftdown = leftdown;
}
void Carbody::show()
{
	cout << " length=" << length << " width=" << width << " ";
	leftdown.show();
}
void Carcircle::reset(int r, const Point& center)
{
	this->r = r;
	this->center = center;
}

void Carcircle::show()
{
	cout << " r=";
	center.show();
}

