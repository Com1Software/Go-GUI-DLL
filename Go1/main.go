package main

/*
#cgo CFLAGS: -I.
#cgo LDFLAGS: -L. -luser32

#include <windows.h>
#include <stdlib.h>
#include <string.h>

typedef const char* (*ShowMessageFunc)(const char*);

const char* CallShowMessage(const char* dllName, const char* message) {
    HMODULE hModule = LoadLibrary(dllName);
    if (hModule == NULL) {
        return "Failed to load DLL";
    }

    ShowMessageFunc ShowMessage = (ShowMessageFunc)GetProcAddress(hModule, "ShowMessage");
    if (ShowMessage == NULL) {
        FreeLibrary(hModule);
        return "Failed to get function address";
    }

    const char* result = ShowMessage(message);
    FreeLibrary(hModule);
    return result;
}
*/
import "C"
import (
	"fmt"
	"unsafe"
)

func main() {
	dllName := C.CString("/Go-GUI-DLL/DLL1/gui.dll")
	defer C.free(unsafe.Pointer(dllName))

	message := C.CString("Hello from Go")
	defer C.free(unsafe.Pointer(message))

	result := C.CallShowMessage(dllName, message)
	Message := C.GoString(result)

	fmt.Println(Message)
}
