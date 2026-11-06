#pragma force_active on

struct Obj64 {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual int f4(int);
    virtual void f5(int, int);
};

struct Obj84 {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9(int, int, int);
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual unsigned int f18(int);
};

struct Modules {
    char pad[0x64];
    Obj64* obj64;
    char pad2[0x1C];
    Obj84* obj84;
};

struct Accessor {
    char pad[0xD8];
    Modules* modules;
};

struct Fighter {
    char pad0[0x60];
    Accessor* accessor;
    char pad1[0x2DB70];
    unsigned char flag;
};

extern "C" void fn_27_12DCA8(void*);

extern "C" void fn_91_98F8(Fighter* self) {
    fn_27_12DCA8(self);
    if (self->accessor->modules->obj84->f18(2) == 1) {
        int val = self->accessor->modules->obj64->f4(0x10000041);
        if (val > 0) {
            if (val - 1 == 0) {
                self->accessor->modules->obj84->f9(2, 2, 0);
            }
            self->accessor->modules->obj64->f5(val - 1, 0x10000041);
        }
    }
    self->flag = 0;
}