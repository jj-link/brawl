#pragma force_active on
struct StateObject {
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
    virtual int f14(int, int);
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
    virtual void f34();
    virtual void f35();
    virtual void f36();
    virtual void f37();
    virtual void f38();
    virtual void f39();
    virtual void f40();
    virtual void f41();
    virtual int f42(int, int);
};

struct FlagObject {
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
    virtual void f12(unsigned int);
};

struct Container {
    char pad0[0x1C];
    StateObject* state;
    char pad1[0x44];
    FlagObject* flags;
};

struct Resource {
    char pad0[0xD8];
    Container* container;
};

struct Fighter {
    char pad0[0x60];
    Resource* resource;
};

extern "C" void fn_105_1BB00(Fighter* fighter, int arg1) {
    if (fighter->resource->container->state->f14(arg1, 0)) {
        if (fighter->resource->container->state->f42(arg1, 0)) {
            fighter->resource->container->flags->f12(0x11000001);
            fighter->resource->container->flags->f12(0x11000002);
        }
    }
}
