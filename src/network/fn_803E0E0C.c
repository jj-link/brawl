#pragma force_active on
#include <types.h>

typedef struct {
    s32 field0;
    s32 field4;
    u32 field8;
    s32 fieldC;
    s32 field10;
} TableEntry;
extern TableEntry lbl_8041B0E0[];

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

extern s32 fn_803DFF50(Outer* arg0, s32 arg1, u32 arg2, s32* arg3, u32* arg4);

s32 fn_803E0E0C(Outer* arg0, s32 arg1, u32 arg2, s32 arg3, s32* arg4) {
    Inner* inner;
    s32 sp_c;
    u32 sp_8;
    s32 result;
    s32 val;

    inner = arg0->inner;
    sp_c = -1;
    sp_8 = 1;

    while (sp_c != 0) {
        result = fn_803DFF50(arg0, arg1, arg2, &sp_c, &sp_8);
        if (result != 0) {
            return result;
        }
        if ((u32)(arg1 + 1) != (u32)sp_c) {
            if ((u32)sp_c == lbl_8041B0E0[inner->state].field8) {
                arg0->field_c = arg1;
                arg0->field_10 = (s32)(arg2 - 1);
            }
            break;
        }
        arg0->field_30[0]++;
        arg0->field_30[1] = sp_c;
        val = *arg4 + inner->byte6;
        *arg4 = val;
        if ((u32)(val << inner->byte20) >= (u32)arg3) {
            break;
        }
        arg1 = sp_c;
        arg2++;
    }
    return 0;
}