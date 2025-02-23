#include <windows.h>
#include <stdio.h>

typedef const char* (*show_message_t)(const char*);

int main() {
    HINSTANCE hinstLib = LoadLibrary("hello.dll");
    if (hinstLib != NULL) {
        show_message_t show_message = (show_message_t) GetProcAddress(hinstLib, "show_message");
        if (show_message != NULL) {
            const char* result = show_message("Your custom message here!");
            printf("%s\n", result);
        } else {
            printf("Could not locate the function.\n");
        }
        FreeLibrary(hinstLib);
    } else {
        printf("Could not load the DLL.\n");
    }
    return 0;
}
