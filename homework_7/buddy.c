#include<stdio.h>
#include<math.h>
int now[33];
int cun[33][10005];
int n;
void Check(void);
int Huge(long long i);
void Put(int u,int id);
int main()
{
    int q;
    scanf("%d%d%c",&n,&q);
    cun[n][0]++;
    while(q!=0)
    {
        q--;
        char ch,rrr;
        int chushi=n;
        scanf("%c%c",&ch,&rrr);
        if(ch=='Q')
        {
            Check();
        }
        else if(ch=='A')
        {
            int id;
            long long b;
            scanf("%d%lld%c",&id,&b,&rrr);
            int num=Huge(b);
            Put(num,id);
        }
    }
    return 0;
}
void Check()
{
    int count=0;
    for(int i=0;i<=n;i++)
    {
        count+=cun[i][0];
    }
    printf("%d\n",count);
    for(int i=0;i<=n;i++)
    {
        for(int j=1;j<=cun[i][0];j++)
        {
            printf("%d ",cun[i][j]);
        }
    }
    printf("\n");
    return ;
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
void Put(int u,int id)
{
    while(now[u]==cun[u][0])
    {     
        int ff;
        for(int i=u+1;i<=n;i++)
        {
            if(now[i]<cun[i][0])
            {
                ff=i;
                break;
            }
        }
        cun[ff][0]--;
        cun[ff-1][0]+=2;

    }
    now[u]++;
    cun[u][now[u]]=id;
    return;
}




