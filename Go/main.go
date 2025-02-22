package main

import (
	"fmt"
	"syscall"
	"unsafe"
)

const (
	IDYES = 6
	IDNO  = 7
)

func main() {
	// Load the DLL
	dll, err := syscall.LoadLibrary("/Go-GUI-DLL/DLL/gui.dll")
	if err != nil {
		panic(err)
	}
	defer syscall.FreeLibrary(dll)

	// Get a handle to the ShowMessage function
	proc, err := syscall.GetProcAddress(dll, "ShowMessage")
	if err != nil {
		fmt.Println(err)
	}

	// Prepare the message
	message := "Do you want to proceed?"
	msgPtr := uintptr(unsafe.Pointer(syscall.StringBytePtr(message)))

	// Call the ShowMessage function
	ret, _, _ := syscall.Syscall(proc, 1, msgPtr, 0, 0)

	// Interpret the return value
	if ret == IDYES {
		fmt.Println("User clicked Yes")
	} else if ret == IDNO {
		fmt.Println("User clicked No")
	} else {
		fmt.Println("DLL function call failed")
	}
}
