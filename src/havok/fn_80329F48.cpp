#include <types.h>
#pragma force_active on

struct Object {
    char pad[0x90];
    u16 byteOff;
    char pad2[6];
};

struct Pair {
    char pad[4];
    Object* a;
    Object* b;
};

struct Item {
    char pad[0x28];
    Pair* pair;
};

struct Entry {
    Item* item;
    int x;
    float y;
};

struct Array {
    Entry* entries;
    int count;
};

extern "C" void fn_80329F48(Array* self, int* out, int* idx) {
    Entry* dst;
    int off;
    Entry* src;
    int i;
    i = *out;
    off = i * 12;
    for (; i < self->count; off += 12, i++) {
        src = (Entry*)((char*)self->entries + off);
        Pair* pair = src->item->pair;
        u8* base = (u8*)*idx;
        if (base[pair->a->byteOff] == 8 && base[pair->b->byteOff] == 8) {
            int n = *out;
            *out = n + 1;
            dst = &self->entries[n];
            Entry tmp = *dst;
            *dst = *src;
            *src = tmp;
        }
    }
}
