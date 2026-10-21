#pragma force_active on
struct Argument {
    int id;
    bool flag;

    Argument(int value) : id(value), flag(false) {}
};

struct Module {
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
    virtual void set(int, const Argument&);
};

struct Modules {
    char pad[0x54];
    Module* module;
};

struct Accessor {
    char pad[0xd8];
    Modules* modules;
};

struct Fighter {
    char pad[0x60];
    Accessor* accessor;
};

extern "C" void fn_122_22D0C(Fighter* self, int enabled) {
    if (enabled) {
        self->accessor->modules->module->set(3, Argument(0x456));
    } else {
        self->accessor->modules->module->set(3, Argument(0x457));
    }
}
