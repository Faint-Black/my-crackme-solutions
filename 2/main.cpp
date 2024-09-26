#include <iostream>

// nimacpp - Level 1
// https://crackmes.one/crackme/65d490306d3d2b1fef4be1ad
//
// solution: the binary should be renamed such that argv[0] satisfies the "nima"
//           if-condition below, and argv[1] can be any string that starts with
//           the character '@'.
//           example: ./Hnima @foo
//
// The following is a recreation of what the original source code of the crackme
// binary may have looked like.

int main(int argc, char** argv)
{
    if(argc != 2)
    {
        std::cout << "Try more ... 1/5";
        return 0;
    }

    if(argv[0][0] + argv[1][0] != 110)
    {
        std::cout << "Try More ....2/5";
        return 0;
    }

    if(argv[0][3] == 'n'
    || argv[0][4] == 'i'
    || argv[0][5] == 'm'
    || argv[0][6] == 'a')
    {
        std::cout << "true point 5/5";
        return 0;
    }

    std::cout << "Try more .... 3/5";

    return 0;
}
