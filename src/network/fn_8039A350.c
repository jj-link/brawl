#include <types.h>
#pragma force_active on
extern u32 fn_8020E18C(void);
extern void fn_8020FC90(void *);
extern s32 fn_80210064(void);
extern s32 fn_802100A0(void);
extern s32 fn_802100DC(void);
extern s32 fn_8038E86C(s32 *, s32 *, s32 *);
extern void fn_80399BB8(s32 *);
extern s32 fn_8039A53C(s32 *, s32);
extern s32 fn_8039C05C(s32, s32);
extern s32 lbl_805A1174;
extern s32 lbl_805A117C;

s32 fn_8039A350(s32 arg0) {
    s32 sp1C[17];
    s32 sp18;
    s32 sp14;
    s32 sp10;
    s32 spC;
    s32 sp8;
    u32 temp_r3;
    s32 temp_r29;
    s32 temp_r30;
    s32 temp_r28;
    s32 var_r31;
    s32 temp_r3_2;

    lbl_805A117C = 0;
    if (lbl_805A1174 != 1) {
        var_r31 = -9;
    } else {
        var_r31 = -0x27;
        do {
            temp_r3 = fn_8020E18C();
        } while (temp_r3 == 1U);
        if (temp_r3 == 2U) {
            lbl_805A117C = 0xFFFE55C8;
        } else {
            temp_r29 = fn_802100DC() & 1;
            temp_r30 = fn_802100A0();
            temp_r28 = fn_80210064() & 2;
            fn_8020FC90(&sp1C);
            if (temp_r29 == 0) {
                lbl_805A117C = 0xFFFE55AD;
            } else if (temp_r30 == 0) {
                lbl_805A117C = 0xFFFE55CD;
            } else {
                if ((arg0 & 1) != 0 && (*(u8 *)&sp1C & 0x80) != 0 && temp_r28 != 0) {
                    lbl_805A117C = 0xFFFE55CD;
                } else {
                    var_r31 = -0x1F;
                    if (fn_8038E86C(&sp18, &sp14, &sp10) < 0) {
                        lbl_805A117C = 0xFFFE55B3;
                    } else if (sp18 == 0 && sp14 == 0 && sp10 == 0) {
                        lbl_805A117C = 0xFFFF3B85;
                    } else if ((arg0 & 1) != 0 && (fn_80399BB8(&spC), spC != 2)) {
                        lbl_805A117C = 0xFFFE55A8;
                    } else {
                        sp8 = 0;
                        temp_r3_2 = fn_8039A53C(&sp8, arg0);
                        if (temp_r3_2 < 0) {
                            var_r31 = temp_r3_2;
                            lbl_805A117C = sp8;
                        } else {
                            temp_r3_2 = fn_8039C05C(0, 0);
                            var_r31 = temp_r3_2;
                            if (temp_r3_2 == -6) {
                                lbl_805A117C = 0xFFFE55CE;
                            } else {
                                var_r31 = 0;
                            }
                        }
                    }
                }
            }
        }
    }
    return var_r31;
}