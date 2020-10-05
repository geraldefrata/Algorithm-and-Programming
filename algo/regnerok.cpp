#include<stdio.h>

int main()
{
	int kasus, temp, lvlkcl, lvlgede, med, player;
	
	scanf("%d", &kasus);
	for(int i=0; i<kasus; i++)
	{
		lvlkcl=1000000000;
		lvlgede=1;
		scanf("%d %d", &player, &med);
		for(int j=0; j<player; j++)
		{
			scanf("%d", &temp);
			if(temp>lvlgede)
			{
				lvlgede=temp;
			}
			if(temp<lvlkcl)
			{
				lvlkcl=temp;
			}
			
		}
		printf("Case #%d: ", i+1);
		if(lvlgede-lvlkcl>med)
		{
			printf("NO\n");
		}
		else
		{
			printf("YES\n");
		}
	}
	
	
	return 0;
}
