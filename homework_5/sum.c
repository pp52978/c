#include<stdio.h>
int main()
{
    int n,t;
    scanf("%d%d",&n,&t);
    int sum=0;
    int k=t;
    for(int i=1;i<=n;i++)
    {
        sum+=t;
        t=t*10+k;
    }
    printf("%d",sum);
    return 0;
}