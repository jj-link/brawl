#include <math.h>
#pragma force_active on

extern const float lbl_27_rodata_46DC;
extern const float lbl_27_rodata_46D8;

struct Work {
    virtual void unused0();
    virtual void unused1();
    virtual void unused2();
    virtual void unused3();
    virtual void unused4();
    virtual void unused5();
    virtual void unused6();
    virtual void unused7();
    virtual void unused8();
    virtual void unused9();
    virtual void unused10();
    virtual void unused11();
    virtual float getFloat(unsigned int);
    virtual void setFloat(float, unsigned int);
};

struct Modules {
    char pad[0x64];
    Work* work;
};

struct Owner {
    char pad[0xD8];
    Modules* modules;
};

struct Object {
    char pad[0x60];
    Owner* owner;
};

extern "C" void fn_27_298804(void*, Object* object) {
    Work* work = object->owner->modules->work;
    float value = work->getFloat(0x11000000);
    if (!((float)fabs(value) <= lbl_27_rodata_46DC)) {
        value *= lbl_27_rodata_46D8;
        work->setFloat(value, 0x11000000);
    }
}
