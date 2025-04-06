/*
Bored - by prague
https://crackmes.one/crackme/6578347c35240bf986f100e9

solution: password = "caesarcipher"

The following is a recreation of what the original source code of the crackme
binary may have looked like, along with an optional keygen function.
*/

#include <stdio.h>
#include <string.h>

void get_input(void);
void process_input(char *, int);
void keygen(char *, int);

int main(void) {
    get_input();
    return 0;
}

void get_input(void) {
    char input_string_ptr[112];
    unsigned long coded_string_ptr[13];

    /* (char*)coded_string_ptr = "geiwevgmtliv" */
    coded_string_ptr[0] = (unsigned long)0x6d67766577696567;
    coded_string_ptr[1] = (unsigned long)0x0000000076696c74;
    coded_string_ptr[2] = (unsigned long)0x0000000000000000;
    coded_string_ptr[3] = (unsigned long)0x0000000000000000;
    coded_string_ptr[4] = (unsigned long)0x0000000000000000;
    coded_string_ptr[5] = (unsigned long)0x0000000000000000;
    coded_string_ptr[6] = (unsigned long)0x0000000000000000;
    coded_string_ptr[7] = (unsigned long)0x0000000000000000;
    coded_string_ptr[8] = (unsigned long)0x0000000000000000;
    coded_string_ptr[9] = (unsigned long)0x0000000000000000;
    coded_string_ptr[10] = (unsigned long)0x0000000000000000;
    coded_string_ptr[11] = (unsigned long)0x0000000000000000;
    coded_string_ptr[12] = (unsigned long)0x0000000000000000;

    /* uncomment line below to print the solution */
    /* keygen((char*)coded_string_ptr, 4); */

    printf("Enter the password: ");
    scanf("%s", input_string_ptr);

    process_input(input_string_ptr, 4);

    if (strcmp((char *)coded_string_ptr, input_string_ptr) == 0) {
        printf("Correct!\n");
    } else {
        printf("Nope\n");
    }

    return;
}

void process_input(char *_input_string, int _shift) {
    int wrap;
    char c;
    unsigned int i = 0;

    while (i < (strlen(_input_string))) {
        if (_input_string[i] >= 'A' && _input_string[i] <= 'Z') {
            /*
              what i had to write before figuring it out:
              RAX = (_input_string[i] - 'A') + _shift;
              RDX = ((int)floor(RAX / 3.25)) / 8;
              RAX = RAX - (RDX * 26);
              RCX = RAX + 0x41;
            */
            wrap = (_input_string[i] > ('Z' - _shift));
            c = (_input_string[i] + _shift) - (wrap * 26);
            _input_string[i] = c;
        } else if (_input_string[i] >= 'a' && _input_string[i] <= 'z') {
            wrap = (_input_string[i] > ('z' - _shift));
            c = (_input_string[i] + _shift) - (wrap * 26);
            _input_string[i] = c;
        }
        ++i;
    }
    printf("\n");

    return;
}

void keygen(char *_string, int _shift) {
    int wrap;
    char c;
    unsigned int i = 0;

    printf("solution string: \"");
    while (i < (strlen(_string))) {
        if (_string[i] >= 'A' && _string[i] <= 'Z') {
            wrap = (_string[i] < ('A' + _shift));
            c = (_string[i] - _shift) + (wrap * 26);
            printf("%c", c);
        } else if (_string[i] >= 'a' && _string[i] <= 'z') {
            wrap = (_string[i] < ('a' + _shift));
            c = (_string[i] - _shift) + (wrap * 26);
            printf("%c", c);
        } else {
            printf("%c", _string[i]);
        }
        ++i;
    }
    printf("\"\n");

    return;
}
