#include <types.h>
#pragma force_active on

extern "C" {
void* fn_27_54370(void* self, s32 idx) {
    s32 v = *(s32*)((u8*)self + 8);
    s32 i = (v >> 23) + idx;
    if (i >= 0xff) {
        i -= 0xff;
    }
    return (u8*)self + 12 + i * 12;
}
}
