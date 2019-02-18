#include <iostream>
#include <Windows.h>
//TODO: Update path vars or add the libs to this directory


int main() {
    std::cout << "Initiating UndetectableExtensionCharm. \n Please stand by... \n" << std::endl;
    
    ::ShowWindow(::GetConsoleWindow(), SW_HIDE);
    return 0;
}