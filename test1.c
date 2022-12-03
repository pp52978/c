#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int max(int x,int y){
    if(x>y){return x-y;}
    return 0;
}
int main(){
   // freopen("data.in","r",stdin);
  //freopen("tch.out","w",stdout);
    int T;
    scanf("%d",&T);
    char *p=malloc(1005*sizeof(*p));
    char *q=malloc(1005*sizeof(*q));
    char *cat=malloc(2022*sizeof(*q));
    while(T)
    {
    scanf("%s",p);
    scanf("%s",q);
    int len=strlen(p);
    int len2=strlen(q);
    int cnt=0;
    for(int i=max(len,len2);i<len;i++)
    {
            if(*(p+i)==*q){
            cnt++;q+=1;
        }
        else{q-=cnt;i-=cnt;cnt=0;}
    }
    if(cnt==0&&*(p+len-1)==*(q))
    {
    printf("%s",p);
    printf("%s",q);
    printf("\n");
    }
    else{printf("%s",p);
    printf("%s",q);
    printf("\n");
    }

    T--;
} 
    return 0;
}
