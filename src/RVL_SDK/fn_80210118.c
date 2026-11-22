#include <types.h>
#pragma force_active on
static inline s32 helper(s32 found, s8 *arg0, s8 *arg1, u32 arg2) {
    s32 match;
    u32 count;
    u32 key;
    u32 pos;
    u8 t;
    s8 c;
    u8 x;
    key = 0x73B5DBFA;
    match = 0;
    count = 0;
    pos = 0;
    for (pos = 0; pos < 0x100; pos++) {
        t = *(u8 *)(0x80003800 + pos);
        if (t != 0) {
            c = arg0[match];
            x = t ^ key;
            if (c == 0 && x == 0x3D) {
                found = 1;
                break;
            }
            match = ((x ^ c) & 0xDF) == 0 ? match + 1 : 0;
        }
        key = (key >> 31) | (key << 1);
    }
    if (found) {
        pos++;
        while (pos < 0x100 && count < arg2) {
            u8 value;
            key = (key >> 31) | (key << 1);
            value = *(u8 *)(0x80003800 + pos);
            if (value != 0) {
                value ^= key;
                if (value == 0xD || value == 0xA) value = 0;
            }
            *arg1 = value;
            count++;
            arg1++;
            if (value == 0) return 1;
            pos++;
        }
    }
    return 0;
}
s32 fn_80210118(s8 *arg0, s8 *arg1, u32 arg2) {
    return helper(0, arg0, arg1, arg2);
}