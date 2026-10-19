#include <types.h>
#pragma force_active on

extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" const char lbl_1_data_5C00[];
extern "C" const char lbl_1_data_5C10[];

extern "C" void* fn_1_1B004() {
    void* obj = __nw__FUlQ25Heaps8HeapType(0xC, 0x2E);
    if (obj != 0) {
        *(const char**)obj = lbl_1_data_5C00;
        *(const char**)((char*)obj + 4) = lbl_1_data_5C10;
    }
    return obj;
}
