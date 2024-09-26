#include <iostream>
#include <cstring>
#include <memory>

// stonezarcon - Getting Started
// https://crackmes.one/crackme/660a24f1cddae72ae250bf56
//
// solution: argv[1] = "secret"
//
// The following is a recreation of what the original source code of the crackme
// binary may have looked like.

int main(int argc, char** argv)
{
    if(argc <= 1)
    {
        std::cout << "Denied." << std::endl;
        return 0;
    }

    char* string_ptr;
    int32_t* alloc_ptr;

    // ultra top secret classified cryptographically unbreakable password generator
    alloc_ptr = (int32_t*)malloc(sizeof(uint32_t) * 6);
    alloc_ptr[0] = 110;
    alloc_ptr[1] = 96;
    alloc_ptr[2] = 94;
    alloc_ptr[3] = 109;
    alloc_ptr[4] = 96;
    alloc_ptr[5] = 111;
    for(int i = 0; i < 5; i++)
    {
        alloc_ptr[0] += 1;
        alloc_ptr[1] += 1;
        alloc_ptr[2] += 1;
        alloc_ptr[3] += 1;
        alloc_ptr[4] += 1;
        alloc_ptr[5] += 1;
    }
    // print the password:
    // printf("%c %c %c %c %c %c \n", alloc_ptr[0], alloc_ptr[1], alloc_ptr[2], alloc_ptr[3], alloc_ptr[4], alloc_ptr[5]);
    // "s e c r e t"

    string_ptr = (char*)malloc(sizeof(char) * 7);
    for(int i = 0; i < 7; i++)
    {
        string_ptr[i] = alloc_ptr[i];
    }
    string_ptr[6] = '\0';

    if(strcmp(string_ptr, argv[1]) == 0)
    {
        std::cout << "Welcome." << std::endl;
    }
    else
    {
        std::cout << "Denied." << std::endl;
    }

    return 0;
}