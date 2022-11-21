#include<stdio.h>
char aa[100][100];
void do1(int y,int x,int z);
void do2(int y,int x,int z);
void do3(int y,int x,int z);
int main()
{
    int t;
    scanf("%d",&t);
    for(int q=1;q<=t;q++)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        for(int i=1;i<=2*(a+b)+1;i++)
        {
            for(int j=1;j<=2*(b+c)+1;j++)
            aa[i][j]=' ';
        }
        for(int i=1;i<=2*c+1;i=i+2)
        {
            do1(i,1,a);//前面+-
        }
        for(int i=2;i<=2*c;i=i+2)
        {
            do2(i,1,a);//前面|
        }
        int st=2;
        for(int i=1;i<=2*b-1;i=i+2)
        {
            do3(2*c+1+i,st,a);//上面/
            st=st+2;
        }
        st=3;
        for(int i=2;i<=2*b;i=i+2)
        {
            do1(2*c+1+i,st,a);
            st=st+2;
        }
        st=2;
        for(int i=2*a+2;i<=2*a+2*b;i=i+2)
        {
            for(int j=st;j<=st+2*(c-1);j+=2)
            {
                aa[i][j]='/';
            }
            st+=2;
        }
        st=3;
        for(int i=2*a+3;i<=2*a+2*b+1;i=i+2)
        {
            for(int j=st;j<=st+2*(c-1);j+=2)
            {
                aa[i][j]='+';
                aa[i][j+1]='|';
            }
            st+=2;
        }
        for(int j=2*(b+c)+1;j>=1;j--)
        {
            for(int i=1;i<=2*(a+b)+1;i++)
            {
                printf("%c",aa[i][j]);
            }
            printf("\n");
        }


    }
    return 0;
    
}
void do1(int y,int x,int z)
{
    int t=x;
    for(int i=1;i<=z+1;i++)
    {
        aa[t][y]='+';
        t=t+2;
    }
    t=x+1;
    for(int i=1;i<=z;i++)
    {
        aa[t][y]='-';
        t=t+2;
    }
}
void do2(int y,int x,int z)
{
    for(int i=1;i<=z+1;i++)
    {
        aa[x][y]='|';
        x=x+2;
    }
}
void do3(int y,int x,int z)
{
    for(int i=1;i<=z+1;i++)
    {
        aa[x][y]='/';
        x=x+2;
    }
}