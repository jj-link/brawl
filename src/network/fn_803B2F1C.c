#include <types.h>
#pragma force_active on
typedef struct Hdr {
    u32 a[13];
    u16 *source;
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
typedef struct Dst {
    u16 h0;
    u8 pad2[0x208];
    u8 b20A, b20B, b20C;
    u8 pad20D[0x1f];
    u16 *source;
} Dst;
extern char lbl_8053B248[];
extern s32 fn_803B2240(Dst *, State *, s32, s32, s32, s32 *);
extern s32 fn_803B4F28(State *, u32);
extern s32 fn_803B502C(State *);
extern s32 fn_803B5138(State *, s32);
extern u32 fn_803BFDB0(s32, u32 *);
s32 fn_803B2F1C(Hdr *arg0, Dst *arg1, u32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 *arg6, s32 *arg7) {
    s32 spC;
    u32 sp8;
    State st;
    u32 special;
    s32 r23;
    s32 t;
    sp8 = arg2;
    special = 0;
    if (arg0 == 0) { *arg6 = 0xF423F; *arg7 = 0xF423F; return 10; }
    if (arg1 == 0) { *arg6 = 0xF423F; *arg7 = 0xF423F; return 10; }
    if (arg2 >= 0xF423F) { *arg6 = 0xF423F; *arg7 = 0xF423F; return 10; }
    if (arg3 == 0) { *arg6 = 0xF423F; *arg7 = 0xF423F; return 10; }
    if (arg4 & arg5) { *arg6 = 0xF423F; *arg7 = 0xF423F; return 10; }
    *arg6 = 0; *arg7 = 0;
    arg1->b20A = 0; arg1->b20B = 0; arg1->b20C = 0; arg1->h0 = 0;
    spC = 0;
    if ((*(u32 *)(lbl_8053B248 + 0x3C) & 2) == 2) {
        special = fn_803BFDB0(arg3, &sp8);
    }
    st.hdr = *arg0;
    if (special == 1) {
        t = fn_803B4F28(&st, sp8 - 1);
        if (t != 0) { *arg6 = 0xF423F; *arg7 = 0xF423F; return t; }
        if (fn_803B2240(arg1, &st, arg3, arg4, arg5, &spC) == 0) {
            *arg6 = 0xF423F; *arg7 = 0xF423F; return 3;
        }
        if (st.buffer[0] & 0x40) {
            t = fn_803B4F28(&st, sp8);
            if (t != 0) { *arg6 = 0xF423F; *arg7 = 0xF423F; return t; }
            if (fn_803B2240(arg1, &st, arg3, arg4, arg5, &spC) == 0) {
                arg1->source = arg0->source;
                *arg6 = spC; *arg7 = st.value; return 0;
            }
        }
        goto fail3;
    }
    r23 = fn_803B4F28(&st, sp8);
    while (fn_803B502C(&st) == 0) {
        if (r23 != 0) { *arg6 = 0xF423F; *arg7 = 0xF423F; return r23; }
        if (st.buffer[0] != 0) {
            if (st.buffer[0] == 0xE5) {
                arg1->b20A = 0;
                arg1->h0 = 0;
            } else if (fn_803B2240(arg1, &st, arg3, arg4, arg5, &spC) == 0) {
                arg1->source = arg0->source;
                *arg6 = spC; *arg7 = st.value; return 0;
            }
            r23 = fn_803B5138(&st, 0);
        } else {
            goto fail3;
        }
    }
fail3:
    *arg6 = 0xF423F; *arg7 = 0xF423F; return 3;
}