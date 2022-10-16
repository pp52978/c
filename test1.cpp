#include<bits/stdc++.h>
using namespace std;
int main()
{
    bool status[20];
    for(int i=0;i<=20;i++)
    status[i]=1;
    int pxy = 20,now=-1;
    int yst = 0;
    while(pxy>1)
    {
        now=(now+1)%20;
        if(status[now]==0)
        continue;
        else
        {
            yst++;
            if(yst%3==0)
            {
                status[now]=0;
                pxy--;
                cout<<now<<' ';
            }
        }
    }
    return 0;
}