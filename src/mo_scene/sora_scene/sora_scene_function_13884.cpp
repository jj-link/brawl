#include <types.h>
#pragma force_active on

extern "C" {
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern char lbl_1_data_5290[];
extern char lbl_1_data_5AB8[];
extern u32 lbl_1_data_4FE0;
void fn_1_139E0(void*);
}

extern "C" void* fn_1_13884() {
    char* obj = (char*)__nw__FUlQ25Heaps8HeapType(0x100, 0x2e);
    if (obj) {
        *(char**)(obj + 0x0) = lbl_1_data_5290;
        *(char**)(obj + 0x4) = lbl_1_data_5AB8;
        *(u32*)(obj + 0xB8) = lbl_1_data_4FE0;
        *(u32*)(obj + 0xBC) = 0;
        *(u32*)(obj + 0xC0) = lbl_1_data_4FE0;
        *(u32*)(obj + 0xC4) = 0;
        *(u32*)(obj + 0xC8) = lbl_1_data_4FE0;
        *(u32*)(obj + 0xCC) = 0;
        *(s8*)(obj + 0xEC) = -1;
        *(u8*)(obj + 0xFA) = 0xFF;
        *(u8*)(obj + 0xFB) = 0xFF;
        fn_1_139E0(obj);
    }
    return obj;
}
