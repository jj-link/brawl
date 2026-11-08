#include <types.h>
#pragma force_active on

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10(s32* value);
};

class Object_vptr_10 {
public:
    virtual void slot0();
    virtual s32 slot1(s32 index);
    virtual void slot2();
    virtual s32 slot3();
};

class Outer {
public:
    char pad[0x10];
    Object_vptr_10 inner;
};

extern "C" void fn_27_1BE610(Outer* self, Object_vptr_0* visitor) {
    s32 count = self->inner.slot3();
    for (s32 i = 0; i < count; ++i) {
        s32 value = self->inner.slot1(i);
        visitor->slot10(&value);
    }
}
