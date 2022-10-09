#include<stdio.h>
#include<math.h>
int ans [1000000]={0};

int main()
{
    int xa,ya,xb,yb,xc,yc;
    scanf("%d%d%d%d%d%d",&xa,&ya,&xb,&yb,&xc,&yc);
    int x[4]={0,0,-1,1};
    int y[4]={1,-1,0,0};
    while(xa!=xb||ya!=yb)
    {
        ans[0]++;
        int bz;
        int dis=10000000;
        for(int i=0;i<=3;i++)
        {
            if(((xa+x[i]!=xc)||(ya+y[i]!=yc))&&(abs(xb-xa-x[i])+abs(yb-ya-y[i])<dis))
            {
                dis=abs(xb-xa-x[i])+abs(yb-ya-y[i]);
                bz=i;
            }
           
        }
        xa+=x[bz];
        ya+=y[bz];
        ans[ans[0]]=bz;

    }
    printf("%d\n",ans[0]);
    for(int i=1;i<=ans[0];i++)
    {
        if(ans[i]==0)
        printf("U");
        else if(ans[i]==1)
        printf("D");
        else if(ans[i]==2)
        printf("L");
        else if(ans[i]==3)
        printf("R");
        
    }
    return 0;
    

}