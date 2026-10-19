#include <types.h>
#pragma force_active on

extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" u8 lbl_1_data_7A28[];
extern "C" u8 lbl_1_data_7B30[];

extern "C" void fn_1_29304() {
    u32* p = (u32*)__nw__FUlQ25Heaps8HeapType(0x2c, 0x2e);
    if (p) {
        p[0] = (u32)lbl_1_data_7A28;
        p[1] = (u32)lbl_1_data_7B30;
        p[2] = 0;
        p[10] = 0;
    }
}
