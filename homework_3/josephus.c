#include<stdio.h>
int sta[600];
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    int pe=n;
    int now=-1;
    int num=0;
    while(pe>1)
    {
        now=(now+1)%n;
        if(sta[now]==1)
        continue;
        else{
            num++;
            if(num%k==0)
            {
                sta[now]=1;
                pe--;
            }
        }


    }
    for(int i=0;i<=n-1;i++)
    {
        if(sta[i]==0)
        {
            printf("%d",i+1);
            break;
        }
    }
    return 0;
}