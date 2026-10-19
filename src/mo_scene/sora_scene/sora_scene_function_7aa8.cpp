#include <types.h>
#pragma force_active on

extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void fn_1_13920(void* self, const char* name);
extern "C" const char lbl_1_data_1B30[];
extern "C" const char lbl_1_data_1BD0[];

extern "C" void* fn_1_7AA8() {
    void* obj = __nw__FUlQ25Heaps8HeapType(0x108, 0x2e);
    if (obj) {
        fn_1_13920(obj, lbl_1_data_1B30);
        ((u32*)obj)[1] = (u32)lbl_1_data_1BD0;
        ((u8*)obj)[0xfd] = 0;
        ((u32*)obj)[0x40] = 0;
        ((u32*)obj)[0x41] = 0;
    }
    return obj;
}
