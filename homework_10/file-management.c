#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct file{
    char name[11];
    char front[11];
    int next[2];
    int num;
    int st;
}list[10003];
int n,q;
int anss;
void remove1(int c)
{
    list[c].st=0;
    if(list[c].num==0)
    return;
    else if(list[c].num==1)
    {
        remove1(list[c].next[0]);
    }
    else{
        remove1(list[c].next[0]);
        remove1(list[c].next[1]);
    }
}
void query(int c)
{
    if(list[c].st==1)
    anss++;
    if(list[c].num==0)
    return;
    else if(list[c].num==1)
    {
        query(list[c].next[0]);
    }
    else{
        query(list[c].next[0]);
        query(list[c].next[1]);
    }
}
int Find(char bb[])
{
    int k;
    for(int i=0;i<n;i++){
        if(strcmp(list[i].name,bb)==0)
        {
            k=i;
            break;
        }
    }
    return k;
}
int main()
{
    freopen("t.in","r",stdin);
    scanf("%d%d",&n,&q);
    for(int i=0;i<n;i++)
    {
        scanf("%s%s",list[i].name,list[i].front);
        list[i].st=1;  
        list[i].num=0;      
    }
    for(int i=0;i<n;i++)
    {
        if(list[i].front[0]!='~'){
            int k = Find(list[i].front);
            list[k].next[list[k].num]=i;
            list[k].num++;
        }
    }
    for(int i=1;i<=q;i++)
    {
        char ta[50];
        char tb[50];
        scanf("%s%s",ta,tb);
        if(ta[0]=='q'){
        anss =0;
        query(Find(tb));
        printf("%d\n",anss);
        }
        else
        remove1(Find(tb));
    }
    return 0;
}