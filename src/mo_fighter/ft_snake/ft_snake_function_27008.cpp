#pragma force_active on

struct VIface54 {
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
    virtual void callC(int, void*);   // offset 0x44
    virtual void f16();
    virtual int callA();              // offset 0x4c
    virtual int callB(void*);         // offset 0x50
};

struct VIface64 {
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
    virtual int callA(int);           // offset 0x4c
};

struct VIface70 {
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
    virtual unsigned int callA();     // offset 0x4c
    virtual int callB(void*);         // offset 0x50
};

struct Modules {
    char pad0[0x54];
    VIface54* unk54;
    char pad1[0x64 - 0x58];
    VIface64* unk64;
    char pad2[0x70 - 0x68];
    VIface70* unk70;
};

struct Accessor {
    char pad0[0xD8];
    Modules* modules;
};

struct Fighter {
    char pad0[0x60];
    Accessor* accessor;
};

struct Tmp {
    int a;
    unsigned char b;
};

extern "C" void fn_122_27008(Fighter* self) {
    unsigned char flag = 0;
    if (self->accessor->modules->unk64->callA(0x12000003) != 0) {
        return;
    }
    int value = flag;
    value |= 3;
    if (self->accessor->modules->unk70->callA() == 1U &&
        self->accessor->modules->unk70->callB(&value)) {
        Tmp t;
        t.a = 0x838;
        t.b = flag;
        self->accessor->modules->unk54->callC(3, &t);
        return;
    }
    Tmp t;
    t.a = 0x839;
    t.b = 0;
    self->accessor->modules->unk54->callC(3, &t);
}
