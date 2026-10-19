#include <types.h>
#pragma force_active on

extern "C" void fn_27_7700(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_41_155DC(void* a, s32 b) {
    if (a != 0) {
        void* p = (char*)a + 8;
        if (p != 0) {
            fn_27_7700(p, 0);
        }
        if ((s16)b > 0) {
            __dl__FPv(a);
        }
    }
    return a;
}
