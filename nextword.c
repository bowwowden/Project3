#include <string.h>
#include <stdio.h>
#include "util.h"
#include <ctype.h>

int nextWord(char *Word)
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