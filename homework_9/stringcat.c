#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    int t;
    scanf("%d",&t);
    char *s1=malloc(1005*sizeof(char));
    char *s2=malloc(1005*sizeof(char));
    while(t>0)
    {
        t--;
        scanf("%s%s",s1,s2);
        int len1=strlen(s1);
        int len2=strlen(s2);
        int num = -4;
        for(int i=len2-1;i>=0;i--)
        {
            int check=1;
            if(len1-1-i<0)
            continue;
            else{
                for(int j=0;j<=i;j++)
                {
                    if(*(s2+j)==*(s1+len1-1-i+j))
                    continue;
                    else
                    {
                        check=0;
                        break;
                    }
                }
            }
            if(check==1)
            {
                num=i;
                break;
            }
    
        }
        if(num==-4)
        {
            printf("%s%s\n",s1,s2);
            continue;
        }
        else{
            printf("%s%s\n",s1,s2+num+1);
        }
    }
    free(s1);
    free(s2);
    return 0;
}