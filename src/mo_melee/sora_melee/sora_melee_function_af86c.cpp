#include <types.h>
#pragma force_active on

struct SoResetData {
    u8 pad0[0x4];
    s32 unk4;
    u16 unk8;
    s16 unkA;
};

extern "C" void fn_27_AF86C(SoResetData* p) {
    p->unk4 = -1;
    p->unk8 = 0;
    p->unkA = -1;
}
