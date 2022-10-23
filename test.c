
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <unistd.h>
int main()
{
    char a[1000]={'*'};
    scanf("%s",a);
    printf("%c",a[1]);
    printf("%d",strlen(a));

}