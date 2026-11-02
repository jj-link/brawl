#include <types.h>
#pragma force_active on

struct Obj;

struct Handle {
    Obj* obj;
};

class Owner {
public:
    virtual void f0();
    virtual Handle* f1(int idx);
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
};

class Obj {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    u8 unk4;
    u8 flag : 1;
};

struct Self {
    char pad[0x14];
    Owner* owner;
};

extern "C" void fn_27_1DC1C0(Self* self) {
    Owner* owner = self->owner;
    Obj* a = owner->f1(0)->obj;
    a->f6();
    a->flag = 0;
    Obj* b = owner->f1(1)->obj;
    b->f6();
    b->flag = 0;
}
