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

struct Motion {
    V32(a)
    virtual int get(int);
};

struct Work {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void set(int, int);
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void on(int);
};

struct ObjectBase {
    char pad[0x3c];
};

struct Obj : ObjectBase {
    V32(a) V32(b) V32(c) V32(d) V32(e)
    V8(f0) V8(f1) V8(f2)
    virtual void h184();
    virtual int get();
};

struct Modules {
    char pad[0x64];
    Work* work;
    char pad68[8];
    Motion* motion;
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

extern "C" void fn_27_17C650(void* self, Access* acc) {
    if (fn_27_193590(acc, acc->modules->motion->get(0)) == 0) {
        fn_27_17B228(self, acc);
        acc->modules->work->on(0x22000013);
        acc->modules->work->set(0, 0x2000000c);

        Obj* o = (Obj*)__dynamic_cast(
            acc->obj, 0x3c, lbl_27_data_69C0, lbl_27_data_248, 1);
        fn_27_1D6434(2, 0x63, 1, o->get(), acc);
    }
    fn_27_17DE50(acc, 0x161, 0x162);
}
