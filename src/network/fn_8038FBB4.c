#include <types.h>
#include <stl/internal/mem.h>
#include <revolution/OS/OSError.h>
#pragma force_active on
extern const u8 lbl_80415DE0[];
extern const u8 lbl_80415FE0[];
extern char lbl_80491460[];
typedef union {
    u32 word;
    struct { u32 rounds : 8; u32 rest : 24; } bits;
} KeyHeader;
s32 fn_8038FBB4(u8 *arg0, const void *arg1, u32 arg2, const void *arg3, void *arg4) {
    s32 result = 0;
    u32 key_words;
    u32 rounds;
    KeyHeader w;
    if (arg2 != 0x10 && arg2 != 0x18 && arg2 != 0x20) {
        OSReport(lbl_80491460);
    } else {
        key_words = (arg2 << 3) >> 5;
        w.word = *(u32 *)(arg0 + 0x100);
        rounds = key_words + 6;
        *(u32 *)(arg0 + 0x104) = (u32)arg4;
        w.word |= 0x800000;
        w.bits.rounds = rounds;
        *(u32 *)(arg0 + 0x100) = w.word;
        memcpy(arg0, arg3, 0x10);
        {
            u32 *temp_r31;
            u32 temp_r30;
            u32 *var_r4;
            u32 var_r8;
            u32 var_r5;
            u32 temp_r0;
            temp_r31 = (u32 *)(arg0 + 0x10);
            temp_r30 = arg2 >> 2;
            memcpy(temp_r31, arg1, arg2);
            var_r4 = temp_r31 + temp_r30;
            var_r8 = var_r4[-1];
            var_r5 = temp_r30;
            while (var_r5 < ((*(u32 *)(arg0 + 0x100) >> 24) + 1) * 4) {
                temp_r0 = var_r5 % temp_r30;
                if (temp_r0 == 0) {
                    var_r8 = (lbl_80415DE0[var_r8 >> 24] ^ ((u32)lbl_80415DE0[(var_r8 >> 16) & 0xFF] << 24))
                           ^ (((u32)lbl_80415DE0[var_r8 & 0xFF] << 8) ^ ((u32)lbl_80415DE0[(var_r8 >> 8) & 0xFF] << 16));
                    var_r8 ^= (u32)lbl_80415FE0[var_r5 / temp_r30 - 1] << 24;
                } else if (temp_r30 > 6 && temp_r0 == 4) {
                    var_r8 = ((u32)lbl_80415DE0[var_r8 >> 24] << 24) ^ (((u32)lbl_80415DE0[(var_r8 >> 16) & 0xFF] << 16) ^ (lbl_80415DE0[var_r8 & 0xFF] ^ ((u32)lbl_80415DE0[(var_r8 >> 8) & 0xFF] << 8)));
                }
                var_r8 ^= temp_r31[var_r5 - temp_r30];
                *var_r4++ = var_r8;
                var_r5++;
            }
        }
        result = 1;
    }
    return result;
}