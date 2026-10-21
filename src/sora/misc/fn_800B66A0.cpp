#include <types.h>
#pragma force_active on

struct fn_800B66A0_Inner {
    u8 pad0[0x20];
    s32 unk20;
};

struct fn_800B66A0_Mid {
    u8 pad0[0x2C];
    fn_800B66A0_Inner *unk2C;
};

struct fn_800B66A0_Outer {
    u8 pad0[0xC];
    fn_800B66A0_Mid *unkC;
};

struct fn_800B66A0_Arg {
    u8 pad0[0x14];
    fn_800B66A0_Outer *unk14;
};

extern "C" bool fn_800B66A0(fn_800B66A0_Arg *arg0) {
    fn_800B66A0_Mid *temp = arg0->unk14->unkC;
    if (temp == 0) {
        return 0;
    }
    return temp->unk2C->unk20 == 1;
}
