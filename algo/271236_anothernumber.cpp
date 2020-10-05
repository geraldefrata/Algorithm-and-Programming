#include<stdio.h>
long long int a,b,c,d;
int main(){
	int j;
	int test;
	scanf("%d",&test);
	for(int i=1;i<=test;i++){
		int count=0;
		scanf("%d %d %d %d",&a,&b,&c,&d);
		for( j=1;j<=100000;j++){
			if(((a*j)+b)%d==c){
				count++;
			}
			
		}
		if(count>=1) printf("Case #%d: YES\n",i);
		else printf("Case #%d: NO\n",i);
		count=0;
	}
return 0;
}
