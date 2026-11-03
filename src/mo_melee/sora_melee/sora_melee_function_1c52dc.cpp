#include <types.h>
#pragma force_active on

class soNullable {
public:
    virtual void isNull();
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

class Class_19FD0 {
public:
    virtual void fn_27_DCA5C();
    virtual s32 fn_27_DC3F0(s32 index);
    virtual void fn_27_DC400();
    virtual s32 fn_27_D32CC();
};

struct Outer {
    char pad[0x10];
    Class_19FD0 inner;
};

extern "C" void fn_27_1C52DC(Outer* self, soNullable* visitor) {
    s32 count = self->inner.fn_27_D32CC();
    for (s32 i = 0; i < count; ++i) {
        s32 value = self->inner.fn_27_DC3F0(i);
        visitor->slot10(&value);
    }
}
