#include <types.h>
#pragma force_active on

extern char lbl_8053B248[];

typedef struct Hdr {
    u32 unk00;
    u32 unk04;
    u32 unk08;
    u32 unk0C;
    u32 unk10;
    u32 unk14;
    u32 unk18;
    u32 unk1C;
    u32 unk20;
    u32 unk24;
    u32 unk28;
    u32 unk2C;
    u32 unk30;
    u16 *unk34;
} Hdr;

typedef struct State {
    s32 value;
    void *file;
    Hdr hdr;
    s32 field40;
    u32 field44;
    u16 field48;
    u16 mask;
    u8 buffer[0x20];
    u8 shift;
} State;

typedef struct Blob {
    u32 w[0x90];
} Blob;

typedef struct Dst {
    u8 pad000[0x22C];
    u16 *unk22C;
    u8 pad230[0x8];
    s32 unk238;
    u16 unk23C;
} Dst;

typedef struct Pair {
    s32 a;
    s32 b;
} Pair;

extern s32 fn_803B2240(Blob *, State *, s32, s32, s32, s32 *);
extern s32 fn_803B4F28(State *, s32);
extern s32 fn_803B5138(State *, s32);
extern s32 fn_803B7080(Hdr *, u32, s32, u32 *);
extern u32 fn_803BFA20(s32);

s32 fn_803B3290(Dst *arg0, s32 arg1, Hdr *arg2, Pair *arg3, s32 arg4, s32 *arg5) {
    State st;
    Blob sp80;
    u32 spC;
    s32 sp8;
    u16 *temp_r31;
    s32 temp_r3;
    s32 var_r3;
    u32 var_r30;
    u16 var_r29;
    u32 var_r28;
    u32 var_r27;
    u32 var_r26;
    u32 var_r25;
    u32 var_r24;
    s32 var_r23;

    if (arg2 == NULL) {
        return 0xA;
    }
    if (arg2->unk34 == NULL) {
        return 0xA;
    }
    if (arg1 == 0) {
        return 0xA;
    }
    if ((u32)arg1 > 0x15U) {
        return 0xA;
    }
    if ((((*(u32 *)(lbl_8053B248 + 0x3C)) & 2) == 2) && fn_803BFA20(arg4) == 1) {
        return 1;
    }

    temp_r31 = arg2->unk34;
    var_r30 = -1;
    var_r24 = 0;
    arg3->b = -1;
    var_r23 = 0;
    var_r29 = 0;
    var_r28 = -1;
    arg3->a = -1;
    var_r26 = -1;
    var_r27 = -1;
    var_r25 = 0;
    st.field44 = 0;
    st.value = 0;
    st.hdr = *arg2;
    var_r3 = fn_803B4F28(&st, 0);

    for (;;) {
        if (var_r3 != 0) {
            if (var_r3 == 0x10) {
                goto done;
            }
            return var_r3;
        }
        if (st.field44 == 0xFFFFFFFFU) {
            goto done;
        }
        if (var_r25 == 0 && var_r24 == 0) {
            var_r29 = st.field48;
            var_r30 = st.field44;
            var_r28 = st.field44;
        }
        if (var_r25 == 0) {
            if (st.buffer[0] == 0 || st.buffer[0] == 0xE5) {
                if (var_r28 != st.field44) {
                    if (var_r27 + 1 == 0) {
                        var_r27 = st.field44;
                    } else {
                        var_r26 = st.field44;
                    }
                    var_r28 = st.field44;
                }
                var_r24++;
            } else {
                var_r24 = 0;
                var_r27 = -1;
                var_r26 = -1;
            }
        }
        if (var_r24 >= (u32)arg1) {
            if (var_r25 == 0) {
                var_r23 = st.value;
                var_r25 = 1;
            }
            if (st.buffer[0] == 0) {
                goto done;
            }
        }
        if (st.buffer[0] != 0 && st.buffer[0] != 0xE5 &&
            fn_803B2240(&sp80, &st, arg4, 0x7F, 0, &sp8) == 0) {
            *(Blob *)arg0 = sp80;
            arg0->unk22C = arg2->unk34;
            return 8;
        }
        if ((s32)(st.field48 + 0x20) == (s32)*temp_r31) {
            temp_r3 = fn_803B7080(arg2, st.field40 + 1, 0, &spC);
            if (temp_r3 != 0) {
                return temp_r3;
            }
            if (spC == 0xFFFFFFFFU && var_r25 == 1) {
                goto done;
            }
        }
        var_r3 = fn_803B5138(&st, 1);
    }

done:
    if (var_r25 == 0) {
        return 5;
    }
    arg3->a = var_r27;
    arg3->b = var_r26;
    arg0->unk238 = var_r30;
    arg0->unk23C = var_r29;
    *arg5 = var_r23;
    return 0;
}
