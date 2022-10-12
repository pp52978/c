#include<bits/stdc++.h>
using namespace std;
int main()
{
    double m,n;
    cin>>n>>m;
    double ans=0;
    for(int i=0;i<=m-n;i++)
    {
        double tmp;
        tmp = 1/(n+i);
        tmp = tmp*tmp;
        tmp = tmp*(i+1);
        ans+=tmp;
    }
    cout<<ans;
    return 0;
}