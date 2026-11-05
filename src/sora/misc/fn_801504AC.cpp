#include <types.h>
#include <gm/gm_global.h>
#pragma force_active on

extern "C" s64 OSGetTime(void);

extern "C" u64 fn_801504AC(u8* arg0) {
    u8* p = *(u8**)((u8*)g_GameGlobal + 0x38);
    u64 t = (u64)OSGetTime();
    t += (((u64)*(u32*)(p + 0x10) << 32) | *(u32*)(p + 0x14));
    if (arg0 != NULL) {
        if ((*(u32*)(p + 0x14) | *(u32*)(p + 0x10)) == 0) {
            *arg0 = 0;
        } else {
            *arg0 = 1;
        }
    }
    return t;
}
