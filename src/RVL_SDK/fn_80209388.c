#include <types.h>
#pragma force_active on
extern char *lbl_805A0B70;
extern s32 fn_802063BC(s32);
typedef struct Work { u8 pad[0x100]; u16 unk100; u16 unk102; u16 unk104[16]; } Work;
#define P(off) (*(s32 *)(p + (off)))
#define H(off) (*(u16 *)(p + (off)))
static inline void output(char *p, Work *arg, u16 *out) {
    u16 d;
    u16 flags;
    d = H(0x24);
    flags = 0;
    *out++ = d;
    if (d != 0) flags |= 1;
    *out++ = ((int)H(0x26) - (int)H(0x24)) / 18;
    if (out[-1] != 0) flags |= 0x2;
    d = H(0x28);
    *out++ = d;
    if (d != 0) flags |= 0x4;
    *out++ = ((int)H(0x2a) - (int)H(0x28)) / 18;
    if (out[-1] != 0) flags |= 0x8;
    d = H(0x2c);
    *out++ = d;
    if (d != 0) flags |= 0x10;
    *out++ = ((int)H(0x2e) - (int)H(0x2c)) / 18;
    if (out[-1] != 0) flags |= 0x20;
    d = H(0x30);
    *out++ = d;
    if (d != 0) flags |= 0x40;
    *out++ = ((int)H(0x32) - (int)H(0x30)) / 18;
    if (out[-1] != 0) flags |= 0x80;
    d = H(0x34);
    *out++ = d;
    if (d != 0) flags |= 0x100;
    *out++ = ((int)H(0x36) - (int)H(0x34)) / 18;
    if (out[-1] != 0) flags |= 0x200;
    d = H(0x38);
    *out++ = d;
    if (d != 0) flags |= 0x400;
    *out++ = ((int)H(0x3a) - (int)H(0x38)) / 18;
    if (out[-1] != 0) flags |= 0x800;
    d = H(0x3c);
    *out++ = d;
    if (d != 0) flags |= 0x1000;
    *out++ = ((int)H(0x3e) - (int)H(0x3c)) / 18;
    if (out[-1] != 0) flags |= 0x2000;
    d = H(0x40);
    *out++ = d;
    if (d != 0) flags |= 0x4000;
    *out++ = ((int)H(0x42) - (int)H(0x40)) / 18;
    if (out[-1] != 0) flags |= 0x8000;
    arg->unk100 = flags;
    *(s32 *)((char *)arg + 0x1C) |= 0x03000000;
}
void fn_80209388(s32 idx, Work *arg) {
    char *p;
    s32 w;
    p = lbl_805A0B70 + idx * 0x44;
    w = P(0);
    if (w & 0xC0000000) {
        if (w & 0x80000000) {
            H(0x24) = H(0x26);
            H(0x28) = H(0x2a);
            H(0x2c) = H(0x2e);
            H(0x30) = H(0x32);
            H(0x34) = H(0x36);
            H(0x38) = H(0x3a);
            H(0x3c) = H(0x3e);
            H(0x40) = H(0x42);
            w = P(0);
            P(0) = w & 0x7FFFFFFF;
        }
        w = P(0);
        if (w & 0x40000000) {
            H(0x26) = fn_802063BC(P(0x4));
            H(0x2e) = fn_802063BC(P(0x8));
            H(0x36) = fn_802063BC(P(0xc));
            H(0x3e) = fn_802063BC(P(0x10));
            w = P(0);
            if (w & 1) {
                H(0x2a) = fn_802063BC(P(0x14));
            } else {
                H(0x2a) = fn_802063BC(P(0x4) + P(0x14));
            }
            w = P(0);
            if (w & 2) {
                H(0x32) = fn_802063BC(P(0x18));
            } else {
                H(0x32) = fn_802063BC(P(0x8) + P(0x18));
            }
            w = P(0);
            if (w & 4) {
                H(0x3a) = fn_802063BC(P(0x1c));
            } else {
                H(0x3a) = fn_802063BC(P(0xc) + P(0x1c));
            }
            w = P(0);
            if (w & 8) {
                H(0x42) = fn_802063BC(P(0x20));
            } else {
                H(0x42) = fn_802063BC(P(0x10) + P(0x20));
            }
            w = P(0);
            P(0) = (w & 0xBFFFFFFF) | 0x80000000;
        }
        output(p, arg, (u16 *)((char *)arg + 0x102));
    }
}
