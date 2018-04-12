#include "Sortings.h"

/* 버블 정렬을 이용한 오름차순 정렬 */
void BubbleSort(int* data, int len) //len : data의 수
{
	int i, j, temp;
	for (i = 0; i < len - 1; i++)
	{
		for (j = 0; j < len - i - 1; j++)
		{
			if (data[j] > data[j + 1])
			{
				temp = data[j + 1];
				data[j + 1] = data[j];
				data[j] = temp;
			}
		}
	}
}

void InsertionSort(int *data, int len)
{
	int i, j, temp;
	for (i = 1; i < len; i++)
	{
		if (data[i] >= data[i - 1])continue;
		temp = data[i];
		for (j = i - 1; j >= 0 && data[j] >= temp; j--)
			data[j + 1] = data[j];
		data[j + 1] = temp;
	}
}

void QuickSort(int* data, int left, int right)
{
	if (right > left)
	{
		int new_pivot = partition(data, left, right);
		QuickSort(data, left, new_pivot - 1);
		QuickSort(data, new_pivot + 1, right);
	}
}

int partition(int* data, int left, int right)
{
	int pivot; // 기준점(첫 요소)의 데이터
	int temp; // 정렬을 위한 데이터 교환 시 temp 변수
	int low, high; // 정렬 여부를 판별하기 위해 사용할 인덱스
	pivot = data[left];
	low = left;
	high = right + 1;

	do
	{
		do
		{
			low++;
		} while (low <= right && data[low] < pivot);

		do
		{
			high--;
		} while (left <= high && data[high] > pivot);
		if (low < high)
			SWAP(data[low], data[high], temp);
	} while (low < high);
	SWAP(data[left], data[high], temp);

	return high;
}

void SelectionSort(int* data, int len)
{
	int i, j, temp, min, min_idx;
	for(i=0;i<len-1;i++)
	{
		min=data[i];
		min_idx=i;
		for(j=i+1;j<len;j++)
		{
			if(min>data[j])
			{
				min=data[j];
				min_idx=j;
			}
		}
		if(min<data[i])SWAP(data[i],data[min_idx],temp);
	}
}

void MergeSort(int* data, int left, int right)
{
	if(left<right)
	{
		int mid = (left+right)/2;
		MergeSort(data, left, mid);
		MergeSort(data, mid + 1, right);
		Merge(data, left, mid, right);
	}
}

void Merge(int* data, int left, int mid, int right)
{
	int start1, start2, i;
	start1 = left;
	start2 = mid + 1;
	int* sorted = (int*)malloc((right - left + 1)*sizeof(int));
	int index = 0;
	while(start1<=mid && start2<=right)
	{
		if(data[start1]<=data[start2]) sorted[index++] = data[start1++];
		else  sorted[index++] = data[start2++];
	}
	if(start1<=mid)
	{
		for(;start1<=mid;start1++, index++) sorted[index] = data[start1];
	}
	if(start2<=right)
	{
		for(;start2<=right;start2++, index++) sorted[index] = data[start2];
	}
	for(i=left;i<=right;i++)
	{
		data[i] = sorted[i - left];
	}
	free(sorted);
}
