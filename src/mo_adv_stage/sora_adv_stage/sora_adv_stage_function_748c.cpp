#include <gf/gf_archive.h>
#include <st/st_data_container.h>
#pragma force_active on

struct Entry {
    u8 kind;
    u8 pad;
    u16 a;
    u16 b;
};
class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual Entry* slot3(u32);
};

struct Self {
    char pad[0x1e4];
    stDataMultiContainer* container;
    Entry** entries;
    u32 count;
};

extern "C" void fn_40_748C(Self* self, gfArchive* archive) {
    stDataContainerData* data = (stDataContainerData*)archive->getData(Data_Type_Misc, 6, 0xfffe);
    if (data && !self->container) {
        self->container = stDataMultiContainer::create(data, (Heaps::HeapType)15);
        for (u32 i = 0; i < self->container->m_filedata->m_numFiles; i++) {
            Entry* entry = (Entry*)self->container->getData(i);
            if (entry->kind != 0 && entry->kind <= 31 && entry->a != 0 && entry->b != 0) {
                self->count++;
            }
        }
        self->entries = new ((Heaps::HeapType)15) Entry*[self->count];
        u32 i = 0;
        u32 n = 0;
        for (; i < self->container->m_filedata->m_numFiles; i++) {
            Entry* entry = (Entry*)self->container->getData(i);
            if (entry->kind != 0 && entry->kind <= 31 && entry->a != 0 && entry->b != 0) {
                self->entries[n++] = entry;
            }
        }
    }
}