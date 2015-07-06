#include <stdio.h>

#define LENGTH(array) ( (sizeof(array)) / (sizeof(array[0])) )

void print_array(int array[], int len);
void quick_sort(int array[], int begin, int end);

int main()
{
	int array[] = {3, 7, 2, 4, 1, 6};
	int ilen = LENGTH(array);
	
	printf("Begin sort:\n");
  	print_array(array, ilen);
	
	quick_sort(array, 0, ilen-1);
	
	printf("After sort: \n");
	print_array(array, ilen);

}

void quick_sort(int array[], int begin, int end)
{
	if(begin < end)
	{
		

		int i,j,x;
		i = begin;
		j = end;
		x = array[begin];
			
		while(i < j)
		{
			while(i < j && array[j] > x)
				j--;
			if(i < j)
				array[i++] = array[j];
			while(i < j && array[i] < x) 
				i++;
			if(i < j)
				array[j--] = array[i];
			
		}
		array[i] = x;

		quick_sort(array, begin, i-1);
		quick_sort(array, i+1, end);
	}
	
	
}


void print_array(int array[], int len)
{
	int i;
	for(i=0; i<len; i++)
	{	
		printf("%d ", array[i]);
	}
	printf("\n");
}
