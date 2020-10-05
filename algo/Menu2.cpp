#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct data
{
	char name[100];
	char extension[100];
	int size;
	struct data *next, *prev;
}*head, *tail;

void push(char name[100], char extension[100], int ukuran)
{
	struct data *node = (struct data*)malloc(sizeof(struct data));
	strcpy(node->name, name);
	strcpy(node->extension, extension);
	node->size = ukuran;
	node->next = node->prev = NULL;
	
	if(head == NULL)
	{
		head = tail = node;
	}
	else if(ukuran < head->size)
	{
		head->prev = node;
		node->next = head;
		head = node;
	}
	else if(ukuran >= tail->size)
	{
		tail->next = node;
		node->prev = tail;
		tail = node;
	}
	else
	{
		struct data *curr = head;
		while(curr->next->size < node->size)
		{
			curr = curr->next;
		}
		curr->next = node->next;
		curr->next = node;
		node->prev = curr;
		node->next->prev = node;
	}
	
}

void view()
{
	int nomor;
	
		struct data *curr = head;
		if(curr == NULL)
		{
			printf("No Data Found\n");
		}
		else
		{
			while(curr != NULL)
			{
				printf("%d. %s.%s			%d MB\n", nomor+1, curr->name, curr->extension, curr->size);
				nomor++;
				curr = curr->next;
			}
		}
		puts("");
	
}

void pop(char extension[100])
{
	struct data *curr = head;
	while(curr != NULL)
	{
		if(strcmp(curr->extension, extension) == 0)
		{
			if(curr == head)
			{
				if(head == tail)
				{
					free(head);
					head = tail = NULL;
				}
				else
				{
					struct data *node = head;
					head = head->next;
					free(node);
					node->prev = NULL;
				}
			}
			else if(curr == tail)
			{
				if(head == tail)
				{
					free(head);
					head = tail = NULL;
				}
				else
				{
					struct data *node = head;
					tail = tail->prev;
					free(node);
					node->next = NULL;
				}
			}
			else
			{
				curr->next->prev = curr->prev;
				curr->prev->next = curr->next;
				free(curr);
				curr = NULL;
			}
		}
		curr = curr->next;
	}
}



int main()
{
	int option;
	char name[100], extension[100];
	int size = 0;
	
	int total = 4096;
	
	do
	{
		view();
		
		printf("Available Space : %d MB\n", total - size);
		printf("1. Add New File\n");
		printf("2. Delete File by Extension\n");
		printf("3. Exit\n");
		
		do
		{
			printf("Input your choice : ");
			scanf("%d", &option);
			
			switch(option)
			{
				case 1:
					do
					{
						printf("input file name [1..20 character] : ");
						scanf("%s", name);
					} while(strlen(name) < 1 || strlen(name) > 20);
					
					do
					{
						printf("input file extension [1..5 characters] : ");
						scanf("%s", extension);
					} while(strlen(extension) < 1 || strlen(extension) > 5);
					
					do
					{
						printf("input file size [1..%d] : ", total - size);
						scanf("%d", &size);
						puts("");
					} while(size < 1 || size > total-size);
					
					push(name, extension, size);
					break;
					
				case 2:
					printf("input extension you want to delete : ");
					scanf("%s", extension);
					pop(extension);
					break;
					
				case 3:
					break;
			}
		}while(option < 1 || option > 3);
		
		
	} while(option != 3);
	
	return 0;
}
