#include<stdio.h>
int main(){
	
	unsigned int banyakkasus,b;
	
	scanf("%d",&banyakkasus);
	
	for (int i=0;i<banyakkasus;i++){
		scanf("%d",&b);
		int batasrow[b] ,batascol[b];
		for (int j=0;j<b;j++){
			batasrow[j]=-127;
			batascol[j]=-127;//syarat soal
		}
		int angka[b][b+1];
		for (int row=0;row<b;row++){
			for (int col=0;col<b;col++){
				scanf("%d",&angka[row][col]);
				if(angka[row][col]>batasrow[row]){
					batasrow[row]=angka[row][col];
				}
				if(angka[row][col]>batascol[col]){
					batascol[col]=angka[row][col];
				}
			}
		}
		printf("Case #%d:\nRow :",i+1);
		for(int k=0;k<b;k++){
			printf(" %d", batasrow[k]);
	}
	printf("\nCol :");
		for(int k=0;k<b;k++){
			printf(" %d", batascol[k]);
	}
	printf("\n");
}
	return 0;
}
