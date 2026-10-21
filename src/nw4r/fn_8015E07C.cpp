#include <types.h>
#pragma force_active on
extern "C" {
s32 fn_8015E07C(void* self) {
    s8* p = *(s8**)((u8*)self + 0x14);
    s8* q = *(s8**)((u8*)p + 0x8);
    return q[2];
}
}
