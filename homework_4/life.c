#include<stdio.h>
#include<string.h>
int de[6]={-3,-2,-1,1,2,3};
int main()
{
    int n;
    char a[1005]={0};
    char tmp[1005]={0};
    scanf("%d",&n);
    scanf("%s",a);
    int l=strlen(a);
    for(int k=1;k<=n;k++)
    {
        for(int i=0;i<l;i++)
        {
            if(a[i]=='.')
            {
                int sta=0;
                char kin;
                int cnt1=0;
                for(int j=0;j<6;j++)
                {
                    
                    if((i+de[j]>=0)&&(i+de[j]<l))
                    {
                        if(cnt1==0)
                        {
                            if(a[i+de[j]]=='A'||a[i+de[j]]=='B')
                            {
                                kin=a[i+de[j]];
                                cnt1++;
                            }
                        }
                        else
                        {
                            if(a[i+de[j]]=='.');
                            
                            else if(a[i+de[j]]==kin)
                            {
                                cnt1++;
                            }
                            else{
                                sta=1;
                                break;
                            }
                        }
                    }
                }
                if(sta==0&&(cnt1>=2&&cnt1<=4))
                {
                    tmp[i]=kin;
                }
                else
                {
                    tmp[i]='.';
                }
            }
            else if(a[i]=='A')
            {
                int sta=0;
                int cnt1=0;
                for(int j=0;j<6;j++)
                {
                    if((i+de[j]>=0)&&(i+de[j]<l))
                    {
                        if(a[i+de[j]]=='B')
                        {
                            sta=1;
                            break;
                        }
                        else if(a[i+de[j]]=='A')
                        {
                            cnt1++;
                        }
                    }
                }
                if(sta==1)
                {
                    tmp[i]='.';
                }
                else if(cnt1<=1||cnt1>=5)
                {
                    tmp[i]='.';
                }
                else
                {
                    tmp[i]='A';
                }
            }
            else if(a[i]=='B')
            {
                int sta=0;
                int cnt1=0;
                for(int j=0;j<6;j++)
                {
                    if((i+de[j]>=0)&&(i+de[j]<l))
                    {
                        if(a[i+de[j]]=='A')
                        {
                            sta=1;
                            break;
                        }
                        else if(a[i+de[j]]=='B')
                        {
                            cnt1++;
                        }
                    }
                }
                if(sta==1)
                {
                    tmp[i]='.';
                }
                else if(cnt1<=1||cnt1>=5)
                {
                    tmp[i]='.';
                }
                else
                {
                    tmp[i]='B';
                }
            }
        }
        strncpy(a,tmp,l);
    }
    printf("%s",a);
    return 0;
}