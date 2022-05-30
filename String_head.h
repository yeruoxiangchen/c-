#pragma once
#include<iostream>
#include <algorithm>
using namespace std;

#define MAXN 100000

class String
{
private:
	char* s;
	int size;
	int capacity;
public:
	String();
	String(const char* s0);
	String(const String& s0);
	char& operator[](int i);
	char& operator[](int i) const;
	int getsize()const;
	void insert(int i, char c);
	void erase(int i);
	String& operator+(String& s1);
	//String& operator=(String& S);
	friend ostream& operator<<(ostream& os, const String& S);
	friend bool operator==(const String& S1, const String& S2);
};
struct Stringtxt
{
	int count;
	String str;
};
extern Stringtxt strtxt[MAXN];
int _find(String S, int n);
bool mycomp(Stringtxt s1, Stringtxt s2);

