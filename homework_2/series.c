#include<stdio.h>
#include<math.h>
int main()
{
    double x;
    int n;
    scanf("%lf%d",&x,&n);
    double ans=0;
    for (int i=0;i<=n;i++)
    {
        ans+=(pow(-1,i)*pow(x,2*i+1))/(2*i+1);
    }
    ans*=4;
    printf("%.10f",ans);
    return 0;
}