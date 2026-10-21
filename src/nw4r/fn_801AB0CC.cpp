#include <types.h>
#pragma force_active on

extern "C" void fn_801AB0CC(u8* p, u32 flag) {
    u16* field = (u16*)(p + 0xDA);
    *field = *field & ~(flag & 0xFFFF);
}
