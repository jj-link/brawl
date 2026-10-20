#include <types.h>
#pragma force_active on

struct fn_Hdr {
    u32 unk0;
    u32 unk4;
};

class fn_Obj : public fn_Hdr {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
};

struct fn_Outer {
    u8 pad[0x24];
    fn_Obj* obj;
};

extern "C" void fn_27_281AD0(fn_Outer* self) {
    fn_Obj* obj = self->obj;
    obj->f4();
}
