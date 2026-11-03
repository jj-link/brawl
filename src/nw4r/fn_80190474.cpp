#include <types.h>
#include <revolution/OS/OSFastCast.h>
#pragma force_active on
extern int lbl_8040A898[];
extern "C" s32 fn_80190474(s32* base, s32 index, s32* out1, s32* out2, s32* out3) {
    s32 root = *base;
    u8* entry = (u8*)(root + (index / 2) * 0x30);
    if (entry[0x8a] == 0) return 0;
    u32 bits = (u32)entry[0x8b] << 24;
    bits |= (u32)entry[0x8c] << 16;
    bits |= (u32)entry[0x8d] << 8;
    bits |= entry[0x8e];
    u32 a, c, b, d;
    if (index & 1) {
        a = (bits >> 15) & 7;
        d = lbl_8040A898[(bits >> 19) & 7];
        c = (bits >> 18) & 1;
        b = (bits >> 12) & 7;
    } else {
        a = (bits >> 3) & 7;
        d = lbl_8040A898[(bits >> 7) & 7];
        c = (bits >> 6) & 1;
        b = bits & 7;
    }
    if (out1) *out1 = a;
    if (out3) *out3 = d;
    if (!c) b = 255;
    if (out2) *out2 = b;
    return 1;
}