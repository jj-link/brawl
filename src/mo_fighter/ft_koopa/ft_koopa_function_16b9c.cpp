#pragma force_active on
struct Obj {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
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
    virtual int v17(int);
    virtual void v18();
    virtual void v19(int);
};

struct Inner {
    char pad[0x64];
    Obj* obj;
};

struct Holder {
    char pad[0xd8];
    Inner* inner;
};

extern "C" void fn_102_16A7C(Holder* h);

extern "C" void fn_102_16B9C(void*, Holder* h) {
    Obj* obj = h->inner->obj;
    if (obj->v17(0x1200003d)) {
        fn_102_16A7C(h);
        obj->v19(0x1200003d);
    }
}
