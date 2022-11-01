#include<stdio.h>
#include<math.h>
int Reverse(int a);
int Check(int b);
int main()
{
    int n;
    scanf("%d",&n);

    int ans=0;
    for(int i=2;i<=n;i++)
    {
        if ((Check(i))&&(Check(Reverse(i))))
        {
            ans++;
        }
        
    }
    printf("%d",ans);
    return 0;
}
int Reverse(int a)
{
    int k=0;
    while(a!=0)
    {
        k=k*10+a%10;
        a=a/10;
    }
    return k;
}
int Check(int b)
{
    int flag = 1; 
    for (int i = 2; i*i<=b; i++) {
    if (b % i == 0) {
        flag = 0;
        break;
        }
    }
    return flag;
}