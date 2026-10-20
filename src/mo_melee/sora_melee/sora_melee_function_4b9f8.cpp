#pragma force_active on
struct B {
    unsigned char pad[0x10];
    float value;
};

struct A {
    virtual void v0();
    virtual B* v1();
};

struct C {
    unsigned char pad[0x2c];
    A* a;
};

extern "C" float fn_27_4B9F8(C* self) {
    return self->a->v1()->value;
}
