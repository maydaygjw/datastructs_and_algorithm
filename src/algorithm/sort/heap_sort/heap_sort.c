#include <stdio.h>

#define LENGTH(array) (sizeof(array) / sizeof(array[0]))



void swap(int a[], int i, int j)
{
	int tmp = a[i];
	a[i] = a[j];
	a[j] = tmp;
}

void print(int a[], int len)
{
	int i;
	for(i=0; i<len; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

void rotate(int a[], int index, int len)
{
	int pivot_idx = 0;
	int left_idx = 2 * index;
	int right_idx = 2* index + 1;

	if(right_idx < len)
	{
		pivot_idx = a[left_idx] < a[right_idx]? right_idx: left_idx;
	} else if(left_idx < len)
	{
		pivot_idx = left_idx;
	}

	if(pivot_idx > 0 && a[index] < a[pivot_idx])
	{
		swap(a, index, pivot_idx);
		rotate(a, pivot_idx, len);
	}
}

void constrct_max_heap(int a[], int len)
{
	int i;
	for(i=len/2; i>0; i--)
	{
		rotate(a, i, len);

		//print(a, len);

	}
}

void sort(int a[], int len)
{
	int i;
	for(i=1; i<len; i++)
	{
		swap(a, 1, len-i);
		rotate(a, 1, len-i);
	}
}

int main()
{
	int a[] = {0, 3, 4, 9, 8, 2, 1, 6, 5};

	int len = LENGTH(a);

	printf("Before construct:\n");
	print(a, len);
	constrct_max_heap(a, len);
	printf("After construct to MAX HEAP:\n");
	print(a, len);

	sort(a, len);

	printf("After sort:\n");
	print(a, len);

	return 0;
}
