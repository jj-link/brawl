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
    virtual void f13(unsigned int arg);
    virtual void f14();
    virtual void f15();
};

struct Ent {
    char pad0[0xc];
    ObjA* a;
    char pad1[0x64 - 0x10];
    ObjB* b;
};

struct Outer {
    char pad[0xd8];
    Ent* e;
};

extern "C" void fn_27_356100(void*, Outer* o) {
    o->e->a->f9();
    o->e->b->f13(0x21000004);
}
