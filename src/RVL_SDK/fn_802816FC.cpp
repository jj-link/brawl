#include <types.h>
#pragma force_active on

extern "C" void fn_802815A0(void* p);

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
};

class Class_804864A0 {
public:
    virtual void fn_802814B8();
    virtual void fn_80080A64();
    virtual void fn_80281744();
    virtual void fn_80281640();
    virtual void fn_802816FC();
    int unk4;
    Object_vptr_0* unk8;
};

extern "C" void fn_802816FC(Class_804864A0* self) {
    fn_802815A0(self);
    if (self->unk8 != 0) {
        self->unk8->slot4();
    }
}
