#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char name[20];
int cun[3][10002];
void PRINT(int ans[],int p){
    int check=1;
    for(int i=p;i>0;i--)
    {
        if(ans[i]!=0)
        {
            check=0;
            break;
        }
    }
    if(check==1){
        printf("%d\n",ans[0]);
        return;
    }   
    for(int i=p;i>=0;i--)
    {
        if(i==p)
        {
            if(ans[i]!=0&&ans[i]*ans[i]!=1)
            {
                printf("%d%s",ans[i],name);
            }
            else if(ans[i]==1)
            {
                printf("%s",name);
            }
            else if (ans[i]==-1)
            {
                 printf("-%s",name);
            }
            if(i!=1)
            printf("^%d",i);
        }
        else if(i==0)
        {
            if(ans[i]>0)
            printf("+");
            else if(ans[i]==0){
            printf("\n");
            continue;}
            printf("%d\n",ans[i]);
        
        }
        else{
            if(ans[i]==0)
            continue;
            if(ans[i]>0)
            printf("+");
            if(ans[i]==1)
            printf("%s",name,i);
            else if(ans[i]==-1)
            printf("-%s",name);
            else
            printf("%d%s",ans[i],name);
            if(i!=1)
            printf("^%d",i);

            
        }
    }
}
int main()
{
    int p1,p2;
    scanf("%d%d",&p1,&p2);
    scanf("%s",name);
    int *ans = malloc((1+p1+p2)*sizeof(int));
    for(int i=p1;i>=0;i--)
    {
        scanf("%d",&cun[1][i]);
    }
    for(int i=p2;i>=0;i--)
    {
        scanf("%d",&cun[2][i]);
    }
    int check,max;
    if(p1>=p2){
        check=1;
        max=p1;
    }
    else{
        check=2;
        max=p2;
    }
    for(int i=max;i>=0;i--)
    {
        ans[i]=0;
        if(p1>=i)
        ans[i]+=cun[1][i];
        if(p2>=i)
        ans[i]+=cun[2][i];
    }
    PRINT(ans,max);
    for(int i=max;i>=0;i--)
    {
        ans[i]=0;
        if(p1>=i)
        ans[i]+=cun[1][i];
        if(p2>=i)
        ans[i]-=cun[2][i];
    }
    PRINT(ans,max);
    memset(ans,0,(1+p1+p2)*sizeof(int));
    for(int i=0;i<=p1;i++)
    {
        for(int k=0;k<=p2;k++)
        {
            ans[i+k]+=cun[1][i]*cun[2][k];
        }
    }
    PRINT(ans,p1+p2);
    free(ans);
    return 0;
}