#include <types.h>
#pragma force_active on

extern "C" void fn_72_F6C(void* this_, void* outInt, void* outFloat);

extern "C" void fn_72_F6C(void* this_, void* outInt, void* outFloat) {
    *(u32*)outInt = *(u32*)((u8*)this_ + 0x188);
    *(float*)outFloat = *(float*)((u8*)this_ + 0x18C);
}
