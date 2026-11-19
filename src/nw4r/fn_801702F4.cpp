#pragma force_active on
#include <types.h>
struct Data { s16 a; u8 b, c, d, e, f, g; };
struct Ref { char pad[16]; int count; };
struct Entry { u8 flag; u8 pad; s16 value; Data data; Ref* ref; int other; };
struct List { int count; Entry entries[1024]; };
extern "C" void fn_801702F4(List* self, Data data, Ref* ref, int other, s16 value) {
    if (self->count < 0x400) {
        self->entries[self->count].flag = 1;
        self->entries[self->count].value = value;
        self->entries[self->count].data = data;
        self->entries[self->count].ref = ref;
        ref->count++;
        self->entries[self->count].other = other;
        self->count++;
    }
}