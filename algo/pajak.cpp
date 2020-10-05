#include<stdio.h>

int main()
{
	long long int gaji, gajitotal, total;
	int anak, istri;
	long long int pajaktotal, pajak1, pajak2, pajak3, pajak4, tunjangan;
	long long int tahunan;
	
	printf("penghasilan perbulan : ");
	scanf("%11d", &gaji);
	tahunan=gaji*12;
	printf("jumlah istri : ");
	scanf("%d", &istri);
	printf("jumlah anak : ");
	scanf("%d", &anak);
	anak = anak+4500000;
	tunjangan = 54000000+anak+istri;
	total = tahunan-tunjangan;
	
		if(total<=54000000)
		{
			printf("tidak kena pajak");
		}
		else if(total<=50000000)
		{
			pajak1 = total*0.05;
			pajaktotal = pajak1;
			gajitotal = tahunan - pajaktotal;
			printf("pajak tahunan ialah %d\ngaji bersih tahunan ialah %d", pajaktotal, gajitotal);
		}
		else if(total>=50000000 || total<=250000000)
		{
			pajak1 = (total-50000000)*0.15;
			pajak2 = 50000000*0.05;
			pajaktotal=pajak1+pajak2;
			gajitotal = tahunan-pajaktotal;
			printf("pajak tahunan ialah %d\ngaji tahunan ialah %d", pajaktotal, gajitotal);
		}
		else if(total>=250000000 || total<500000000)
		{
			pajak1 = (total-50000000)*0.25;
			pajak2 = 50000000*0.05;
			pajak3 = 50000000*0.15;
			pajaktotal=pajak1+pajak2+pajak3;
			gajitotal = tahunan-pajaktotal;
			printf("pajak tahunan ialah %d\n dan gaji tahunan ialah %d", pajaktotal, gajitotal);
		}
		else if(total>=5000000000)
		{
			pajak1 = (total-50000000)*0.30;
			pajak2 = 50000000*0.05;
			pajak3 = 50000000*0.15;
			pajak4 = 50000000*0.25;
			pajaktotal=pajak1+pajak2+pajak3+pajak4;
			gajitotal = tahunan-pajaktotal;
			printf("pajak tahunan ialah %d\n dan gaji tahunan ialah %d\n", pajaktotal, gajitotal);
		}
		
		
		
	return 0;
}
