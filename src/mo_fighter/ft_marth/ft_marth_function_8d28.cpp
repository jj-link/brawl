#include <types.h>
#pragma force_active on

extern "C" void fn_106_8CC8(void*, s16);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_106_8D28(void* p, s16 n) {
    if (p != 0) {
        fn_106_8CC8((char*)p + 4, -1);
        if (n > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
