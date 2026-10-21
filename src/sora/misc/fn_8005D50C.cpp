#include <types.h>
#pragma force_active on

extern "C" void fn_8005D4F8(void* a, int* b, int c);
extern "C" void fn_80164480(int arg, void (*cb)(void*, int*, int), int* p, int flag);

extern "C" int fn_8005D50C(int* arg0, int arg1) {
    *arg0 = 0;
    fn_80164480(arg1, fn_8005D4F8, arg0, 1);
    return *arg0;
}
