#include<stdio.h>
#include<string.h>

FILE *fp;
int count;
int angka[1001];

void read_file(){
	count = 0;
	
	fp = fopen("testdata.in", "r");
	
	while(fscanf(fp, "%d\n", &angka[count]) != EOF)
	{
		count++;
	}
	
	fclose(fp);
}

void hitung(){
	int ngitung = 0;
	
	for(int i=0;i<count;i++)
	{
		ngitung++;
	}
	printf("Count : %d\n", ngitung);
}

void penjumlahan(){
	int hasil = 0;
	for(int j=0;j<count;j++)
	{
		hasil = hasil + angka[j];
	}
	printf("Sum   : %d\n", hasil);
}

void mean(){
	double sum;
	double ngitung = 0;
	
	for(int i=0;i<count;i++)
	{
		ngitung++;
	}
	
	for(int j=0; j<count; j++)
	{
		sum = sum + angka[j];
	}
	printf("Mean  : %.2f\n", sum/ngitung);
}

void min(){
	int smallest = angka[0];
	int largest = angka[0];
	
	for(int y=0;y<count;y++)
	{
		if(angka[y]>largest)
		{
			largest = angka[y];
		}
		if(angka[y]<smallest)
		{
			smallest = angka[y];
		}
	}
	printf("Min   : %d\n", smallest);
}

void max(){
	int smallest = angka[0];
	int largest = angka[0];
	
	for(int y=0;y<count;y++)
	{
		if(angka[y]>largest)
		{
			largest = angka[y];
		}
		if(angka[y]<smallest)
		{
			smallest = angka[y];
		}
	}
	printf("Max   : %d\n", largest);
}

void range(){
	int smallest = angka[0];
	int largest = angka[0];
	
	for(int y=0;y<count;y++)
	{
		if(angka[y]>largest)
		{
			largest = angka[y];
		}
		if(angka[y]<smallest)
		{
			smallest = angka[y];
		}
	}
	printf("Range : %d\n", largest-smallest);
}

int main()
{
	read_file();
	hitung();
	penjumlahan();
	mean();
	min();
	max();
	range();
	
	return 0;
}
