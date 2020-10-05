#include<stdio.h>
int  angka[100000];
int main(){
	int test,jumlah,dicari;
scanf("%d %d",&jumlah,&test);
	for(int j=0;j<jumlah;j++){
		scanf("%d",&angka[j]);
	}
	for(int i=1;i<=test;i++){
			scanf("%d",&dicari);
		for(int j=0;j<jumlah-1;j++){
			for(int k=0;k<jumlah-1-j;k++){
				if(angka[k]>angka[k+1]){
					int swap=angka[k];
					angka[k]=angka[k+1];
					angka[k+1]=swap;
					
				}
			}
		}
	
		for(int j=0;j<jumlah;j++){
			
			
			if(angka[dicari-1]==angka[j]){
			
				
				printf("%d\n",angka[j]);
				break;
		}
				
			
		
		}
	
		
}
return 0;
}
