#include<stdio.h>
int cun[2005];
int Find(int x[],int len);
int Find1(int x[],int len,int v);
void Reverse(int x[],int k,int p);
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&cun[i]);

    }
    int w=Find(cun,n);
    int kk=Find1(cun,n,cun[n-w]);
    int tmp=cun[n-w];
    cun[n-w]=cun[kk];
    cun[kk]=tmp;
    Reverse(cun,n,w);
    for(int i=1;i<=n;i++)
    {
        printf("%d ",cun[i]);
    }
    return 0;
}
int Find(int x[],int len)
{
    int tp=1;
    for(int i=len-1;i>=1;i--)
    {
        if(x[i]>x[i+1])
        {
            tp++;
        }
        else{
            return tp;
        }

    }
}
int Find1(int x[],int len,int v)
{
    for(int i=len;i>=1;i--)
    {
        if(x[i]>v)
        {
            return i;
        }
    }
}
void Reverse(int x[],int k,int p)
{
    for(int i=k;i>(2*k-p+1)/2;i--)
    {
        int tmp=x[i];
        x[i]=x[2*k-p+1-i];
        x[2*k-p+1-i]=tmp;
    }
}