#include <types.h>
#pragma force_active on

class ObjBase {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
};

struct Outer {
    u8 pad[0x10];
};

extern "C" {
void fn_27_31948C(Outer* p) {
    ObjBase* obj = reinterpret_cast<ObjBase*>(reinterpret_cast<char*>(p) + 0x10);
    obj->vf3();
}
}
