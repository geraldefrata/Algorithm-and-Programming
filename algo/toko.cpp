#include<stdio.h>

int main()
{
	int input, jumlah, temp;
	int warna[1000];
	int i, j, k;
	char ukuran[1000];
	
	scanf("%d", &input);

	for(i=0; i<input; i++)
	{
		scanf("%d", &jumlah); getchar();
		temp = 0;
		
		for(j=0; j<jumlah; j++)
		{
			scanf("%c", &ukuran[j]); getchar();
			scanf("%d", &warna[j]); getchar();
			
			for(k=j-1; k>=0; k--)
			{
				if(ukuran[k]==ukuran[j] && warna[k]==warna[j])
				{
					temp = temp + 10;
					warna[k] = k - 10000;
					warna[j] = j - 10000;
					break;
				}
			}
		}
		printf("Case #%d: %d\n", i+1, temp);
	}
	
	return 0;
}
