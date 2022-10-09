#include <stdio.h>
int re[1000005]={0};
int main()
{

    int n;
    int tmp;
    scanf("%d",&n);
    for(int i=1;i<=2*n-1;i++ )
    {

        scanf("%d",&tmp);
        re[tmp]++;
    }
    for (int i=1;i<=1000003;i++)
    {
        if (re[i] == 1){
            printf("%d",i);
            break;
        }

    }
    return 0;
}