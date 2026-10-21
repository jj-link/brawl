#include <types.h>
#pragma force_active on

class Item {
public:
    char pad[0x18];
    s32 m_id;
};

extern "C" void fn_27_118398(Item* item, s32 id, s32 arg);

class ItemList {
public:
    virtual void vf0();
    virtual Item** getAt(s32 idx);
    virtual void vf4();
    virtual s32 getCount();
};

class Holder {
public:
    u32 pad[2];
    ItemList list;
};

class Owner {
public:
    char pad[0x154];
    Holder* m_holder;
};

extern "C" {
void fn_27_10B464(Owner* self, s32 id, s32 arg) {
    s32 count = self->m_holder->list.getCount();
    for (s32 i = 0; i < count; i++) {
        Item* item = *self->m_holder->list.getAt(i);
        if (id != item->m_id) {
            fn_27_118398(item, id, arg);
        }
    }
}
}
