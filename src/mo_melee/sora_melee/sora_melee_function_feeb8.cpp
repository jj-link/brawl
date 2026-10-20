#include <types.h>
#pragma force_active on

struct fn_27_FEEB8_obj {
    u8 pad[8];
    u32 flags;
};

extern "C" void fn_27_FEEB8(fn_27_FEEB8_obj* p) {
    p->flags &= ~0x00010000;
}
