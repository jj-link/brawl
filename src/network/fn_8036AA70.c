#include <types.h>
#pragma force_active on

extern void* fn_803F602C(void* dest, const void* src, u32 count);

typedef struct Buf {
    char* unk0;
    u32 unk4;
    s32 unk8;
    s32 unkC;
} Buf;

s32 fn_8036AA70(void* unused, Buf* arg1) {
    char* temp_r3;
    s32 temp_r5;
    s32 temp_r6;

    if (arg1 == 0 || (temp_r3 = arg1->unk0) == 0 || (temp_r6 = arg1->unkC) == 0) {
        return 0;
    }
    temp_r5 = arg1->unk8 - temp_r6;
    arg1->unk8 = temp_r5;
    if (temp_r5 != 0) {
        fn_803F602C(temp_r3, temp_r3 + temp_r6, temp_r5);
    }
    arg1->unk0[arg1->unk8] = 0;
    arg1->unkC = 0;
    return 0;
}
