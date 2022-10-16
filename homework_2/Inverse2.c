#include<stdio.h>
char t[10000007];
char kk[10000007];
int main()
{
    int n,k;
    scanf("%d%c",&n);
    for(int i=0;i<=n-1;i++)
    scanf("%c",&t[i]);
    scanf("%d",&k);
    
    for(int i=k-1;i>=0;i--)
    kk[k-1-i]=t[i];
    for(int i=n-1;i>=k;i--)
    kk[n-1-i+k]=t[i];
    for(int i=0;i<=n-1;i++)
    printf("%c",kk[i]);
    return 0;

}