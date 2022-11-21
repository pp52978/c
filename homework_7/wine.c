#include<stdio.h>
int wi[10004][2];
int check[10004];
int main()
{
    int n,l;
    scanf("%d%d",&n,&l);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&wi[i][0]);

    }
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&wi[i][1]);

    }
    int ans=0;
    while(l>0)
    {
        int max=0;
        int wei;
        for(int i=1;i<=n;i++)
        {
            if(check[i]!=1&&wi[i][0]>=max)
            {
                max = wi[i][0];
                wei=i;
            }
        }
        check[wei]=1;
        if(wi[wei][1]<=l)
        {
            l-=wi[wei][1];
            ans+=wi[wei][1]*wi[wei][0];
        }
        else
        {
            ans+=wi[wei][0]*l;
            l=0;
        }
    }
    printf("%d",ans);
    return 0;
}