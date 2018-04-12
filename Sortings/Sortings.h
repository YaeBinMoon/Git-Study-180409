#ifndef SORTING_H
#define SORTING_H

#include <stdio.h>
#include <stdlib.h>

#define SWAP(x,y,t) ((t)=(x),(x)=(y),(y)=(t))

/* 버블 정렬을 이용한 오름차순 정렬 */
void BubbleSort(int* data, int len);
void InsertionSort(int *data, int len);
int partition(int* data, int left, int right);
void QuickSort(int* data, int left, int right);
void SelectionSort(int* data, int len);
void MergeSort(int* data, int left, int right);
void Merge(int* data, int left, int mid, int right);

#endif
