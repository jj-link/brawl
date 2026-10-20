#include <types.h>
#pragma force_active on

struct fn_27_1CF7C4_obj {
    u32 unk0;
    u32 unk4;
    u32 unk8;
};

extern "C" void fn_27_1CF7C4(fn_27_1CF7C4_obj* p) {
    p->unk8 |= 0x10000;
}
