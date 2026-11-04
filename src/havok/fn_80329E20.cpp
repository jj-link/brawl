#include <types.h>
#pragma force_active on
struct Flag { s8 value; Flag(bool b) : value(b) {} operator s8() const { return value; } };
struct Object {
    char pad[0xA8]; u8 type;
    Flag is7() const { return type == 7; }
    Flag is6() const { return type == 6; }
    bool valid() const { return is7() || is6(); }
};
struct Pair { char pad[4]; Object* a; Object* b; bool valid() const { return a->valid() || b->valid(); } };
struct Item { char pad[0x28]; Pair* pair; };
struct Entry { Item* item; int x; float y; };
struct Array { Entry* entries; int count; };
extern "C" void fn_80329E20(Array* self, int* out, int n) {
    Entry* e;
    for (int i = self->count - n; i < self->count; i++) {
        e = &self->entries[i];
        if (e->item->pair->valid()) {
            int index = (*out)++;
            Entry* dst = &self->entries[index];
            Entry tmp = *dst;
            *dst = *e;
            *e = tmp;
        }
    }
}