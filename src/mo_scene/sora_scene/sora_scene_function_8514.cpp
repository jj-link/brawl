#include <types.h>
#pragma force_active on

extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void* fn_1_13920(void*, const char*);
extern "C" const char lbl_1_data_1DD0[];
extern "C" u8 lbl_1_data_1F30[];

extern "C" void* fn_1_8514() {
    void* obj = __nw__FUlQ25Heaps8HeapType(0x100, 0x2e);
    if (obj) {
        fn_1_13920(obj, lbl_1_data_1DD0);
        *(void**)((u8*)obj + 4) = lbl_1_data_1F30;
    }
    return obj;
}
