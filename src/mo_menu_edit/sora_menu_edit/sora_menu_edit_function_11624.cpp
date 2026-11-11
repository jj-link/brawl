#include <types.h>
#pragma force_active on

extern "C" {
void* fn_5_12068(void* t, u32 key);
extern s32 lbl_5_data_0[];
extern s32 lbl_5_data_C[];

s32 fn_5_11624(u8* self) {
    s32 r30;
    u8* base;
    u32 r28;
    u32 r27;
    s32 r26;
    s32 r25;
    r26 = 0;
    r28 = 0;
    r30 = 0;
    while (r28 < (u32)lbl_5_data_0[*(s32*)(self + 0x7D160)]) {
        base = self + r30;
        r25 = -1;
        r27 = 0;
        while (r27 < (u32)lbl_5_data_C[*(s32*)(self + 0x7D160)]) {
            s16 s = *(s16*)(base + 0x7D8A0);
            if (s != -1) {
                u32 key = reinterpret_cast<u32*>(self)[(s << 3) + 0x1F6A6];
                void* e = fn_5_12068(*(void**)(self + 0xC4758), key);
                u32 id = *(u32*)e;
                u16 v = *(u16*)((u8*)e + 0x42);
                u32 q = id / 10;
                if (q == 0x5B || q == 0x5C || q == 0x5D || q == 0x63) {
                    v = 4;
                } else if (q - 0x5F <= 2) {
                    v = 0;
                }
                if (v <= 1) {
                    if ((s32)(r27 - 1) == r25) {
                        r26++;
                        if (r26 >= 4) return 1;
                        break;
                    }
                } else if (v == 4) {
                    r25 = (s32)r27;
                }
            } else {
                r25 = (s32)r27;
            }
            base += 0x24;
            r27++;
        }
        r30 += 2;
        r28++;
    }
    return 0;
}
}