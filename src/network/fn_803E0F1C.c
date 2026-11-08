#pragma force_active on
#include <types.h>
typedef struct { s32 field0, field4; u32 field8; s32 fieldC, field10; } TableEntry;
extern TableEntry lbl_8041B0E0[];
typedef struct { u16 field0; u8 pad[4]; u8 field6; u8 pad2[0x15]; s32 state; } Inner;
typedef struct { s32 pad[3]; s32 fieldC, field10; s32 pad2[8]; Inner* inner; } Outer;
extern s32 fn_803DFF50(Outer*, s32, u32, s32*, u32*);
s32 fn_803E0F1C(Outer* arg0, s32 arg1, u32 arg2, u32 arg3, s32* arg4)
{
    Inner* inner;
    s32 spC;
    u32 sp8;
    s32 r;
    s32 current;
    u32 acc;
    inner = arg0->inner;
    spC = -1;
    current = arg1;
    sp8 = 1;
    acc = 0;
    while (spC != 0) {
        acc += inner->field0 * inner->field6;
        *arg4 += 1;
        if (acc >= arg3) break;
        r = fn_803DFF50(arg0, current, arg2, &spC, &sp8);
        if (r != 0) return r;
        if ((u32)spC == lbl_8041B0E0[inner->state].field8) {
            arg0->fieldC = current;
            arg0->field10 = arg2 - 1;
            break;
        }
        current = spC;
        arg2++;
    }
    return 0;
}