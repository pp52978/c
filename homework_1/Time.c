#include<stdio.h>
int main()
{
    char mon[10];
    char weekday[10];
    int day,year,hour,minute,second;

    scanf("%s%d%d%s%d%d%d",mon,&day,&year,weekday,&hour,&minute,&second);

    printf("%.3s %.3s %02d %02d:%02d:%02d %04d",weekday,mon,day,hour,minute,second,year);

    return 0;
}