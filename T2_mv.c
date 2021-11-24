void Team2_Go_Piece(int* yut_array, int count, int* Team2_B, int* Team2_b) //Team 2 말 이동
{
	int count_ne = count;
	int temp1, temp2;
	char wantPiece;
	while (count_ne != 0)
	{
		int wantYut = 0;
	RE:
		printf("\n남은 윷: ");
		for (int i = 0; i < count; i++)
		{
			if (yut_array[i] == 1) printf("도 ");
			if (yut_array[i] == 2) printf("개 ");
			if (yut_array[i] == 3) printf("걸 ");
			if (yut_array[i] == 4) printf("윳 ");
			if (yut_array[i] == 5) printf("모 ");
			if (yut_array[i] == 6) printf("빽도 ");
		}

		if (*Team2_B == 0 && *Team2_b == 0 && yut_array[0] == 6)
		{
			printf("\n\n갈 수 있는 말이 없습니다.\n\n");
			break;
		}

		printf("\n(도=1, 개=2, 걸=3, 윷=4, 모=5, 빽도=6)(B/b)\n쓰고 싶은 윷,말>> ");

		scanf("%d%c", &wantYut, &wantPiece);

		if (wantPiece == 'B')
		{
			if (*Team2_B > 20)
			{
				printf("\n\n이미 난 말 입니다\n\n");
				goto RE;
			}

			for (int i = 0; i < count; i++)
			{
				if (yut_array[i] == wantYut)
				{
					yut_array[i] = 0;
					if (wantYut == 6)
					{
						if (*Team2_B == 0 && *Team2_b == 0)
						{
							printf("갈 수 있는 말이 없습니다.\n\n");
							break;
						}
						else if (*Team2_B == 0 && Team2_b != 0)
							printf("그 말은 뒤로 갈 수 없습니다.\n\n");
						else
						{
							temp1 = *Team2_B;
							*Team2_B -= 1;
							temp2 = *Team2_B;
							movePiece(temp1, temp2, 'B');
							print_Map(map);
						}
					}
					else
					{
						temp1 = *Team2_B;
						*Team2_B += wantYut;
						temp2 = *Team2_B;
						movePiece(temp1, temp2, 'B');
						print_Map(map);
					}
					count_ne--;
					break;
				}
				else if (i == count - 1)
				{
					printf("그 윷은 던진 적이 없습니다.\n\n");
					break;
				}
			}
		}

		else if (wantPiece == 'b')
		{
			if (*Team2_b > 20)
			{
				printf("\n\n이미 난 말 입니다\n\n");
				goto RE;
			}

			for (int i = 0; i < count; i++)
			{
				if (yut_array[i] == wantYut)
				{
					yut_array[i] = 0;
					if (wantYut == 6)
					{
						if (*Team2_B == 0 && *Team2_b == 0)
							printf("갈 수 있는 말이 없습니다.\n\n");
						else 
						{
							temp1 = *Team2_b;
							*Team2_b -= 1;
							temp2 = *Team2_b;
							movePiece(temp1, temp2, 'b');
							print_Map(map);
						}
					}
					else
					{
						temp1 = *Team2_b;
						*Team2_b += wantYut;
						temp2 = *Team2_b;
						movePiece(temp1, temp2, 'b');
						print_Map(map);
					}
					count_ne--;
					break;
				}
				else if (i == count - 1)
				{
					printf("\n그 윷은 던진 적이 없습니다.\n\n");
					break;
				}
			}
		}
		else 
		{
			printf("그런 말은 없습니다.\n\n");
			goto RE;
		}
	}
}
