#include <types.h>
#pragma force_active on

struct fn_27_1D053C_arg {
    u32 unk0;
    u32 unk4;
    u32 unk8;
};

extern "C" s32 fn_27_1D053C(fn_27_1D053C_arg* p) {
    return (s32)((p->unk8 >> 19) & 0x7F) << 25 >> 26;
}
