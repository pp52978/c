#include<stdio.h>
int cun[1000005];
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&cun[i]);

    }
    int l=0,r=n+1;
    int cc=cun[k];
    while(l!=r)
    {
        int ch_1=0;
        while(ch_1==0)
        {
            l++;
            if(l==r||cun[l]>=cc)
            ch_1=1;
        }
        if(l==r)
        {break;}
        int ch_2=0;
        while(ch_2==0)
        {
            r--;
            if(r==l||cun[r]<cc)
            ch_2=1;
        }
        int tmp=cun[l];
        cun[l]=cun[r];
        cun[r]=tmp;

    
    }
    int upd;
    for(int i=1;i<=n;i++)
    {
        if (cun[i]==cc)
        upd=i;
    }
    if((l<upd&&cun[l]>cc)||(l>upd&&cun[l]<cc))
    {
        int tmp=cun[l];
        cun[l]=cun[upd];
        cun[upd]=tmp;
    }
    for(int i=1;i<=n;i++)
    printf("%d ",cun[i]);
    return 0;

}