#include<stdio.h>
int Search(int x);
int main()
{
    int n;
    scanf("%d",&n);
    int ans = Search(n);
    printf("%d",ans);
    return 0;
}
int Search(int x)
{
    if(x==1)
    {
        return 1;
    }
    else if(x==2)
    {
        return 2;
    }
    else{
        return Search(x-1)+Search(x-2);
    }
}