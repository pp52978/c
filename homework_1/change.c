#include<stdio.h>
int main()
{
    int a,ans50,ans20,ans10,ans5,ans1;
    scanf("%d",&a);
   
    ans50=a/50;
    a=a%50;
    ans20=a/20;
    a=a%20;
    ans10=a/10;
    a=a%10;
    ans5=a/5;
    a=a%5;
    ans1=a/1;
    printf("%d\n%d\n%d\n%d\n%d",ans50,ans20,ans10,ans5,ans1);
    return 0;
}