#include <types.h>
#pragma force_active on

void* fn_8024231C(void*);
void fn_8023F844(u8*, s32, u32*);
void* memcpy(void*, void*, u32);
void* memset(void*, s32, u32);
extern u32 lbl_8040D768[];

void fn_80232B9C(u8* arg0) {
    u32 sp8[2];
    void* temp;
    u32 bit;
    u8 index;
    temp = fn_8024231C(arg0 + 8);
    if (temp != NULL) {
        memcpy(sp8, temp, 8);
    } else {
        memset(sp8, 0, 8);
    }
    if (arg0[0xF] != 2) {
        if (arg0[0xF] == 0) {
            if (arg0[0xE] <= 0x17U) {
                bit = lbl_8040D768[arg0[0xE]];
                index = bit / 32;
                sp8[index] |= 1 << (bit - index * 32);
            }
        }
        fn_8023F844(arg0 + 8, 0, sp8);
        return;
    }
    fn_8023F844(arg0 + 8, 0xB, sp8);
}
