#include <types.h>
#pragma force_active on

struct Item {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void call();
};

struct Owner {
    char pad[0x18];
    s32 m_count;
    Item** m_items;
};

extern "C" void fn_8019A05C(Owner* self) {
    for (s32 i = 0; i < self->m_count; i++) {
        if (self->m_items[i] != 0) {
            self->m_items[i]->call();
        }
    }
}
