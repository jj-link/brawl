#include <types.h>
#pragma force_active on

extern "C" void fn_27_37D7C(void*, void*, s32, s32);

struct Item {
    u8 pad[0x38];
    void* a;
    void* b;
};

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual Item* slot1(s32 i);
    virtual void slot2();
    virtual s32 slot3();
};

struct Host {
    u8 pad[0x8];
    Object_vptr_0* list;
};

extern "C" void fn_27_366BC(Host* self, s32 arg1) {
    Item* item;
    s32 i;
    for (i = 0; i < self->list->slot3(); i++) {
        item = self->list->slot1(i);
        fn_27_37D7C(item, item->a, 1, arg1);
        fn_27_37D7C(item, item->b, 1, arg1);
    }
}
