#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){
    char *p=malloc(15*sizeof(*p));
    char *q=malloc(1200*sizeof(*q));
    char *vari=malloc(1200*sizeof(vari));
    char *str=malloc(15*sizeof(*str));
    char tmp;
    freopen("data.in","r",stdin);
    freopen("output.out","w",stdout);
    scanf("%s",q);
    int len2=strlen(q);
    scanf("%s",p);
    printf("%s",p);
    int cnt=0;
    int cnt2=0;
    int cnt3=0;
    char tmp1;
    char tmp2;
    while(scanf("%s",vari)!=EOF){
        int len=strlen(vari);
            if(cnt2==0)//上一个字符串不是需要值的参数
                {if(*vari=='-')//若该变量为参数
            {   cnt=0;
                tmp1=*(vari+1);
                for(int i=0;i<len2;i++){//在解析规则中寻找该变量
                if(*(q+i)==*(vari+1)){
                    cnt+=1;//若找到,则参数数量加一
                if(*(q+1+i)!=':'){//若参数不需要值
                        *(str+cnt3)=*(vari+1);
                        cnt3++;
                        *(str+cnt3)='\n';
                        cnt3++;
                    }
                else{//若参数需要值
                        *(str+cnt3)=*(vari+1);
                        cnt3++;
                        tmp2=*(vari+1);
                        *(str+cnt3)='=';
                        cnt3++;
                        cnt2=1;
                    }}}
                if(cnt==0){break;}    
                }}
            else if(cnt2!=0)//如果上一个字符串是需要值的参数
            {
                for(int i=0;i<len;i++)
                {
                    *(str+cnt3)=*(vari+i);
                    cnt3++;
                }
                *(str+cnt3)='\n';
                cnt3+=1;
                cnt2=0;
            } 
            }
            *(str+cnt3-1)='\0';
            int i=0;
        if(cnt==0)
        {
            printf(": invalid option -- '%c'",tmp1);
            
        }    
        else if(cnt2!=0)
        {
            printf(": option requires an argument -- '%c'",tmp2);
        }
        else
        {
            printf("\n");
            while(*(str+i)!='\0')
        {
            printf("%c",*(str+i));
            i++;
        }
        }
return 0;
}
