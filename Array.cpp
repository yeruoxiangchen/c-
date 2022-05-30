#include<iostream>
#include<vector>
using namespace std;


template<class T>
class Array
{
private:
	int msize; T val;
	T* ar;
public:
	Array() :msize(0), val(0) {}
	Array(int _size) ;
	Array(int _szie, T inival) ;
	Array(const Array& arr0);
	T& operator[](int i);
	int size()const;
	void resize(int size);
	void push_back(T a);
	void clear();
	void insert(int n, T x);
	void del(int n);
	~Array();
};

template<class T>
Array<T>::Array(int _size) :msize(_size), val(0)
{
	ar = new T[msize];
	for (int i = 0; i < msize; i++)
	{
		ar[i] = val;
	}
}


template<class T>
Array<T>::Array(int _szie, T inival) :msize(_szie), val(inival)
{
	ar = new T[msize];
	for (int i = 0; i < msize; i++)
	{
		ar[i] = val;
	}
}

template<class T>
Array<T>::Array(const Array& arr0) :msize(arr0.msize), val(arr0.val)
{
	ar = new T[msize];
	for (int i = 0; i < msize; i++)
	{
		ar[i] = arr0.ar[i];
	}
}

template<class T>
T& Array<T>::operator[](int i)
{
	return ar[i];
}
template<class T>
int Array<T>::size()const
{
	return msize;
}


template<class T>
void Array<T>::resize(int size)
{
	msize = size; val = 0;
	delete[]ar;
	ar = new T[msize];
	for (int i = 0; i < msize; i++)
	{
		ar[i] = val;
	}
}


template<class T>
void Array<T>::push_back(T a)
{
	T* ar0 = new T[msize];
	for (int i = 0; i < msize + 1; i++)
	{
		ar0[i] = ar[i];
	}
	msize++;
	delete[]ar;
	ar = new T[msize];
	for (int i = 0; i < msize - 1; i++)
	{
		ar[i] = ar0[i];
	}
	ar[msize - 1] = a;
}


template<class T>
void Array<T>::clear()
{
	msize = 0;
	delete[]ar;
	ar = nullptr;
}


template<class T>
void Array<T>::insert(int n, T x)
{
	T* ar0 = new T[msize];
	for (int i = 0; i < n; i++)
	{
		ar0[i] = ar[i];
	}
	ar0[n] = x;
	for (int i = n + 1; i < msize + 1; i++)ar0[i] = ar[i - 1];
	msize++;
	delete[]ar;
	ar = new T[msize];
	for (int i = 0; i < msize; i++)
	{
		ar[i] = ar0[i];
	}
}


template<class T>
void Array<T>::del(int n)
{

	T* ar0 = new T[msize];
	for (int i = 0; i < n; i++)
	{
		ar0[i] = ar[i];
	}
	for (int i = n; i < msize - 1; i++)ar0[i] = ar[i + 1];
	delete[]ar;
	msize--;
	ar = new T[msize];
	for (int i = 0; i < msize; i++)
	{
		ar[i] = ar0[i];
	}
	delete[]ar0;
}


template<class T>
Array<T>::~Array()
{
	if (ar != nullptr)
		delete[]ar;
}



int main()
{
	Array<int> arr(5,1);
	cout << "test 1 -- 赋值" << endl;
	for (int i = 0; i < 5; i++) 
	{
		arr[i] = i;
		cout << arr[i] << endl;
	}
	cout << "test 2 -- 改变大小" << endl;
	arr.resize(6);
	for (int i = 0; i < 6; i++)
	{
		arr[i] = i;
		cout << arr[i] << endl;
	}
	cout << "test t3 -- 尾插" << endl;
	arr.push_back(7);
	for (int i = 0; i < 7; i++)
	{
		cout << arr[i] << endl;
	}
	cout << "test 4 -- 插入" << endl;
	arr.insert(2, 9);
	for (int i = 0; i < 8; i++)
	{
		cout << arr[i] << endl;
	}
	cout << "test 5 -- 删除" << endl;
	arr.del(3);
	for (int i = 0; i < 7; i++)
	{
		cout << arr[i] << endl;
	}
	cout << "test 6 -- 清除" << endl;
	arr.clear();
	cout << arr.size() << endl;
	cout << "test 7 " << endl;
	arr.resize(3);
	for (int i = 0; i < 3; i++)
	{
		arr[i] = i;
		cout << arr[i] << endl;
	}

	return  0;
}