#pragma force_active on
#include <types.h>

typedef struct {
    s32 field0;
    s32 field4;
    u32 field8;
    s32 fieldC;
    s32 field10;
} TableEntry;
extern TableEntry lbl_804169B0[];

typedef struct {
    u16 field0;
    u8 pad[4];
    u8 byte6;
    u8 pad2[0x15];
    s32 field_1c;
    u8 pad3;
    u8 byte21;
} Inner;

typedef struct {
    s32 pad[3];
    s32 field_c;
    s32 field_10;
    s32 pad2[7];
    s32* field_30;
    Inner* inner;
} Outer;

extern s32 fn_803B5650(Inner*, s32*, u32);
extern s32 fn_803B5CEC(Outer*, s32, u32, s32*, u32*, s32*);

s32 fn_803B6A08(Outer* arg0, s32 arg1, s32 arg2, u32 arg3, s32* arg4) {
    Inner* inner;
    s32 sp10;
    u32 spC;
    s32 sp8;
    s32 result;
    s32 current;
    u32 count;

    inner = arg0->inner;
    sp10 = -1;
    spC = 1;
    current = arg1;
    count = 0;
    result = fn_803B5650(inner, &sp8, arg1);
    if (result != 0) {
        return result;
    }
    while (sp10 != 0) {
        count += (u32)inner->field0 << inner->byte21;
        *arg4 += 1;
        if ((u32)count >= arg3) {
            break;
        }
        result = fn_803B5CEC(arg0, current, arg2, &sp10, &spC, &sp8);
        if (result != 0) {
            return result;
        }
        if ((u32)sp10 == (u32)lbl_804169B0[inner->field_1c].field8) {
            arg0->field_c = current;
            arg0->field_10 = (s32)(arg2 - 1);
            break;
        }
        current = sp10;
        arg2 += 1;
    }
    return 0;
}
