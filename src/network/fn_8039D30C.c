#include <types.h>
#pragma force_active on

extern u8* lbl_8059FCF8;

s32 fn_8039D30C(u8* src, s32 srcLen, s32* srcUsed, u8* dst, s32 dstLen, s32* dstUsed)
{
    s32 out;
    s32 in;
    s32 result;
    s32 w2;
    s32 w1;
    s32 v;

    in = 0;
    result = 0;
    out = 0;
    for (; in < srcLen; in += 3) {
        if (out + 3 >= dstLen) {
            result = -8;
            break;
        }
        w2 = 0;
        w1 = 0;
        v = src[in] << 8;
        if (in + 1 < srcLen) {
            w1 = 1;
            v |= src[in + 1];
        }
        v <<= 8;
        if (in + 2 < srcLen) {
            w2 = 1;
            v |= src[in + 2];
        }
        dst[out] = lbl_8059FCF8[(v >> 18) & 0x3F];
        dst[out + 1] = lbl_8059FCF8[(v >> 12) & 0x3F];
        dst[out + 2] = lbl_8059FCF8[w1 ? ((v >> 6) & 0x3F) : 0x40];
        dst[out + 3] = lbl_8059FCF8[w2 ? (v & 0x3F) : 0x40];
        out += 4;
    }
    *dstUsed = out;
    if (srcUsed != NULL) {
        if (srcLen < in) {
            in = srcLen;
        }
        *srcUsed = in;
    }
    return result;
}