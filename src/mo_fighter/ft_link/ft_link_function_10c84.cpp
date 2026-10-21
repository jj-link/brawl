#pragma force_active on
struct ObjA {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual int f4();
    virtual void f5(int, int);
};

struct ObjB {
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
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22(int, int, bool);
};

struct Inner {
    char pad0[0x64];
    ObjA* a;
    char pad1[0x88 - 0x68];
    ObjB* b;
};

struct Outer {
    char pad0[0xd8];
    Inner* inner;
};

extern "C" void fn_93_10C84(Outer* self, int arg) {
    Inner* in = self->inner;
    ObjA* a = in->a;
    ObjB* b = in->b;
    int h = a->f4();
    if (h != 0) {
        bool t = true;
        b->f22(h, 1, t);
        a->f5(0, arg);
    }
}
