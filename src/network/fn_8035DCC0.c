#include <types.h>
#pragma force_active on

extern int lbl_805A4980;
extern int lbl_805A4984;
extern int lbl_805A4988;

typedef struct Enc {
    u8 *src;
    s32 len;
    s32 mode;
} Enc;

static inline void convert(u8 *p, u8 *tbl) {
    u8 v = *p;
    if ((s8)v <= 25) {
        *p = v + 'A';
    } else if ((s8)v <= 51) {
        *p = v + 71;
    } else if ((s8)v <= 61) {
        *p = v - 4;
    } else if ((s8)v == 62) {
        *p = tbl[0];
    } else if ((s8)v == 63) {
        *p = tbl[1];
    }
}

static inline void readChunk(Enc *self, u8 *buf) {
    s32 i;
    u8 *src;
    s32 n = 3;
    if (self->len < 3) {
        n = self->len;
    }
    src = self->src;
    for (i = 0; i < n; i++) {
        buf[i] = src[i];
    }
    for (; i < 3; i++) {
        buf[i] = 0;
    }
}

s32 fn_8035DCC0(Enc *self, u8 *out) {
    u8 buf[8];
    u8 *tbl;
    s32 i;
    s32 n;
    u8 *src;
    s32 k;
    s8 v;

    if (self->len <= 0) {
        return 0;
    }
    switch (self->mode) {
    case 1:
        tbl = (u8 *)&lbl_805A4984;
        break;
    case 2:
        tbl = (u8 *)&lbl_805A4988;
        break;
    default:
        tbl = (u8 *)&lbl_805A4980;
        break;
    }
    readChunk(self, buf);
    out[0] = (u8)(buf[0] >> 2);
    out[1] = (u8)(((buf[1] >> 4) & ~0x30) | ((buf[0] << 4) & 0x30));
    out[2] = (u8)(((buf[2] >> 6) & ~0x3C) | ((buf[1] << 2) & 0x3C));
    out[3] = (u8)(buf[2] & 0x3F);

    self->src += 3;
    self->len -= 3;

    for (k = 0; k < 4; k++) {
        convert(&out[k], tbl);
    }

    if (self->len < 0) {
        out[3] = tbl[2];
        if (self->len == -2) {
            out[2] = tbl[2];
        }
    }
    return 1;
}
