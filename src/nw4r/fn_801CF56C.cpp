#pragma force_active on
struct Inner {
    char pad[0xBD];
    unsigned char flag;
};

struct Obj {
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual int v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19(int, int);
    virtual void v20();
    virtual int v21();
};

struct Outer {
    char pad[0x10];
    Inner* p10;
    Obj* p14;
};

extern "C" void fn_801CF56C(Outer* self) {
    self->p10->flag = 1;
    Obj* a = self->p14;
    if (a != 0 && a->v21() != 0) {
        Obj* b = self->p14;
        if (b->v10() != 0) {
            Obj* c = self->p14;
            c->v19(0, 0);
            return;
        }
        Obj* d = self->p14;
        d->v18();
    }
}
