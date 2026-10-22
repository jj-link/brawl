#pragma force_active on
struct ObjA {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7(unsigned int);
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual int v17(unsigned int);
    virtual void v18(unsigned int);
};

struct ObjB {
    virtual void v0();
    virtual void v1();
    virtual void v2(int, int);
};

struct ObjD {
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
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21(int, void*);
};

struct Inner {
    char pad0[0x58];
    ObjB* c;
    char pad1[0x64 - 0x5c];
    ObjA* a;
    char pad2[0x7c - 0x68];
    ObjD* b;
};

struct Holder {
    char pad[0xd8];
    Inner* inner;
};

extern "C" void fn_102_D21C(void*, Holder* h) {
    ObjA* a = h->inner->a;
    if (a->v17(0x22000010) != 0 && a->v17(0x22000011) == 0) {
        h->inner->b->v21(0, h);
        a->v18(0x22000011);
    }
    a->v7(0x20000000);
    if (a->v17(0x22000012) != 0) {
        h->inner->c->v2(1, 1);
        h->inner->c->v2(0, -1);
        return;
    }
    h->inner->c->v2(1, 0);
    if (a->v17(0x12000006) != 0) {
        h->inner->c->v2(0, 0);
    }
}
