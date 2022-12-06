#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
char s[1300];
typedef struct{
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
Value Wrong;
int pt_token = 0;
int chk_error = 0;
void Ma(int left, int right);
void Make_token(char *a);
Value Yst(int l,int r);
int FindOp(int l,int r);
int FindPri(int x);
void Upd(void);
int check_parent(int l,int r);
Value Super_yst(Value a,Value b,char c);
int main()
{
    freopen("tt.in","r",stdin);
    freopen("tt.out","w",stdout);
    while(gets(s)!=NULL)
    {
        Wrong.type=Value::ERROR;
        chk_error=0;
        pt_token = 0;
        Make_token(s);
        Upd();
        if(chk_error==1)
        {
            printf("Error");
            continue;
        }
        ans = Yst(0,pt_token-1);//后期改为Yst_Pxy()
        printf("%d\n",ans.val.iVal);
    }
    return 0;
}
void Ma(int left, int right)
{
    int len = right -left +1;
    if(len==1){
        if(s[left]=='+'||s[left]=='-'||s[left]=='*'||s[left]=='/'||s[left]=='('||s[left]==')'||s[left]=='=')
        {
            tokens[pt_token].type=Token::Operator;
            tokens[pt_token].str[0]=s[left];
            tokens[pt_token].str[1]='\0';
            pt_token ++;
            return;
        }
        else if((s[left]>=48)&&(s[left]<=57))
        {
            tokens[pt_token].type=Token::Int;
            tokens[pt_token].str[0]=s[left];
            tokens[pt_token].str[1]='\0';
            pt_token++;
            return;
        }
        else if(((s[left]>=65)&&(s[left]<=90))||((s[left]>=97)&&(s[left]<=122))||(s[left]=='_'))
        {
            
            tokens[pt_token].type=Token::Vari;
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
                tokens[pt_token].type=Token::Int;
                else if(cnt==1)
                tokens[pt_token].type=Token::Float;
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
            tokens[pt_token].type=Token::Vari;
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
void Upd(void){
    for(int i=0;i<pt_token;i++)
    {
        tokens[i].val.iVal=0;
        tokens[i].val.fVal=0;
        if(tokens[i].type==Token::Int)
        {
            int len = strlen(tokens[i].str);
            for(int k=0;k<len;k++)
            {
                tokens[i].val.iVal+=(tokens[i].str[k]-48)*pow(10,len-1-k);
            }
        }
        else if(tokens[i].type==Token::Float)
        {
            int len = strlen(tokens[i].str);
            int pos;
            for(int k=0;k<len;k++)
            {
                if(tokens[i].str[k]=='.')
                {
                    pos = k;
                    break;
                }
            }
            for(int k=0;k<pos;k++)
            {
                tokens[i].val.fVal+=(tokens[i].str[k]-48)*pow(10,pos-1-k);
            }
            for(int k=pos+1;k<len;k++)
            {
                tokens[i].val.fVal+=(tokens[i].str[k]-48)*pow(10,(-1)*(k-pos));
            }
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
    int access=0;
    for(int i=l;i<=r;i++)
    {
        if(tokens[i].type!=Token::Operator)
        continue;
        else{
            if(access!=0)
            {
                if(tokens[i].str[0]==')')
                {
                    access--;continue;
                }
                else if(tokens[i].str[0]=='(')
                {
                    access++;continue;
                }
                else{
                    continue;
                }
            }
            else{
                if(access==0)
                {
                    if(tokens[i].str[0]=='(')
                    {
                        access++;continue;
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
        if(tokens[i].type==Token::Operator)
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
        if(tokens[l].type==Token::Operator&&tokens[r].type==Token::Operator&&tokens[l].str[0]=='('&&tokens[r].str[0]==')')
        {
            return 1;
        }
        else
        {
            return 2;
        }
    }

}
Value Super_yst(Value a,Value b,char c){
    Value anss;
    if(a.type==Value::ERROR||b.type==Value::ERROR)
    {
        return Wrong;
    }
    else {
        int ia,ib;
        double fa,fb;
        if(a.type==Value::INT&&b.type==Value::INT)
        {
            ia=a.val.iVal;
            ib=b.val.iVal;
            anss.type=Value::INT;
            if(c=='+')
            {
                anss.val.iVal=ia+ib;
                return anss;
            }
            else if(c=='-')
            {
                anss.val.iVal=ia-ib;
                return anss;
            }
            else if(c=='*')
            {
                anss.val.iVal=ia*ib;
                return anss;
            }
            else if(c=='/')
            {
                anss.val.iVal=ia/ib;
                return anss;
            }
        }
        else{
            if(a.type==Value::INT)
            fa=a.val.iVal;
            else
            fa=a.val.fVal;
            if(b.type==Value::INT)
            fb=b.val.iVal;
            else
            fb=b.val.fVal;
            anss.type=Value::FLOAT;
            if(c=='+')
            {
                anss.val.fVal=fa+fb;
                return anss;
            }
            else if(c=='-')
            {
                anss.val.fVal=fa-fb;
                return anss;
            }
            else if(c=='*')
            {
                anss.val.fVal=fa*fb;
                return anss;
            }
            else if(c=='/')
            {
                anss.val.fVal=fa/fb;
                return anss;
            }
        }       
    }
}
Value Yst(int l,int r)
{

    if(l>r||l<0||r>=pt_token)
    {
        return Wrong;//??存疑
    }
    else if(l==r)
    {
        Value para;
        if(tokens[l].type==Token::Int)
        {
            para.type=Value::INT;
            para.val.iVal=tokens[l].val.iVal;
        }
        else if(tokens[l].type==Token::Float)
        {
            para.type=Value::FLOAT;
            para.val.fVal=tokens[l].val.fVal;
        }
        else if (tokens[l].type==Token::Operator)
        {
            para.type=Value::ERROR;
        }
        
        //else if(tokens[l].type==Vari)

        return para;
    }
    else if(check_parent(l,r)==0)
    {
        chk_error=1;
        return Wrong;//??
    }
    else if(check_parent(l,r)==1&&check_parent(l+1,r-1)!=0)
    {


        return Yst(l+1,r-1);
    }
    else
    {
        int op = FindOp(l,r);//运算四则
        if(op==-1)
        {
            chk_error=1;
            return Wrong;
        }
        Value val1 = Yst(l, op - 1);
        Value val2 = Yst(op + 1, r);
        Value ans1= Super_yst(val1,val2,tokens[op].str[0]);
        return ans1;
    }


}