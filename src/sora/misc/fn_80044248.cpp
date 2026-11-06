#pragma force_active on
typedef unsigned int u32;
struct BitSet { u32 size; u32 data[1]; };
extern "C" bool fn_80044248(BitSet* self) {
    u32 size = self->size;
    u32 i = 0;
    for (; i < (size >> 5); ++i) {
        if (self->data[i] != 0xffffffff) return true;
    }
    if ((i << 5) < size) {
        int bit;
        u32 mask = 0;
        u32 bits = size - (i << 5);
        for (bit = 0; bit < bits; ++bit) {
            mask |= 1 << bit;
        }
        if (mask != (mask & self->data[i])) return true;
    }
    return false;
}