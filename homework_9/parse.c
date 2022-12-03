#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int pt=0;
void PutAns(char *AN,char *b){
    int len=strlen(b);
    strncpy(AN+pt,b,len);
    pt+=len;
}
int main()
{
    freopen("read.txt","r",stdin);
    freopen("ans.txt","w",stdout);
    char *a=malloc(141*sizeof(char));
    char *b=malloc(1500*sizeof(char));
    char *name=malloc(1500*sizeof(char));
    char *ans=malloc(15000*sizeof(char));
    char *tt=malloc(1500*sizeof(char));
    scanf("%s",a);
    scanf("%s",name);

    while(scanf("%s",b)!=EOF)
    {
        if(*b!='-')
        continue;
        else{
            if(strchr(a,*(b+1))==NULL)
            {
                printf("%s: invalid option -- '%c'",name,*(b+1));
                return 0;
            }
            else if(*(strchr(a,*(b+1))+1)!=':')
            {
                *(ans+pt)=*(b+1);
                pt++;
                *(ans+pt)='\n';
                pt++;

            }
            else if(*(strchr(a,*(b+1))+1)==':')
            {
                if(scanf("%s",tt)!=EOF)
                {
                    *(ans+pt)=*(b+1);
                    pt++;
                    *(ans+pt)='=';
                    pt++;
                    PutAns(ans,tt);
                    *(ans+pt)='\n';
                    pt++;
                }
                else{
                    printf("%s: option requires an argument -- '%c'",name,*(b+1));
                    return 0;
                }
            }
        }
    }
    *(ans+pt)='\0';
    printf("%s\n",name);
    printf("%s",ans);
    return 0;
}