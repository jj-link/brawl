#pragma force_active on

struct ObjA {
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
    virtual void f18(unsigned int arg);
    virtual void f19(unsigned int arg);
};

struct Ent {
    char pad0[0x64];
    ObjA* a;
};

struct Outer {
    char pad[0xd8];
    Ent* e;
};

extern "C" {
struct Result {
    int a;
    int pad;
    int b;
};

int fn_27_195528(void*, int*, int*);

void fn_27_1689A0(void*, Outer* o) {
    Result r;
    if (fn_27_195528(o, &r.b, &r.a) & 6) {
        o->e->a->f18(0x22000013);
    } else {
        o->e->a->f19(0x22000013);
    }
}
}
