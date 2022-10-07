#include<stdio.h>
int main()
{
    const double PI = 3.1415926;
    int radius = 10;
    double circumference = 2 * PI *radius;
    double area = PI * radius *radius;
    printf("circumference = %.2f\narea = %.2f\n",circumference,area);
    return 0;
}