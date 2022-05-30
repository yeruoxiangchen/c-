#include<iostream>
using namespace std;


class Base
{
public:
	int pb;
	void pbfunc()
	{
		cout << "����public" << endl;
	}
private:
	int pv;
	void pvfunc()
	{
		cout << "����private" << endl;
	}
protected:
	int pd;
	void pdfunc()
	{
		cout << "����protected" << endl;
	}
};


//���ڲ���ͬ�̳����͵ķ��ʣ����б���˽��
class A :public Base
{
public:
	int A0;
	void test()
	{
		int a;
		a = pb;//��ȷ,���г�Ա
		pbfunc();
		//a = pv;//error,˽�в��ɷ���
		//pvfunc();
		a = pd;//��ȷ,������Ա
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
		b = pb;//��ȷ,˽�г�Ա
		pbfunc();
		//b = pv;//error,˽�в��ɷ���
		//pvfunc();
		b = pd;//��ȷ,˽�г�Ա
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
		c = pb;//��ȷ,˽�г�Ա
		pbfunc();
		//c = pv;//error,˽�в��ɷ���
		//pvfunc();
		c = pd;//��ȷ,˽�г�Ա
		pdfunc();
	}
};


void test()
{
	//���ⲿ��ͬ���ͼ̳еķ��ʣ�
	//A��(���м̳ж����������͵ķ��ʣ�
	A a;
	a.pb;//���������������
	a.pbfunc();
	//  a.pd;a.pv;   //������˽�������ɷ��ʣ���Ϊһ�������оͲ��ɷ��ʣ�һ�������б�Ϊ����
	B b;
	//b.pb;b.pv;b.pd    //��˽����˽����Ϊ˽��,˽˽�����в��ɷ���
	C c;
	//c.pb;c.pv;c.pd;    //��������������Ϊ������˽�����ɷ���
	//����˽�б��������ⲻ�ɷ��ʣ���������ɼ̳б���
	//���ڹ��У��������ⶼ�ɷ���
	
}



//����������Ĺ���˳��


class Far
{
public:
	Far()
	{
		cout << "����Ĺ���" << endl;
	}
	~Far()
	{
		cout << "���������" << endl;
	}
};

class Son:public Far
{
public:
	Son()
	{
		cout << "������Ĺ���" << endl;
	}
	~Son()
	{
		cout << "������Ĺ���" << endl;
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