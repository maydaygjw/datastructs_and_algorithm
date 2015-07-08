#include <stdio.h>
#include <stdlib.h>
#include <sys/malloc.h>

typedef struct tag_node
{
	struct tag_node *next;
	struct tag_node *prev;
	void  *p;

}node;

node *phead = NULL;

int count = 0;

node* create_node(void *pval)
{
	node *pnode = NULL;
	pnode = (node*)malloc(sizeof(node));
	if(!pnode)
	{
		printf("create node error!\n");
		return NULL;
	}

	pnode -> prev = pnode -> next = pnode;
	pnode -> p = pval;

	return pnode;
}

int create_dlink()
{
	phead = create_node(NULL);
	if(!phead)
	{
		return -1;
	}

	count = 0;
	return 0;
}

int is_empty()
{
	return count == 0;
}

int size()
{
	return count;
}

node* get_node(int index)
{

	if(index < 0 || index >= count)
	{
		return NULL;
	}

	node *pnode = phead;

	if(index < count / 2)	//forward
	{

		int i = 0;
		
		while(i++ <= index)
		{
			pnode = pnode -> next;
		}
	} else 
	{
		//reverse find
		int i=0;
		while(i++ < count-index)
		{
			pnode = pnode -> prev;
		}
	}
	return pnode;

}

int insert_first(void *pval)
{
	node *pnode = create_node(pval);

	phead -> next = pnode;
	pnode -> prev = phead;

	if(count == 0)
	{
		
		phead -> prev = pnode;
		pnode -> next = phead;
	} else 
	{
		node *pnext = get_node(0);

		pnext -> prev = pnode;
		pnode -> next = pnext;
	}

	count ++;
	return 1;
}

int append_end(void *pval)
{
	if(count == 0)
	{
		return insert_first(pval);
	}



	node *pnode = create_node(pval);
	node *prev = get_node(count - 1);


	prev -> next = pnode;
	pnode -> prev = prev;
	pnode -> next = phead;
	phead -> prev = pnode;

	count ++;



	return 1;
}



int insert(int index, void *pval)
{
	if(index < 0 || index > count)
	{
		return -1;
	}

	if(index == 0)
		return insert_first(pval);
	if(index == count)
		return append_end(pval);

	node *pnode = create_node(pval);

	node *pprev = get_node(index - 1);
	node *pnext = get_node(index);

	pnode -> next = pnext;
	pnext -> prev = pnode;
	pprev -> next = pnode;
	pnode -> prev = pprev;

	count ++;

	return 1;
}


void print_chain()
{
	int i = 0;
	node *pnode = phead;
	while(i++ < count - 1)
	{
		pnode = pnode -> next;
		char *data = (char *)pnode -> p;
		printf("%s->", data);
	}
	
	if(0 != count)
	{
		node *pnode = get_node(count-1);
		char *data = (char *)pnode -> p;
		printf("%s\n", data);
	}
}

void reverse_print_chain()
{
	int i=0;
	node *pnode = phead;
	while(i++ < count - 1)
	{
		pnode = pnode -> prev;
		char *data = (char*)pnode -> p;
		printf("%s<-", data);
	}

	if(0 != count)
	{
		node *pnode = get_node(0);
		char *data = (char *)pnode -> p;
		printf("%s\n", data);
	}
}

int delete_at(int index)
{
	if(index < 0 || index >= count)
	{
		return -1;
	}
	node *pnode = get_node(index);
	node *pnext = pnode -> next;
	node *pprev = pnode -> prev;

	char *data = pnext -> p;

	pnext -> prev = pprev;
	pprev -> next = pnext;

	free(pnode);

	count --;

	return 0;
}





int main()
{
	create_dlink();
	insert_first("hello");
	insert(1, "junwen");
	append_end("world");
	insert(3, "ge");

	print_chain();
	reverse_print_chain();

	delete_at(1);
	delete_at(2);
	print_chain();
}


























