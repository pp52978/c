#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include<string.h>
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
    if(strcmp(S,"const")*strcmp(S,"int")*strcmp(S,"float")*strcmp(S,"double")*strcmp(S,"long")*strcmp(S,"static")*
    strcmp(S,"void")*strcmp(S,"char")*strcmp(S,"extern")*strcmp(S,"return")*strcmp(S,"break")*strcmp(S,"enum")*
    strcmp(S,"struct")*strcmp(S,"typedef")*strcmp(S,"union")*strcmp(S,"goto")==0)
    {
        PutAns(AN,"reserved");
        return;
    }
    else
    {

    }
}
int main(){
   char *p=malloc(200*sizeof(char));
   //char * pos = strchr(p,'f');
    *p='e';

    *(p+1)='\n';
    *(p+2)='2';
    *(p+3)='\0';
   printf("%s",p);

   
}
