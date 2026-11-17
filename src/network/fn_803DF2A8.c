#include <types.h>
#pragma force_active on

typedef struct State {
    u32 position;
    s32 handle;
    u8 pad08[0x34];
    u32 field3C;
    u32 pad40;
    u32 sector;
    u16 length;
    u16 pad4A;
    u8 data[0x20];
} State;

typedef struct Out {
    u16 unk0;
    u8 pad02[0x208 - 0x02];
    u8 pad208[0x20A - 0x208];
    u8 unk20A;
    u8 unk20B;
    u8 unk20C;
    u8 pad20D;
    u8 unk20E[0x21C - 0x20E];
    u8 unk21C;
    u8 pad21D[0x22C - 0x21D];
    u32 unk22C;
    u8 pad230[0x234 - 0x230];
    u32 unk234;
    u32 unk238;
    u16 unk23C;
} Out;

extern s32 PFSEC_ReadData(s32, void *, u32, u16, u32, u32 *, s32);
extern u8 fn_803DCE4C(void *);
extern void fn_803DCEBC(void *, void *);
extern void fn_803DCF04(void *, void *);
extern s32 fn_803DD04C(void *, void *);
extern s32 fn_803DDF18(void *, s32);
extern s32 fn_803DEE48(void *);
extern void fn_803E799C(void *, void *, u8);
extern s32 fn_803E7D7C(void *, void *);

s32 fn_803DF2A8(State *arg0, Out *arg1, u32 arg2, s32 *arg3)
{
    s32 temp_r4;
    s32 temp_r5;
    s32 var_r24;
    u32 temp_r23;
    s32 var_r23;
    s32 var_r4;
    s32 temp_r3_2;
    s32 temp_r3_3;
    s32 temp_r3_4;
    s32 temp_r3_5;
    s32 temp_ret;
    u8 spC[0x14];
    u32 sp8;
    u8 temp_r3;

    var_r23 = 0;
    *arg3 = 0;
    arg1->unk20A = 0;
    arg1->unk20B = 0;
    arg1->unk20C = 0;
    if ((arg1->unk21C & 0x10) && arg1->unk234 == 1) {
        return 2;
    }

    while (fn_803DEE48(arg0) == 0) {
        if (var_r23 != 0) {
            return var_r23;
        }
        if (arg0->data[0] == 0xE5) {
            arg1->unk20A = 0;
            arg1->unk0 = 0;
            goto block_34;
        }
        temp_r3 = arg0->data[0xB];
        if ((temp_r3 & 0xF) == 0xF) {
            if (fn_803DD04C(arg1, arg0->data) != 0) {
                arg1->unk20A = 0;
                arg1->unk0 = 0;
            }
            goto block_34;
        }
        if (temp_r3 & 0x8) {
            arg1->unk20A = 0;
            arg1->unk0 = 0;
            goto block_34;
        }
        if (!(temp_r3 & 0x10)) {
            arg1->unk20A = 0;
            arg1->unk0 = 0;
            goto block_34;
        }
        fn_803DCEBC(arg1, arg0->data);
        if (arg1->unk20A != 0 && arg1->unk20B == 1 && arg1->unk20C == fn_803DCE4C(arg1)) {
            fn_803DCF04(arg1, arg0->data);
            arg1->unk238 = arg0->sector;
            temp_r3_2 = arg1->unk21C & 0x10;
            arg1->unk23C = arg0->length;
            arg1->unk22C = arg0->field3C;
            if (temp_r3_2 != 0 && arg1->unk234 != arg2) {
                arg1->unk20A = 0;
                arg1->unk0 = 0;
                goto block_34;
            }
            if (temp_r3_2 != 0 && arg1->unk234 == 0) {
                arg1->unk234 = 1;
            }
            *arg3 = 1;
        }
        if (arg0->data[0x0C] & 0x18) {
            fn_803E799C(arg1->unk20E, spC, arg0->data[0x0C]);
            temp_ret = fn_803E7D7C(arg1, spC);
            temp_r4 = temp_ret % 13;
            temp_r5 = temp_ret / 13;
            arg1->unk20A = (u8)(temp_r5 + (temp_r4 != 0));
            arg1->unk20C = fn_803DCE4C(arg1);
            arg1->unk20B = 1;
        }
        fn_803DCF04(arg1, arg0->data);
        arg1->unk238 = arg0->sector;
        temp_r3_3 = arg1->unk21C & 0x10;
        arg1->unk23C = arg0->length;
        arg1->unk22C = arg0->field3C;
        if (temp_r3_3 != 0 && arg1->unk234 != arg2) {
            arg1->unk20A = 0;
            arg1->unk0 = 0;
            *arg3 = 0;
            goto block_34;
        }
        if (temp_r3_3 != 0 && arg1->unk234 == 0) {
            arg1->unk234 = 1;
        }
        *arg3 = 1;
        return 0;

block_34:
        temp_r23 = arg0->position;
        arg0->position = temp_r23 + 1;
        temp_r3_4 = fn_803DDF18(arg0, 0);
        var_r24 = temp_r3_4;
        if (temp_r3_4 != 0) {
            arg0->position = temp_r23;
            fn_803DDF18(arg0, 0);
        } else {
            if (arg0->sector == 0xFFFFFFFFU) {
                var_r4 = 0x10;
            } else {
                temp_r3_5 = PFSEC_ReadData(arg0->handle, arg0->data, arg0->sector, arg0->length, 0x20, &sp8, 0);
                var_r4 = 0x11;
                if (sp8 == 0x20U) {
                    var_r4 = temp_r3_5;
                }
            }
            var_r24 = var_r4 & ((-var_r4 | var_r4) >> 31);
        }
        var_r23 = var_r24 & ((-var_r24 | var_r24) >> 31);
    }
    return 0;
}