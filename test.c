#include<stdio.h>
int numbers[1000005]={0};
int main(){
    int n;
    scanf("%d",&n);

    numbers[0]=n;
    for(int i=1;i<=10000005;i++)
    {   
        if(numbers[i-1]%2==0){numbers[i]=numbers[i-1]/2;
            
        }
        else{
            numbers[i]=3*numbers[i-1]+1;
        }
        if(numbers[i]=1){break;}
    }
    for(int i=1;i<=1000005;i++)
    {
        int max=numbers[0];
        if(numbers[i]>numbers[0]){
    
            max=numbers[i];printf("%d",max);
        }
    }
    
    return 0;
}
