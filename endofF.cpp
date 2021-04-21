#include <stdio.h>
int main(int argc, char *argv[])
{
    char c;

    c = getchar();
    while (c != EOF){
        printf("%c", c);
        c = getchar();
    }
    if (c == EOF)
        printf("EOF reached\n");
    return 0;
} 