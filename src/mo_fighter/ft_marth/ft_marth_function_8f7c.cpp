#include <types.h>
#pragma force_active on

extern "C" {
void* fn_106_8F1C(void* ptr, s16 flag);
void* fn_106_8DE8(void* p, s16 n);
void __dl__FPv(void* p);

void* fn_106_8F7C(void* ptr, s16 arg2) {
    void* ret = ptr;
    if (ptr != nullptr) {
        fn_106_8F1C((char*)ptr + 0x134, -1);
        if (ptr != nullptr) {
            fn_106_8DE8(ptr, 0);
        }
        if (arg2 > 0) {
            __dl__FPv(ptr);
        }
    }
    return ret;
}
}
