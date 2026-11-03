#include <types.h>
#include <gm/gm_global.h>
#include <revolution/OS/OSTime.h>

#pragma force_active on

extern "C" void fn_8015051C(s64 arg) {
    if (arg != 0) {
        u8* p = *(u8**)((u8*)g_GameGlobal + 0x38);
        s64 t = OSGetTime();
        s64 v = arg - t;
        *(s32*)(p + 0x14) = (s32)v;
        *(s32*)(p + 0x10) = (s32)(v >> 32);
        if (((s32)v | (s32)(v >> 32)) == 0) {
            *(s32*)(p + 0x14) = 1;
            *(s32*)(p + 0x10) = 0;
        }
    }
}
