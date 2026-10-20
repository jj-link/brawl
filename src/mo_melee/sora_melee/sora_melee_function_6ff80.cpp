#include <types.h>
#pragma force_active on

extern void* lbl_27_bss_120[];

extern "C" {
void fn_80045E64(void*, u32);
void fn_800461D4(void*, u32);
void fn_27_6FF80(void* p, u32 q) {
    u32* ptr = (u32*)p;
    if (ptr[1] != 0xFFFF) {
        if (q == 0) {
            fn_80045E64(lbl_27_bss_120[ptr[0]], ptr[1]);
        } else {
            fn_800461D4(lbl_27_bss_120[ptr[0]], ptr[1]);
        }
        ptr[1] = 0xFFFF;
    }
}
}
