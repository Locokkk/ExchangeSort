#pragma once
#include<stdio.h>
#include<stdlib.h>

void swap(int *t1, int *t2)
{
	int t3 = *t1;
	*t1 = *t2;
	*t2 = t3;
}


//冒泡排序
void BubbleSort(int array[], int length)
{
	for (int end = length - 1;end > 0;--end)
	{
		for (int i = 0;i < end;++i)
		{
			if (array[i] > array[i + 1])
			{
				swap(&array[i], &array[i + 1]);
			}
		}
	}
}




//快速排序
//1.左右指针法
int PartSort1(int array[], int left, int right)
{
	int key = array[right];
	int key_index = right;
	while (left < right)
	{
		while (left < right&&array[left] <= key)
		{
			++left;
		}
		while (left<right&&array[right]>=key)
		{
			--right;
		}
		if (left < right)
		{
			swap(&array[left], &array[right]);
			++left;
			--right;
		}
	}
	swap(&array[key_index], &array[left]);
	return left;
}

void QuickSort(int a[], int left,int right)
{
	if (left >= right)
		return;
	int key_index = PartSort1(a, left, right);
	QuickSort(a, left, key_index - 1);
	QuickSort(a, key_index+1, right);
}




//2.挖坑法
int PartSort2(int array[], int left, int right)
{
	int key = array[right];
	while (left < right)
	{
		while (left < right&&array[left] <= key)
		{
			++left;
		}
		array[right] = array[left];
		while (left<right&&array[right]>=key)
		{
			--right;
		}
		array[left] = array[right];
	}
	array[left] = key;//left和right相遇时：要么left就是坑，要么left走到了坑的位置
}





//3.前后指针法
int PartSort3(int array[], int left, int right)
{
	int key = array[right];
	int prev = left - 1;
	int cur = left;
	while (cur < right)
	{
		if (array[cur] < key&&++prev != cur)
		{
			swap(&array[prev], &array[cur]);
			++cur;
		}
		++cur;
	}
	++prev;
	swap(&array[right], &array[prev]);
	return prev;
}

void QuickSort(int a[], int left, int right)
{
	if (left >= right)
		return;
	int key_index=PartSort2(a, left, right);
	QuickSort(a, left, key_index - 1);
	QuickSort(a, key_index+1, right);
}