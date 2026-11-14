#include <types.h>
#include <gr/collision/gr_collision.h>
#pragma force_active on
struct Entry { u8 pad[8]; u8 a, b; s16 c, d; u8 tail[4]; };
struct Obj { u16 id; u16 pad0; u16 count; u8 pad2[0xe]; Entry* entries; };
extern "C" void fn_80111224(Obj* self) {
    unsigned short value;
    int offset;
    unsigned int i;
    Entry* entry;
    Entry* entry2;
    unsigned int j;
    int offset2;
    i = 0;
    offset = 0;
    for (; i < self->count; ++i) {
        entry = (Entry*)((char*)self->entries + offset);
        if (entry->c != -1) { entry->c = -1; entry->a = 0; }
        if (entry->d != -1) { entry->d = -1; entry->b = 0; }
        offset += 18;
    }
    value = self->id;
    nw4r::ut::LinkList<u8, 48>& list = *(nw4r::ut::LinkList<u8, 48>*)&g_grCollisionList;
    nw4r::ut::LinkList<u8, 48>::Iterator it = list.GetBeginIter();
    for (; it != list.GetEndIter(); ++it) {
        Obj* o = (Obj*)&*it;
        j = 0;
        offset2 = 0;
        for (; j < o->count; ++j) {
            entry2 = (Entry*)((char*)o->entries + offset2);
            if (entry2->a == value) { entry2->c = -1; entry2->a = 0; }
            if (entry2->b == value) { entry2->d = -1; entry2->b = 0; }
            offset2 += 18;
        }
    }
}