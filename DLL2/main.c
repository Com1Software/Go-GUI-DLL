#include <windows.h>
#include <stdio.h>

typedef void (*say_hello_t)();

int main() {
    HINSTANCE hinstLib = LoadLibrary("hello.dll");
    if (hinstLib != NULL) {
        say_hello_t say_hello = (say_hello_t) GetProcAddress(hinstLib, "say_hello");
        if (say_hello != NULL) {
            say_hello();
        } else {
            printf("Could not locate the function.\n");
        }
        FreeLibrary(hinstLib);
    } else {
        printf("Could not load the DLL.\n");
    }
    return 0;
}
