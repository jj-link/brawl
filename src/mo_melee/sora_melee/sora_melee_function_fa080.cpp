#include <types.h>
#pragma force_active on

class soNullable {
public:
    virtual void isNull();
    virtual s32 slot1(s32 index);
    virtual void slot2();
    virtual s32 slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10(s32* value);
};

class Outer {
public:
    u32 pad[4];
    soNullable inner;
};

extern "C" void fn_27_FA080(Outer* self, soNullable* visitor) {
    s32 count = self->inner.slot3();
    for (s32 i = 0; i < count; ++i) {
        s32 value = self->inner.slot1(i);
        visitor->slot10(&value);
    }
}
