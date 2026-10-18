#include <types.h>
#pragma force_active on

struct UnkStruct27 {
    u8 unk0[0x4];
    s32 unk4;
    s16 unk8;
    s16 unkA;
};

extern "C" void fn_27_EF15C(UnkStruct27* p) {
    p->unk4 = -1;
    p->unk8 = 0;
    p->unkA = -1;
}
