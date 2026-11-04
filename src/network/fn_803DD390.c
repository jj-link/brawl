#pragma force_active on

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;

typedef struct File {
    u8 pad[0x20];
    u8 shift;
} File;

typedef struct State {
    s32 value;
    File *file;
    u8 pad08[0x34];
    File *source;
    s32 field40;
    u32 field44;
    u16 field48;
    u16 mask;
    u8 buffer[0x20];
    u8 shift;
} State;

typedef struct Src {
    u8 pad[0x34];
    File *source;
} Src;

typedef struct Dst {
    u16 h0;
    u8 pad2[0x208];
    u8 b20A;
    u8 b20B;
    u8 b20C;
    u8 pad20D[0x1F];
    File *u22C;
} Dst;

extern char lbl_805644C0[];

s32 fn_803DC790(Dst *, State *, s32, s32, s32, s32 *);
s32 fn_803DED54(State *, s32);
s32 fn_803DEE48(State *);
s32 fn_803DEF54(State *, s32);
s32 fn_803E8BD0(s32, s32 *);

s32 fn_803DD390(Src *arg0, Dst *arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 *arg6, s32 *arg7) {
    s32 spC;
    s32 sp8;
    State st;
    u32 r11;
    s32 r23;
    s32 t;

    sp8 = arg2;
    r11 = 0;
    *arg6 = 0;
    *arg7 = 0;
    arg1->b20A = 0;
    arg1->b20B = 0;
    arg1->b20C = 0;
    arg1->h0 = 0;
    spC = 0;
    if ((*(u32 *)(lbl_805644C0 + 0x60) & 2) == 2) {
        r11 = fn_803E8BD0(arg3, &sp8);
    }
    *(Src *)&st.pad08 = *arg0;
    if (r11 == 1) {
        t = fn_803DED54(&st, sp8 - 1);
        if (t != 0) {
            *arg6 = 0xF423F;
            *arg7 = 0xF423F;
            return t;
        }
        if (fn_803DC790(arg1, &st, arg3, arg4, arg5, &spC) == 0) {
            *arg6 = 0xF423F;
            *arg7 = 0xF423F;
            return 3;
        }
        if (st.buffer[0] & 0x40) {
            t = fn_803DED54(&st, sp8);
            if (t != 0) {
                *arg6 = 0xF423F;
                *arg7 = 0xF423F;
                return t;
            }
            if (fn_803DC790(arg1, &st, arg3, arg4, arg5, &spC) == 0) {
                arg1->u22C = arg0->source;
                *arg6 = spC;
                *arg7 = st.value;
                return 0;
            }
        }
        goto fail3;
    }
    r23 = fn_803DED54(&st, sp8);
    while (fn_803DEE48(&st) == 0) {
        if (r23 != 0) {
            *arg6 = 0xF423F;
            *arg7 = 0xF423F;
            return r23;
        }
        if (st.buffer[0] != 0) {
            if (st.buffer[0] == 0xE5) {
                arg1->b20A = 0;
                arg1->h0 = 0;
            } else if (fn_803DC790(arg1, &st, arg3, arg4, arg5, &spC) == 0) {
                arg1->u22C = arg0->source;
                *arg6 = spC;
                *arg7 = st.value;
                return 0;
            }
            r23 = fn_803DEF54(&st, 0);
        } else {
            goto fail3;
        }
    }
fail3:
    *arg6 = 0xF423F;
    *arg7 = 0xF423F;
    return 3;
}
