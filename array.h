#pragma once
#include<iostream>
#include<stdio.h>
#include<malloc.h>
using namespace std;
int* arrset(int arr[], int targe,int size);
int* arrattach(int arr1[], int arr2[],int size1,int size2);
pair<int, int> find_max_and_min(int arr[],int size);
void findgreater(int arr[],int newarr[],int targe,int len,int &size);