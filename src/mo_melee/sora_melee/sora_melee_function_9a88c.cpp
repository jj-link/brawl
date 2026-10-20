#pragma force_active on
struct Target {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual int call(int);
};

struct Modules {
    unsigned char padding[0x6C];
    Target* target;
};

struct Owner {
    unsigned char padding[0xD8];
    Modules* modules;
};

struct Object {
    unsigned char padding[0x44];
    Owner* owner;
    unsigned char padding48[0x28];
    int index;
};

extern "C" int fn_27_9A88C(Object* self) {
    int index = self->index;
    if (index >= 0) {
        Target* target = self->owner->modules->target;
        return target->call(index);
    }
    return 0;
}
