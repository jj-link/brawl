#include <types.h>
#pragma force_active on

class soFn27Obj {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};

class soFn27Owner {
public:
    u8 pad[8];
    soFn27Obj* m_obj;
};

extern "C" void fn_27_90224(soFn27Owner* self) {
    self->m_obj->f1();
}
