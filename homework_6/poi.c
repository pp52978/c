#include<stdio.h>
int cun[100004];
int find(int x);
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&cun[i]);
    }
    
    for(int i=1;i<=n;i++)
    {
        printf("%d ",find(i));
    }
    return 0;
}
int find(int x)
{
    if(cun[x]==x)
    return x;
    else
    {
     return find(cun[x]);
    }
}