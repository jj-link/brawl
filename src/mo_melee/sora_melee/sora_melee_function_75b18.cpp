#include <types.h>
#pragma force_active on

class fn27Obj {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
};

class fn27Outer {
public:
    u8 pad[0x2c];
    fn27Obj* m_obj;
};

extern "C" {
void fn_27_75B18(fn27Outer* p) {
    p->m_obj->vf2();
}
}
