#include <gf/gf_pad_system.h>
#include <types.h>
#pragma force_active on

extern "C" {
void fn_8002B4E8(s32 arg0) {
    if (arg0 == 1) {
        u8* p = (u8*)g_gfPadSystem;
        p[0x34] = (u8)(p[0x34] | 0x40);
    }
}
}
