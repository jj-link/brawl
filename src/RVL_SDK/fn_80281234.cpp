#include <types.h>
#pragma force_active on

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual u32 slot2();
};

struct Holder {
    u8 pad[8];
    Object_vptr_0* obj;
    u8 pad2[4];
    int a;
    int b;
};

extern "C" int fn_80281234(Holder* self) {
    int result = 1;
    if (self->a == self->b) {
        if ((s8)(self->obj->slot2() >> 24) == 0) {
            result = 0;
        }
    }
    return result << 24;
}
