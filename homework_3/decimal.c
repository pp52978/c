#include<stdio.h>
#include<math.h>
char cun[40];
int main()
{
    int n,len;
    char f;
    scanf("%d%d%c",&len,&n,&f);
    char y[17]={'0','0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
    for(int i=1;i<=len;i++)
    {
        scanf("%c",&cun[i]);
        if(cun[i]>y[n])
        {
            printf("Error");
            return 0;
        }
    }
    int ans = 0;
    for(int i=len;i>=1;i--)
    {
        int tp;
        if(cun[i]<='9')
        {
            tp=cun[i]-'0';
        }
        else
        {
            tp=cun[i]-'A'+10;
        }
        ans += tp*pow(n,len-i);
    }
    printf("%d",ans);
    return 0;
}