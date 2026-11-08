#include <types.h>
#pragma force_active on

static inline int decode(u8 c) {
    if (c >= 'A' && c <= 'Z') return c - 'A';
    if (c >= 'a' && c <= 'z') return c - 'a' + 26;
    if (c >= '0' && c <= '9') return c - '0' + 52;
    if (c == '.') return 62;
    if (c == '-') return 63;
    return -1;
}

static inline int getblock(u8 *out, const char *in) {
    int n = 0;
    int i;
    for (i = 0; i < 4; i++) {
        if (*in) {
            *out++ = *in++;
            n++;
        } else {
            *out++ = 0;
        }
    }
    return n;
}

int fn_803568D0(u8 *out, const char *in, int size) {
    u8 input[4];
    char output[3];
    int result = 0;
    int n = getblock(input, in);
    int value = 0;
    int i;
    while (n > 0 && value >= 0) {
        output[0] = 0;
        output[1] = 0;
        output[2] = 0;
        value = decode(input[0]);
        if (value >= 0) {
            output[0] = value << 2;
            value = decode(input[1]);
            if (value >= 0) {
                output[0] |= value >> 4;
                output[1] = value << 4;
                value = decode(input[2]);
                if (value >= 0) {
                    output[1] |= value >> 2;
                    output[2] = value << 6;
                    value = decode(input[3]);
                    if (value >= 0)
                        output[2] |= value;
                }
            }
        }
        for (i = 0; i < n - 1; i++)
            *out++ = output[i];
        size -= 4;
        result += n - 1;
        in += n;
        if (size <= 0)
            break;
        n = getblock(input, in);
    }
    *out = 0;
    return result;
}