#include <types.h>
#pragma force_active on

extern "C" {
u32 OSDisableInterrupts(void);
void OSRestoreInterrupts(u32);
void fn_80202510(u32, u16*, u16*);
void* memcpy(void*, const void*, unsigned long);
}

struct Sub {
    char pad[0xE2];
    u16 unkE2;
    u16 unkE4;
    u16 unkE6;
    u16 unkE8;
};

struct Obj {
    Sub* unk0;
    u32 unk4;
};

extern "C" void fn_801BA494(Obj* arg0, u32 arg1) {
    u32 saved = OSDisableInterrupts();
    u32 lv2;
    if (arg0->unk0 == 0) {
        OSRestoreInterrupts(saved);
        return;
    }
    if (arg1 >= 0x3E80) {
        u16 buf2[4];
        buf2[0] = 0;
        buf2[1] = 0;
        u32 lv1 = OSDisableInterrupts();
        Sub* s = arg0->unk0;
        if (s == 0) {
            OSRestoreInterrupts(lv1);
        } else {
            memcpy(&s->unkE2, buf2, 8);
            arg0->unk4 |= 0x80000;
            OSRestoreInterrupts(lv1);
        }
    } else {
        int var = 0;
        if (arg0->unk0 != 0 && arg0->unk0->unkE2 == 1) {
            var = 1;
        }
        if (var != 0) {
            u16 x;
            u16 y;
            fn_80202510(arg1, &x, &y);
            u16 a;
            u16 b;
            b = y;
            a = x;
            u32 s2 = OSDisableInterrupts();
            if (arg0->unk0 == 0) {
                OSRestoreInterrupts(s2);
            } else {
                arg0->unk0->unkE6 = a;
                arg0->unk0->unkE8 = b;
                arg0->unk4 |= 0x100000;
                OSRestoreInterrupts(s2);
            }
        } else {
            u16 buf1[4];
            buf1[0] = 1;
            buf1[1] = 0;
            fn_80202510(arg1, &buf1[2], &buf1[3]);
            lv2 = OSDisableInterrupts();
            Sub* s = arg0->unk0;
            if (s == 0) {
                OSRestoreInterrupts(lv2);
            } else {
                memcpy(&s->unkE2, buf1, 8);
                arg0->unk4 |= 0x80000;
                OSRestoreInterrupts(lv2);
            }
        }
    }
    OSRestoreInterrupts(saved);
}
