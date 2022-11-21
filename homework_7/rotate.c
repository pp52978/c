#include<stdio.h>
int main()
{
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    int s[2]={0,0};
    char t;
    while(scanf("%c",&t)!=EOF)
    {
        if(t=='W')
        {
            s[0]-=c;
            int tmp=c;
            c=a;
            a=tmp;
        }
        else if (t=='A')
        {
            s[1]-=c;
            int tmp=c;
            c=b;
            b=tmp;
        }
        else if(t=='S')
        {
            s[0]+=a;
            int tmp=c;
            c=a;
            a=tmp;
        }
        else if(t=='D')
        {
            s[1]+=b;
            int tmp=c;
            c=b;
            b=tmp;
        }

        
    }
    printf("%d %d %d %d",s[0],s[0]+a,s[1],s[1]+b);
    return 0;
}