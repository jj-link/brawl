#pragma force_active on

struct WorkModule {
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
    virtual unsigned int get(unsigned int);
};

struct StatusModule {
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
    virtual int get();
};

struct Lookup {
    virtual void f0();
    virtual int* get(int);
};

struct GroundModule {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void set(int);
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
    virtual void apply(int, int);
};

struct Modules {
    char pad0[0x20];
    GroundModule* ground;
    char pad1[0x40];
    WorkModule* work;
    char pad2[8];
    StatusModule* status;
};

struct Accessor {
    char pad[0xD8];
    Modules* modules;
};

struct Fighter {
    char pad0[0x60];
    Accessor* accessor;
    char pad1[0x32D0];
    Lookup lookup;
};

extern "C" void fn_113_1901C(Fighter* self) {
    int value;
    if (self->accessor->modules->work->get(0x12000003) == 1U) {
        value = 0;
    } else {
        value = *self->lookup.get(self->accessor->modules->status->get());
    }
    if (value == 3) {
        self->accessor->modules->ground->set(1);
    } else {
        self->accessor->modules->ground->set(0);
    }
    self->accessor->modules->ground->apply(value, 0);
}
