#pragma force_active on
struct Target {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void call();
};

struct Modules {
    char padding[0x58];
    Target* target;
};

struct Owner {
    char padding[0xD8];
    Modules* modules;
};

struct Object {
    char padding[0x60];
    Owner* owner;
};

extern "C" void fn_113_1B238(Object* object) {
    object->owner->modules->target->call();
}
