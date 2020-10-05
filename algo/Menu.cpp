#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct data
{
	char name[100];
	float bmi;
	char category[100];
	struct data *next, *prev;
}*head, *tail;

void push(char nama[100], float bmi, char kategori[100])
{
	struct data *node = (struct data*)malloc(sizeof(struct data));
	strcpy(node->name, nama);
	node->bmi = bmi;
	strcpy(node->category, kategori);
	node->next = node->prev = NULL;
	
	if(head == NULL)
	{
		head = tail = node;
	}
	else if(bmi < head->bmi)
	{
		head->prev = node;
		node->next = head;
		head = node;
	}
	else if(bmi >= tail->bmi)
	{
		tail->next = node;
		node->prev = tail;
		tail = node;
	}
	else
	{
		struct data *curr = head;
		while(curr->next->bmi < node->bmi)
		{
			curr = curr->next;
		}
		curr->next = node->next;
		curr->next->prev = node->prev;
	}
}

void pop()
{
	struct data *curr = head;
	while(curr)
	{
		if(strcmp(curr->category, "Normal") == 0)
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
				struct data *temp = head;
				temp = curr;
				curr = curr->prev;
				curr->next = temp->next;
				temp->next->prev = curr;
				free(temp);
				temp = NULL;
			}
			curr = curr->next;
		}
	}
}

void view()
{
	struct data *curr = head;
	if(curr == NULL)
	{
		printf("No data found\n");
	}
	else
	{
		printf("Name		|	BMI		|		Category\n");
		while(curr)
		{
			printf("%s		|		%.2f	|		%s\n", curr->name, curr->bmi, curr->category);
			curr = curr->next;
		}
	}
	puts("");
}

int main()
{
	int option;
	char nama[100], kategori[100];
	float berat, tinggi;
	float bmi;
	
	do
	{
		printf("Body Mass Index\n");
		printf("===============\n");
		
		view();
		
		printf("1. Add New Data\n");
		printf("2. Delete All Data in Normal Category\n");
		printf("3. Exit\n");
		printf(">> ");
		scanf("%d", &option);
		
		switch(option)
		{
			case 1:
				do
				{
					printf("Full name [2 - 20 Characters]: ");
					scanf("%s", nama);
				} while(strlen(nama) < 2 || strlen(nama) > 20);
				do
				{
					printf("Weight [35.00 - 300.00 Kilograms]: ");
					scanf("%f", &berat);
				} while(berat < 35 || berat > 300);
				do
				{
					printf("Height [0.50 - 3.00 Meter]: ");
					scanf("%f", &tinggi);
				} while(tinggi < 0.50 || tinggi > 3);
				
				bmi = (berat)/(tinggi * tinggi);
				
				if(bmi < 18.5)
				{
					strcpy(kategori, "Underweight");
				}
				else if(18.5 < bmi < 25)
				{
					strcpy(kategori, "Normal");
				}
				else
				{
					strcpy(kategori, "Overweight");
				}
				push(nama, bmi, kategori);
				break;
				
			case 2:
				pop();
				break;
				
			case 3:
				break;		
		}
		
	} while(option != 3);
	
	return 0;
}
