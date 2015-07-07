#include <stdio.h>
#include <stdlib.h>

#define LENGTH(array) ((sizeof(array) / sizeof(array[0])))
#define LEN 30
static int m_heap[LEN];	//data
static int m_capacity = 30;		//index from 1..30
static int m_size = 0;


int get_index(int data);
void insert(int data);
void filter_up(int index);
int get_parent_index(int index);
void print();
void swap(int i, int j);
int get_max();
void rotate(int index);

int main()
{
	insert(3);
	insert(4);
	insert(5);
	insert(6);
	insert(7);
	insert(8);
	insert(9);
	insert(10);

	print();
	
	int i;
	for(i=0; i<9; i++)
	{
		printf("%d ", get_max());
	}
	printf("\n");

}

int get_index(int data)
{
	int i;
	for(i=0; i<LEN; i++)
	{
		if(data == m_heap[i])
			return i;
	}
	return -1;
}

void insert(int data)
{
	if(m_size < 30)
	{
		m_heap[++m_size] = data;
		filter_up(m_size);
	}
}

void filter_up(int index)
{
	int parent_idx = get_parent_index(index);
	if(parent_idx != -1 && m_heap[index] > m_heap[parent_idx])
	{
		swap(index, parent_idx);
		filter_up(parent_idx);
	}
}

int get_parent_index(int index)
{
	return index / 2 > 0? index / 2 : -1; 
}

void print() {
	int i;
	for(i=1; i<m_size+1; i++)
	{
		printf("%d ", m_heap[i]);
	}
	printf("\n");
}

void swap(int i, int j)
{
	int tmp = m_heap[i];
	m_heap[i] = m_heap[j];
	m_heap[j] = tmp;
}

int get_max() 
{
	if(m_size == 0)
		return -1;
	int result = m_heap[1];
	m_heap[1] = m_heap[m_size--];
	rotate(1);

//	printf("After rotate:\n");
//	print();
	
	return result;
	
}

void rotate(int index)
{
	int left_child_idx = 2 * index;
	int right_child_idx = 2 * index + 1;
	int pivot_index = 0;
	if(right_child_idx < m_size + 1)
	{
		pivot_index = m_heap[left_child_idx] > m_heap[right_child_idx]? left_child_idx: right_child_idx;
	} else if(left_child_idx < m_size + 1)
	{
		pivot_index = left_child_idx;
	}
	if(pivot_index > 0 && m_heap[index] < m_heap[pivot_index])
	{
		swap(index, pivot_index);
		rotate(pivot_index);
	}
}





