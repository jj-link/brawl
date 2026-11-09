#pragma force_active on
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

s32 fn_8039D7C4(u8 *out, u32 out_size, s32 *out_pos, u8 *src, u32 src_len, s32 *in_count, s32 flag)
{
    u8 buf[8];
    s32 hi;
    s32 lo;
    u32 total;
    u32 i;
    s32 ret;
    s32 line;
    s32 inject;
    s32 k;
    s32 raw;
    s32 written;
    s32 consume;

    ret = 0;
    if (out == 0) {
        return -3;
    }
    if (src == 0) {
        return -3;
    }
    if (src_len == 0) {
        return -8;
    }
    if (in_count != 0) {
        *in_count = 0;
    }
    if (out_pos != 0) {
        *out_pos = 0;
    }
    line = 0;
    total = 0;
    i = 0;
    while (i < src_len) {
        raw = src[0];
        inject = 0;
        if ((s8)raw >= 0x21 && (s8)raw <= 0x7e && (s8)raw != 0x3d) {
            buf[0] = raw;
            consume = 1;
            written = 1;
        } else if (i + 1 < src_len && (s8)raw == 0x0d && (s32)src[1] == 0x0a) {
            buf[0] = raw;
            buf[1] = src[1];
            consume = 2;
            written = 1;
        } else {
            buf[0] = 0x3d;
            hi = src[0] >> 4;
            if (hi >= 10) {
                buf[1] = hi % 10 + 0x41;
            } else {
                buf[1] = hi % 10 + 0x30;
            }
            lo = src[0] & 0xf;
            if (lo >= 10) {
                buf[2] = lo % 10 + 0x41;
            } else {
                buf[2] = lo % 10 + 0x30;
            }
            consume = 1;
            written = 3;
        }
        if (flag == 0 && line + written >= 0x4b) {
            inject = 1;
            written += 3;
        }
        if (total + written >= out_size) {
            ret = -8;
            break;
        }
        total += written;
        if (inject != 0) {
            out[0] = 0x3d;
            line = 0;
            out[1] = 0x0d;
            out[2] = 0x0a;
            out += 3;
            written -= 3;
        }
        line += written;
        for (k = 0; k < written; k++) {
            *out++ = buf[k];
        }
        i += consume;
        src += consume;
    }
    if (in_count != 0) {
        *in_count = i;
    }
    if (out_pos != 0) {
        *out_pos = total;
    }
    return ret;
}
