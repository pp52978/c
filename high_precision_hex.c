#include<stdio.h>
#include<string.h>
char hex1[260],hex2[260];
int h1[260],h2[260];
int ans1[260],ans2[260];
char a1[260],a2[260];
int main()
{
    scanf("%s",hex1);
    scanf("%s",hex2);
    int len1=strlen(hex1);
    int len2=strlen(hex2);
    for(int i=0,j=len1-1;i<len1;i++,j--)
    {
        if(hex1[j]<='9')
        {
            h1[i]=hex1[j]-'0';
        }
        else{
            h1[i]=hex1[j]-'A'+10;
        }
    }
    for(int i=0,j=len2-1;i<len2;i++,j--)
    {
        if(hex2[j]<='9')
        {
            h2[i]=hex2[j]-'0';
        }
        else{
            h2[i]=hex2[j]-'A'+10;
        }
    }
    for(int i=0;i<len1;i++)
    {
        ans1[i]+=h1[i]+h2[i];
        ans1[i+1]=ans1[i]/16;
        ans1[i]%=16;
    }
    if(ans1[len1]!=0)
    {
        for(int i=len1;i>=0;i--)
        {
            if(ans1[i]<=9)
            {
                a1[len1-i]=ans1[i]+'0';
            }
            else{
                a1[len1-i]=ans1[i]-10+'A';
            }
        }
    }
    else
    {       
        for(int i=len1-1;i>=0;i--)
        {
            if(ans1[i]<=9)
            {
                a1[len1-1-i]=ans1[i]+'0';
            }
            else{
                a1[len1-1-i]=ans1[i]-10+'A';
            }
        }
    }
    printf("%s\n",a1);
    for(int i=0;i<len1;i++)
    {
        ans2[i]+=(h1[i]-h2[i]);
        if(ans2[i]<0)
        {
            ans2[i]+=16;
            ans2[i+1]--;
        }
    }
    int ans_len=len1;
    for(int i=ans_len-1;i>=1;i--)
    {
        if(ans2[i]==0)
        {
            ans_len--;
        }
        else{
            break;
        }
    }
    for(int i=ans_len-1;i>=0;i--)
        {
            if(ans2[i]<=9)
            {
                a2[ans_len-1-i]=ans2[i]+'0';
            }
            else{
                a2[ans_len-1-i]=ans2[i]-10+'A';
            }
        }
    printf("%s\n",a2);
    return 0;
}