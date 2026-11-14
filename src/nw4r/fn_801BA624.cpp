#include <types.h>
#pragma force_active on

extern "C" s32 OSDisableInterrupts();
extern "C" void OSRestoreInterrupts(s32);
extern "C" void fn_801D3620(s32 arg0, u16* a1, u16* a2, u16* a3, u16* a4, u16* a5);
extern "C" void fn_801BB004(void* self, s32 arg1, ...);
extern "C" void* memcpy(void* dst, const void* src, u32 n);

extern "C" void fn_801BA624(u8* arg0, s32 arg1) {
    u16 zero[10];
    u16 blk[10];
    u16 a, b, c, d, e;

    s32 level = OSDisableInterrupts();
    u8* node = *(u8**)arg0;
    if (node == NULL) {
        OSRestoreInterrupts(level);
        return;
    }
    if (arg1 == 0) {
        zero[0] = 0;
        s32 level2 = OSDisableInterrupts();
        node = *(u8**)arg0;
        if (node == NULL) {
            OSRestoreInterrupts(level2);
        } else {
            memcpy(node + 0x13c, zero, 0x14);
            *(u32*)(arg0 + 4) |= 0x10000000;
            OSRestoreInterrupts(level2);
        }
    } else {
        s32 flag = 0;
        if (node != NULL) {
            if (*(u16*)(node + 0x13c) == 2) {
                flag = 1;
            }
        }
        if (flag != 0) {
            fn_801D3620(arg1, &a, &b, &c, &d, &e);
            fn_801BB004(arg0, 2, a, b, c, d, e);
        } else {
            blk[0] = 2;
            blk[1] = 0;
            blk[2] = 0;
            blk[3] = 0;
            blk[4] = 0;
            fn_801D3620(arg1, &blk[5], &blk[6], &blk[7], &blk[8], &blk[9]);
            s32 level2 = OSDisableInterrupts();
            node = *(u8**)arg0;
            if (node == NULL) {
                OSRestoreInterrupts(level2);
            } else {
                memcpy(node + 0x13c, blk, 0x14);
                *(u32*)(arg0 + 4) |= 0x10000000;
                OSRestoreInterrupts(level2);
            }
        }
    }
    OSRestoreInterrupts(level);
}