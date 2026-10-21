#include <types.h>
#pragma force_active on

struct Item {
    char pad[0x38];
    u32 field_0x38;
};

struct Collection {
    virtual void v0();
    virtual Item* get(int index);
    virtual void v2();
    virtual int size();
};

struct Container {
    char pad[0x28];
    Collection* m_collection;
};

extern "C" int fn_27_26854(Container* self) {
    int count = self->m_collection->size();
    for (int i = 0; i < count; i++) {
        if (((self->m_collection->get(i)->field_0x38 >> 12) & 0xF) == 0 ||
            ((self->m_collection->get(i)->field_0x38 >> 12) & 0xF) == 2) {
            return 1;
        }
    }
    return 0;
}
