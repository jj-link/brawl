#include <types.h>
#pragma force_active on

struct fn_27_D2660_obj {
    u32 unk0;
    u32 unk4;
    u32 unk8;
};

extern "C" {
s32 fn_27_D2660(fn_27_D2660_obj* p) {
    return ((s32)((p->unk8 << 4) & 0xE0000000)) >> 30;
}
}
