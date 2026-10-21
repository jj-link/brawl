#include <types.h>
#pragma force_active on

extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void fn_6_180(void*, void*);
extern "C" void fn_6_278(void*, int, int, void*);
extern "C" u8 lbl_8_data_0[];
extern "C" u8 lbl_8_data_10C[];
extern "C" u8 lbl_8_data_318[];
extern "C" u8 lbl_8_data_C[];

extern "C" void* fn_8_0(void* arg0) {
    void* obj = __nw__FUlQ25Heaps8HeapType(0x1B0, 0x2a);
    void* obj2;
    if (obj) {
        fn_6_180(obj, lbl_8_data_0);
        *(void**)((u8*)obj + 0x3c) = lbl_8_data_10C;
    }
    obj2 = __nw__FUlQ25Heaps8HeapType(0x1D20, 0x2a);
    if (obj2) {
        fn_6_278(obj2, 0x19, 4, lbl_8_data_C);
        *(void**)((u8*)obj2 + 0x1D08) = lbl_8_data_318;
        *(int*)((u8*)obj2 + 0x1D0C) = 0;
        *(int*)((u8*)obj2 + 0x1D10) = 0;
        *(int*)((u8*)obj2 + 0x1D14) = 0;
        *(int*)((u8*)obj2 + 0x1CF8) = 0xF;
    }
    *(void**)((u8*)obj + 0x1AC) = obj2;
    *(void**)((u8*)obj2 + 0x1D0C) = arg0;
    return obj;
}
