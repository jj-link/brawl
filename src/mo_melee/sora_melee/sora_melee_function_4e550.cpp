#include <types.h>
#pragma force_active on

struct fn27Obj {
    virtual void f0();
    virtual s32* f1();
};

struct fn27Owner {
    u8 pad[0x2c];
    fn27Obj* m_obj;
};

extern "C" {
bool fn_27_4E550(fn27Owner* self) {
    s32* p = self->m_obj->f1();
    return *p != 0;
}
}
