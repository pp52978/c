#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
char s[1300];
typedef struct {
    enum {Int,Float,Operator,Vari}type;
    char str[32];
    union {
        int iVal;
        double fVal;
    } val;
} Token;
Token tokens[2000];
typedef struct {
    enum {
        INT,
        FLOAT,
        ERROR
    } type;
    union {
        int iVal;
        double fVal;
    } val;
} Value;
Value ans;
int pt_token = 0;
int chk_error = 0;
void Ma(int left, int right);
void Make_token(char *a);
Value Yst(int l,int r);
int FindOp(int l,int r);
int FindPri(int x);
void Upd(void);
int check_parent(int l,int r);

int main()
{
   freopen("tt.in","r",stdin);
    freopen("tt.out","w",stdout);
    while(gets(s)!=NULL)
    {
        chk_error=0;
        pt_token = 0;
        Make_token(s);
        printf("%d",check_parent(0,pt_token));
        if(chk_error==1)
        {
            printf("Error");
            continue;
        }
        if(chk_error==1)
        {
            printf("Error");
            continue;
        }
    }
    return 0;
}
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
int FindPri(int x){
    if(tokens[x].str[0]=='+'||tokens[x].str[0]=='-')
    return 0;
    else if(tokens[x].str[0]=='*'||tokens[x].str[0]=='/')
    return 1;
}
int FindOp(int l,int r)
{
    int pos = -1 ;
    int access=1;
    for(int i=l;i<=r;i++)
    {
        if(tokens[i].type!=Operator)
        continue;
        else{
            if(access==0)
            {
                if(tokens[i].str[0]==')')
                {
                    access=1;continue;
                }
                else{
                    continue;
                }
            }
            else{
                if(access==1)
                {
                    if(tokens[i].str[0]=='(')
                    {
                        access=0;continue;
                    }
                    else if(pos==-1)
                    {
                        pos=i;continue;
                    }
                    else
                    {
                        if(FindPri(i)<=FindPri(pos))
                        {
                            pos=i;
                            continue;
                        }
                    }
                }
            }
        }
    }
    return pos;
}
int check_parent(int l,int r){
    int top = 0;
    for(int i=0;i<pt_token;i++)
    {
        if(tokens[i].type==Operator)
        {
            if(tokens[i].str[0]=='(')
            top++;
            else if(tokens[i].str[0]==')')
            {
                if(top<1)
                {
                    chk_error=1;
                    return 0;
                }
                else 
                top--;
            }
        }
    }
    if(top!=0)
    {

        return 0;
    }
    else{
        if(tokens[0].type==Operator&&tokens[pt_token-1].type==Operator&&tokens[0].str[0]=='('&&tokens[pt_token-1].str[0]==')'&&(check_parent(l+1,r-1)!=0))
        {
            return 1;
        }
        else
        {
            return 2;
        }
    }

}
