#include <string.h>
#include "Sortings.h"

int for_compare(const void* elem1, const void* elem2)
{
	int* e1 = (int*)elem1;
	int* e2 = (int*)elem2;

	if(*e1>*e2) return 1;
	else if(*e1<*e2) return -1;
	else return 0;
}

int main(void)
{
	int Dataset[] = { 6,4,2,3,1,5 };
	int i;
	int len = sizeof(Dataset) / sizeof(int);

	MergeSort(Dataset, 0, len - 1);
	printf("> Sort\n");
	for (i = 0; i < len; i++)
	{
		printf("%d ", Dataset[i]);
	}
	printf("\n");

	int Dataset2[] = { 6,4,2,3,1,5 };
	qsort((void*)Dataset2, len, sizeof(int), for_compare);

	for (i = 0; i < len; i++)
	{
		printf("%d ", Dataset[i]);
	}
	printf("\n");

	return 0;
}
