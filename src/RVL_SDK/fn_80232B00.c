#include <types.h>
#pragma force_active on

void* fn_8024231C(void*);
void fn_8023F780(void*, s32, u8, void*, void*);
void* memcpy(void*, void*, u32);
void* memset(void*, s32, u32);

void fn_80232B00(u8* arg0) {
    u8 sp8[8];
    void* temp_r3;

    temp_r3 = fn_8024231C(arg0 + 8);
    if (temp_r3 != NULL) {
        memcpy(sp8, temp_r3, 8);
    } else {
        memset(sp8, 0, 8);
    }
    if (arg0[0xE] != 0) {
        fn_8023F780(arg0 + 8, 0, arg0[0xF], arg0 + 0x10, sp8);
        return;
    }
    fn_8023F780(arg0 + 8, 0xB, 0, NULL, sp8);
}
