#include<stdio.h>
#include<math.h>
char cun[2051][1030];
void draw(int a,int b,int c);
int main()
{  
    int n;
    scanf("%d",&n);
    int h=pow(2,n);
    int len=pow(2,n+1);
    for(int i=1;i<=h;i++)
    {
        for(int j=1;j<=len;j++)
        {
            cun[i][j]=' ';
        }
    }
    int stan_x=len/2;
    int stan_y=1;
    draw(n,stan_y,stan_x);//if meet /n then continue to print
    for(int i=1;i<=h;i++)
    {
        for(int j=1;j<=len;j++)
        {
  
            printf("%c",cun[i][j]);
        }
        printf("\n");
    }
}
void draw(int a,int b,int c)
{
    if(a==1)
    {
        int tmpb=b;
        int tmpc=c;
        cun[tmpb][tmpc++]='/';
        cun[tmpb++][tmpc]='\\';
        cun[tmpb][c-1]='/';
        cun[tmpb][c]='_';
        cun[tmpb][c+1]='_';
        cun[tmpb][c+2]='\\';
    }
    else
    {
        draw(a-1,b,c);
        draw(a-1,b+pow(2,a-1),c-pow(2,a-1));
        draw(a-1,b+pow(2,a-1),c+pow(2,a-1));
    }
}