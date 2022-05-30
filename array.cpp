#include"array.h"
int* arrset(int arr[], int targe,int size)
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = targe;
	}
	return arr;
}
int* arrattach(int arr1[], int arr2[], int size1, int size2)
{
	
	int *arrtarge = new int[size1 + size2];
	for (int i = 0; i < size1; i++)arrtarge[i] = arr1[i];
	for (int i = 0; i < size2; i++)arrtarge[i+size1] = arr2[i];
	return arrtarge;
}
pair<int, int>find_max_and_min(int arr[], int size)
{
	pair<int, int>ans(arr[0],arr[0]);
	for (int i = 1; i < size; i++)
	{
		ans.first = ans.first > arr[i] ? ans.first : arr[i];
		ans.second = ans.second < arr[i] ? ans.second : arr[i];
	}
	return ans;
}
void findgreater(int arr[],int newarr[],int targe,int len,int&size)
{
	for (int i = 0,j = 0; i < len; i++)
	{ 
		if (arr[i] > targe)
		{
			newarr[j] = arr[i];
			size++; j++;
		}
	}
}
