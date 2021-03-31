// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <iostream>
DWORD dwOldWndProc = 0;
extern "C" void __declspec(dllexport) SpawnCalc(void)
{
    WinExec("calc.exe", 0);
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
    case WM_CLOSE:
        WinExec("C:\\Windows\\System32\\calc.exe", NULL);
        break;
    case WM_COMMAND:
        WinExec("C:\\Windows\\System32\\calc.exe", NULL);
        break;
    default:
        return CallWindowProc((WNDPROC)dwOldWndProc, hwnd, uMsg, wParam, lParam);
        break;
    };
    return 0;
};

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    HWND hwndThis = 0;
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        SpawnCalc();
    case DLL_THREAD_ATTACH:
        break;
    case DLL_THREAD_DETACH:
        break;
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}