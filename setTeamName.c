void setTeamName(char *Team1,char *Team2)
{
    char Temp[16];
    printf("\n순서를 정하기 위해 윷을 처음 던질 팀의 이름을 입력해주세요 >");
    scanf("%s", Temp);
    strcpy(Team1, Temp);
    printf("\n순서를 정하기 위해 윷을 두 번째로 던질 팀의 이름을 입력해주세요 >");
    scanf("%s", Temp);
    strcpy(Team2, Temp);
}//need string T1, T2
