#include <types.h>

#pragma force_active on

class Class_80487550 {
public:
    virtual void fn_802D2670();
    virtual void fn_802D45D0();
    virtual void fn_802D45C8();
    virtual void fn_802D3478();
    virtual void fn_802D0890();
    virtual void fn_802D3B30();
};

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5(void* ptr, u16 type, s32 align);
};

extern Object_vptr_0* lbl_805A0EB8;

struct DtorObj {
    void* vtable;
    u16 type;
};

extern "C" void* fn_802D2670(void* arg0, s32 arg1) {
    DtorObj* self = (DtorObj*)arg0;
    if (self != 0 && arg1 > 0) {
        lbl_805A0EB8->slot5(self, self->type, 0x25);
    }
    return self;
}
