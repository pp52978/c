#include<stdio.h>
#include<math.h>
int main()
{
    long long xa,ya,xb,yb,xc,yc;
    scanf("%lld%lld%lld%lld%lld%lld",&xa,&ya,&xb,&yb,&xc,&yc);
    int x[4]={0,0,-1,1};
    int y[4]={1,-1,0,0};
    int bz;
    long long d=abs(xa-xb)+abs(ya-yb);
    long long ans;
    if(((xa==xb)&&(xb==xc)&&((ya-yc)*(yb-yc)<0))||((ya==yb)&&(yb==yc)&&((xa-xc)*(xb-xc)<0)))
    {
        ans = d+2;
        printf("%d\n",ans);
        if(xa==xb)
        {
            if(yb>ya)
            {
                printf("R");
                for(int i=1;i<=yb-ya;i++)
                {
                    printf("U");
                }
                printf("L");
            }
            else
            {
                printf("R");
                for(int i=1;i<=ya-yb;i++)
                {
                    printf("D");
                }
                printf("L");
            }
        }
        else
        {
            if(xb>xa)
            {
                printf("U");
                for(int i=1;i<=xb-xa;i++)
                {
                    printf("R");
                }
                printf("D");
            }
            else
            {
                printf("U");
                for(int i=1;i<=xa-xb;i++)
                {
                    printf("L");
                }
                printf("D");
            }
        }
 

    }
    
    else{
        ans = d;
        printf("%d\n",ans);
        if((xa==xc)||(yb==yc))
        {
            if(xb>=xa)
            {
                for(int i=1;i<=xb-xa;i++)
                {
                    printf("R");
                }
            }
            else
            {
                
                for(int i=1;i<=xa-xb;i++)
                {
                    printf("L");
                }
            }
            if(yb>=ya)
            {
                for(int i=1;i<=yb-ya;i++)
                {
                    printf("U");
                }
            }
            else
            {
                 for(int i=1;i<=ya-yb;i++)
                {
                    printf("D");
                }
            }
        }
        else{
             if(yb>=ya)
            {
                for(int i=1;i<=yb-ya;i++)
                {
                    printf("U");
                }
            }
            else
            {
                 for(int i=1;i<=ya-yb;i++)
                {
                    printf("D");
                }
            }
            if(xb>=xa)
            {
                for(int i=1;i<=xb-xa;i++)
                {
                    printf("R");
                }
            }
            else
            {
                
                for(int i=1;i<=xa-xb;i++)
                {
                    printf("L");
                }
            }


        }
    }

    
    return 0;
    

}