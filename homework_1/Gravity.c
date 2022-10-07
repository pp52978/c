#include<stdio.h>
#include<math.h>
int main()
{
    const double g=6.674e-11,M=77.15;
    double m,r;
    scanf("%lf%lf",&m,&r);
    double ans;
    ans= g*m*M/pow(r,2);
    printf("%.3e",ans);
    return 0;
}