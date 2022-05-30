#include<iostream>
using namespace std;


class Base
{
public:
	int pb;
	void pbfunc()
	{
		cout << "基类public" << endl;
	}
private:
	int pv;
	void pvfunc()
	{
		cout << "基类private" << endl;
	}
protected:
	int pd;
	void pdfunc()
	{
		cout << "基类protected" << endl;
	}
};


//类内部不同继承类型的访问，公有保护私有
class A :public Base
{
public:
	int A0;
	void test()
	{
		int a;
		a = pb;//正确,公有成员
		pbfunc();
		//a = pv;//error,私有不可访问
		//pvfunc();
		a = pd;//正确,保护成员
		pdfunc();

	}
};

class B :private Base
{
public:
	int B0;
	void test()
	{
		int b;
		b = pb;//正确,私有成员
		pbfunc();
		//b = pv;//error,私有不可访问
		//pvfunc();
		b = pd;//正确,私有成员
		pdfunc();
	}
};

class C :protected Base
{
public:
	int C0;
	void test()
	{
		int c;
		c = pb;//正确,私有成员
		pbfunc();
		//c = pv;//error,私有不可访问
		//pvfunc();
		c = pd;//正确,私有成员
		pdfunc();
	}
};


void test()
{
	//类外部不同类型继承的访问：
	//A：(公有继承对于三种类型的访问）
	A a;
	a.pb;//公公可在类外访问
	a.pbfunc();
	//  a.pd;a.pv;   //保公、私公都不可访问，因为一个在类中就不可访问，一个在类中变为保护
	B b;
	//b.pb;b.pv;b.pd    //公私、保私都变为私有,私私在类中不可访问
	C c;
	//c.pb;c.pv;c.pd;    //公保、保保都变为保护，私保不可访问
	//对于私有保护，类外不可访问，但派生类可继承保护
	//对于公有，类内类外都可访问
	
}



//基类派生类的构造顺序


class Far
{
public:
	Far()
	{
		cout << "基类的构造" << endl;
	}
	~Far()
	{
		cout << "基类的析构" << endl;
	}
};

class Son:public Far
{
public:
	Son()
	{
		cout << "派生类的构造" << endl;
	}
	~Son()
	{
		cout << "派生类的构造" << endl;
	}
};


void test2()
{
	Far f;
	Son s;

}

int main()
{
	test2();
	return 0;

}