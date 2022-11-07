#include<stdio.h>
long long pp[100009];
int ans[100009][2];
void do1(int a,int b);
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&pp[i]);

    }
    do1(1,n);
    for(int i=1;i<=n;i++)
    {
        printf("%d %d\n",ans[i][0],ans[i][1]);
    }
    return 0;
}
void do1(int a,int b)
{
    long long tmp=0;
    int sta=0;
    for(int i=a;i<=b;i++)
    {
        if(pp[i]>tmp){
        tmp=pp[i];
        sta=i;
        }
    }
    ans[sta][0]=a;
    ans[sta][1]=b;
    if(sta-1>=a)
    do1(a,sta-1);
    if(sta+1<=b)
    do1(sta+1,b);
}