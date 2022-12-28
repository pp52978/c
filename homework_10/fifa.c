#include<stdio.h>
#include<stdlib.h>
typedef struct team{
    char name[1000];
    double t1;
    double t2;
    double t3;
}TEAM;
TEAM cun[1006];
int cmp1(const void *v1,const void *v2){
    TEAM *a1=(TEAM*)v1;
    TEAM *a2=(TEAM*)v2;
    if(a2->t1<a1->t1)
    {
        return -1;
    }
    if(a2->t1==a1->t1)
    {
        return 0;
    }
    if(a2->t1>a1->t1)
    {
        return 1;
    }
}
int cmp2(const void *v1,const void *v2){
    TEAM *a1=(TEAM*)v1;
    TEAM *a2=(TEAM*)v2;
    if(a2->t2<a1->t2)
    {
        return -1;
    }
    if(a2->t2==a1->t2)
    {
        return 0;
    }
    if(a2->t2>a1->t2)
    {
        return 1;
    }
}
int cmp3(const void *v1,const void *v2){
    TEAM *a1=(TEAM*)v1;
    TEAM *a2=(TEAM*)v2;
    if(a2->t3<a1->t3)
    {
        return -1;
    }
    if(a2->t3==a1->t3)
    {
        return 0;
    }
    if(a2->t3>a1->t3)
    {
        return 1;
    }
}
int main()
{
    int n;
    size_t size=sizeof(TEAM);
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%s",cun[i].name);
        for(int k=1;k<=11;k++)
        {
            int tp1,tp2,tp3;
            char rub[90];
            scanf("%s%d%d%d",rub,&tp1,&tp2,&tp3);
            cun[i].t1+=tp1;
            cun[i].t2+=tp2;
            cun[i].t3+=tp3;
        }
        cun[i].t1/=11;
        cun[i].t2/=11;
        cun[i].t3/=11;
    }
    qsort(cun,n,size,cmp1);
    for(int i=0;i<n;i++)
    {
        printf("%s ",cun[i].name);
    }
    printf("\n");
     qsort(cun,n,size,cmp2);
    for(int i=0;i<n;i++)
    {
        printf("%s ",cun[i].name);
    }
    printf("\n");
     qsort(cun,n,size,cmp3);
    for(int i=0;i<n;i++)
    {
        printf("%s ",cun[i].name);
    }
    printf("\n");
}