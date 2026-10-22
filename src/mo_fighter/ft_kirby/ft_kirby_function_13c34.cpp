#pragma force_active on

class Obj {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void* f6(int);
    virtual void f7();
    virtual void f8();
    virtual void f9();
};

struct Inner {
    char pad[0x7C];
    Obj* obj;
};

struct Outer {
    char pad[0xD8];
    Inner* inner;
};

struct Flags {
    char pad[5];
    unsigned char b : 1;
    unsigned char a : 7;
};

extern "C" void fn_96_13C34(void* unused, Outer* outer) {
    Obj* obj = outer->inner->obj;
    obj->f9();
    Flags* p;
    p = (Flags*)obj->f6(0);
    p->b = 0;
    p = (Flags*)obj->f6(1);
    p->b = 0;
    p = (Flags*)obj->f6(2);
    p->b = 0;
    p = (Flags*)obj->f6(3);
    p->b = 0;
}
