#include<stdio.h>
#include<math.h>
const double d=1e-4;
int p;
int c[23];
double f1(double x,int n);
double Solve(double x,double y,int n,double s);
double S1(double x,double y,int n);

int main()
{
    int n;
    scanf("%d%d",&n,&p);

    for(int i=0;i<=n;i++)
    scanf("%d",&c[i]);
    double a,b;
    scanf("%lf%lf",&a,&b);
    double ans=Solve(a,b,n,d);
    printf("%lf",ans);
}
double f1(double x,int n)
{
    double k=c[0];
    for(int i=1;i<=n;i++)
    {
        k+=c[i]*pow(x,i);
    }
    double yy=pow(k,p);
    return yy;
}
double S1(double x,double y,int n){
    double k;
    double mid=(x+y)/2.0;
    k=(4*f1(mid,n)+f1(x,n)+f1(y,n))/6.0*(y-x);
    return k;
}
double Solve(double x,double y,int n,double s)
{
    double mid=(x+y)/2.0;
    double S,SL,SR;
    S=S1(x,y,n);
    SL=S1(x,mid,n);
    SR=S1(mid,y,n);
    if((SL+SR-S<=15*s)&&(SL+SR-S>=-15*s))
    {
        return SL+SR+(SL+SR-S)/15.0;
    }
    else
    {
        return(Solve(x,mid,n,s/2.0)+Solve(mid,y,n,s/2.0));
    }
}
