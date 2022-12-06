#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
char s[1300];
typedef struct{
    enum {Int,Float,Operator,Vari}type;
    char str[32];
} Token;
Token tokens[2000];
int pt_token = 0;
int chk_error = 0;
void Ma(int left, int right)
{
    int len = right -left +1;
    if(len==1){
        if(s[left]=='+'||s[left]=='-'||s[left]=='*'||s[left]=='/'||s[left]=='('||s[left]==')'||s[left]=='=')
        {
            tokens[pt_token].type=Operator;
            tokens[pt_token].str[0]=s[left];
            tokens[pt_token].str[1]='\0';
            pt_token ++;
            return;
        }
        else if((s[left]>=48)&&(s[left]<=57))
        {
            tokens[pt_token].type=Int;
            tokens[pt_token].str[0]=s[left];
            tokens[pt_token].str[1]='\0';
            pt_token++;
            return;
        }
        else if(((s[left]>=65)&&(s[left]<=90))||((s[left]>=97)&&(s[left]<=122))||(s[left]=='_'))
        {
            
            tokens[pt_token].type=Vari;
            tokens[pt_token].str[0]=s[left];
            tokens[pt_token].str[1]='\0';
            pt_token++;
            return;
        }
        else
        {
            chk_error =1;
            return;
        }
    }
    else if(len !=1)
    {
        if((s[left]>=49)&&(s[left]<=57))//第一位是数，且非0
        {
            int cnt = 0;//'.'的次数
            for(int i=1;i<=len-1;i++)
            {
                if((s[left+i]>=48)&&(s[left+i]<=57))
                continue;
                else if(s[left+i]=='.'&&left+i<right&&(s[left+i+1]>=48)&&(s[left+i+1]<=57))
                {
                    cnt++;
                    if(cnt>1)
                    {
                        chk_error=1;
                        break;
                    }
                }
                else
                {
                    chk_error=1;
                    break;
                }
            }
            if(chk_error==1)
            {
                return;
            }
            else
            {
                if(cnt==0)
                tokens[pt_token].type=Int;
                else if(cnt==1)
                tokens[pt_token].type=Float;
                for(int k=0;k<len;k++)
                {
                    tokens[pt_token].str[k]=s[left+k];
                }
                tokens[pt_token].str[len]='\0';
                pt_token++;
                return;
                
            }
        }
        else if(((s[left]>=65)&&(s[left]<=90))||((s[left]>=97)&&(s[left]<=122))||(s[left]=='_'))
        {
            tokens[pt_token].type=Vari;
            for(int k=0;k<len;k++)
            {
                tokens[pt_token].str[k]=s[left+k];
            }
            tokens[pt_token].str[len]='\0';
            pt_token++;
            return;
        }
        else
        {
            chk_error=1;
            return;
        }
   
    }
}
void Make_token(char *a)
{
    int len_1=strlen(a);
    char tmp[32];
    int t_l=0,t_r=0;
    while(1)
    {
        if(t_r==len_1-1)
        {
            Ma(t_l,t_r);          
            break;
        }
        else if(a[t_r+1]==' ')
        {
            Ma(t_l,t_r); 
            if(t_r+2>=len_1)
            break;
            else{
                t_l=t_r+2;
                t_r+=2;
            }
        }
        else
        {
            t_r++;
        }
    }

}
int main()
{
    freopen("tt.in","r",stdin);
    freopen("tt.out","w",stdout);
    while(gets(s)!=NULL)
    {
        chk_error=0;
        pt_token = 0;
        Make_token(s);
        if(chk_error==1)
        {
            printf("Error\n");
            continue;
        }
        for(int i=0;i<pt_token;i++)
        {
            printf("%d ",tokens[i].type);
        }
        printf("\n");
        
    }
    return 0;
}