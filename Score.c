void Score(int* Team1_A, int* Team1_a, int* Team2_B, int* Team2_b, char* name1, char* name2)
{
    if (*Team1_A > 20 &&*Team1_A<29) {
        score1++;
        *Team1_A = 30;
    }
    if (*Team1_a > 20 && *Team1_a < 29) {
        score1++;
        *Team1_a = 30;
    }
    else if (*Team1_A > 20 && *Team1_a > 20)
        score1 = score1 + 2;
    if (*Team2_B > 20 && *Team2_B < 29) {
        score2++;
        *Team2_B = 30;
    }
    if (*Team2_b > 20 && *Team2_b < 29) {
        score2++;
        *Team2_b = 30;
    }
    else if (*Team2_B > 20 && *Team2_b > 20)
        score2 = score2 + 2;
    printf("\n%s팀 점수 : %d\n%s팀 점수 : %d\n", name1, score1, name2, score2);
}
