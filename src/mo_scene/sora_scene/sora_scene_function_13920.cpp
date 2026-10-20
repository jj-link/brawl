#include <types.h>
#pragma force_active on

extern "C" {
extern char lbl_1_data_5AB8[];
extern u32 lbl_1_data_4FE0;
void fn_1_139E0(void*);
}

extern "C" void* fn_1_13920(void* obj, void* vtbl) {
    *(void**)((char*)obj + 0x0) = vtbl;
    *(char**)((char*)obj + 0x4) = lbl_1_data_5AB8;
    *(u32*)((char*)obj + 0xB8) = lbl_1_data_4FE0;
    *(u32*)((char*)obj + 0xBC) = 0;
    *(u32*)((char*)obj + 0xC0) = lbl_1_data_4FE0;
    *(u32*)((char*)obj + 0xC4) = 0;
    *(u32*)((char*)obj + 0xC8) = lbl_1_data_4FE0;
    *(u32*)((char*)obj + 0xCC) = 0;
    *(s8*)((char*)obj + 0xEC) = -1;
    *(u8*)((char*)obj + 0xFA) = 0xFF;
    *(u8*)((char*)obj + 0xFB) = 0xFF;
    fn_1_139E0(obj);
    return obj;
}
