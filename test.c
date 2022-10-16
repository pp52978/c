#include<stdio.h>
#include<math.h>
int main(){
    int len;
    scanf("%d",&len);
    char aa[40];
    //int bb[40]={0};
    for(int i=1;i<=len;i++)
    {
       
      scanf("%c",&aa[i]);
      printf("%d",i);
   }
       /* for(int i=0;i<=len-1;i++)
    {if(aa[i]==65){aa[i]=10;}
     if(aa[i]==66){aa[i]=11;}
     if(aa[i]==67){aa[i]=12;}
     if(aa[i]==68){aa[i]=13;}
     if(aa[i]==69){aa[i]=14;}
     if(aa[i]==70){aa[i]=15;}}*/
    // printf("%c",aa[1]); 
    /*for(int i=0;i<=len-1;i++)
    {
        if(0<=aa[i]<=15){aa[i]=aa[i]*pow(N,i);}
        else{aa[35]=1;}
    } 
    for (int i=1;i<=len-1;i++){
        aa[i]=aa[i]+aa[i-1];
    }
    if(aa[35]=1){printf("Error");}
    else {printf("%d",aa[len-1]);}*/
    return 0;
}
