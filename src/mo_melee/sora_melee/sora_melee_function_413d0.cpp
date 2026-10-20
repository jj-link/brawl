#include <types.h>
#pragma force_active on

class Obj {
public:
    virtual int vf0();
    virtual int vf1();
    virtual int vf2();
    virtual int vf3();
    virtual int vf4();
    virtual int vf5();
};

class Outer {
public:
    u8 pad[0x30];
    Obj* m_obj;
};

extern "C" int fn_27_413D0(Outer* p) {
    return p->m_obj->vf3();
}
