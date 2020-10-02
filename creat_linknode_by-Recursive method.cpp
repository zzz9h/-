
#include <stdio.h>
#include <malloc.h>
#include<windows.h>

/*typedef struct Lnode
{
	int data;
	struct Lnode* next;
}LNODE, * Linklist;
*/

/*
Linklist creat(Linklist L)
{
	int i=0;
	int node; Linklist p;
	L = (Linklist)malloc(sizeof(LNODE));
	L->next = NULL;
	while (i<20)
	{
		node = rand();
		p = (Linklist)malloc(sizeof(LNODE));
		if (!p) break;
		p->data = node;
		p->next = L->next;
		L->next = p;
		i++;
	}
	return L;
}
*/
typedef struct node
{
	int data;
	struct node* next;

}node, * linknode;
linknode display(linknode L)
{
	linknode p;
	p = L->next;
	while (p != NULL)
	{
		printf("%4d|", p->data);
		p = p->next;
	}
	printf("\n");
	return L;
}

linknode creat(linknode L, int n)
{
	if (n==0)
	{
		return L;
	}
	int node = rand();
	linknode p;
	p = (linknode)malloc(sizeof(node));
	p->data = node;
	p->next = L->next;
	L->next = p;
	return creat(L,n-1);
}

int main()
{
	linknode L = NULL;
	L = (linknode)malloc(sizeof(node));
	L->next = NULL;
	L = creat(L,5);
	display(L);
}
/*int main()
{
	Linklist L = NULL; int i, x;
	L = creat(L);
	printf("the Linklist is:\n");
	display(L);

}*/

