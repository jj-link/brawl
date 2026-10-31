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
    virtual void v16(int, int);
};

struct Inner {
    char pad[0x84];
    Obj *obj;
};

struct Outer {
    char pad[0xd8];
    Inner *inner;
};

extern "C" {
void fn_104_1EE84(void *a, Outer *b, int c) {
    if (c != 0x11b && c != 0x81) {
        b->inner->obj->v16(2, 0);
    }
}
}
