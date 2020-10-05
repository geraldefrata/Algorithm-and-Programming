#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// DOUBLE LINKED LIST

//NODE
struct data
{
	int value;
	char name[100];
	struct data *next;
//Pembeda
	struct data *prev;
}*head, *tail;

void pushhead(int val, char a[100])
{
	struct data *node = (struct data*)malloc(sizeof(struct data));
	node->value = val;
	strcpy(node->name, a);
	node->next = node->prev = NULL;
	
	if(head == NULL)
	{
		head = tail = node;
	}
	else
	{
		node->next = head;
		head->prev = node;
		head = node;
	}
}

void pushtail(int val, char a[100])
{
	struct data *node = (struct data*)malloc(sizeof(struct data));
	node->value = val;
	strcpy(node->name, a);
	node->next = node->prev = NULL;
	
	if(head == NULL)
	{
		head = tail = node;
	}
	else
	{
		tail->next = node;
		node->prev = tail;
		tail = node;
	}
}

void pushmid(int val, char a[100])
{
	struct data *node = (struct data*)malloc(sizeof(struct data));
	node->value = val;
	strcpy(node->name, a);
	node->next = node->prev = NULL;
	
	if(head == NULL)
	{
		head = tail = node;
	}
//	pushhead
	else if(val <= head->value)
	{
		node->next = head;
		head->prev = node;
		head = node;
	}
//	pushtail
	else if(val >= tail->value)
	{
		tail->next = node;
		node->prev = tail;
		tail = node;
	}
	else
	{
		struct data *curr = head;
		while(curr->next->value < node->value)
		{
			curr = curr->next;
		}
		node->next = curr->next;
		node->next->prev = node;
		node->prev = curr;
		curr->next = node;
	}
}

void pophead()
{
	if(head != NULL)
	{
		if(head == tail)
		{
			free(head);
			head = tail = NULL;
		}
		else
		{
			head = head->next;
			free(head->prev);
			head->prev = NULL;
		}
	}
}

void poptail()
{
	if(head != NULL)
	{
		if(head == tail)
		{
			head = tail = NULL;
		}
		else
		{
			tail = tail->prev;
			free(tail->next);
			tail->next = NULL;
		}
	}
}

void popmid(int val)
{
	if(head != NULL)
	{
		if(head == tail)
		{
			if(head->value == val)
			{
				free(head);
				head = tail = NULL;
			}
		}
		else if(val == head->value)
		{
//			pophead
			head = head->next;
			free(head->prev);
			head->prev = NULL;
		}
		else if(val == tail->value)
		{
//			poptail
			tail = tail->prev;
			free(tail->next);
			tail->next = NULL;
		}
		else
		{
			struct data *curr = head;
			while(curr->value != val && curr != tail)
			{
				curr = curr->next;
			}
			if(curr->value == val)
			{
				curr->next->prev = curr->prev;
				curr->prev->next = curr->next;
				free(curr);
				curr = NULL;
			}
			else
			{
				printf("Data is not available\n");
			}
		}
	}
}

void printall()
{
	struct data *curr = head;
	while(curr != NULL)
	{
		printf("[%d %s]", curr->value, curr->name);
		curr = curr->next;
	}
}

int main()
{
	pushhead(5, "Andi");
	pushhead(15, "Budi");
	pushhead(25, "Caca");
	pushhead(35, "Dodi");
	pushhead(45, "Eric");
	
	printall();
	puts("");
	
//	depan hilang
	pophead();
	printall();
	puts("");
	
//	belakang hilang
	poptail();
	printall();
	puts("");
	
//	data yang diisi hilang
	popmid(20);
	printall();
	puts("");
	 
//	pushtail(5, "Andi");
//	pushtail(15, "Budi");
//	pushtail(25, "Caca");
//	pushtail(35, "Dodi");
//	pushtail(45, "Eric");
//	
//	printall();
//	puts("");
	
//	pushmid(5, "Andi");
//	pushmid(35, "Budi");
//	pushmid(25, "Caca");
//	pushmid(55, "Dodi");
//	pushmid(45, "Eric");
//	
//	printall();
//	puts("");

	
	
	
	return 0;
}
