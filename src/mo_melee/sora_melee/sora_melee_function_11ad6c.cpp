#include <types.h>
#pragma force_active on

struct Fn27Unk {
    u32 unk0;
    s32 unk4;
    s16 unk8;
    s16 unkA;
};

extern "C" void fn_27_11AD6C(Fn27Unk* self) {
    self->unk4 = -1;
    self->unk8 = 0;
    self->unkA = -1;
}
