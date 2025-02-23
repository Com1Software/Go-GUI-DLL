#include <stdio.h>

__declspec(dllexport) void say_hello() {
    printf("Hello, World!\n");
}
