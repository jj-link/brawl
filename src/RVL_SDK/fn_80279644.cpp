#include <types.h>
#pragma force_active on

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
};

struct Entry {
    void* unused;
    Object_vptr_0* object;
};

struct Container {
    u8 padding[8];
    u8 list[8];
    u16 count;
};

extern "C" Entry* fn_8015C1EC(void*, u16);

extern "C" void fn_80279644(Container* self) {
    for (u32 i = 0; i < self->count; ++i) {
        fn_8015C1EC(self->list, (u16)i)->object->slot4();
    }
}
