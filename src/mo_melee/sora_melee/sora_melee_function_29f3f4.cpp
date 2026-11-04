#pragma force_active on

struct Target {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8(int);
    virtual int f9(int);
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
    virtual void f34();
    virtual void f35();
    virtual void f36();
    virtual void f37();
    virtual void f38();
    virtual void f39();
    virtual void f40();
    virtual void f41();
    virtual void* f42(int);
};

struct Inner {
    char pad[0x54];
    Target* target;
};

struct Middle {
    char pad[0xd8];
    Inner* inner;
};

struct Self {
    char pad[0x60];
    Middle* middle;
};

extern "C" int fn_27_29F3F4(void*, Self* self, void* arg) {
    if (self->middle->inner->target->f9(1) != 0) {
        if (arg != self->middle->inner->target->f42(1)) {
            self->middle->inner->target->f8(1);
        }
    }
    return 1;
}