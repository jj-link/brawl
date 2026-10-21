#pragma force_active on
struct Obj {
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual int v5();
    virtual int v6(int);
    virtual void v7(int, int);
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15(float, int);
};

struct B {
    char pad0[0x14];
    Obj* p14;
    char pad1[0x64 - 0x18];
    Obj* p64;
};

struct A {
    char pad[0xD8];
    B* b;
};

struct Dat {
    char pad[8];
    float f;
};

struct Cfg {
    char pad[0x80];
    Dat* d;
};

struct Arg {
    char pad0[0x60];
    A* a;
    char pad1[0x22284 - 0x64];
    Cfg* cfg;
};

extern "C" void fn_27_12DCA8(void*);

extern "C" void fn_95_A1A8(Arg* arg0) {
    fn_27_12DCA8(arg0);
    Obj* obj = arg0->a->b->p64;
    if (obj->v6(0x10000040)) {
        Obj* o = arg0->a->b->p14;
        if (o->v5() == 0) {
            obj->v7(0, 0x10000040);
            obj->v15(arg0->cfg->d->f, 0x11000013);
        }
    }
}
