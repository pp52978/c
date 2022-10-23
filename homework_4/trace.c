#include<stdio.h>
int m,n,x0,y;
char cun[52][52];
int vis[52][52];
int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};
void se(int aa,int bb)
{
    printf("%d %d\n",aa,bb);
    vis[aa][bb]=1;
    for(int i=0;i<=3;i++)
    {
        if(vis[aa+dx[i]][bb+dy[i]]==0&&cun[aa+dx[i]][bb+dy[i]]=='#')
        {
            se(aa+dx[i],bb+dy[i]);
            break;
        }
    }
}
int main()
{   
    int cnt=0;
    char g;
    scanf("%d%d%d%d%c",&n,&m,&x0,&y,&g);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            scanf("%c",&cun[i][j]);
            if(cun[i][j]=='#')
            {
                cnt++;
            }
        }
        getchar();
    }
    printf("%d\n",cnt);
    se(x0,y);
    return 0;
}