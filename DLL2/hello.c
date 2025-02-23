#include <windows.h>
#include <stdio.h>

__declspec(dllexport) const char* show_message(const char* message) {
    MessageBox(NULL, message, "Message", MB_OK);
    return "Hello, World!";
}
