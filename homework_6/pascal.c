#include<stdio.h>
int Solve(int x,int y);
int main()
{
    int a,b;
    scanf("%d%d",&a,&b);
    printf("%lld",Solve(a,b));
    return 0;
}
int Solve(int x,int y)
{
    if(x==y||y==1)
    {
        return 1;
    }
    else
    {
        return Solve(x-1,y)+Solve(x-1,y-1);
    }
}