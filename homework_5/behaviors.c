#include<stdio.h>
void do1(void);
void do2(void);
int main()
{
    do2();
    do2();
    do1();
    do2();
    do2();
    do2();
    do2();
    do2();
    do2();
    do2();
    do2();
    do2();
    return 0;
}
void do1()
{
    printf("YES\n");
}
void do2()
{
    printf("NO\n");
}