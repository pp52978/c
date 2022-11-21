#include<stdio.h>
#include<math.h>
int lian[100000][4];//0为大小，1为id，2为后驱,lian[0][0]记录容量
int n;
int Huge(long long i);
int main()
{
    int q;
    char rrr;
    scanf("%d%d%c",&n,&q,&rrr);
    lian[1][0]=n;
    lian[0][0]=1;
    while(q!=0)
    {
        q--;
        char ch,rrr;
        int chushi=n;
        scanf("%c%c",&ch,&rrr);
        
        if(ch=='Q')
        {
            printf("%d\n",lian[0][0]);
            int search=1;
            while(search!=0)
            {
                printf("%d ",lian[search][1]);
                search=lian[search][2];
            }
            printf("\n");
        }
        else if(ch=='A')
        {
            int id;
            long long b;
            scanf("%d%lld%c",&id,&b,&rrr);
            int num=Huge(b);
            int search=1;
            int Iff=0;

            while(search!=0)
            {
                if(lian[search][0]==num&&lian[search][1]==0)
                {
                    lian[search][1]=id;
                    Iff=1;
                    break;
                }
                search=lian[search][2];
            }
            while(Iff==0)
            {
                int fir;
                search=1;
                while(search!=0)
                {
                    if(lian[search][0]>num&&lian[search][1]==0)
                    {
                        fir=search;
                        break;
                    }
                    search=lian[search][2];
                }
                lian[0][0]++;
                lian[lian[0][0]][2]=lian[fir][2];
                lian[fir][0]--;
                lian[lian[0][0]][0]=lian[fir][0];
                lian[fir][2]=lian[0][0];
                search =1;
                while(search!=0)
                {
                    if(lian[search][0]==num&&lian[search][1]==0)
                    {
                        lian[search][1]=id;
                        Iff=1;
                        break;
                    }
                    search=lian[search][2];
                }
            }
        }
    }
    
}
int Huge(long long i)
{
    if (i==1)
    return 0;
    else
    {
        for(int k=0;k<n;k++)
        {
            if(i>pow(2,k)&&i<=pow(2,k+1))
            return k+1;
        }
    }
}