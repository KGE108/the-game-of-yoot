void init_Map(char map[6][6])
{
	for(int i=0; i<6; i++)
	{
		for(int j=0;j<6; j++)
		{
			if(i==0 || i==5)
			{
				map[i][j] = 'O';
			}
			else if(j==0 || j==5)
			{
				map[i][j] = 'O';
			}
			else
				map[i][j] = ' ';
		}	
	}
}