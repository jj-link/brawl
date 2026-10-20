#include <types.h>
#pragma force_active on

struct fn_27_41AA8_obj {
    u32 unk0;
    u32 unk4;
    u32 unk8_hi : 8;
    u32 unk8_field : 4;
    u32 unk8_lo : 20;
};

extern "C" void fn_27_41AA8(fn_27_41AA8_obj* p, u32 v) {
    p->unk8_field = v;
}
