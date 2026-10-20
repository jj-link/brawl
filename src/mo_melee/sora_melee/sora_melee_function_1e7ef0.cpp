#include <types.h>
#pragma force_active on

struct fn_27_1E7EF0_Obj {
    u8 pad[0x8];
    u32 unk8;
};

extern "C" s32 fn_27_1E7EF0(fn_27_1E7EF0_Obj* p) {
    return ((s32)((p->unk8 << 4) & 0xF8000000)) >> 28;
}
