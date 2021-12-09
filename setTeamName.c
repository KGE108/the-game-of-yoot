void setTeamName(char *Team1,char *Team2)
{
    char Temp[16];
    printf("\nSet Team1 Name >");
    scanf("%s", Temp);
    strcpy(Team1, Temp);
    printf("\nSet Team2 Name >");
    scanf("%s", Temp);
    strcpy(Team2, Temp);
}//need string T1, T2