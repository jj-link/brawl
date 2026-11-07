#pragma force_active on
#include <types.h>

struct Modules;
struct Acc;

struct Vec {
    float x, y, z;
};

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
    virtual float slot9(Modules*);
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual Vec slot14(int);
};

struct Modules {
    char pad[12];
    Object_vptr_0* object;
};

struct Acc {
    char pad[0xD8];
    Modules* modules;
};

class Self {
public:
    virtual void slot0();
    virtual void slot1(Acc*);

    unsigned char f4;
    unsigned char f5a : 1;
    unsigned char f5b : 7;
    unsigned char f6;
    char pad[0x35];
    float value;
};

extern "C" float lbl_27_rodata_79D0;
extern "C" float lbl_27_rodata_79D8;

extern "C" void fn_27_359CE4(Self* self, u32 unused, Acc* acc) {
    Modules* mod = acc->modules;
    int sign;

    if (mod->object->slot9(mod) < lbl_27_rodata_79D0)
        sign = -1;
    else
        sign = 1;

    float f = (float)sign;
    float x = -acc->modules->object->slot14(0).x;
    self->value = lbl_27_rodata_79D8 * (x * f);

    if ((u32)(!!self->f5a) == 1 && self->f6 == 0)
        self->slot1(acc);
}
