#include<stdio.h>
int ans=0;
long long Vol[4];
long long init[4];
long long Tar[4];
int k;
void dfs(int k);
void pour(int a,int b);
int main()
{

    scanf("%d",&k);
    for(int i=1;i<=3;i++)
    scanf("%d",&Vol[i]);
    for(int i=1;i<=3;i++)
    scanf("%d",&init[i]);
    for(int i=1;i<=3;i++)    
    scanf("%d",&Tar[i]);
    if(init[1]==Tar[1]&&init[2]==Tar[2]&&init[3]==Tar[3])
    {
        ans=1;
    }
    dfs(k);
    if(ans==0)
    {
        printf("No");
    }
    else
    {
        printf("Yes");

    }
    return 0;
}
void dfs(int k)
{
   
    if(ans==1||k==0)
    {
        return ;
    }
    for(int i=1;i<=3;i++)
    {
        for(int j=1;j<=3;j++)
        {
            if(i!=j)
            {
                long long tmp1=init[1],tmp2=init[2],tmp3=init[3];
                pour(i,j);
                if(init[1]==Tar[1]&&init[2]==Tar[2]&&init[3]==Tar[3])
                {
                    ans=1;
                    return;
                }
                else
                {
                    dfs(k-1);
                }
                init[1]=tmp1;
                init[2]=tmp2;
                init[3]=tmp3;
            }
        }
    }
}
void pour(int a,int b)
{
    long long kk=Vol[b]-init[b];
    if(kk<init[a])
    init[b]=Vol[b];
    else
    init[b]+=init[a];
    init[a]=0;
}