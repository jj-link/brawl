#include <types.h>
#pragma force_active on

extern "C" {
extern unsigned char lbl_80423690[];

u32 fn_6_2FA0(unsigned char* self) {
    unsigned char* tbl = lbl_80423690;
    unsigned char* inner = *(unsigned char**)(self + 0x1ac);
    if (*(s32*)(inner + 0x1a0) == 0) {
        return *(u32*)(tbl + 0xc);
    }
    return *(u32*)(tbl + 0x8);
}
}
