#include <types.h>
#pragma force_active on

struct Ret {
    u8 pad[0x14];
    float m_value;
};

struct Obj {
    virtual void f0();
    virtual Ret* f1();
};

struct Self {
    u8 pad[0x30];
    Obj* m_obj;
};

extern "C" float fn_27_3A6A4(Self* self) {
    Ret* r = self->m_obj->f1();
    return r->m_value;
}
