#pragma force_active on

typedef unsigned int u32;

static inline int firstZero(u32 value)
{
    for (int i = 0; i < 32; ++i) {
        if (!(value & 1)) {
            return i;
        }
        value >>= 1;
    }
    return 33;
}

static inline u32 makeMask(u32 bits)
{
    u32 mask = 0;
    for (int bit = 0; bit < bits; ++bit) {
        mask |= 1 << bit;
    }
    return mask;
}

struct BitSet {
    u32 size;
    u32 data[1];
};

extern "C" int fn_8004465C(BitSet* self)
{
    u32 size = self->size;
    int base = 0;
    u32 i = 0;

    for (; i < (size >> 5); ++i) {
        if (self->data[i] != 0xFFFFFFFF) {
            return base + firstZero(self->data[i]);
        }
        base += 32;
    }

    if ((i << 5) < size) {
        int bit;
        u32 mask = 0;
        u32 bits = size - (i << 5);
        for (bit = 0; bit < bits; ++bit) {
            mask |= 1 << bit;
        }
        u32 value = self->data[i] | ~mask;
        if (value != 0xFFFFFFFF) {
            return base + firstZero(value);
        }
    }

    return 0x0FFFFFFF;
}
