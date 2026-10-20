#include <types.h>
#pragma force_active on

struct fn_27_1A40F8_obj {
    u32 unk0;
    u32 unk4;
    u32 flags;
};

extern "C" void fn_27_1A40F8(fn_27_1A40F8_obj* p) {
    p->flags &= ~0x00400000;
}
