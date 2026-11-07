#pragma force_active on
class Class_7FE8 {
public:
    virtual void fn_113_80F4();
    virtual void fn_113_1552C();
    virtual void fn_113_1C084();
    virtual void fn_113_1C07C();
    virtual int fn_113_1C074(int);
    virtual void fn_113_1C06C();
    virtual void fn_113_1C064();
    virtual void fn_113_1C05C();
    virtual void fn_113_1C054(int);
    virtual void fn_113_1C04C();
    virtual void fn_113_1C044();
    virtual void fn_113_1C03C();
    virtual void fn_113_1C034();
    virtual void fn_113_1C02C(float, int);
    virtual void fn_113_1BFDC();
    virtual void fn_113_1C024();
    virtual void fn_113_1C014();
    virtual void fn_113_1C004();
    virtual void fn_113_1BFF4();
    virtual void fn_113_1BFE4(int);
};
struct State {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual int f3();
};
struct Other {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual int f9();
};
struct Container {
    char pad0[0x14];
    State* state;
    char pad1[0x2c];
    Other* other;
    char pad2[0x1c];
    Class_7FE8* flags;
};
struct Resource {
    char pad[0xd8];
    Container* container;
};
struct Fighter {
    char pad[0x60];
    Resource* resource;
};
extern "C" void* fn_113_A3D8();
extern "C" unsigned int fn_27_5BE80(void*);
extern "C" void fn_113_1B58C(void*);
extern "C" void fn_113_1B79C(void*);
extern "C" void fn_27_1D9FF8(void*);
extern "C" const float lbl_113_rodata_64;
extern "C" void fn_113_17BE0(Fighter* self) {
    self->resource->container->flags->fn_113_1BFE4(0x12000004);
    if (fn_27_5BE80(fn_113_A3D8()) == 1U) {
        if (self->resource->container->other->f9() == 0) {
            fn_113_1B58C(self);
            fn_113_1B79C(self);
            if (self->resource->container->state->f3() != 3) {
                int id = 0x1000000c;
                if (self->resource->container->flags->fn_113_1C074(id) >= 0) {
                    self->resource->container->flags->fn_113_1C054(id);
                }
            }
        }
    }
    self->resource->container->flags->fn_113_1C02C(lbl_113_rodata_64, 0x11000001);
    fn_27_1D9FF8(self);
}