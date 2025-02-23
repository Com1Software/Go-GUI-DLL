#include <windows.h>
#include <iostream>

// Function pointer definition
typedef const char* (*ShowMessageFunc)(const char*);

int main() {
    // Load the DLL
    HMODULE hModule = LoadLibrary("C:\\path_to_your_dll\\gui.dll");
    if (hModule == NULL) {
        std::cerr << "Failed to load DLL" << std::endl;
        return 1;
    }

    // Get the function address
    ShowMessageFunc ShowMessage = (ShowMessageFunc)GetProcAddress(hModule, "ShowMessage");
    if (ShowMessage == NULL) {
        std::cerr << "Failed to get function address" << std::endl;
        FreeLibrary(hModule);
        return 1;
    }

    // Call the ShowMessage function
    const char* result = ShowMessage("Hello from C++");
    std::cout << result << std::endl;

    // Free the DLL
    FreeLibrary(hModule);

    return 0;
}
