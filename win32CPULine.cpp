#include <Windows.h>
#include <stdlib.h>
#include <math.h>
// COUNT * SPLIT = 2
// http://www.ituring.com.cn/article/195430

const int COUNT = 200;
const double SPLIT = 0.01;
const double PI = 3.1415926;
const int HALF_INTERVAL = 200;
int main()
{
    SetThreadAffinityMask(GetCurrentThread(), 0x00000001);
    unsigned int busySpan[COUNT];
    unsigned int idleSpan[COUNT];

    // From 0 to 2PI is a cycle
    double radian = 0.0;
    for (int i = 0; i < COUNT; i++)
    {
        busySpan[i] = (HALF_INTERVAL + sin(PI * radian) * HALF_INTERVAL);
        idleSpan[i] = HALF_INTERVAL * 2 - busySpan[i];
        radian += SPLIT;
    }
    int startTime = 0;
    int j = 0;
    while (true)
    {
        j = j % COUNT;
        startTime = GetTickCount();
        while ((GetTickCount() - startTime) <= busySpan[j]);
        Sleep(idleSpan[j]);
        j++;
    }
    return 0;
}