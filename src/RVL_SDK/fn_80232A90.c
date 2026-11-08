#include <types.h>
#pragma force_active on

void* fn_8024231C(void*);
s32 fn_8023FA20(u8*, u32, u8*, u32*);
void* memcpy(void*, void*, u32);
void* memset(void*, s32, u32);

void fn_80232A90(u8* arg0) {
    u8 sp8[8];
    void* temp_r3;

    temp_r3 = fn_8024231C(arg0 + 8);
    if (temp_r3 != NULL) {
        memcpy(sp8, temp_r3, 8);
    } else {
        memset(sp8, 0, 8);
    }
    fn_8023FA20(arg0 + 8, arg0[0xE], arg0 + 0xF, (u32*)sp8);
}
