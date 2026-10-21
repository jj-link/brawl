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
    virtual void v9(int);
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual int v19(int);
    virtual void v20(int);
    virtual void v21();
    virtual void v22();
    virtual void v23(int);
};

struct Obj2 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v9(int);
};

struct Inner {
    char pad0[0x58];
    Obj2* a58;
    char pad1[0x8];
    Obj* a64;
    char pad2[0x20];
    Obj* a88;
};

struct Holder {
    char pad[0xd8];
    Inner* inner;
};

extern "C" void fn_109_DE84(void* self);

extern "C" void fn_109_DB6C(void*, Holder* h) {
    Obj* obj = h->inner->a64;
    if (obj->v19(0x22000010) == 0 && obj->v19(0x22000011) == 0) {
        h->inner->a88->v23(8);
        h->inner->a58->v9(0);
        obj->v20(0x22000011);
    }
    fn_109_DE84(h);
}
