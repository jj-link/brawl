#pragma force_active on
typedef unsigned int u32;
typedef unsigned long long u64;
typedef unsigned char u8;

struct Entry {
    u8 pad0[0x20];
    u64 v;
};

struct Holder {
    u8 pad0[0x0c];
    Entry *entries;
    u32 count;
};

extern "C" u64 fn_8014D0D8(Holder *h, u32 idx)
{
    if (idx >= h->count) {
        return 0;
    }
    return h->entries[idx].v;
}
