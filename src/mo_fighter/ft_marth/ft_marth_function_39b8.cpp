#include <types.h>
#pragma force_active on

extern "C" {
void* fn_27_1A15B8(void*, s16);
void* fn_106_3A30(void*, s16);
void __dl__FPv(void*);

void* fn_106_39B8(void* ptr, s16 arg2) {
    if (ptr != nullptr) {
        fn_27_1A15B8((char*)ptr + 0x2FC, -1);
        if (ptr != nullptr) {
            fn_106_3A30(ptr, 0);
        }
        if (arg2 > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
}
