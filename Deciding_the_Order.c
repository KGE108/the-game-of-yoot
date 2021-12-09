void Deciding_the_Order(char* name1, char* name2)
{

	int go[16] = { 1,1,1,2,2,2,2,2,2,3,3,3,3,4,5,0 };
	char act;
	char name_yut1[20];
	char name_yut2[20];
	char zero[10] = "빽도";
	char one[4] = "도";
	char two[4] = "개";
	char three[4] = "걸";
	char four[4] = "윷";
	char five[4] = "모";
Ex:
    system("cls");
	printf("윷을 던지시려면 엔터를 눌러주세요.\n\n");
	scanf("%c", &act);
	int yut1 = go[rand() % 16];
	switch (yut1)
	{
	case 0:
		strcpy(name_yut1, zero);
		break;
	case 1:
		strcpy(name_yut1, one);
		break;
	case 2:
		strcpy(name_yut1, two);
		break;
	case 3:
		strcpy(name_yut1, three);
		break;
	case 4:
		strcpy(name_yut1, four);
		break;
	case 5:
		strcpy(name_yut1, five);
		break;
	}
	printf("------------------------------\n%s의 윷: %s\n------------------------------\n\n\n", name1, name_yut1);
	printf("윷을 던지시려면 엔터를 눌러주세요.\n\n");
	scanf("%c", &act);
	int yut2 = go[rand() % 16];
	switch (yut2)
	{
	case 0:
		strcpy(name_yut2, zero);
		break;
	case 1:
		strcpy(name_yut2, one);
		break;
	case 2:
		strcpy(name_yut2, two);
		break;
	case 3:
		strcpy(name_yut2, three);
		break;
	case 4:
		strcpy(name_yut2, four);
		break;
	case 5:
		strcpy(name_yut2, five);
		break;
	}
	printf("------------------------------\n%s의 윷: %s\n------------------------------\n\n\n", name2, name_yut2);
	if (yut1 == yut2)
	{
		printf("두 팀의 윷이 같아 재진행합니다!\n\n");
		Sleep(3000);
		goto Ex;
	}

	if (yut1 > yut2) printf("%s의 선입니다!\n\n\n", name1);

	if (yut1 < yut2)
	{
		char tmp[20];
		printf("%s의 선입니다!\n\n\n", name2);
		*tmp = *name1;
		*name1 = *name2;
		*name2 = *tmp;
	}
	Sleep(3000);
	system("cls");
} //main func needs "srand(time(NULL))", team names
