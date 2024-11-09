#include <stdio.h>

int main(void)
{
    char str[99];

    printf("What's your name? ");
    scanf("%s", str);
    printf("hello, %s\n", str);

    return 0;
}