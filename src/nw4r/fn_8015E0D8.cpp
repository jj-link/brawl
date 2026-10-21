#include <types.h>
#pragma force_active on
extern "C" {
s32 fn_8015E0D8(void* self) {
    s8* p = *(s8**)((u8*)self + 0x14);
    return p[1];
}
}
