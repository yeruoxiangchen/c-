#include<iostream>
using namespace std;



class Base0
{
public:
	string base0;
	Base0():base0("A")
	{
		cout << "Base0构造函数1" << endl;
	}
	Base0(string a):base0(a)
	{
		cout << "Base0构造函数2" << endl;
	}
	~Base0()
	{
		cout << "Base析构" << endl;
	}
};

class Derived0 :public Base0
{
public:
	int derived0;
	Base0 b0;
	Derived0() :derived0(0), b0("B")
	{
		cout << "derived0构造函数" << endl;
	}
	~Derived0()
	{
		cout << "derived0析构函数" << endl;
	}
};



class Base1
{
public:
	string b0;
	Base1(string a) :b0(a)
	{
		cout << "Base1构造函数1" << "  " << b0 << endl;
	}
	~Base1()
	{
		cout << "Base1析构函数" <<  endl;
	}
};

class Derived1 
{
public:
	string d0;
	Base1 b11;
	Base1 b12;
	Derived1() :d0("d0"), b12("B"),b11("A")
	{
		cout << "Derived1构造函数" << " " << d0 << endl;
	}
	~Derived1()
	{
		cout << "Derived1析构函数" << endl;
	}
};


class Base2:public Base0
{
public:
	Base2() 
	{
		cout << "Base2构造函数" << endl;
	}

};

class Base3:public Base0
{
public:
	Base3() 
	{
		cout << "Base3构造函数" << endl;
	}
};

class Derived2 :
	public Base2,
	public Base3
{
public:
	Derived2() 
	{
		cout << "Derived2构造函数" << endl;
	}
};


class Base
{
public:
	int a;
};
class Basee1 :
	public Base
{
};
class Basee2 :
	public Base
{

};

class D :
	public Basee1,
	public Basee2
{

};


class D1
{
public:
	D1()
	{
		cout << "D1" << endl;
	}
};

class D2
{
public:
	D2()
	{
		cout << "D2" << endl;
	}
};

class D0 :
	public D1,
	virtual public D2
{
	
};




void test()
{
	//Derived2 d;
	/*D d;
	d.Basee1::a = 0;
	d.Basee2::a = 0;
	d.a = 0;*/

	D0 d0;

}


int main()
{
	test();
	return 0;
}