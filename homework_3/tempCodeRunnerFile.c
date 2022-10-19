#include<stdio.h>
int a1[100];
int a2[100];
int ch[100];
char s[100010];
int numn[200];
int main()
{
    int tmp=-1;
    for(int i=0;i<10;i++)
    {
        for(int k=1;k<=10;k++)
        {
            tmp++;
            a1[tmp]=i;
        }
    }
    tmp=-1;
    for(int i=0;i<10;i++)
    {
        for(int k=0;k<=9;k++)
        {
            tmp++;
            a2[tmp]=k;
        }
    }
   
    int n;
    char fei;
    scanf("%d%c",&n,&fei);
    for(int i=1;i<=n;i++)
    {
        scanf("%c",&s[i]);     
    }
    for(int i=1;i<=n;i++)
    {
        if(s[i]=='?'&&s[n-i+1]!='?')
        {
            s[i]=s[n-i+1];
    
        }
    }
    int cur=0;
    for(int i=1;i<=n/2;i++)
    {
        if(s[i]!='?')
        {
            printf("%c",s[i]);
        }
        else
        {
            cur++;
            for(int j=0;j<100;j++)
            {
                if(ch[j]!=1)
                {
                    numn[cur]=j;
                    ch[j]=1;
                    for(int kkk=0;kkk<100;kkk++)
                    {
                        if((a1[kkk]==a2[j])&&(a2[kkk]==a1[j]))
                        ch[kkk]=1;
                    }
                    break;;
                }
            }
            printf("%c%c",a1[numn[cur]]+48,a2[numn[cur]]+48);
        }
    }
    if(n%2==1)
    printf("%c",s[n/2+1]);
    for(int i=n/2;i>=1;i--)
    {
        if(s[i]!='?')
        {
            printf("%c",s[i]);
        }
        else
        {
           
            printf("%c%c",a2[numn[cur]]+48,a1[numn[cur]]+48);
            cur--;
        }
    }
    return 0;
}