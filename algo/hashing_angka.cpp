#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define memory

struct data
{
	int x;
	struct data *next, *prev;
}*head[20], *tail[20];

int hash_function(int x)
{
	return x % 20;
}

void pushtail(int x)
{
	struct data *node = (struct data*)malloc(sizeof(struct data));
	int key = hash_function(x);
	node->x = x;
	node->next = node->prev = NULL;
	
	if(head[key] == NULL)
	{
		head[key] = tail[key] = node;
	}
	else
	{
		tail[key]->next =  node;
		node->prev = tail[key];
		tail[key] = node;
	}
}

void print_chaining()
{
	for(int i = 0; i<20; i++)
	{
		struct data *curr = head[i];
		printf("%d. ", i);
		while(curr)
		{
			printf("%d \n", curr->x);
			curr = curr->next;
		}
		puts("");
	}
}


int main()
{
	pushtail(2);
	pushtail(3);
	pushtail(5);
	pushtail(12);
	pushtail(13);
	pushtail(15);
	
	print_chaining();
	
	return 0;
}
