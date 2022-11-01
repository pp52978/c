#include<stdio.h>
#include<math.h>
int Change(int m,int n);
int Check(int x,int y);
int main()
{
    int p,q,r;
    scanf("%d%d%d",&p,&q,&r);
    for(int i=2;i<=40;i++)
    {
        if(Change(p,i)*Change(q,i)==Change(r,i)&&Check(p,i)&&Check(q,i)&&Check(r,i))
        {
            printf("%d",i);
            return 0;
        }

    }
    printf("0");
    return 0;

}
int Change(int m,int n){
    int k=0,w=0;
    while(m!=0)
    {
        k+=m%10*pow(n,w);
        m/=10;
        w++;
    }
    return k;
}
int Check(int x,int y)
{
    while(x!=0)
    {
        int tmp=x%10;
        if(tmp>=y)
        {
            return 0;
        }
        x/=10;
    }
    return 1;
}