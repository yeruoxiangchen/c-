#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<io.h>
#include <fstream>
#include <cstdlib>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<windows.h>
#include<atlstr.h>
using namespace std;
vector<string> selfDir(string s);
void syncFolders(string &src, string &dst);