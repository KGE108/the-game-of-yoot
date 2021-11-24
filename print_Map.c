void print_Map(char map[6][6])
{
	printf("\n");
	for(int i=0; i<6; i++)
	{
		for(int j=0; j<6; j++)
		{
			printf("%c ", map[i][j]);
		}
		printf("\n");
	}
}