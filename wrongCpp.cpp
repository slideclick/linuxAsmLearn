#include <iostream>
#include <string>
#include <windows.h>
// should not print Oh while it will
// https://msdn.microsoft.com/zh-cn/library/hh567368.aspx#concurrencytable
// http://www.ituring.com.cn/article/194454
// http://blog.csdn.net/haoel/article/details/4028232
// http://blog.csdn.net/cgxrit/article/details/43741771
// http://www.aristeia.com/Papers/DDJ_Jul_Aug_2004_revised.pdf

DWORD WINAPI ThreadProc(LPVOID lpParameter)
{
    static std::string x = std::string(10000000, 'e');
    if (x.length() == 0) {
        std::cout << "Oh!" << std::endl;
    }
    else {
        std::cout << x.length() << std::endl;
    }

    return 0;
}

int main()
{
    CreateThread(NULL, 0, ThreadProc, NULL, 0, NULL);
    CreateThread(NULL, 0, ThreadProc, NULL, 0, NULL);
    Sleep(100);
    return 0;
}