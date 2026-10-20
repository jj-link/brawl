#include <types.h>
#pragma force_active on

struct UnkStruct27 {
    u32 unk0;
    s32 unk4;
    s16 unk8;
    s16 unkA;
};

extern "C" void fn_27_1BA420(UnkStruct27* p) {
    p->unk4 = -1;
    p->unk8 = 0;
    p->unkA = -1;
}
