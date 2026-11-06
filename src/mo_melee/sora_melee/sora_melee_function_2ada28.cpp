#include <types.h>
#pragma force_active on
struct Entry {
    u8 flags;
    char pad[7];
    s16 prev;
    s16 next;
};
struct Object {
    u32 unk;
    signed int freeIndex : 9;
    signed int first : 9;
    signed int last : 9;
    unsigned int rest : 5;
    char pad[4];
    Entry entries[1];
};
extern "C" int fn_27_2AD89C(Object*, int);
extern "C" int fn_27_2AF314(Object*, int);
extern "C" int fn_27_2ADA28(Object* self, int pos, int where) {
    int prev = -1;
    if (pos >= 0) {
        prev = fn_27_2AD89C(self, pos);
        if (prev < 0) return -1;
    }
    int idx = fn_27_2AF314(self, where);
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