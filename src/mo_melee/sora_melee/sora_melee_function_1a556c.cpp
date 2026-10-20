#include <types.h>
#pragma force_active on

struct Fn27Src {
    u32 unk0;
    u32 unk4;
    u32 unk8;
};

extern "C" {
s32 fn_27_1A556C(const Fn27Src* p) {
    return (s32)(((p->unk8 >> 19) & 0x1F) << 27) >> 28;
}
}
