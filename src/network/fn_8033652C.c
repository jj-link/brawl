#include <types.h>
#include <revolution/OS/OSTime.h>

extern u32 lbl_80533718[6];
extern void fn_80390010(u32*);

#pragma force_active on

s32 fn_8033652C(s32 arg0) {
    u32 seed[2];
    u32 mixed;
    u32 high;
    u32 low;
    u64 time;

    if (((u64*)lbl_80533718)[0] == 0 &&
        ((u64*)lbl_80533718)[1] == 0 &&
        ((u64*)lbl_80533718)[2] == 0) {
        fn_80390010(seed);
        time = OSGetTime();
        high = (u32)(time >> 32);
        low = (u32)time;

        mixed = (u32)((*(u64*)seed >> 24) & 0xFFFFFF);

        seed[1] = mixed | (low << 24);
        seed[0] = (u32)((time << 24) >> 32);

        ((u64*)lbl_80533718)[0] = *(u64*)seed;
        ((u64*)lbl_80533718)[1] = 0x5D588B656C078965ULL;
        ((u64*)lbl_80533718)[2] = 0x00269EC3ULL;
    }

    ((u64*)lbl_80533718)[0] =
        ((u64*)lbl_80533718)[1] * ((u64*)lbl_80533718)[0] +
        ((u64*)lbl_80533718)[2];

    if (arg0 == 0) {
        return (s32)lbl_80533718[0];
    }
    return (s32)(((((u64*)lbl_80533718)[0] >> 32) * (u32)arg0) >> 32);
}
