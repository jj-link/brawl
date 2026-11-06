#include <types.h>
#pragma force_active on

class Class_802AF338 {
public:
    virtual ~Class_802AF338();
    virtual void fn_80080A64();
    virtual void fn_802B2140();
    virtual void fn_802B26C8();
    virtual void fn_802B7A14();
    virtual void fn_802B37E4();

    u16 type;
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

extern "C" void* __dt__14Class_802AF338Fv(void* arg0, s32 arg1) {
    Class_802AF338* self = (Class_802AF338*)arg0;
    if (self != 0 && arg1 > 0) {
        lbl_805A0EB8->slot5(self, self->type, 0x1d);
    }
    return self;
}
