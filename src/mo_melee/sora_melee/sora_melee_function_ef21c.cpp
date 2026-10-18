#include <types.h>
#pragma force_active on

struct UnkResetData {
    u8 pad0[4];
    s32 unk4;
    s16 unk8;
    s16 unkA;
};

extern "C" void fn_27_EF21C(UnkResetData* p) {
    p->unk4 = -1;
    p->unk8 = 0;
    p->unkA = -1;
}
