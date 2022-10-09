#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int ans = 0;
    int max = n;
    while(n!=1)
    {
        if(n%2==0)
        {
            ans++;
            n=n/2;
        }
        else{
            ans++;
            n=3*n+1;
            if(n>max)
            {
                max = n;
            }
        }
    }
    printf("%d %d",ans ,max);
    return 0;
}