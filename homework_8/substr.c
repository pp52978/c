#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define LEN 100005
int main()
{
    char *s=malloc(LEN*sizeof(*s));
    char *t=malloc(LEN*sizeof(*t));
    scanf("%s%s",s,t);
    int len_a= strlen(s);
    int len_b= strlen(t);
    for(int i=0;i<len_a;i++)
    {
        if(*(s+i)==*(t))
        {
            int check =1 ;
            for(int k=1;k<len_b;k++)
            {
                if(i+k>=len_a)
                {
                    check= 0;
                    break;
                }
                else
                {
                    if(*(s+i+k)!=*(t+k))
                    {
                        check =0;
                        break;
                    }
                }
            }
            if(check==1)
            {
                printf("%d ",i);
            }
        }
    }
    free(s);
    free(t);
    return 0;
}