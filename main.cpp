#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include <iostream>
#include <thread>

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
    int key_count = 4;

    INPUT* input = new INPUT[key_count];
    for( int i = 0; i < key_count; i++ )
    {
        input[i].ki.dwFlags = 0;
        input[i].type = INPUT_KEYBOARD;
    }


    input[0].ki.wVk = VK_CONTROL;
    input[0].ki.wScan = MapVirtualKey( VK_CONTROL, MAPVK_VK_TO_VSC );
    input[1].ki.wVk = 0x56;// Virtual key code for 'v'
    input[1].ki.wScan = MapVirtualKey( 0x56, MAPVK_VK_TO_VSC );
    input[2].ki.dwFlags = KEYEVENTF_KEYUP;
    input[2].ki.wVk = input[0].ki.wVk;
    input[2].ki.wScan = input[0].ki.wScan;
    input[3].ki.dwFlags = KEYEVENTF_KEYUP;
    input[3].ki.wVk = input[1].ki.wVk;
    input[3].ki.wScan = input[1].ki.wScan;

    if( !SendInput( key_count, (LPINPUT)input, sizeof(INPUT) ) )
    {
        // You can get more information on why this function failed by calling
        //        // the win32 function, GetLastError().
    }

    if( OpenClipboard(NULL) )
    {
        // Optionally you may want to change CF_TEXT below to CF_UNICODE.
        // Play around with it, and check out all the standard formats at:
        // http://msdn.microsoft.com/en-us/library/ms649013(VS.85).aspx
        HGLOBAL hglb = GetClipboardData( CF_TEXT );
        LPSTR lpstr = GlobalLock(hglb);

        // Copy lpstr, then do whatever you want with the copy.

        GlobalUnlock(hglb);
        CloseClipboard();
    }
    else
    {
        // You know the drill by now. Check GetLastError() to find out what
        // went wrong. :)
    }
}