#include <mu/mu_object.h>
#include <types.h>
#pragma force_active on

struct Entry {
    const char* name;
    u8 begin;
    u8 end;
    u8 kind;
};

struct Self {
    char pad[0x4C];
    MuObject* objects[256];
};

extern "C" {
extern const Entry lbl_103_rodata_28;
extern const float lbl_103_rodata_30;
}

extern "C" void fn_103_10B94(
    void* self, nw4r::g3d::ResFile* resFile, Heaps::HeapType heapType, int base)
{
    int n;
    int i;
    int j;
    const Entry* entry = &lbl_103_rodata_28;
    Self* s = (Self*)self;

    i = 0;
    while (i < 1) {
        if (entry->begin < entry->end)
            n = entry->end - entry->begin;
        else
            n = 1;

        for (j = 0; j < n; j++) {
            MuObject* obj = MuObject::create(resFile, entry->name, entry->kind + base, 0, heapType);
            s->objects[entry->begin + j] = obj;
            s->objects[entry->begin + j]->m_modelAnim->setUpdateRate(lbl_103_rodata_30);
        }
        i++;
        entry++;
    }
}