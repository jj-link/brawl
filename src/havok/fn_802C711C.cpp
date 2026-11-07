#include <types.h>
#pragma force_active on

class Class_80487134 {
public:
    virtual void fn_802C711C();
    virtual void fn_80080A64();
    virtual void fn_802C7B54();
    virtual void fn_802C7288();
    virtual void fn_802B7A14();
    virtual void fn_802C7EBC();
};

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5(void*, u16, s32);
};

extern Object_vptr_0* lbl_805A0EB8;

struct DtorObj {
    void* vtable;
    u16 type;
};

extern "C" void* fn_802C711C(void* arg0, s32 arg1) {
    DtorObj* self = (DtorObj*)arg0;
    if (self != 0 && arg1 > 0) {
        lbl_805A0EB8->slot5(self, self->type, 0x1d);
    }
    return self;
}