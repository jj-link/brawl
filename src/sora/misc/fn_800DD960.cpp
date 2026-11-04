#include <mu/mu_object.h>
#include <cstdio>
#pragma force_active on
struct Entry { const char* name; unsigned char begin, end, kind; };
struct Owner { char pad[0x10]; MuObject* objects[1]; };
extern "C" {
extern char lbl_8059E220[6];
void fn_800B20B0(MuObject*, int);
void fn_800B21C4(MuObject*, int);
}
extern "C" void fn_800DD960(Owner* self, Entry* entry, int count, nw4r::g3d::ResFile* res) {
    char buf[0x40];
    int n;
    Owner* slot;
    Entry* p = entry;
    int i;
    int j;
    for (i = 0; i < count; i++, p++) {
        n = 1;
        if (p->begin < p->end)
            n = p->end - p->begin;
        sprintf(buf, lbl_8059E220, p->name);
        for (j = 0; j < n; j++) {
            slot = (Owner*)((char*)self + (p->begin + j) * 4);
            slot->objects[0] = MuObject::create(res, p->name, p->kind, 0, (HeapType)0x28);
            fn_800B20B0(slot->objects[0], 1);
            fn_800B21C4(slot->objects[0], 1);
            slot->objects[0]->changeAnimN(buf);
            *(int*)((char*)slot->objects[0]->m_sceneModel + 0x118) = 8;
        }
    }
}