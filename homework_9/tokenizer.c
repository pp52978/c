#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int check=1;
int pt=0;
void PutAns(char *AN,char *b){
    int len=strlen(b);
    strncpy(AN+pt,b,len);
    pt+=len;
    *(AN+pt)=' ';
    pt++;
}
void process(char *S,char *AN)
{
    int len=strlen(S);
    if(strcmp(S,"const")*strcmp(S,"int")*strcmp(S,"float")*strcmp(S,"double")*strcmp(S,"long")*strcmp(S,"static")*
    strcmp(S,"void")*strcmp(S,"char")*strcmp(S,"extern")*strcmp(S,"return")*strcmp(S,"break")*strcmp(S,"enum")*
    strcmp(S,"struct")*strcmp(S,"typedef")*strcmp(S,"union")*strcmp(S,"goto")==0)
        {
            PutAns(AN,"reserved");
            return;
        }
    else if(strcmp(S,"+")*strcmp(S,"-")*strcmp(S,"*")*strcmp(S,"/")*strcmp(S,"=")*strcmp(S,"==")*
    strcmp(S,"!=")*strcmp(S,">=")*strcmp(S,"<=")*strcmp(S,">")*strcmp(S,"<")==0)
        {
            PutAns(AN,"operator");
            return;
        }
    else if((*S>=65&&*S<=90)||(*S>=97&&*S<=122)||*S==95)
        {
            int ch=1;
            for(int i=1;i<len;i++)
            {
                if(!((*(S+i)==95)||(*(S+i)>=65&&*(S+i)<=90)||(*(S+i)>=97&&*(S+i)<=122)||(*(S+i)>=48&&*(S+i)<=57)))
                {
                    ch=0;
                }
            }
            if(ch==0)
            {
                check=0;
                return;
            }
            else if(ch==1)
            {
                PutAns(AN,"variable");
                return;
            }
        }
    else if(*S>=48&&*S<=57) //判断浮点和整
    {
        int num = 0,chk=1;
        for(int i=1;i<len;i++)
        {
            if(*(S+i)>=48&&*(S+i)<=57)
            continue;
            else if(*(S+i)=='.')
            {
                num++;
            }
            else{
                chk=0;
                break;
            }
        }
        if(chk==0||num>=2)
        {
            check=0;
            return;
        }
        else if(num==0)
        {
            PutAns(AN,"integer");
            return;
        } 
        else if(num==1)
        {
            PutAns(AN,"float");
            return;
        }
    } 
    else if(*S=='.')
    {
        int  chk=1;
        for(int i=1;i<len;i++)
        {
            if(!(*(S+i)>=48&&*(S+i)<=57))
            {
                chk=0;
                break;
            }
        }
        if(chk==1)
        {
            PutAns(AN,"float");
        }
        else if(chk==0)
        {
            check=0;
            return;
        }
    } 
    else if(*S==';')
    {
        *(AN+pt)='\n';
        pt++;
    }
    else{
        check=0;
        return;
    } 
    
}
int main()
{
    freopen("te.txt","r",stdin);
    freopen("tm.txt","w",stdout);
    char *new1=(char*)malloc(10000*sizeof(char));
    char *s = (char*)malloc(10000*sizeof(char));
    char *ans = (char*)malloc(100000*sizeof(char));
    while(check==1&&scanf("%s",s)!=EOF)
    {
        char *pos=strchr(s,';');
        if(pos==NULL)process(s,ans);
        else{
            
            strncpy(new1,s,pos-s);
            *(new1+(pos-s))='\0';
            if(*new1!='\0')
            process(new1,ans);
            *(ans+pt)='\n';
            pt++;
            strcpy(new1,pos+1);
            if(*new1!='\0')
            process(new1,ans);// 分割前半部分要加\0,换行需要单独

        }
    }
    *(ans+pt)='\0';
    if(check==0)
    {
        printf("Compile Error");
    }
    else
    {
        printf("%s",ans);
    }

    free(s);
    free(ans);
    free(new1);   
    return 0;
}