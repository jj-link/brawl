#include <types.h>
#pragma force_active on

struct UnkEF12C {
    u32 unk0;
    s32 unk4;
    s16 unk8;
    s16 unkA;
};

extern "C" void fn_27_EF12C(UnkEF12C* p) {
    p->unk4 = -1;
    p->unk8 = 0;
    p->unkA = -1;
}
