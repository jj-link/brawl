#include <types.h>
#pragma force_active on

extern "C" {
void fn_801EC158(void *p);
void fn_801629AC(void *m, f32 x, f32 y, f32 z);
extern f32 lbl_805A31A0;
extern f32 lbl_805A31A4;
extern f32 lbl_805A31A8;

typedef struct Src {
    u8 pad0[0x14];
    u32 flags14;
    u8 pad1[0x8];
    f32 f20;
    f32 f24;
    f32 f28;
    f32 f2C;
    f32 f30;
    f32 f34;
    f32 f38;
    f32 f3C;
    f32 f40;
} Src;

typedef struct Dst {
    u32 flags;
    f32 f4;
    f32 f8;
    f32 fC;
    u8 pad10[0x18];
    f32 f28;
    u8 pad2C[0xC];
    f32 f38;
    u8 pad3C[0xC];
    f32 f48;
} Dst;

void fn_80192BC8(Src **arg0, Dst *arg1) {
                f32 k;
    Src *src;
    u32 t;
    u32 flags;
    f32 saved[3];

    src = *arg0;
    if (src != 0) {
        flags = arg1->flags;
        if (flags & 0x80) {
            t = src->flags14;
            if (t & 8) {
                f32 c = lbl_805A31A0;
                flags |= 0x18;
                arg1->fC = c;
                arg1->f8 = c;
                arg1->f4 = c;
            } else {
                u32 v = flags & ~0x10;
                if (t & 0x10) {
                    v = flags | 0x10;
                }
                flags = v & ~0xA;
                arg1->f4 = src->f20;
                arg1->f8 = src->f24;
                arg1->fC = src->f28;
            }
        }
        if (flags & 0x100) {
            f32 t48 = arg1->f48;
            saved[1] = arg1->f38;
            saved[0] = arg1->f28;
            saved[2] = t48;
            if (src->flags14 & 4) {
                fn_801EC158((u8 *)arg1 + 0x1C);
                flags |= 0x20;
            } else {
                f32 x2C, y30, z34;
                z34 = src->f34;
                k = lbl_805A31A4;
                y30 = src->f30;
                x2C = src->f2C;
                fn_801629AC((u8 *)arg1 + 0x1C, k * x2C, k * y30, k * z34);
                flags &= ~0x26;
            }
            flags |= 0x80000000;
            arg1->f28 = saved[0];
            arg1->f38 = saved[1];
            arg1->f48 = saved[2];
        }
        if (flags & 0x200) {
            if (src->flags14 & 2) {
                f32 c = lbl_805A31A8;
                flags |= 0x40;
                arg1->f48 = c;
                arg1->f38 = c;
                arg1->f28 = c;
            } else {
                flags &= ~0x46;
                arg1->f28 = src->f38;
                arg1->f38 = src->f3C;
                arg1->f48 = src->f40;
            }
        }
        if ((flags & 0x20) && (flags & 0x40)) {
            flags |= 4;
            if (flags & 8) {
                flags |= 2;
            }
        }
        arg1->flags = flags & 0xFFFFFC7F;
    }
}
}
