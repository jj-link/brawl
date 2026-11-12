#include <types.h>
#pragma force_active on
struct Obj { u8 pad[0xE4]; u32 count; u8 pad2[4]; u32* items; };
extern "C" void* fn_801ABFFC(Obj*, u32);
inline void shift(Obj* self, u32 index, u32 count) {
    for (; index < count; index++) {
        self->items[index] = self->items[index + 1];
    }
}
extern "C" void* fn_801B5004(Obj* self, u32 index) {
    void* result = fn_801ABFFC(self, index);
    if (result) {
        shift(self, index, self->count);
    }
    return result;
}