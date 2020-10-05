#include<stdio.h>
int main(){
	int kasus, size, pangkat, M=1000000007;
	scanf("%d",&kasus);
	for(int z=0;z<kasus;z++){
			
		scanf("%d", &size);
		
		pangkat=size;
		
		long long int isi[size+1][size+1],temp[size+1][size+1],temp2[size+1][size+1],hasil_akhir[size+1][size+1];
		for(int baris=0;baris<size;baris++){
			for(int kolom=0;kolom<size;kolom++){
				scanf("%lld", &isi[baris][kolom]);
				temp[baris][kolom]=isi[baris][kolom];//matrix temp = matrix isi
			}
		}
		
		
		for(int p=0;p<pangkat-1;p++){ //perulangan sebanyak pangkat
		
			/////////////////////////DEBUG////////////////////////////////////
//			printf("pass %d:\n", p+1);
//			
//			printf("////////////////////Pre-process////////////////////\n");
//			
//			printf("temp:\n");
//			for(int baris=0;baris<size;baris++){
//				for(int kolom=0;kolom<size;kolom++){
//					printf("%d ", temp[baris][kolom]);
//				}
//				printf("\n");
//			}
//			
//			printf("temp2:\n");
//			for(int baris=0;baris<size;baris++){
//				for(int kolom=0;kolom<size;kolom++){
//					printf("%d ", temp2[baris][kolom]);
//				}
//				printf("\n");
//			}
//			printf("\n////////////////////Process////////////////////\n");
//			printf("////////////////////Post-Process////////////////////\n");
//			
			/////////////////////////////////////////////////////////////
		
		
			
			for(int baris=0;baris<size;baris++){//matrix temp2 = matrix temp * matrix isi
				for(int kolom=0;kolom<size;kolom++){
					temp2[baris][kolom]=0;
					for(int i=0;i<size;i++){
						temp2[baris][kolom]+=((temp[baris][i]*isi[i][kolom])%M);
						temp2[baris][kolom]%=M;
					}
				}
				for(int kolom=0;kolom<size;kolom++){ //matrix temp = matrix temp2
					temp[baris][kolom]=temp2[baris][kolom];
				}
			}
			
			/////////////////////////DEBUG////////////////////////////////////
//			printf("temp2[0][0] = temp[0][0] * isi[0][0]\n %lld %lld %lld\n", temp2[0][0], temp[0][0], isi[0][0]);
//			printf("temp:\n");
//			for(int baris=0;baris<size;baris++){
//				for(int kolom=0;kolom<size;kolom++){
//					printf("%d ", temp[baris][kolom]);
//				}
//				printf("\n");
//			}
//			
//			printf("temp2:\n");
//			for(int baris=0;baris<size;baris++){
//				for(int kolom=0;kolom<size;kolom++){
//					printf("%d ", temp2[baris][kolom]);
//				}
//				printf("\n");
//			}
//			
//			printf("////////////////////End_pass////////////////////\n");
			/////////////////////////////////////////////////////////////
		}
		
		printf("Case #%d:\n", z+1);
			for(int baris=0;baris<size;baris++){
				for(int kolom=0;kolom<size;kolom++){
					if(kolom!=0){
						printf(" ");
					}
					printf("%d", temp[baris][kolom]);
				}
				printf("\n");
			}
			
	}
	
	
	return 0;
}
