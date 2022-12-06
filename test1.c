#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
    char p;
    int t=0;
    int tt=0;
    int *number=malloc(1000*sizeof(int));
    char *a=malloc(200*sizeof(char));
    char *b=malloc(200*sizeof(char));
    char *c=malloc(200*sizeof(char));
    char *d=malloc(10000*sizeof(char));
    freopen("data.in","r",stdin);
    freopen("output.out","w",stdout);
    scanf("%s",a);
    int x=strlen(a);
    scanf("%s",b);
    int y=strlen(b);
    int error1,error2=0;
    while(scanf("%s",c)!=EOF){        
        int n=strlen(c);
        if(n==2&&*(c)=='-'&&*(d+t-1)!='='){
            int num=0;
            int o;
            for(int i=0;i<x;i++){
                if(*(c+1)==*(a+i)){
                    o=i;
                    num++;
                    break;
                }
            }
            if(num==0){
                error1=1;
                p=*(c+1);
                break;
            }
            else if(num==1){
                if(*(a+o+1)!=':'){
                    *(d+t)=*(c+1);
                    *(number+tt)=t;
                    tt++;
                    t++;
                }
                if(*(a+o+1)==':'){
                    p=*(c+1);
                    error2++;
                    *(d+t)=*(c+1);
                    *(d+t+1)='=';
                    t=t+2;
                }
            }
        }
        else if(*(d+t-1)=='='){
            error2--;
            for(int i=0;i<n;i++){
                *(d+t)=*(c+i);
                t++;
            }
            *(number+tt)=t-1;
            tt++;
        }
    }
    tt=0;
    
    if(error1==0&&error2==0){
        for(int i=0;i<y;i++){
        printf("%c",*(b+i));
    }
        printf("\n");
        for(int i=0;i<t;i++){
            printf("%c",*(d+i));
            if(i==t-1){
                break;
            }
            if(i==*(number+tt)){
                printf("\n");
                tt++;
            }
        }
    }
    if(error1==1){
        for(int i=0;i<y;i++){
        printf("%c",*(b+i));
    }
        printf(": invalid option -- '%c'",p);
    }
    if(error1==0&&error2!=0){
        for(int i=0;i<y;i++){
        printf("%c",*(b+i));
    }
        printf(": option requires an argument -- '%c'",p);
    }
    return 0;
}
