#include <windows.h>

extern "C" __declspec(dllexport) const char* ShowMessage(const char* message)
{
    int msgboxID = MessageBox(NULL, message, "Message", MB_YESNO | MB_ICONQUESTION);
    if (msgboxID == IDYES) {
        return "User clicked Yes";
    } else if (msgboxID == IDNO) {
        return "User clicked No";
    } else {
        return "MessageBox failed";
    }
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved)
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}
