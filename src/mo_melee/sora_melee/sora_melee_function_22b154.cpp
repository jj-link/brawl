#include <types.h>
#pragma force_active on

struct Entry {
    u32 w0;
    u32 w1;
    u32 w2;
    u32 w3;
    u32 w4;
};

struct Container {
    u8 pad[0x48];
    Entry* entries;
    u32 pad4C;
    u32 count;
};

extern "C" void fn_27_22B154(Container* self, Entry* src, u32 index) {
    if (index >= self->count)
        return;

    Entry* dst = self->entries + index;
    dst->w0 = src->w0;
    u32 a = src->w1;
    u32 b = *(u32*)((char*)src + 8);
    u64 pair = ((u64)a << 32) | b;
    dst->w1 = pair >> 32;
    dst->w2 = pair;
    u64 pair2 = ((u64)src->w3 << 32) | src->w4;
    dst->w3 = pair2 >> 32;
    dst->w4 = pair2;
}
