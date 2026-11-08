#include <types.h>
#include <string.h>

#pragma force_active on

typedef struct {
    u32 count;
    u32 words[64];
} BigNumber;

extern s32 fn_8035D770();
extern s32 fn_8035ECE0(u32 *, u32, u32 *, u32);
extern s32 fn_8035F5A8(u32 *, u32, u32 *, u32, u32 *);
extern s32 fn_803601C4(u32 *, u32 *, u32 *);
extern s32 fn_80360DE8(u32 *, u32 *, u32 *, s32, u32 *);
extern u32 lbl_805349A8[];

#define END_TIMER()                                                    \
    do {                                                               \
        if (lbl_805349A8[35] == 1U) {                                 \
            u32 elapsed = fn_8035D770() - lbl_805349A8[32];            \
            lbl_805349A8[33] += elapsed;                              \
            lbl_805349A8[35] = 0;                                     \
        }                                                              \
    } while (0)

s32 fn_803607C4(u32 *arg0, u32 *arg1, u32 *arg2, u32 *arg3)
{
    u32 sp724[65];
    u32 sp620[65];
    u32 sp51C[65];
    u32 sp418[65];
    u32 sp314[65];
    u32 sp210[65];
    u32 sp10C[65];
    u32 sp8[65];
    s32 var_r28;
    s32 var_r31;
    s32 temp_r27;
    u64 inverse;
    u64 bit;
    u32 var_ctr;
    u32 temp_r3;
    u32 temp_r4;
    u32 modulus;

    if (lbl_805349A8[35] == 0) {
        u32 t = lbl_805349A8[34];
        lbl_805349A8[34] = t + 1;
        lbl_805349A8[32] = fn_8035D770(t);
        lbl_805349A8[35] = 1;
    }

    memset(sp724, 0, 0x104);
    memset(sp620, 0, 0x104);
    memset(sp51C, 0, 0x104);
    memset(sp418, 0, 0x104);
    memset(sp314, 0, 0x104);
    memcpy(sp210, arg0, 0x104);
    memcpy(sp10C, arg1, 0x104);
    memcpy(sp8, arg2, 0x104);

    while (sp210[0] != 0 && sp210[sp210[0]] == 0)
        sp210[0]--;

    while (sp10C[0] != 0 && sp10C[sp10C[0]] == 0)
        sp10C[0]--;

    while (sp8[0] != 0 && sp8[sp8[0]] == 0)
        sp8[0]--;

    if (sp8[0] == 0) {
        arg3[0] = 0;
        END_TIMER();
        return 0;
    }

    if (sp8[0] == 1 && sp8[1] == 1) {
        arg3[0] = 0;
        arg3[1] = 0;
        END_TIMER();
        return 1;
    }

    if (sp10C[0] == 0) {
        arg3[0] = 1;
        arg3[1] = 1;
        END_TIMER();
        return 1;
    }

    if ((sp8[1] & 1) == 0) {
        arg3[0] = 0;
        arg3[1] = 0;
        END_TIMER();
        return 0;
    }

    if (fn_8035ECE0(&sp210[1], sp210[0], &sp8[1], sp8[0]) != -1)
        fn_8035F5A8(&sp210[1], sp210[0], sp8, 0, sp210);

    if (sp210[0] == 0) {
        arg3[0] = 0;
        arg3[1] = 0;
        END_TIMER();
        return 1;
    }

    var_r31 = 0x20;
    temp_r4 = ((BigNumber *)(sp10C + ((s32)sp10C[0] - 1)))->words[0];
    while (((1U << (var_r31 - 1)) & temp_r4) == 0)
        var_r31--;

    var_r31 += (sp10C[0] - 1) << 5;
    memset(sp724, 0, 0x104);
    temp_r3 = sp8[0];
    sp724[0] = ++temp_r3;
    if (temp_r3 > 0x40)
        return 0;

    (&sp724[1])[--temp_r3] = 1;
    modulus = sp8[1];
    bit = 2;
    inverse = 1;
    for (var_ctr = 0; var_ctr < 0x1f; var_ctr++) {
        u64 mask = (bit << 1) - 1;
        u64 product = modulus * inverse;
        if ((product & mask) > bit)
            inverse += bit;
        bit <<= 1;
    }

    temp_r27 = (s32)(bit - inverse);
    if (fn_8035F5A8(&sp724[1], sp724[0], sp8, 0, sp620) == 0) {
        END_TIMER();
        return 0;
    }

    if (fn_803601C4(sp620, sp8, sp51C) == 0) {
        END_TIMER();
        return 0;
    }

    if (fn_80360DE8(sp210, sp51C, sp8, temp_r27, sp314) == 0) {
        END_TIMER();
        return 0;
    }

    memcpy(arg3, sp620, 0x104);
    var_r28 = var_r31 - 1;
    while (var_r28 >= 0) {
        fn_80360DE8(arg3, arg3, sp8, temp_r27, arg3);
        temp_r4 = 1U << var_r28;
        if (temp_r4 == (temp_r4 & sp10C[var_r28 / 32 + 1]))
            fn_80360DE8(arg3, sp314, sp8, temp_r27, arg3);
        var_r28--;
    }

    sp418[0] = 1;
    sp418[1] = 1;
    fn_80360DE8(arg3, sp418, sp8, temp_r27, arg3);
    END_TIMER();
    return 1;
}
