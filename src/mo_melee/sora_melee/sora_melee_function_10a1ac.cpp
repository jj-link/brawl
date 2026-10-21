#include <types.h>
#pragma force_active on

extern "C" void fn_27_124364(void* obj, unsigned long id);

struct SubList {
    virtual void f0();
    virtual void* getItem(u32 index);
    virtual void f4();
    virtual s32 getCount();
};

struct Item {
    u8 pad[0x2c];
    void* m_obj;
};

struct Child {
    u8 pad[0x8];
    SubList m_list;
};

struct Entity {
    u8 pad[0x154];
    Child* m_child;
};

extern "C" {
void fn_27_10A1AC(Entity* entity, u32 id)
{
    s32 count = entity->m_child->m_list.getCount();
    for (s32 i = 0; i < count; i++) {
        Item* item = *(Item**)entity->m_child->m_list.getItem(i);
        fn_27_124364(item->m_obj, id);
    }
}
}
