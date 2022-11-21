#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define LEN 4500
int main()
{
    char *a=malloc(LEN*sizeof(*a));
    while(scanf("%s",a)!=EOF)
    {
        int l=strlen(a);
        if(*a>=97)
        {
            *a-=32;
        }
        for(int i=1;i<l;i++)
        {
            if(*(a+i)<97)
            {
                *(a+i)+=32;
            }
        }
        printf("%s ",a);
    }
    free(a);
    return 0;
}