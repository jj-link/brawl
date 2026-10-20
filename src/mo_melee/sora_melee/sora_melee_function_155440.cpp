#pragma force_active on
struct Base {
    virtual int f0(void);
    virtual int f1(void);
    virtual int f2(void);
    virtual int f3(void);
    virtual int f4(void);
    virtual int f5(void);
    virtual int f6(void);
    virtual int f7(void);
    virtual int f8(void);
    virtual int f9(void);
    virtual int f10(void);
    virtual int f11(void);
    virtual int f12(void);
    virtual int f13(void);
    virtual int f14(void);
    virtual int f15(void);
    virtual int f16(void);
    virtual int f17(void);
    virtual int f18(void);
    virtual int f19(void);
    virtual int f20(void);
    virtual int f21(void);
    virtual int f22(void);
    virtual int f23(void);
    virtual int f24(void);
    virtual int f25(void);
    virtual int f26(void);
    virtual int f27(void);
    virtual int f28(void);
    virtual int f29(void);
    virtual int f30(void);
    virtual int f31(void);
    virtual int f32(void);
    virtual int f33(void);
    virtual int f34(int arg);
    virtual int f35(void);
    virtual int f36(int arg);
};

struct A {
    char pad0[0x20];
    Base* c;
    char pad1[0x70 - 0x24];
    Base* b;
};

struct Self {
    char pad[0xd8];
    A* a;
};

extern "C" int fn_27_155440(void* unused, Self* self) {
    if (self->a->b->f16() != 0xc6 && self->a->c->f34(0) == 0) {
        return 1;
    }
    return 0;
}
