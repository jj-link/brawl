#include <types.h>
#pragma force_active on

extern "C" void fn_27_3135A8(void* p, s32 n);
void operator delete(void* p);

extern "C" void* fn_27_313410(void* p, s32 n) {
    if (p) {
        if ((u32)p + 8 && (u32)p + 8 && (u32)p + 0xc) {
            fn_27_3135A8((char*)p + 0x14, -1);
        }
        if (n > 0) {
            operator delete(p);
        }
    }
    return p;
}
