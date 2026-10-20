#pragma force_active on
struct Access;

struct Module {
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
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void f25();
    virtual void f26();
    virtual void f27();
    virtual void f28();
    virtual void f29();
    virtual void f30();
    virtual void f31();
    virtual void f32();
    virtual void f33();
    virtual void call(int, Access*);
};

struct Modules {
    char pad[0x70];
    Module* module;
};

struct Access {
    char pad[0xD8];
    Modules* modules;
};

struct Self {
    char pad[0x60];
    Access* access;
};

struct Event {
    int kind;
};

extern "C" void fn_27_1DB0F0(Self*, Event*, void*, void*, int);

extern "C" void fn_116_11104(
    Self* self, Event* event, void* a, void* b, int c)
{
    switch (event->kind) {
    case 0x838:
        Module* module = self->access->modules->module;
        module->call(1, self->access);
        return;
    }

    fn_27_1DB0F0(self, event, a, b, c);
}
