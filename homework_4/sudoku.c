#include<stdio.h>
int c[10][10];
int main()
{
  
    for(int i=1;i<=9;i++)
    {
        int ch1[10]={0};
        for(int j=1;j<=9;j++)
        {
            scanf("%d",&c[i][j]);
            ch1[c[i][j]]++;
        }
        for(int k=1;k<=9;k++)
        if(ch1[k]==0)
        {
            printf("NO");
            return 0;
        }
    }
    
    for(int i=1;i<=9;i++)
    {
        int ch2[10]={0};
        for(int j=1;j<=9;j++)
        {
            ch2[c[j][i]]++;
        }
        for(int k=1;k<=9;k++)
        if(ch2[k]==0)
        {
            printf("NO");
            return 0;
        }
    }
    for(int i=1;i<=7;i=i+3)
    {
        for(int j=1;j<=7;j=j+3)
        {
            int ch3[10]={0};
            for(int ii=0;ii<=2;ii++)
            {
                for(int jj=0;jj<=2;jj++)
                {
                    ch3[c[i+ii][j+jj]]++;
                }
            }
            for(int k=1;k<=9;k++)
            if(ch3[k]==0)
            {
                printf("NO");
                return 0;
            }
        }
    }
    printf("YES");
    return 0;

}