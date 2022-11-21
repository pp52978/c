#include<stdio.h>
#include<string.h>

int main()
{
    char s[100004];
    char s1[100004];
    int t;
    scanf("%d",&t);
    for(int u=1;u<=t;u++)
    {

        int top=0;
        scanf("%s",s1);
        int j=strlen(s1);
        int jud=1;
        for(int i=0;i<j;i++)
        {
            if(s1[i]=='['||s1[i]=='('||s1[i]=='{')
            {
                top++;
                s[top]=s1[i];
            }
            else
            {
                if((s1[i]=='}'&&s[top]=='{')||(s1[i]==')'&&s[top]=='(')||(s1[i]==']'&&s[top]=='['))
                {
                    top--;
                }
                else
                {
                    jud=0;
                    break;
                }
            }
        }
        if(jud==1&&top==0)
        {
            printf("True\n");
        }      
        else
        {
            printf("False\n");
        }
    }
    return 0;
}