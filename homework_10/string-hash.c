#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node{
    char *content;
    struct node* next;
};
int hash(char *s,int p){
    int len=strlen(s);
    int ret=0;
    for(int i=0;i<len;i++)ret=(ret+s[i]*(i+1))%(2*p);
    return ret;
}
struct node *Find_last(struct node *a)
{
    if(a->next==NULL)
    {
        return a;
    }
    else {
        return Find_last(a->next);
    }
}
int check(char *tp,struct node* kk){
    if(strcmp(tp,kk->content)==0)
    {
        return 1;
    }
    else if(kk->next!=NULL)
    {
        return check(tp,kk->next);
    }
    else if(kk->next==NULL)
    {
        return 0;
    }
}
int main()
{
    int m,q;
    scanf("%d%d",&m,&q);
    struct node **cun=(struct node **)malloc(2*m*sizeof(struct node));
    for(int i=0;i<2*m;i++)
    {
        cun[i]=NULL;
    }
    for(int j=1;j<=m;j++)
    {
        struct node *i=(struct node*)malloc(sizeof(struct node));
        char tmkp[1004];
        scanf("%s",tmkp);
        char *real=malloc((strlen(tmkp)+1)*sizeof(char));
        strcpy(real,tmkp);
        i->content=real;
        i->next=NULL;
        int ha=hash(i->content,m);
        if(cun[ha]==NULL)
        {
            cun[ha]=i;
        }
        else{
            struct node * last = Find_last(cun[ha]);
            last->next=i;
        }
    }
    for(int z=1;z<=q;z++)
    {
        char tp[1003];
        scanf("%s",tp);
        int ha=hash(tp,m);
        if(cun[ha]==NULL)
        {
            printf("No\n");
            continue;
        }
        else{
            int c=check(tp,cun[ha]);
            if(c==1)
            {
                printf("Yes\n");
            }
            else{
                printf("No\n");
            }
        }
    }

}