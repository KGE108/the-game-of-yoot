void Throwing_Yuts(int* yut_array, int *count)
{
	const int go[16] = { 1,1,1,2,2,2,2,2,2,3,3,3,3,4,5,6 };
	int state = 0, i = 0;
	yut_array[20] = { 0, };
	char act;
	printf("윷을 던지시려면 엔터를 눌러주세요.\n\n");
	scanf("%c",&act);
	while (1)
	{
		int yut = go[rand() % 16];
		state = 0;
		switch (yut)
		{
		case 1:
			yut_array[i] = yut;
			printf("도!\n");
			break;
		case 2:
			yut_array[i] = yut;
			printf("개!\n");
			break;
		case 3:
			yut_array[i] = yut;
			printf("걸!\n");
			break;
		case 4:
			yut_array[i] = yut;
			printf("윷!\n");
			i++;
			state = 1;
			break;
		case 5:
			yut_array[i] = yut;
			printf("모!\n");
			i++;
			state = 1;
			break;
		case 6:
			yut_array[i] = yut;
			printf("빽도!\n");
			break;
		}
		if (state == 0) break;
	}
	*count = i + 1;
}
