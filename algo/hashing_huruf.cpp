#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define memory

struct data
{
	char name[100];
	int key;
	struct data *next, *prev;
}*head[97], *tail[97];

int size = 97;

int hash_function(char name[])
{
	int len = strlen(name);
	int sum = 0;
	
	for(int i = 0; i<len; i++)
	{
		sum += name[i];
	}
	int modulo = sum % size;
	
	return modulo;
}

void print_chaining()
{
	for(int i=0 ; i<size; i++)
	{
		if(head[i] == NULL)
		{
		 	printf("%d. \n", i);
		}
		else
		{
			printf("%d. ", i);
			struct data *curr = head[i];
			while(curr != NULL)
			{
				printf("%s -> ", curr->name);
				curr = curr->next;
			}
		}
		puts("");
	}
}

void pushtail(char name[])
{
	struct data *node = (struct data*)malloc(sizeof(struct data));
	int key = hash_function(name);
	strcpy(node->name, name);
	node->key = key;
	node->next = node->prev = NULL;
	
	if(head[key] == NULL)
	{
		head[key] = tail[key] = NULL;
	}
	else
	{
		tail[key]->next = node;
		node->prev = tail[key];
		tail[key] = node;
	}
}

int main()
{
	printf("%d\n", hash_function("AA"));
	pushtail("AA");
	print_chaining();
	
	
	return 0;
}
