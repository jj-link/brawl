#include <types.h>
#pragma force_active on

extern "C" void getSysPadStatus__11gfPadSystemFiP11gfPadStatus(void*, int, void*);
extern void* g_gfPadSystem;
extern u32 lbl_8045D918[];

extern "C" s32 fn_8010FFBC(s32 arg0) {
    u8 buf[0x40];
    s32 i;
    for (i = 0; i < 8; i++) {
        if (arg0 & (1 << i)) {
            getSysPadStatus__11gfPadSystemFiP11gfPadStatus(g_gfPadSystem, i, buf);
            if (*(u32*)(buf + 0x0C) & lbl_8045D918[*(u32*)(buf + 0x3C)]) {
                return 1;
            }
        }
    }
    return 0;
}
