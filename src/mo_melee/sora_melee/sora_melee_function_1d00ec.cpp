#include <types.h>
#pragma force_active on

struct fn_27_1D00EC_arg {
    u32 unk0;
    u32 unk4;
    u32 unk8;
};

extern "C" {
s32 fn_27_1D00EC(fn_27_1D00EC_arg* p) {
    u32 v = p->unk8;
    return (s32)(((v >> 23) & 0x1F) << 27) >> 28;
}
}
