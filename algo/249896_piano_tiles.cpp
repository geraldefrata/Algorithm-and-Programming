#include <stdio.h>

void readstring(char name[], int column);
void get_data(char name[][101], int row, int column);
void show_data(char name[][101], int row);

int main()
{
	int t;
	char name[101][101];
	int row, column;

	scanf("%d", &t);

	for(int k=1 ; k<=t ; k++)
	{
		scanf("%d %d", &row, &column);
		getchar();

		get_data(name, row, column);
		//printf("\n");
		//show_data(name, row);

		int last_finger_index;
		int tap_number = 1;
		for (int i = 0; i < column; i++)
		{
			if (name[0][i] == '.')
				continue;
			else if (name[0][i] == '|')
				last_finger_index = i;
			else if (name[0][i] == '/')
				last_finger_index = i - 1;
			else
				last_finger_index = i + 1;
		}

		//printf("\nlast finger index 1: %d\n", last_finger_index);
		

		for (int i = 1; i < row; i++)
		{
			for (int j = 0; j < column; j++)
			{
				if (name[i][j] == '.')
				{
					continue;
				}
				else if (name[i][j] == '|')
				{
					if (j != last_finger_index)
						tap_number++;
					last_finger_index = j;
				}
				else if (name[i][j] == '/')
				{
					if (j != last_finger_index)
						tap_number++;
					last_finger_index = j - 1;
				}
				else
				{
					if (j != last_finger_index)
						tap_number++;
					last_finger_index = j + 1;
				}
				//printf("last finger index %d: %d\n", i+1, last_finger_index);
			}
		}

		printf("Case #%d: %d\n",k, tap_number);
	}

	getchar();
	return 0;
}

void get_data(char name[][101], int row, int column){
	int i = 0;
	for (i = 0; i<row; i++){
		readstring(name[i], column);
	}
}

void show_data(char name[][101], int row){
	int i;
	for (i = 0; i<row; i++){
		printf("%s", name[i]);
	}
}

void readstring(char str[], int column){
	int i = 0;
	while (i<column)
	{ 
		str[i] = getchar();
		if (str[i] == '\n')
			str[i] = '\0';
		i++;
	}
	getchar();
}