void Team1_Go_Piece(int* yut_array, int count, int* Team1_A, int* Team1_a, int* Team2_B, int* Team2_b) //Team 1 말 이동
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

        if (*Team1_A == 0 && *Team1_a == 0 && yut_array[0] == 6)
        {
            printf("\n\n갈 수 있는 말이 없습니다.\n\n");
            break;
        }
        printf("\n\n윷은 윷에 해당되는 숫자를, 말은 A와a 중 하나를 골라 이어서 입력해주세요( ex : 2a or 3A)");
        printf("\n(도=1, 개=2, 걸=3, 윷=4, 모=5, 빽도=6)(A/a)\n쓰고 싶은 윷,말>> ");


        scanf("%d%c", &wantYut, &wantPiece);

        if (wantPiece == 'A')
        {
            if (*Team1_A > 20)
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
                        if (*Team1_A == 0 && *Team1_a == 0)
                        {
                            printf("갈 수 있는 말이 없습니다.\n\n");
                            break;
                        }
                        else if (*Team1_A == 0 && Team1_a != 0)
                            printf("그 말은 뒤로 갈 수 없습니다.\n\n");
                        else
                        {
                            if (*Team1_A == *Team1_a && *Team1_A != 0 && *Team1_a != 0) stacked_A = 'T';
                            if (stacked_A == 'T')
                            {
                                temp1 = *Team1_A;
                                *Team1_A -= 1;
                                temp2 = *Team1_A;
                                *Team1_a = temp2;
                                movePiece(temp1, temp2, 'C');
                                if (*Team1_A == *Team2_B && *Team2_B != *Team2_b)
                                {
                                    Token_A = 'T';
                                    *Team2_B = 0;
                                }
                                if (*Team1_A == *Team2_b && *Team2_B != *Team2_b)
                                {
                                    Token_A = 'T';
                                    *Team2_b = 0;
                                }
                                if (*Team1_A == *Team2_B && *Team2_B == *Team2_b)
                                {
                                    Token_A = 'T';
                                    *Team2_B = 0;
                                    *Team2_b = 0;
                                    stacked_B = 'F';
                                }
                                print_Map(map);
                            }
                            else
                            {
                                temp1 = *Team1_A;
                                *Team1_A -= 1;
                                temp2 = *Team1_A;
                                movePiece(temp1, temp2, 'A');
                                if (*Team1_A == *Team2_B && *Team2_B != *Team2_b)
                                {
                                    Token_A = 'T';
                                    *Team2_B = 0;
                                }
                                if (*Team1_A == *Team2_b && *Team2_B != *Team2_b)
                                {
                                    Token_A = 'T';
                                    *Team2_b = 0;
                                }
                                if (*Team1_A == *Team2_B && *Team2_B == *Team2_b)
                                {
                                    Token_A = 'T';
                                    *Team2_B = 0;
                                    *Team2_b = 0;
                                    stacked_B = 'F';
                                }
                                if (*Team1_a == *Team1_A && *Team1_A != 0 && *Team1_a != 0)
                                {
                                    stacked_A = 'T';
                                    movePiece(*Team1_A, *Team1_A, 'C');
                                }
                                print_Map(map);
                            }
                        }
                    }
                    else
                    {
                        if (*Team1_A == *Team1_a && *Team1_A != 0 && *Team1_a != 0) stacked_A = 'T';
                        if (stacked_A == 'T')
                        {
                            temp1 = *Team1_A;
                            *Team1_A += wantYut;
                            temp2 = *Team1_A;
                            *Team1_a = temp2;
                            movePiece(temp1, temp2, 'C');
                            if (*Team1_A == *Team2_B && *Team2_B != *Team2_b)
                            {
                                Token_A = 'T';
                                *Team2_B = 0;
                            }
                            else if (*Team1_A == *Team2_b && *Team2_B != *Team2_b)
                            {
                                Token_A = 'T';
                                *Team2_b = 0;
                            }
                            else if (*Team1_A == *Team2_B && *Team2_B == *Team2_b)
                            {
                                Token_A = 'T';
                                *Team2_B = 0;
                                *Team2_b = 0;
                                stacked_B = 'F';
                            }
                            print_Map(map);
                        }
                        else
                        {
                            temp1 = *Team1_A;
                            *Team1_A += wantYut;
                            temp2 = *Team1_A;
                            movePiece(temp1, temp2, 'A');
                            if (*Team1_A == *Team2_B && *Team2_B != *Team2_b)
                            {
                                Token_A = 'T';
                                *Team2_B = 0;
                            }
                            if (*Team1_A == *Team2_b && *Team2_B != *Team2_b)
                            {
                                Token_A = 'T';
                                *Team2_b = 0;
                            }
                            if (*Team1_A == *Team2_B && *Team2_B == *Team2_b)
                            {
                                Token_A = 'T';
                                *Team2_B = 0;
                                *Team2_b = 0;
                                stacked_B = 'F';
                            }
                            if (*Team1_a == *Team1_A && *Team1_A != 0 && *Team1_a != 0)
                            {
                                stacked_A = 'T';
                                movePiece(*Team1_A, *Team1_A, 'C');
                            }
                            print_Map(map);
                        }
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

        else if (wantPiece == 'a')
        {
            if (*Team1_a > 20)
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
                        if (*Team1_A == 0 && *Team1_a == 0)
                            printf("갈 수 있는 말이 없습니다.\n");
                        else
                        {
                            if (*Team1_A == *Team1_a && *Team1_A != 0 && *Team1_a != 0) stacked_A = 'T';
                            if (stacked_A == 'T')
                            {
                                temp1 = *Team1_a;
                                *Team1_a -= 1;
                                temp2 = *Team1_a;
                                *Team1_A = temp2;
                                movePiece(temp1, temp2, 'C');
                                if (*Team1_A == *Team2_B && *Team2_B != *Team2_b)
                                {
                                    Token_A = 'T';
                                    *Team2_B = 0;
                                }
                                else if (*Team1_A == *Team2_b && *Team2_B != *Team2_b)
                                {
                                    Token_A = 'T';
                                    *Team2_b = 0;
                                }
                                else if (*Team1_A == *Team2_B && *Team2_B == *Team2_b)
                                {
                                    Token_A = 'T';
                                    *Team2_B = 0;
                                    *Team2_b = 0;
                                    stacked_B = 'F';
                                }
                                print_Map(map);
                            }
                            else
                            {
                                temp1 = *Team1_a;
                                *Team1_a -= 1;
                                temp2 = *Team1_a;
                                movePiece(temp1, temp2, 'a');
                                if (*Team1_a == *Team2_B && *Team2_B != *Team2_b)
                                {
                                    Token_A = 'T';
                                    *Team2_B = 0;
                                }
                                if (*Team1_a == *Team2_b && *Team2_B != *Team2_b)
                                {
                                    Token_A = 'T';
                                    *Team2_b = 0;
                                }
                                if (*Team1_a == *Team2_B && *Team2_B == *Team2_b)
                                {
                                    Token_A = 'T';
                                    *Team2_B = 0;
                                    *Team2_b = 0;
                                    stacked_B = 'F';
                                }
                                if (*Team1_a == *Team1_A && *Team1_A != 0 && *Team1_a != 0)
                                {
                                    stacked_A = 'T';
                                    movePiece(*Team1_A, *Team1_A, 'C');
                                }
                                print_Map(map);
                            }
                        }
                    }
                    else
                    {
                        if (*Team1_A == *Team1_a && *Team1_A != 0 && *Team1_a != 0) stacked_A = 'T';
                        if (stacked_A == 'T')
                        {
                            temp1 = *Team1_a;
                            *Team1_a += wantYut;
                            temp2 = *Team1_a;
                            *Team1_A = temp2;
                            movePiece(temp1, temp2, 'C');
                            if (*Team1_a == *Team2_B && *Team2_B != *Team2_b)
                            {
                                Token_A = 'T';
                                *Team2_B = 0;
                            }
                            else if (*Team1_a == *Team2_b && *Team2_B != *Team2_b)
                            {
                                Token_A = 'T';
                                *Team2_b = 0;
                            }
                            else if (*Team1_a == *Team2_B && *Team2_B == *Team2_b)
                            {
                                Token_A = 'T';
                                *Team2_B = 0;
                                *Team2_b = 0;
                                stacked_B = 'F';
                            }
                            print_Map(map);
                        }
                        else
                        {
                            temp1 = *Team1_a;
                            *Team1_a += wantYut;
                            temp2 = *Team1_a;
                            movePiece(temp1, temp2, 'a');
                            if (*Team1_a == *Team2_B && *Team2_B != *Team2_b)
                            {
                                Token_A = 'T';
                                *Team2_B = 0;
                            }
                            else if (*Team1_a == *Team2_b && *Team2_B != *Team2_b)
                            {
                                Token_A = 'T';
                                *Team2_b = 0;
                            }
                            else if (*Team1_a == *Team2_B && *Team2_B == *Team2_b)
                            {
                                Token_A = 'T';
                                *Team2_B = 0;
                                *Team2_b = 0;
                                stacked_B = 'F';
                            }
                            if (*Team1_a == *Team1_A && *Team1_A != 0 && *Team1_a != 0)
                            {
                                stacked_A = 'T';
                                movePiece(*Team1_A, *Team1_A, 'C');
                            }
                            print_Map(map);
                        }
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
