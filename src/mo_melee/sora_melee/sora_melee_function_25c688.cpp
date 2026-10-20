#include <types.h>
#pragma force_active on

struct FnObj {
    u8 pad0[0x48];
    u32 m48;
    u32 m4c;
    u8 pad1[0x68 - 0x50];
    u32 m68;
};

extern "C" {
void fn_27_25C688(FnObj* p) {
    if (p->m4c < p->m68) {
        p->m4c = p->m4c + 1;
    } else {
        p->m48 = 0xD;
    }
}
}
