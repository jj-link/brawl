#pragma force_active on
struct IB {
    virtual int v0();
    virtual int v1();
    virtual int v2();
    virtual int v3();
    virtual int v4();
    virtual int v5();
    virtual int v6();
    virtual int v7();
    virtual int v8();
    virtual int v9();
    virtual int v10();
    virtual int v11();
    virtual int v12();
    virtual int v13();
    virtual int v14();
    virtual int v15();
    virtual int v16();
    virtual int v17();
    virtual int v18();
    virtual int v19();
    virtual int v20();
    virtual int v21();
    virtual int v22();
    virtual int v23();
    virtual int v24();
    virtual int v25();
};

struct A {
    char p0[0x44];
    IB* c;
    char p1[0xC];
    IB* b;
};

struct Self {
    char p0[0xd8];
    A* a;
};

extern "C" {
void fn_27_18F878(int, Self* self) {
    if (self->a->b->v23() == 0) {
        self->a->c->v5();
        self->a->c->v7();
    }
}
}
