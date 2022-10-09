#include<stdio.h>
const int M=10007;
int main()
{
    int n;
    scanf("%d",&n);
    int ans = 0;
    for (int i=1; i<=n; i++)
    {
        int a=1;
        for(int k=1; k<=i; k++)
        {
            a*=k;
            a%=M;

        }
        ans +=a;
        ans%=M;
    }
    printf("%d",ans);
    return 0;

}