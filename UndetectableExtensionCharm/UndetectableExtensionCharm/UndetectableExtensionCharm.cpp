// UndetectableExtensionCharm.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <Windows.h>

int main()
{
    if (RegisterHotKey(NULL, 1, MOD_ALT | MOD_NOREPEAT, 0x42))  //0x42 is 'b'
    {
        printf(("Hotkey 'ALT+b' registered, using MOD_NOREPEAT flag\n"));
    }

    MSG msg = { 0 };
    while (GetMessage(&msg, NULL, 0, 0) != 0)
    {
        if (msg.message == WM_HOTKEY)
        {
            printf(("WM_HOTKEY received\n"));
        }
    }

    return 0;
}
