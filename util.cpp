#include "util.h"

int nextCommand(int *n, int *f, int* i)
{
    char c;
    while(1){
        scanf("%c", &c);
        while (c == ' ' || c == '\t'  || c == '\n'){
            scanf("%c", &c);
        }
        if (c == 'S' || c == 's'){
            break;
        }
        if (c == 'C' || c == 'c'){
            scanf("%d", n);
            if (*n == 0){
                printf("Warning in nextCommand: read in int %d\n", *n);
            }
            break;
        }
        if (c == 'P' || c == 'p'){
            break;
        }
        if (c == 'R' || c == 'r'){
            scanf("%d", f);
            break;
        }
        if (c == 'W' || c == 'w'){
            break;
        }
        if (c == 'I' || c == 'i')
        {
            scanf("%d", f);
            break;
        }
        if (c == 'K' || c == 'k')
        {
            scanf("%d", f);
            scanf("%d", i);
            break;
        }
        if (c == 'D' || c == 'd')
        {
            scanf("%d", f);
            break;
        }

        printf("Warning in nextCommand: invalid input \n");
        break;
    }
    return c;
}