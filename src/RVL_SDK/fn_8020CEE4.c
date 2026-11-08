#include <revolution/OS/OSTime.h>
#pragma force_active on
extern void fn_8020CFB0(int, int *);
extern int fn_80215368(void (*)(int, int *), int *);
extern s64 fn_803F1470(s64, s64);
int fn_8020CEE4(int final, unsigned int event) {
    if (!final) {
        if (event == 2) {
            int shutdown = 0;
            s64 start = OSGetTime();
            fn_80215368(fn_8020CFB0, &shutdown);
            while (fn_803F1470(OSGetTime() - start, OS_TIME_SPEED / 1000) < 500) {
                if (shutdown) break;
            }
        }
        return 1;
    }
    return 1;
}