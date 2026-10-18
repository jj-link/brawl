#pragma force_active on
struct StateObject {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual int getState();
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
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void setState(unsigned int);
};

struct Container {
    char pad0[0x14];
    StateObject* state;
    char pad1[0x4C];
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

extern "C" void fn_27_12E7C8(void*);

extern "C" void fn_115_8A50(Fighter* fighter) {
    fn_27_12E7C8(fighter);
    if (fighter->resource->container->state->getState() != 2 &&
        fighter->resource->container->state->getState() != 5) {
        fighter->resource->container->flags->setState(0x1200003E);
        fighter->resource->container->flags->setState(0x1200003F);
    }
}
