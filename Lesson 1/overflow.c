#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    // this one with encounter overflow
    int a = 20000000000000, b = 20000000000000;
    printf("The result is %d  \n", (a*b));

    // this one will not encounter overflow since it is using long long int 
    long long int a = 20000000000000, b = 20000000000000;
    printf("The result is %lli  \n", (a*b)); 
    return 0;
}
