#include <types.h>
#pragma force_active on

extern void fn_8027D4A4(void* a, s32 b);

struct Map {
    s32* data;
    s32 count;
    s32 mask;
};

void fn_8027D0B8(struct Map* self, u32 key, s32 value) {
    s32 idx;
    if (self->count * 2 > self->mask) {
        fn_8027D4A4(self, self->mask * 2 + 2);
    }
    idx = self->mask & ((key >> 4) * 0x9E3779B1);
    while ((u32)self->data[idx] != 0 && (u32)self->data[idx] != key) {
        idx = (idx + 1) & self->mask;
    }
    self->count += ((u32)self->data[idx] != key);
    self->data[idx] = (s32)key;
    self->data[idx + self->mask + 1] = value;
}