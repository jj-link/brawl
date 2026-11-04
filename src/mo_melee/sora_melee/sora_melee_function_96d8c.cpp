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
    virtual s32 slot6();
};

struct Element {
    soNullable* target;
};

class Class_14370 {
public:
    virtual void fn_27_93100();
    virtual Element* fn_27_9329C(s32);
    virtual void fn_27_932A0();
    virtual s32 fn_27_93778();
    virtual void fn_27_95264();
    virtual void fn_27_93860();
    virtual void fn_27_94198();
};

struct Self {
    char pad[0x2c];
    Class_14370* inner;
};

extern "C" soNullable* fn_27_96D8C(Self* self, s32 id) {
    s32 i = 0;
    while (i < self->inner->fn_27_93778()) {
        if (self->inner->fn_27_9329C(i)->target != 0) {
            if (id == self->inner->fn_27_9329C(i)->target->slot6()) {
                return self->inner->fn_27_9329C(i)->target;
            }
        }
        i++;
    }
    return 0;
}