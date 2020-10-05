#include<stdio.h>
#include<stdlib.h>

// NODE
struct data
{
	int value;
	struct data *next;
	 
}*head, *tail;

void pushHead(int val)
{
	struct data *node = (struct data*) malloc (sizeof(struct data));
//	(*node).value = 15;
	node->value = val;
//	MENGISI VALUE
	node->next = NULL;
//	LANJUT KE VALUE
	
	if(head == NULL)
	{
		head = tail = node;
	}
	else
	{
		node->next = head;
		head = node;
	}
}

void pushTail(int val)
{
	struct data *node = (struct data*) malloc (sizeof(struct data));
	node->value = val;
	node->next = NULL;
	
	if(tail == NULL)
	{
		tail = head = node;
	}
	else
	{
		tail->next = node;
		tail = node;
	}
}

void pushMid(int val)
{
	struct data *node = (struct data*)malloc(sizeof(struct data));
	node->value = val;
	node->next = NULL;
	
	if(head == NULL)
	{
		head = tail = node;
	}
//	pushHead
	else if(val <= head->value)
	{
		node->next = head;
		head = node;
	}
//	pushTail
	else if(val >= tail->value)
	{
		tail->next = node;
		tail = node;
	}
//	kalau ada di tengah-tengah
	else
	{
		struct data *curr = head;
		while(curr->next->value < val)
		{
			curr = curr->next;
		}
		
		node->next = curr->next;
		curr->next = node;
	}
}
// mengeluarkan data, gak perlu pakai value
void popHead()
{
	if(head != NULL)
	{
		if(head == tail)
		{
			// DIALLOCATED MEMOTRY(MENGHAPUS MEMORI YANG TIDAK TERPAKAI)
			free(head);
			head = tail = NULL;
		}
		else
		{
			struct data *node = head;
			head = head->next;
			free(node);
			node = NULL;
		}
	}
}

void popTail()
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
			struct data *node = head;
			while(node->next != tail)
			{
				node = node->next;
			}
			free(tail);
			tail = node;
			node->next = NULL;
			
		/*	ATAU
			tail = node;
		  	free(tail->next);
		  	tail->next = NULL;
		*/
		}
	}
}

void popMid(int val)
{
	if(head != NULL)
	{
		if(head == tail)
		{
			free(head);
			head = tail = NULL;
		}
		else if(val == head->value)
		{
//			popHead
			struct data *node = head;
			head = head->next;
			free(node);
			node = NULL;
		}
		else if(val == tail->value)
		{
//			popTail
			struct data *node = tail;
			while(node->next != tail)
			{
				node = node->next;
			}
			free(tail);
			tail = node;
			node->next = NULL;
		}
		else
		{
//			popMid

			struct data *node = head;
			while(node->next->value == val && node->next != tail)
			{
				node = node->next;
			}
			if(node->next->value == val)
			{
				struct data *temp = node->next;
				node->next = temp->next;
				free(temp);
				temp = NULL;
			}
			else
			{
				printf("No Data\n");
			}
		}
	}
}

void popAll()
{
	while(head != NULL)
	{
		popHead();
	}
}

void printall()
{
	struct data *curr = head;
	while(curr != NULL)
	{
		printf("%d ", curr->value);
		curr = curr->next;
	}

}


int main()
{
	pushHead(50);
	pushHead(75);
	pushHead(20);
	pushHead(30);
	
	printall();
	printf("\n");
//	
//	pushTail(30);
//	pushTail(15);
//	pushTail(20);
//	pushTail(10);
//	
//	printall();
//	printf("\n");
	
//	pushMid(5);
//	pushMid(20);
//	pushMid(15);
//	pushMid(50);
//	pushMid(10);
//	
//	printall();
//	puts("");
	
//	popHead();
//	printall();
//	puts("");
//	
//	popHead();
//	printall();
//	puts("");
//	
//	popHead();
//	printall();
//	puts("");
//	
//	popHead();
//	printall();
//	puts("");
	
//	popTail();
//	printall();
//	puts("");
//	
//	popTail();
//	printall();
//	puts("");
//	
//	popTail();
//	printall();
//	puts("");
//	
//	popTail();
//	printall();
//	puts("");
	
//	popMid(55);
//	printall();
//	puts("");
	
	
	
	return 0;
}
