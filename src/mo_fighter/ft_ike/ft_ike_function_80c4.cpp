#pragma force_active on
struct Resource;

struct Obj1 {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3(int, Resource*);
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
    virtual int f16();
};

struct Obj2 {
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
    virtual int f17(int);
    virtual void f18(int);
};

struct Container {
    char pad0[0x64];
    Obj2* obj2;
    char pad1[0x08];
    Obj1* obj1;
};

struct Resource {
    char pad0[0xD8];
    Container* container;
};

struct Fighter {
    char pad0[0x60];
    Resource* resource;
};

extern "C" int fn_27_135EE0(void*);

extern "C" int fn_119_80C4(Fighter* self) {
    Obj1* o1 = self->resource->container->obj1;
    if (o1->f16() == 0x11B) {
        Obj2* o2 = self->resource->container->obj2;
        if (o2->f17(0x22000013) != 0) {
            Resource* resource = self->resource;
            resource->container->obj1->f3(0x11C, resource);
            self->resource->container->obj2->f18(0x22000013);
            return 1;
        }
    }
    return fn_27_135EE0(self);
}
