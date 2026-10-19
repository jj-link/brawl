#pragma force_active on
typedef unsigned int u32;
typedef unsigned char u8;

struct Entry {
    u8 data[0x18];
};

struct Holder {
    u8 pad0[0x0c];
    u32 count;
    Entry *entries;
};

extern "C" Entry *fn_41_D5A0(Holder *h, u32 idx)
{
    if (idx >= h->count) {
        return 0;
    }
    return h->entries + idx;
}
