#include <types.h>
#pragma force_active on

extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" u8 lbl_1_data_64E8[];
extern "C" u8 lbl_1_data_65C8[];

extern "C" void fn_1_2006C() {
    u32* obj = (u32*)__nw__FUlQ25Heaps8HeapType(0x34, 0x2E);
    if (obj) {
        obj[0] = (u32)lbl_1_data_64E8;
        obj[1] = (u32)lbl_1_data_65C8;
        obj[6] = 0;
        obj[11] = 0;
        obj[12] = 0;
    }
}
