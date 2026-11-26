#include <types.h>
#pragma force_active on

extern "C" {
    u8 fn_800C8548(void);
    u8 fn_800C851C(void);
    s32 fn_803F6150(const void *a, const void *b, u32 n);
}

extern "C" s32 fn_800D82E8(void *self, u8 *out, s32 flag) {
    u8 index = fn_800C8548();
    u8 *slot;
    if (index == 0xFF) {
        u8 local = fn_800C851C();
        if (local == 0xFF) {
            local = 4;
        }
        slot = (u8*)((u32)self + local * 0x218 + 0x70);
    } else {
        u32 base = (u32)self + index * 0x218;
        slot = (u8*)(base + 0x70);
        if (!((((u8*)base)[0xE8] >> 7) & 1)) {
            u8 local = fn_800C851C();
            if (local == 0xFF) {
                local = 4;
            }
            slot = (u8*)((u32)self + local * 0x218 + 0x70);
        }
    }
    u8 *s = (u8*)self;
    s32 r = fn_803F6150(s + 0xFFC, slot + 0x7D, 4) != 0;
    if (flag != 0 || r != 0) {
        s[0xFFC] = slot[0x7D];
        s[0xFFD] = slot[0x7E];
        s[0xFFE] = slot[0x7F];
        s[0xFFF] = slot[0x80];
        out[0] = slot[0x7D];
        out[1] = slot[0x7E];
        out[2] = slot[0x7F];
        out[3] = slot[0x80];
        u8 local = fn_800C851C();
        if (local == 0xFF) {
            local = 4;
        }
        u8 b2, b1, b0;
        b0 = slot[0x7D];
        u8 *dst = s + local * 0x218;
        dst[0xD4] = b0;
        b1 = slot[0x7E];
        dst[0xD5] = b1;
        b2 = slot[0x7F];
        dst[0xD6] = b2;
        dst[0xD7] = slot[0x80];
        dst[0xED] = b0;
        dst[0xEE] = b1;
        dst[0xEF] = b2;
        dst[0xF0] = slot[0x80];
        return 1;
    }
    return 0;
}
