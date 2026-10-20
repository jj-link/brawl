#include <types.h>
#pragma force_active on

extern "C" {
extern void* lbl_27_bss_6148;
extern void fn_27_271B60(void*, s32, s32);
extern void __dl__FPv(void*);
extern u8 lbl_27_data_58060[];
}

extern "C" void* fn_27_272420(void* p, s32 arg2) {
    if (p) {
        *(void**)p = lbl_27_data_58060;
        u8 b5 = ((u8*)p)[5];
        void* bss = lbl_27_bss_6148;
        if (b5 && bss) {
            fn_27_271B60(bss, 0, ((u8*)p)[4]);
        }
        if (arg2 > 0)
            __dl__FPv(p);
    }
    return p;
}