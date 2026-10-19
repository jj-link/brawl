#include <types.h>
#pragma force_active on

extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void fn_1_13920(void* self, const char* name);
extern "C" const char lbl_1_data_5CA8[];
extern "C" char lbl_1_data_5CB8[];

extern "C" void* fn_1_1B750() {
    void* obj = __nw__FUlQ25Heaps8HeapType(0x100, 0x2e);
    if (obj) {
        fn_1_13920(obj, lbl_1_data_5CA8);
        ((u32*)obj)[1] = (u32)lbl_1_data_5CB8;
    }
    return obj;
}
