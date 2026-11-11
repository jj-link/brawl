#include <types.h>
#pragma force_active on

extern const char lbl_80415720[];

static inline int getblock(u8 *out, const char *in, int size) {
    int n = 0;
    int i;
    for (i = 0; i < (size > 3 ? 3 : size); i++) {
        if (*in) {
            *out++ = *in++;
            n++;
        } else {
            *out++ = 0;
        }
    }
    return n;
}

int fn_80356738(s8 *out, const char *in, int size) {
    u8 buf[3];
    int len = 0;
    int n = getblock(buf, in, size);
    while (n > 0) {
        int a, b, c, d;
        if (size < 3) buf[2] = 0;
        if (size < 2) buf[1] = 0;
        a = buf[0] >> 2;
        b = ((buf[0] << 4) | (buf[1] >> 4)) & 0x3F;
        c = ((buf[1] << 2) | (buf[2] >> 6)) & 0x3F;
        d = buf[2] & 0x3F;
        out[0] = lbl_80415720[a];
        out[1] = lbl_80415720[b];
        out[2] = n > 1 ? lbl_80415720[c] : 42;
        out[3] = n > 2 ? lbl_80415720[d] : 42;
        size -= n;
        in += n;
        out += 4;
        len += 4;
        if (size == 0) break;
        n = getblock(buf, in, size);
    }
    *out = 0;
    return len;
}
