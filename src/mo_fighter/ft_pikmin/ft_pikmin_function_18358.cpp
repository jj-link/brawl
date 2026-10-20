#pragma force_active on
struct Accesser;

struct Target {
    unsigned char pad[8];
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void invoke(Accesser*, int, int);
};

struct Provider {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual Target* get();
};

struct Modules {
    unsigned char pad[0x64];
    Provider* provider;
};

struct Accesser {
    unsigned char pad[0xD8];
    Modules* modules;
};

struct Owner {
    unsigned char pad[0x60];
    Accesser* accesser;
};

extern "C" void fn_113_18358(Owner* owner, int arg) {
    Accesser* accesser = owner->accesser;
    Target* target = accesser->modules->provider->get();
    target->invoke(accesser, arg, 0);
}
