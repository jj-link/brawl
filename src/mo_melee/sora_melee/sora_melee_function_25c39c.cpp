#include <types.h>
#pragma force_active on

struct fn_27_25C39C_obj {
    u8 pad0[0x48];
    u32 unk48;
    u32 unk4c;
    u8 pad1[0x58 - 0x50];
    u32 unk58;
};

extern "C" void fn_27_25C39C(fn_27_25C39C_obj* p) {
    if (p->unk4c < p->unk58) {
        p->unk4c = p->unk4c + 1;
    } else {
        p->unk48 = 7;
    }
}
