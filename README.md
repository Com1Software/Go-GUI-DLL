# Go-GUI-DLL
Graphical User Interface DLL for Go

g++ -shared -o gui.dll gui.cpp -Wl,--subsystem,windows

g++ -shared -o gui.dll -Wl,--out-implib,libmygui.a gui.cpp

g++ -o test.exe test.cpp -luser32


