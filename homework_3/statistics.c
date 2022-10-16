#include<stdio.h>
int c[200];
int main()
{
    int n;
    char tmp;
    scanf("%d%c",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%c",&tmp);
        c[tmp]++;
    }
    int max=0;
    for(int i= 65;i<=122;i++)
    {
        if(c[i]>max)
        max=c[i];
    }
    for(int t=max;t>=1;t--)
    {
        for(int i=97;i<=122;i++)
        {
            if(c[i]>=t)
            {
                printf("=");
                if(c[i-32]>=t)
                {
                    printf("= ");
                }
                else if(c[i-32]!=0)
                {
                    printf("  ");
                }
                else
                {
                    printf(" ");
                }
            }
            else if((c[i-32]>=t)&&c[i]!=0)
            {
                printf(" = ");
            }
            else if((c[i-32]!=0)&&c[i]!=0)
            {
                printf("   ");
            }
            else if((c[i-32]==0)&&c[i]!=0)
            {
                printf("  ");
            }
            else if((c[i]==0)&&(c[i-32]>=t))
            {
                printf("= ");
            }
            else if((c[i]==0)&&(c[i-32]!=0))
            {
                printf("  ");
            }
        }
        printf("\n");
    }
    int ch=0;
    for(int i=97;i<=122;i++)
    {
        if(ch==0)
        {
            if(c[i]!=0)
            {
                printf("-");
                if(c[i-32]!=0)
                {
                    printf("-");
                }
                ch++;
            }
            else if(c[i-32]!=0)
            {
                printf("-");
                ch++;
            }
            
        }
        else
        {
            if(c[i]!=0)
            {
                printf("--");
                if(c[i-32]!=0)
                {
                    printf("-");
                }

            }
            else if(c[i-32]!=0)
            {
                printf("--");
            }
        }
    }
    printf("\n");
    for(int i=97;i<=122;i++)
    {
        if(c[i]!=0)
        {
            printf("%c",i);
            if(c[i-32]!=0)
            {
                printf("%c ",i-32);
            }
            else
            {
                printf(" ");
            }
        }
        else if(c[i-32]!=0)
        {
            printf("%c ",i-32);
        }
    }
}