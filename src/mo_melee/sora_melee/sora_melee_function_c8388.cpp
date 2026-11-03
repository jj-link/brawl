#include <types.h>
#pragma force_active on
struct Entry {
    u8 flags;
    char pad[15];
    s8 prev;
    s8 next;
    char pad2[2];
};
struct Object {
    u32 unk;
    unsigned int a : 5;
    signed int first : 5;
    signed int last : 5;
    unsigned int rest : 17;
    Entry entries[1];
};
extern "C" int fn_27_C81F4(Object*, int);
extern "C" int fn_27_C8048(Object*, int);
extern "C" int fn_27_C8388(Object* self, int arg1, int arg2) {
    int prev = -1;
    if (arg1 >= 0) {
        prev = fn_27_C81F4(self, arg1);
        if (prev < 0)
            return -1;
    }
    int idx = fn_27_C8048(self, arg2);
    if (idx < 0)
        return -1;
    int next = -1;
    if (prev < 0) {
        next = self->first;
    } else {
        if (self->entries[prev].next >= 0)
            next = self->entries[prev].next;
    }
    if (prev >= 0)
        self->entries[prev].next = idx;
    else
        self->first = idx;
    self->entries[idx].prev = prev;
    if (next >= 0)
        self->entries[next].prev = idx;
    else
        self->last = idx;
    self->entries[idx].next = next;
    self->entries[idx].flags |= 0x80;
    return idx;
}