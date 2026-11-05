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
    u8 pad[6];
    u8 byte6;
    u8 pad2[0x15];
    s32 state;
    u8 byte20;
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

s32 fn_803B68D8(Outer* arg0, s32 arg1, u32 arg2, u32 arg3, s32* arg4) {
    Inner* inner;
    s32 sp10;
    u32 spC;
    s32 sp8;
    s32 result;
    s32 val;
    s32 current;

    inner = arg0->inner;
    sp10 = -1;
    spC = 1;
    current = arg1;
    result = fn_803B5650(inner, &sp8, arg1);
    if (result != 0) {
        return result;
    }
    while (sp10 != 0) {
        result = fn_803B5CEC(arg0, current, arg2, &sp10, &spC, &sp8);
        if (result != 0) {
            return result;
        }
        if ((u32)(current + 1) != (u32)sp10) {
            if ((u32)sp10 == lbl_804169B0[inner->state].field8) {
                arg0->field_c = current;
                arg0->field_10 = (s32)(arg2 - 1);
            }
            break;
        }
        arg0->field_30[0]++;
        arg0->field_30[1] = sp10;
        val = *arg4 + inner->byte6;
        *arg4 = val;
        if ((u32)(val << inner->byte20) >= arg3) {
            break;
        }
        current = sp10;
        arg2++;
    }
    return 0;
}
