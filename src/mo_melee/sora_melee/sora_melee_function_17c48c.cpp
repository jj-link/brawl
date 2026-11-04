#pragma force_active on

#define V8(p) \
    virtual void p##0(); \
    virtual void p##1(); \
    virtual void p##2(); \
    virtual void p##3(); \
    virtual void p##4(); \
    virtual void p##5(); \
    virtual void p##6(); \
    virtual void p##7();

#define V32(p) V8(p##0) V8(p##1) V8(p##2) V8(p##3)

struct A {
    V32(a)
    virtual void b0();
    virtual void b1();
    virtual void b2();
    virtual void b3();
    virtual void b4();
    virtual bool check(int);
};

struct B {
    V32(a)
    virtual int get(int);
};

struct C {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void on(int, int, int, int);
};

struct ObjectBase {
    char pad[0x3c];
};

struct D : ObjectBase {
    V32(a) V32(b) V32(c) V32(d) V32(e)
    V8(f0) V8(f1) V8(f2)
    virtual void g0();
    virtual int call();
};

struct Modules {
    char pad[0x50];
    C* c;
    char pad54[0x1c];
    B* b;
    char pad74[0x34];
    A* a;
};

struct Access {
    char pad[8];
    void* obj;
    char padC[0xcc];
    Modules* modules;
};

extern "C" {
    int fn_27_193590(Access*, int);
    void fn_27_17B228(void*, Access*);
    void fn_27_17DE50(Access*, int, int);
    void fn_27_1D6434(int, int, int, int, Access*);
    void* __dynamic_cast(void*, long, const void*, const void*, short);
    extern const char lbl_27_data_69C0[];
    extern const char lbl_27_data_248[];
}

extern "C" void fn_27_17C48C(void* self, Access* acc) {
    fn_27_17B228(self, acc);
    if (acc->modules->a->check(0) == 0) {
        fn_27_17DE50(acc, 0x15f, 0x160);
        if (fn_27_193590(acc, acc->modules->b->get(0)) == 0) {
            acc->modules->c->on(0x1f9f, 0, 0, 0);
        }
    } else {
        fn_27_17DE50(acc, 0x15d, 0x15e);
    }
    if (fn_27_193590(acc, acc->modules->b->get(0)) == 0) {
        D* o = (D*)__dynamic_cast(
            acc->obj, 0x3c, lbl_27_data_69C0, lbl_27_data_248, 1);
        fn_27_1D6434(2, 0x62, 1, o->call(), acc);
    }
}
