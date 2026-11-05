#include <types.h>
#pragma force_active on

struct Entry {
    u8 flags;
    char pad[7];
    s8 prev;
    s8 next;
    char pad2[2];
};

struct Object {
    u32 unk;
    signed int freeIndex : 3;
    signed int first : 3;
    signed int last : 3;
    unsigned int rest : 23;
    Entry entries[1];
};

extern "C" int fn_27_2AC504(Object*, int);
extern "C" int fn_27_2AE498(Object*, int);

extern "C" int fn_27_2AC698(Object* self, int pos, int where) {
    int prev = -1;
    if (pos >= 0) {
        prev = fn_27_2AC504(self, pos);
        if (prev < 0) return -1;
    }
    int idx = fn_27_2AE498(self, where);
    if (idx < 0) return -1;
    int next = -1;
    if (prev < 0) next = self->first;
    else if (self->entries[prev].next >= 0) next = self->entries[prev].next;
    if (prev >= 0) self->entries[prev].next = idx;
    else self->first = idx;
    self->entries[idx].prev = prev;
    if (next >= 0) self->entries[next].prev = idx;
    else self->last = idx;
    self->entries[idx].next = next;
    self->entries[idx].flags |= 0x80;
    return idx;
}
