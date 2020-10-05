#include <stdio.h>
#include <string.h>

struct mahasiswa
{
	int id;
	int tanggal;
	int bulan;
	int tahun;
	char nama[11];
	char ad[11];
};

void search(struct mahasiswa siswa[], int b, int *idx, int a)
{
	*idx = -1;
	for(int i=0 ; i<a ; i++)
	{
		if(siswa[i].id == b)
		{
			*idx = i;
			break;
		}
	}
}

int main ()
{
	int t;
	int q;
	int angka;
	int idx = -1;
	struct mahasiswa siswa[101];

	scanf("%d", &t);

	for(int i=0 ; i<t ; i++)
	{
		scanf("%d %d %d %d %s %s", &siswa[i].id, &siswa[i].tanggal, &siswa[i].bulan, &siswa[i].tahun, siswa[i].nama, siswa[i].ad);
	}
	scanf("%d", &q);
	for(int i=0 ; i<q ; i++)
	{
		scanf("%d", &angka);
		search(siswa,angka,&idx,t);
		if(idx==-1)
		{
			printf("No data found!\n");
		}
		else
		{
			printf("%d. %s was born on %d/%d/%d and live at %s\n",siswa[idx].id, siswa[idx].nama, siswa[idx].tanggal, siswa[idx].bulan, siswa[idx].tahun, siswa[idx].ad );
		}
	}


	return 0;
}
