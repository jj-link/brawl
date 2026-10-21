#pragma force_active on
struct Ifc {
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11(int, int);
    virtual unsigned int v12(int);
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual bool v19(int);
};

struct Sub {
    char pad0[0x3c];
    Ifc* w;
    char pad1[0x54 - 0x40];
    Ifc* z;
    char pad2[0x64 - 0x58];
    Ifc* y;
};

struct Owner {
    char pad[0xd8];
    Sub* s;
};

extern "C" void fn_96_17EF4(void*, Owner* o) {
    if (!o->s->y->v19(0x22000016)) {
        if (o->s->z->v12(0) == 1) {
            o->s->w->v11(0, 1);
        }
    }
}
