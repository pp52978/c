#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
void process(char *m,char *ans);
int n=0;
int error=0;
int main(){
    freopen("data.in","r",stdin);
    freopen("o.out","w",stdout);
    int tt=0;
    char *ans=malloc(10000*sizeof(char));
    int *number=malloc(1000*sizeof(int));
    char *a=malloc(100*sizeof(char));    
    while(scanf("%s",a)!=EOF){
        int x=strlen(a);
        char *position=strchr(a,';');
        if(position==NULL){
            process(a,ans);
        }
        if(position!=NULL){
            char *b=malloc(100*sizeof(char));
            char *c=malloc(100*sizeof(char));   
            int index;
            for(int i=0;i<x;i++){
                if(*(a+i)==';'){
                    index=i;
                    break;
                }
            }         
            int num=0;
            for(int i=0;i<index;i++){
                *(b+i)=*(a+i);
            }
            *(b+index)='\0';
            for(int i=index+1;i<x;i++){
                *(c+num)=*(a+i);
                num++;
            }
            *(c+num)='\0';
            if(x==1){
                n--;
                *(number+tt)=n-1;tt++;
            }
            else if(index!=0&&index!=x-1){
                process(b,ans);
                n--;
                *(number+tt)=n-1;tt++;
                process(c,ans);
            }
            else if(index==0){
                n--;
                *(number+tt)=n-1;tt++;
                process(c,ans);
            }
            else if(index==x-1){
                process(b,ans);
                n--;
                *(number+tt)=n-1;tt++;
            }
            free(b);
            free(c);
        }
    }
    tt=0;
    if(error==0){
        for(int i=0;i<n;i++){
            printf("%c",*(ans+i));
            if(i==*(number+tt)){
                printf("\n");
                tt++;
            }
    }    
    }
    else if(error==1){
        printf("Compile Error");
    }       
    free(a);
    free(ans);
    return 0;
}
void process(char *m,char *ans){
        int x=strlen(m);
        int y=0;
        int o=0;
        int p=0;
        for(int i=0;i<x;i++){
            if(*(m+i)=='0'||*(m+i)=='1'||*(m+i)=='2'||*(m+i)=='3'||*(m+i)=='4'||*(m+i)=='5'||*(m+i)=='6'||*(m+i)=='7'||*(m+i)=='8'||*(m+i)=='9'){
                y++;
            }
        }
        for(int i=0;i<x;i++){
            if(*(m+i)>=97&&*(m+i)<=122){
                o++;
            }
            else if(*(m+i)<=90&&*(m+i)>=65){
                o++;
            }
            else if(*(m+i)=='_'){
                o++;
            }
        }
        for(int i=0;i<x;i++){
            if(*(m+i)=='.'){
                p++;
            }
        }
if((*(m)=='c'&&*(m+1)=='o'&&*(m+2)=='n'&&*(m+3)=='s'&&*(m+4)=='t')||
        (*(m)=='f'&&*(m+1)=='l'&&*(m+2)=='o'&&*(m+3)=='a'&&*(m+4)=='t')||
        (*(m)=='i'&&*(m+1)=='n'&&*(m+2)=='t')||
        (*(m)=='d'&&*(m+1)=='o'&&*(m+2)=='u'&&*(m+3)=='b'&&*(m+4)=='l'&&*(m+5)=='e')||
        (*(m)=='l'&&*(m+1)=='o'&&*(m+2)=='n'&&*(m+3)=='g')||
        (*(m)=='s'&&*(m+1)=='t'&&*(m+2)=='a'&&*(m+3)=='t'&&*(m+4)=='i'&&*(m+5)=='c')||
        (*(m)=='v'&&*(m+1)=='o'&&*(m+2)=='i'&&*(m+3)=='d')||
        (*(m)=='c'&&*(m+1)=='h'&&*(m+2)=='a'&&*(m+3)=='r')||
        (*(m)=='e'&&*(m+1)=='x'&&*(m+2)=='t'&&*(m+3)=='e'&&*(m+4)=='r'&&*(m+5)=='n')||
        (*(m)=='r'&&*(m+1)=='e'&&*(m+2)=='t'&&*(m+3)=='u'&&*(m+4)=='r'&&*(m+5)=='n')||
        (*(m)=='b'&&*(m+1)=='r'&&*(m+2)=='e'&&*(m+3)=='a'&&*(m+4)=='k')||
        (*(m)=='e'&&*(m+1)=='n'&&*(m+2)=='u'&&*(m+3)=='m')||
        (*(m)=='s'&&*(m+1)=='t'&&*(m+2)=='r'&&*(m+3)=='u'&&*(m+4)=='c'&&*(m+5)=='t')||
        (*(m)=='g'&&*(m+1)=='o'&&*(m+2)=='t'&&*(m+3)=='o')||
        (*(m)=='u'&&*(m+1)=='n'&&*(m+2)=='i'&&*(m+3)=='o'&&*(m+4)=='n')||
        (*(m)=='t'&&*(m+1)=='y'&&*(m+2)=='p'&&*(m+3)=='e'&&*(m+4)=='d'&&*(m+5)=='e'&&*(m+6)=='f')){
            *(ans+n)='r';n++;
            *(ans+n)='e';n++;
            *(ans+n)='s';n++;
            *(ans+n)='e';n++;
            *(ans+n)='r';n++;
            *(ans+n)='v';n++;
            *(ans+n)='e';n++;
            *(ans+n)='d';n++;
            *(ans+n)=' ';n++;            
        }
        else if(*(m)=='+'||*(m)=='-'||*(m)=='*'||*(m)=='/'||*(m)=='='||*(m)=='>'||*(m)=='<'){            
            *(ans+n)='o';n++;
            *(ans+n)='p';n++;
            *(ans+n)='e';n++;
            *(ans+n)='r';n++;
            *(ans+n)='a';n++;
            *(ans+n)='t';n++;
            *(ans+n)='o';n++;
            *(ans+n)='r';n++;
            *(ans+n)=' ';n++;
        }
        else if((*(m)=='='&&*(m+1)=='=')||(*(m)=='!'&&*(m+1)=='=')||(*(m)=='>'&&*(m+1)=='=')||(*(m)=='<'&&*(m+1)=='=')){
            *(ans+n)='o';n++;
            *(ans+n)='p';n++;
            *(ans+n)='e';n++;
            *(ans+n)='r';n++;
            *(ans+n)='a';n++;
            *(ans+n)='t';n++;
            *(ans+n)='o';n++;
            *(ans+n)='r';n++;
            *(ans+n)=' ';n++;
        }
        else if(y==x){
            *(ans+n)='i';n++;
            *(ans+n)='n';n++;
            *(ans+n)='t';n++;
            *(ans+n)='e';n++;
            *(ans+n)='g';n++;
            *(ans+n)='e';n++;
            *(ans+n)='r';n++;
            *(ans+n)=' ';n++;
        }
        else if(o+y==x&&*(m)!='0'&&*(m)!='1'&&*(m)!='2'&&*(m)!='3'&&*(m)!='4'&&*(m)!='5'&&*(m)!='6'&&*(m)!='7'&&*(m)!='8'&&*(m)!='9'){
            *(ans+n)='v';n++;
            *(ans+n)='a';n++;
            *(ans+n)='r';n++;
            *(ans+n)='i';n++;
            *(ans+n)='a';n++;
            *(ans+n)='b';n++;
            *(ans+n)='l';n++;
            *(ans+n)='e';n++;
            *(ans+n)=' ';n++;
        }
        else if(p==1&&y==x-1){
            *(ans+n)='f';n++;
            *(ans+n)='l';n++;
            *(ans+n)='o';n++;
            *(ans+n)='a';n++;
            *(ans+n)='t';n++;
            *(ans+n)=' ';n++;
        }
        else {error=1;}
        return ;       
}
