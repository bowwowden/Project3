#include <string.h>
#include <stdio.h>
#include "util.h"
#include <ctype.h>

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

int nextWord(char *word)
{
    char c;
    int i, r_value;

    r_value = 0;
    c = getchar();

#if _util_version == 1
    while (c == ' ' || c == '\t' || c == '\n'){
        c = getchar();
    }
#else
    while (!isalpha(c)){
        c = getchar();
        if (c == EOF) return (0);
    }
#endif

    i = 0;
    while (c != EOF){
#if _util_version == 2
        if (c == ' ' || c == '\t' || c == '\n'){
            break;
        }
#else   
        if (!isalpha(c)){
            break;
        }
#endif
        r_value = 1;
        word[i] = c;
        i++;
        c = getchar();
    }
// end of a word
    word[i] = '\0';
    
    return r_value;
}