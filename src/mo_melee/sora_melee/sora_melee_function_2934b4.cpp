#include <types.h>
#pragma force_active on

class Class_15DB8 {
public:
    virtual void fn_27_AC9D8();
    virtual s32 fn_27_AC37C(s32);
    virtual void fn_27_AC38C();
    virtual s32 fn_27_ABFCC();
};

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
    virtual void slot10(s32*);
};

class Outer {
public:
    u32 pad[4];
    Class_15DB8 inner;
};

extern "C" void fn_27_2934B4(Outer* self, soNullable* visitor) {
    s32 count = self->inner.fn_27_ABFCC();
    for (s32 i = 0; i < count; ++i) {
        s32 value = self->inner.fn_27_AC37C(i);
        visitor->slot10(&value);
    }
}