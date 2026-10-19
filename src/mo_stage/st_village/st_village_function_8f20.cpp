#include <types.h>
#pragma force_active on

extern "C" const float lbl_70_rodata_11C;

extern "C" void fn_70_8F20(void* obj) {
    u8* b = (u8*)obj;
    u32 v = *(u32*)(b + 0x74);
    float z = lbl_70_rodata_11C;
    *(float*)(b + 0x60) = z;
    *(float*)(b + 0x64) = z;
    *(float*)(b + 0x68) = z;
    *(u32*)(b + 0x74) = v & ~31u;
}
