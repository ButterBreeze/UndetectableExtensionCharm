#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include <iostream>
#include <thread>
#include "main.h"

//TODO: Update path vars or add the libs to this directory
//TODO: Have fun debugging the background thread....

void backgroundThreadMain();

int main() {
    backgroundThreadMain();//working on getting the background shtuffs to work.
    /*
    std::cout << "Initiating UndetectableExtensionCharm. \n Please stand by... \n" << std::endl;
    std::thread backgroundThread(backgroundThreadMain);
    backgroundThread.detach();
    return 0;
    */
}

void backgroundThreadMain()
{
    if(RegisterHotKey(NULL, 1, MOD_SHIFT, 0x42))//rmsbtn 0x02/VK_RBUTTON
    {
        //Retrieve the applications instance
        HINSTANCE instance = GetModuleHandle(NULL);
        //Set a global Windows Hook to capture keystrokes using the function declared above
        HHOOK test1 = SetWindowsHookEx( WH_KEYBOARD_LL, LowLevelKeyboardProc, instance,0);
    }

}

LRESULT CALLBACK LowLevelKeyboardProc( int nCode, WPARAM wParam, LPARAM lParam )
{
    char pressedKey;
    // Declare a pointer to the KBDLLHOOKSTRUCTdsad
    KBDLLHOOKSTRUCT *pKeyBoard = (KBDLLHOOKSTRUCT *)lParam;
    switch( wParam )
    {
        case WM_KEYUP: // When the key has been pressed and released
        {
            //get the key code
            pressedKey = (char)pKeyBoard->vkCode;
        }
            break;
        default:
            return CallNextHookEx( NULL, nCode, wParam, lParam );
            break;
    }

    //do something with the pressed key here
    //....

    //according to winapi all functions which implement a hook must return by calling next hook
    return CallNextHookEx( NULL, nCode, wParam, lParam);
}