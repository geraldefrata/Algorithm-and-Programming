#include<stdio.h>
#include<stdlib.h>
#include<string.h>


struct data
{
	int weight;
	char type[100];
	struct data *next, *prev;
}*head, *tail;

void pushtail(char tipe[100], int berat)
{
	struct data *node = (struct data*)malloc(sizeof(struct data));
	node->weight = berat;
	strcpy(node->type, tipe);
	node->next = node->prev = NULL;
	
	if(head == NULL)
	{
		head = tail = node;
	}
	else
	{
		tail->next = node;
		node->next = tail;
		tail = node;
	}

}

void poptail()
{
	if(head == NULL)
	{
		printf("---The Rice Storage is Empty---\n");
	}
	else
	{
		tail = tail->prev;
		free(tail->next);
		tail->next = NULL;
		printf("--- Sell Rice Success ---\n");
	}
}

void view()
{
	struct data *curr = head;
	if(head == NULL)
	{
		printf("---The Rice Storage is Empty---\n");
	}
	while(curr != NULL)
	{
		printf("%s %d\n", curr->type, curr->weight);
		curr = curr->next;
	}
	puts("");-
	--
}

int main()
{
	int opt;
	char tipe[100];
	int berat;
	
	do
	{
		printf("BLUE RICE STOCK\n");
		printf("^^^^^^^^^^^^^^^\n");
	do
	{
		view();
		
		printf("1. Stock Rice Sack\n");
		printf("2. Sell Rice Sack\n");
		printf("3. Exit\n");
		puts("");
		printf(">> Input choice : ");
		scanf("%d", &opt);
		
		switch(opt)
		{
			case 1 :
				do
				{
					printf("Input Rice Type [long/medium/short]: ");
					scanf("%s", &tipe);
				} while(strcmp(tipe, "long") && strcmp(tipe, "medium") && strcmp(tipe, "short"));
				printf("Input Weight of The Rice Sack: ");
				scanf("%d", &berat);
				
				pushtail(tipe, berat);
				break;
				
			case 2 :
				poptail();
				break;

		}
	} while(opt<1 || opt>3);
	} while(opt != 3);
	return 0;
}
