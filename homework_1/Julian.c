#include<stdio.h>
#include<math.h>
int main()
{
    int year,month,d;
    scanf("%d%d%d",&year,&month,&d);
    int a = floor((14-month)/12.0);
    int y= year +4800 -a;
    int m=month +12*a-3;
    int ans=d + floor((153*m+2)/5.0) +365*y+y/4-y/100+y/400-32045;
    printf("%d",ans);

    return 0;
}