#include <types.h>
#pragma force_active on

struct LucasIndexed {
    char pad[0x18];
    s32 base;
    char pad2[0x2c - 0x1c];
};

extern "C" u32 fn_114_20C40(LucasIndexed* self, s32 unused, s32 index) {
    u32* arr = (u32*)((char*)self + 0x2c);
    return arr[index - self->base];
}
