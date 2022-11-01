#include<stdio.h>
int c[1005][1005];
void put1(int x,int k[][1005],int len);
int main()
{
    int n;
    scanf("%d",&n);
    c[1][n/2+1]=1;
    c[0][0]=1;
    c[0][1]=n/2+1;
    for(int i=2;i<=n*n;i++)
    {
        put1(i,c,n);
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            printf("%d ",c[i][j]);
        }
        printf("\n");
    }
    return 0;
}
void put1(int x,int k[][1005],int len)
{
    int tmp1,tmp2;
    if(k[0][0]==1)
    {
        tmp1=len;
    }
    else
    tmp1=k[0][0]-1;
    if(k[0][1]==len)
    {
        tmp2=1;
    }
    else
    tmp2=k[0][1]+1;
    if(k[tmp1][tmp2]!=0)
    {
        if(k[0][0]+1==len+1)
        {
            k[0][0]=1;
        }
        else
        k[0][0]++;
        
    }
    else
    {
        k[0][0]=tmp1;
        k[0][1]=tmp2;
    }
    k[k[0][0]][k[0][1]]=x;

}