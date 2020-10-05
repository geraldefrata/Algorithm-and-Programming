#include<stdio.h>
int fibo[100005];

int main(){
int test,m=1000000009,jumlah;
long long int sum;
scanf("%d",&test);
for(int i=1;i<=test;i++){
	sum=0;
	scanf("%d",&jumlah);
	fibo[0]=0;
	fibo[1]=1;
	sum=1;
	for(int j=2;j<=jumlah;j++){
		fibo[j]=(fibo[j-1]+fibo[j-2])%m;
		
		sum=(sum+fibo[j])%m;
		
	}

	printf("Case #%d: %d\n",i,sum);
	
}

	
	
return 0;
}

