#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
using namespace std;

typedef struct list
{
	int data;
	struct list* next;
}List;

List* creatlist()
{
	int x=1;
	List* tou = NULL, * p=NULL;
	List* s;
	while (x!=0) 
	{
		s = (List*)malloc(sizeof(List*));
		s->data = x;
		s->next = (List*)malloc(sizeof(List*));
		p = s;
		tou == NULL ? tou = s : p->next = s;
		scanf("%d", &x);
	}
	s->next = NULL;
	return tou;
}

void printflist(List *cur) //List* head = creatlist(); printflist(head);��������������д��
{
	while (cur)
	{
		cout << cur->data<<" ";
		cur = cur->next;
	}
	printf("\n");
}

List *deletelist(int v,List*cur)
{
	if (cur->data == v)
	{
		cur = cur->next;
		return cur;
	}
	else
	{
		List* cur1 = cur->next;
		while (cur1 && cur1->data != v)
		{
			cur = cur->next;
			List* cur1 = cur->next;
		}
		if (cur1)
		{
			cur->next = cur1->next;
		}
		else
		{
			return NULL;
		}
	}
}

void insertlist(int x, List*cur)
{
	int i = 2;
	while (i != x)
	{
		cur = cur->next;
		i++;
	}
	List t;
	List* cur1;
	cur1 = cur->next;
	t.data = x;
	cur->next->data;
	cur = cur->next;
	cur->next = cur1;
}

int main()
{
	int v,u;
	List* head = creatlist();
	printflist(head);
	cin >> v>>u;
	head=deletelist(v, head);
	printflist(head);
	insertlist(u, head);
	printflist(head);
	return 0;
}