package main

import (
	"fmt"
	"syscall"
)

func main() {
	// Load the DLL
	dll, err := syscall.LoadLibrary("/Go-GUI-DLL/DLL/gui.dll")
	if err != nil {
		panic(err)
	}
	defer syscall.FreeLibrary(dll)

	// Get a handle to the HelloWorld function
	proc, err := syscall.GetProcAddress(dll, "HelloWorld")
	if err != nil {
		fmt.Println(err)
	}

	// Call the HelloWorld function
	ret, _, _ := syscall.Syscall(proc, 0, 0, 0, 0)
	if ret != 0 {
		fmt.Println("DLL function call failed")
	} else {
		fmt.Println("DLL function call succeeded")
	}
}
