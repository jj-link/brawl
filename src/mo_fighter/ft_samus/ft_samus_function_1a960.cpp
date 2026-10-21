#pragma force_active on
struct ObjA {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5(int, int);
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

struct ObjB {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5(int, int, int);
};

struct Inner {
    char pad0[0x64];
    ObjA* a;
    char pad1[0x84 - 0x68];
    ObjB* b;
};

struct Holder {
    char pad[0xd8];
    Inner* inner;
};

extern "C" void fn_94_1A960(void*, Holder* h) {
    ObjA* a = h->inner->a;
    if (a->v17(0x22000014)) {
        a->v19(0x22000014);
        a->v5(0, 0x10000040);
        h->inner->b->v5(3, 0, 1);
    }
}
