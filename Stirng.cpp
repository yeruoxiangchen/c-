#include"String_head.h"

String::String()
{
	size = 0; capacity = 0;
	s = new char[capacity];
}
String::String(const char* s0)
{
	size = strlen(s0);
	capacity = size + 10;
	s = new char[capacity];
	for (int i = 0; i < size; i++) s[i] = s0[i];
}
String::String(const String& s0)
{
	size = s0.size;
	capacity = s0.capacity;
	s = new char[capacity];
	for (int i = 0; i < size; i++)s[i] = s0.s[i];
}

char&String:: operator[](int i)
{
	return s[i];
}
char& String:: operator[](int i)const
{
	return s[i];
}

int String::getsize()const
{
	return size;
}

void String:: insert(int i, char c)
{
	char* tmp = new char[size + 1];
	for (int j = 0; j < i; j++)tmp[j] = s[j];
	tmp[i] = c;
	for (int j = i + 1; j < size + 1; j++)tmp[j] = s[j - 1];
	size++; capacity++;
	s = tmp;
	delete[]tmp;
}
String&String:: operator+(String& s1)
{
	if (s1.size + size > capacity)
	{
		char* tmp = new char[size];
		for (int j = 0; j < size; j++)tmp[j] = s[j];
		int newsize = size + s1.size;
		for (int j = size; j <= newsize; j++)tmp[j] = s1[j - size];
		capacity = newsize + 10;
		s = tmp;
		size = newsize;
	}
	else
	{
		for (int i = size; i < s1.size + size; i++)
		{
			s[i] = s1[i - size];
		}
	}
	return *this;
}

//String& String:: operator=(String& S)
//{
//	size = S.size;
//	capacity = S.capacity;
//	s = new char[capacity];
//	for (int i = 0; i < size; i++)s[i] = S[i];
//	return *this;
//}


void String::erase(int i)
{
	char* tmp = new char[size - 1];
	for (int j = 0; j < i; j++)tmp[j] = s[j];
	for (int j = i; j < size - 1; j++)tmp[j] = s[j + 1];
	size--; capacity--;
	s = new char [capacity];
	for (int i = 0; i < size; i++)s[i] = tmp[i];
	delete[]tmp;
}

ostream& operator<<(ostream& os, const String& S)
{
	for (int i = 0; i < S.size; i++)
	{
		cout << S[i];
	}
	return os;
}

bool operator==(const String& S1, const String& S2)
{
	if (S1.getsize() == 0 || S2.getsize() == 0)return false;
	else if (S1.size != S2.size || S1.capacity != S2.capacity)return false;
	else
	{
		for (int i = 0; i < S1.size; i++)
		{
			if (S1[i] != S2[i])return false;
		}
	}
	return true;
}




Stringtxt strtxt[MAXN];

int _find(String S, int n)
{
	for (int i = 0; i < n; i++)
	{
		if (S == strtxt[i].str)return i;
	}
	return -1;
}
bool mycomp(Stringtxt s1, Stringtxt s2)
{
	return s1.count > s2.count;
}