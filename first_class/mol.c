#include<stdio.h>
int main()
{
    const double MOL=6.02e23;
    const int MOL_PER_GRAM=32;
    int mass = 6;
    double quantity = mass *1.0/MOL_PER_GRAM*MOL;
    printf("quantity= %.3e\nquantity=%.5g\n",
    quantity,quantity);
}