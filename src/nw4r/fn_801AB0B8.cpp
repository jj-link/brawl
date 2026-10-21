#include <types.h>
#pragma force_active on

extern "C" void fn_801AB0B8(u8* p, u32 v) {
    u16* field = (u16*)(p + 0xda);
    *field = *field | (u16)v;
}
