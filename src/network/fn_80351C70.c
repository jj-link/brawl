#include <types.h>
#pragma force_active on

typedef struct {
    u32 unk0;
    u32 unk4;
    u32 unk8;
} S;

s32 fn_80351C70(S *arg0, S *arg1) {
    u32 temp_r7;
    u32 temp_r8;
    u32 temp_r5;
    s32 var_r7;

    temp_r7 = arg0->unk0;
    temp_r8 = arg1->unk0;
    if (((temp_r7 >> 11) & 3) != ((temp_r8 >> 11) & 3)) {
        return 0;
    }
    temp_r5 = (temp_r7 >> 11) & 3;
    if (temp_r5 == 3) {
        return arg0->unk4 == arg1->unk4;
    }
    if (temp_r5 == 1) {
        var_r7 = 0;
        if (((((unsigned long long)(temp_r7 & 0x7FF) << 32) | arg0->unk4) == (((unsigned long long)(temp_r8 & 0x7FF) << 32) | arg1->unk4)) && (arg0->unk8 == arg1->unk8)) {
            var_r7 = 1;
        }
        return var_r7;
    }
    if (temp_r5 == 2) {
        return (((unsigned long long)arg0->unk8 << 32) | arg0->unk4) == (((unsigned long long)arg1->unk8 << 32) | arg1->unk4);
    }
    return 0;
}
