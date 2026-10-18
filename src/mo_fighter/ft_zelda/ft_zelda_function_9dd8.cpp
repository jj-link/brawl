#pragma force_active on
struct Owner {
    unsigned char pad[0x60];
    void* module;
};

struct Module {
    unsigned char pad[0xD8];
    void* submodule;
};

struct Interface;

struct Submodule {
    unsigned char pad[0x64];
    Interface* interface;
};

struct Interface {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void invoke(void*, int);
};

struct Arg {
    unsigned char pad[0x100];
    void* value;
};

extern "C" void fn_27_13D34C(void*, void*);

extern "C" void fn_104_9DD8(Owner* owner, Arg* arg) {
    fn_27_13D34C(owner, arg);
    Interface* p =
        (Interface*)((Submodule*)((Module*)owner->module)->submodule)->interface;
    p->invoke(arg->value, 0x10000040);
}
