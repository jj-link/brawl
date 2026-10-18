#pragma force_active on
struct Obj {
    virtual int f0();
    virtual int f1();
    virtual int f2();
    virtual int f3();
    virtual int f4();
    virtual int f5();
    virtual int f6();
    virtual int f7();
    virtual int f8();
    virtual int f9();
    virtual int f10();
    virtual int f11();
    virtual int f12();
    virtual int f13();
    virtual int f14();
    virtual int f15();
    virtual int f16();
    virtual int f17();
    virtual int f18();
    virtual int f19();
    virtual int f20();
    virtual int f21();
    virtual int f22();
    virtual int f23();
    virtual int f24();
    virtual int f25();
    virtual int f26();
    virtual int f27();
    virtual int f28();
    virtual int f29();
    virtual int f30();
    virtual int f31();
    virtual int f32();
    virtual int f33();
    virtual int f34();
};

struct Owner {
    char pad[0xd8];
    Obj *child;
};

struct Mid {
    char pad[0x8];
    Obj *obj;
};

extern "C" int fn_115_F940(void *unused, Owner *self)
{
    Mid *m = (Mid *)self->child;
    return m->obj->f34();
}
