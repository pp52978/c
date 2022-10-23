#include<stdio.h>
char c[102][102];
int x[8]={-1,0,1,1,1,0,-1,-1};
int y[8]={1,1,1,0,-1,-1,-1,0};
int main()
{   
    int n;
    char g;
    scanf("%d%c",&n,&g);
    for(int i=1;i<=n;i++)
    {
        for(int k=1;k<=n;k++)
        {
            scanf("%c",&c[i][k]);
        }
        char kk;
        scanf("%c",&kk);
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(c[i][j]=='o')
            {
                int cnt=0;
                for(int m=0;m<8;m++)
                {
                    if(c[i+x[m]][j+y[m]]=='*')
                    cnt++;
                }
                c[i][j]=cnt+48;
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            printf("%c",c[i][j]);
        }
        printf("\n");
    }
    return 0;
   

}