#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*
stonezarcon - Getting Started
https://crackmes.one/crackme/660a24f1cddae72ae250bf56

solution: argv[1] = "secret"

The following is a recreation of what the original source code of the crackme
binary may have looked like.
*/

int main(int argc, char** argv)
{
    char* string_ptr;
    int* alloc_ptr;
    int i;

    if(argc <= 1){
        puts("Denied.");
        return 0;
    }

    /* ultra top secret classified cryptographically unbreakable password generator */
    alloc_ptr = (int*)malloc(6 * sizeof(int));
    alloc_ptr[0] = 110;
    alloc_ptr[1] = 96;
    alloc_ptr[2] = 94;
    alloc_ptr[3] = 109;
    alloc_ptr[4] = 96;
    alloc_ptr[5] = 111;
    for(i = 0; i < 5; i++){
        alloc_ptr[0] += 1;
        alloc_ptr[1] += 1;
        alloc_ptr[2] += 1;
        alloc_ptr[3] += 1;
        alloc_ptr[4] += 1;
        alloc_ptr[5] += 1;
    }
    /* printing the resulting array returns "s e c r e t" */

    string_ptr = (char*)malloc(7 * sizeof(char));
    for(i = 0; i < 7; i++){
        string_ptr[i] = alloc_ptr[i];
    }
    string_ptr[6] = '\0';

    if(strcmp(string_ptr, argv[1]) == 0){
        puts("Welcome.");
    }
    else{
        puts("Denied.");
    }

    return 0;
}
