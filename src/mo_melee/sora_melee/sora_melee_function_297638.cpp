#pragma force_active on
class Target {
    char padding[8];

public:
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
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void call(int);
};

struct Modules {
    char padding[0xB0];
    Target* target;
};

struct Owner {
    char padding[0xD8];
    Modules* modules;
};

struct Argument {
    char padding[0x60];
    Owner* owner;
};

extern "C" void fn_27_297638(void*, Argument* argument) {
    argument->owner->modules->target->call(9);
}
