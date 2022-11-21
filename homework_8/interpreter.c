#include<stdio.h>
int main()
{
    int a;
    scanf("%x",&a);
    int *s=&a;
    float *kk=&a;
    unsigned int ans_2=*s;
    float ans_3=*kk;
    printf("%d\n%u\n%lf\n%.3e",a,ans_2,ans_3,ans_3);
    return 0;
}