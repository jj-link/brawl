#include <types.h>
#pragma force_active on

typedef struct Ctx {
    u32 unk0;
    s32 unk4;
    s32 unk8;
    u8 pad0C[0x2C];
    s32 unk38;
    s32 unk3C;
    u8 pad40[0x48];
    u8 unk88[0x40];
    u8 unkC8;
} Ctx;

extern u8 *lbl_805A1170;
extern u8 lbl_8059FD84[5];
extern s32 lbl_805A1190;

extern void *fn_80397748(void *, unsigned char, unsigned long);
extern void fn_80397818(void *, const void *, s32);
extern s32 fn_8039EDE8(void *, s32, void *, s32, s32 *);
extern s32 fn_80398BD8(void *, s32, s32);

s32 fn_8039F1F4(Ctx *self) {
    u8 *entry;
    u8 *out;
    s32 i;
    s32 remain;
    s32 length;
    u8 *buf;
    s32 total;
    s32 result;

    buf = lbl_805A1170;
    result = 0;
    fn_80397748(buf, 0, 0x400);
    fn_80397818(buf, lbl_8059FD84, 0x400);
    out = buf + 4;
    entry = self->unk88;
    i = 0;
    self->unk38 = self->unk8 + 4;
    total = 4;
    remain = 0x3FC;
    for (; i < self->unkC8; i++) {
        result = fn_8039EDE8(entry, self->unk4, out, remain, &length);
        if (result != 0) {
            break;
        }
        remain -= length;
        out += length;
        total += length;
        if (remain <= 4) {
            result = -11;
            break;
        }
        if (i < (s32)self->unkC8 - 1) {
            out[0] = 0x2C;
            total += 4;
            remain -= 4;
            out[1] = 0xD;
            out[2] = 0xA;
            out[3] = 0x20;
            out += 4;
        }
        entry += 8;
    }
    out[0] = 0xD;
    out[1] = 0xA;
    if (result == 0) {
        result = fn_80398BD8(lbl_805A1170, total + 2, lbl_805A1190);
        if (result == 0) {
            s32 t = self->unk8 + total + 2;
            self->unk8 = t;
            self->unk3C = (t - self->unk38) - 2;
        }
    }
    return result;
}
