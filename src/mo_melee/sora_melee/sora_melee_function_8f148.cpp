#include <types.h>
#pragma force_active on

extern "C" void* fn_27_71BC(void* p, s32 n);
extern "C" void __destroy_arr(void* p, void (*dtor)(void*, int), u32 size, u32 count);
extern "C" void __dl__FPv(void* p);

extern "C" void* fn_27_8F148(void* p, s32 n) {
    if (p) {
        if (p && (char*)p + 0x14 != 0) {
            __destroy_arr((char*)p + 0x20, (void (*)(void*, int))fn_27_71BC, 8, 0x1F4);
        }
        if (n > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
