#include <internal/mem.h>
#pragma force_active on
extern "C" void fn_8034F028(void*, const char*, unsigned int);
extern const char* lbl_8059F058;

extern "C" unsigned int fn_80334DE4(const char* src, unsigned int size, char* dst, unsigned int capacity) {
    int count;
    unsigned int required = (size / 3) * 4 + (size % 3 ? 4 : 0);
    if (dst == 0) return required;
    if (capacity < required) return -1;
    unsigned int chars;
    const char* p = src;
    const char* end = src + size;
    char* out = dst;
    while (p != end) {
        int remaining = end - p;
        unsigned int bits = remaining * 8;
        chars = bits / 6 + (bits % 6 != 0);
        count = remaining < 3 ? remaining : 3;
        unsigned char buf[3];
        memset(buf, 0, 3);
        fn_8034F028(buf, p, count);
        out[0] = lbl_8059F058[buf[0] >> 2];
        if (chars >= 2) out[1] = lbl_8059F058[((buf[0] & 3) << 4) | (buf[1] >> 4)];
        else out[1] = '*';
        if (chars >= 3) out[2] = lbl_8059F058[((buf[1] & 15) << 2) | (buf[2] >> 6)];
        else out[2] = '*';
        if (chars >= 4) out[3] = lbl_8059F058[buf[2] & 63];
        else out[3] = '*';
        p += count;
        out += 4;
    }
    return out - dst;
}
