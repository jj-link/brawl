#include <types.h>
#pragma force_active on

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual int slot2();
};

struct MainObj {
    char pad0_28[0x28];
    float f28;
    char pad2c_48[0x1C];
    Object_vptr_0* ptr48;
};

extern "C" float fn_8015F874(MainObj* self) {
    return self->f28 * (float)self->ptr48->slot2();
}
