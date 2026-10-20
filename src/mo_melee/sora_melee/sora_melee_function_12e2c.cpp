#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;
typedef int s32;

struct Entry {
    void **table;
    s32 base;
};

struct Owner {
    u8 pad[0x38];
    Entry *entries;
};

extern "C" void *fn_27_12E2C(Owner *o, u32 a, s32 b) {
    s32 n = b + 1;
    return o->entries[a].table[o->entries[a].base - n];
}
