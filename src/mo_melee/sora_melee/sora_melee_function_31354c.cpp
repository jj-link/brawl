#include <types.h>
#pragma force_active on

extern "C" void fn_27_3135A8(void* p, s32 n);

extern "C" void* fn_27_31354C(void* p, s32 n) {
    if (p) {
        fn_27_3135A8((char*)p + 0x8, -1);
        if (n > 0) {
            ::operator delete(p);
        }
    }
    return p;
}
