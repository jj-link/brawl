#pragma force_active on
#include <types.h>

extern "C" void fn_8031830C(void* a, void* b);

extern "C" void fn_80302904(void* arg0, void* arg1, void* arg2) {
    fn_8031830C(arg0, arg2);
    ((u8*)arg1)[2] = ((u8*)arg0)[2];
    *(int*)arg0 = 0;
}
