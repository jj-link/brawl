#pragma force_active on
#include <types.h>
#include <revolution/GX/GXHardware.h>

struct Obj {
    u32 flags;
    u8 c4, c5, c6, c7;
    u8 m8, m9, mA, mB;
    u32 w0C, w10, flags14;
    u8 c18, c19, c1A, c1B;
    u8 c1C, c1D, c1E, c1F;
    u32 w20, w24;
};

struct Obj44C0 {
    u8 b0, b1, b2, b3;
    s32 d4;
    u32 d8;
};

extern "C" {
extern Obj44C0 lbl_804A44C0;
extern const f32 lbl_805A332C, lbl_805A3330;
void fn_8019DA9C(u8, u8, u8, u8, s32);
}

#define GXW8(v) (WGPIPE.uc = (u8)(v))
#define GXW16(v) (WGPIPE.us = (u16)(v))
#define GXW32(v) (WGPIPE.ui = (u32)(v))

#define COLOR(o, a, b, c, d, addr) { \
    u8 p[4]; \
    p[0] = (o)->a; p[1] = (o)->b; p[2] = (o)->c; p[3] = (o)->d; \
    GXW8(0x10); GXW16(0); GXW16(addr); GXW32(*(u32*)p); \
}

inline void sendColor(u32 value) {
    GXW8(0x10);
    GXW16(0);
    GXW16(0x100A);
    GXW32(value);
}

inline void sendCtrl(u32 addr, u32 value, u32 arg, u32 mask) {
    value &= mask;
    value |= ((arg << 2) & 0x3c) | ((arg << 7) & 0x7800);
    GXW8(0x10);
    GXW16(0);
    GXW16(addr);
    GXW32(value);
}

#define CTRL(word, arg, addr, mask) { \
    sendCtrl(addr, word, arg, mask); \
}

extern "C" void fn_8019FD30(Obj** arg0, s32 arg1, s32 arg2, s32 arg3,
                            s32 arg4, u8* arg5, s32 arg6) {
    Obj* o = *arg0;
    if (o != 0) {
        u8 q[4];
        if (o->flags & 1) {
            if (o->flags & 2) {
                COLOR(o, c4, c5, c6, c7, 0x100c)
            } else {
                COLOR(o, c4, c5, c6, c7, 0x100c)
            }
        } else if (o->flags & 2) {
            COLOR(o, c4, c5, c6, c7, 0x100c)
        }

        {
            u32 fl = o->flags;
            f32 blue, green;
            q[0] = (u8)(s32)(lbl_805A332C + lbl_805A3330 * (f32)(s32)(arg5[0] * o->m8));
            green = lbl_805A332C + lbl_805A3330 * (f32)(s32)(arg5[1] * o->m9);
            blue = lbl_805A332C + lbl_805A3330 * (f32)(s32)(arg5[2] * o->mA);
            q[1] = (u8)(s32)green;
            q[2] = (u8)(s32)blue;
            q[3] = (u8)(s32)(lbl_805A332C + lbl_805A3330 * (f32)(s32)(arg5[3] * o->mB));

            if (fl & 4) {
                if (fl & 8) {
                    sendColor(*(u32*)q);
                } else {
                    sendColor(*(u32*)q);
                }
            } else if (fl & 8) {
                sendColor(*(u32*)q);
            }
        }

        if (arg6 != 0) {
            if (o->flags & 0x10) CTRL(o->w0C, arg1, 0x100e, 0xffff87c1)
            if (o->flags & 0x20) CTRL(o->w10, arg2, 0x1010, 0xffff87c1)
        } else {
            if (o->flags & 0x10) CTRL(o->w0C, arg1, 0x100e, 0xffff87c3)
            if (o->flags & 0x20) CTRL(o->w10, arg2, 0x1010, 0xffff87c3)
        }

        const Obj44C0* cfg = &lbl_804A44C0;
        if (cfg->b1 == 2) {
            Obj* t = *arg0;
            if (t->flags14 & 1) {
                if (t->flags14 & 2) {
                    COLOR(t, c18, c19, c1A, c1B, 0x100d)
                } else {
                    COLOR(t, c18, c19, c1A, c1B, 0x100d)
                }
            } else if (t->flags14 & 2) {
                COLOR(t, c18, c19, c1A, c1B, 0x100d)
            }

            if (t->flags14 & 4) {
                if (t->flags14 & 8) {
                    COLOR(t, c1C, c1D, c1E, c1F, 0x100b)
                } else {
                    COLOR(t, c1C, c1D, c1E, c1F, 0x100b)
                }
            } else if (t->flags14 & 8) {
                COLOR(t, c1C, c1D, c1E, c1F, 0x100b)
            }

            if (arg6 != 0) {
                if (t->flags14 & 0x10) CTRL(t->w20, arg3, 0x100f, 0xffff87c1)
                if (t->flags14 & 0x20) CTRL(t->w24, arg4, 0x1011, 0xffff87c1)
            } else {
                if (t->flags14 & 0x10) CTRL(t->w20, arg3, 0x100f, 0xffff87c3)
                if (t->flags14 & 0x20) CTRL(t->w24, arg4, 0x1011, 0xffff87c3)
            }
        } else {
            GXW8(0x10);
            GXW16(0);
            GXW16(0x100f);
            GXW32(0);
            GXW8(0x10);
            GXW16(0);
            GXW16(0x1011);
            GXW32(0);
        }

        if ((lbl_804A44C0.d8 & 4) && ((lbl_804A44C0.d8 & 3) != 3)) {
            fn_8019DA9C(lbl_804A44C0.b0, lbl_804A44C0.b1,
                        lbl_804A44C0.b2, lbl_804A44C0.b3,
                        lbl_804A44C0.d4);
            lbl_804A44C0.d8 |= 3;
        }
    }
}
