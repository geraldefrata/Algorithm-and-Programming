#include <stdio.h>

//int sama(char size, int color){
//	if(si)
//}

int main(){
	int input, banyak, temp;
	char size[1000];
	int color[1000];
	
	scanf("%d", &input);getchar();
	
	for(int i=0;i<input;i++){
		scanf("%d", &banyak);getchar();
		temp=0;
		
		for(int j=0;j<banyak;j++){
			scanf("%c", &size[j]);getchar();
			scanf("%d", &color[j]);getchar();
			
			for(int k=j-1;k>=0;k--){
				if(size[k]==size[j] && color[k]==color[j]){
					temp+=10;
					color[k]=k-10000;
					color[j]=j-10000;
					break;
				}
			}			
		}
		printf("Case #%d: %d\n", i+1, temp);
	}
	
	
	
	return 0;
}
