#include<iostream>
using namespace std;

int rectCount = 0;

class Rectangle
{
private:
	int x1, x2, y1, y2;//×óÉÏ½Çx1y1¡¢ÓÒÏÂ½Ç×ø±êx2y2;
public:
	Rectangle();
	Rectangle(int x1, int y1, int x2, int y2);
	Rectangle(const Rectangle& rec);
	void reset(int x1, int y1, int x2, int y2);
	void overlap(Rectangle rec1, Rectangle rec2);
	void printrecsize();
	int size();
	bool ifsame(Rectangle rec);
	void _resize(int relength, int rewidth);
	void move(int vertical, int crosswise);
	~Rectangle();
};

Rectangle::Rectangle()
{
	rectCount++;
}

Rectangle::Rectangle(int x1, int y1, int x2, int y2)
{
	this->x1 = x1;
	this->y1 = y1;
	this->x2 = x2;
	this->y2 = y2;
	rectCount++;
}
Rectangle::Rectangle(const Rectangle& rec)
{
	this->x1 = rec.x1;
	this->x2 = rec.x2;
	this->y1 = rec.y1;
	this->y2 = rec.y2;
	rectCount++;
}
Rectangle::~Rectangle()
{
	rectCount--;
}
void Rectangle::reset(int x1, int y1, int x2, int y2)
{
	this->x1 = x1;
	this->y1 = y1;
	this->x2 = x2;
	this->y2 = y2;
}
void Rectangle::overlap(Rectangle rec1, Rectangle rec2)
{
	x1 = rec1.x1 > rec2.x1 ? rec1.x1 : rec2.x1;
	x2 = rec1.x2 < rec2.x2 ? rec1.x2 : rec2.x2;
	y1 = rec1.y1 < rec2.y1 ? rec1.y1 : rec2.y1;
	y2 = rec1.y2 > rec2.y2 ? rec1.y2 : rec2.y2;
}

void  Rectangle::printrecsize()
{
	cout << "length=" << x2 - x1 << " width=" << y1 - y2 << endl;
	cout << "x1=" << x1 << " y1=" << y1 << " x2=" << x2 << " y2=" << y2 << endl;
}

int  Rectangle::size()
{
	return (y1 - y2) * (x2 - x1);
}

bool Rectangle::ifsame(Rectangle rec)
{
	if (this->x1 != rec.x1 || this->x2 != rec.x2 || this->y1 != rec.y1 || this->y2 != rec.y2)return false;
	return true;
}
void  Rectangle::_resize(int relength, int rewidth)
{
	x2 = x1 + relength;
	y2 = y1 - rewidth;
}

void Rectangle::move(int vertical, int crosswise)
{
	x1 += crosswise;
	x2 += crosswise;
	y1 += vertical;
	y2 += vertical;
}


int main()
{
	Rectangle rec1(10, 10, 15, 5);
	Rectangle rec2(5, 15, 12, 7);
	if (!rec2.ifsame(rec1))cout << 1 << endl;
	Rectangle rec3;
	rec3.overlap(rec1, rec2);
	rec3.printrecsize();
	cout << rectCount;
	//rec1.printrecsize();
	return 0;
}