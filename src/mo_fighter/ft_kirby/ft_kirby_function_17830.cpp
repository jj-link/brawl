#pragma force_active on
struct Mod {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5(int);
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
    virtual int v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25(int);
};

struct Comp {
    char a[0x20];
    Mod* m20;
    char b[0x18];
    Mod* m3c;
    char c[0x30];
    Mod* m70;
};

struct Fighter {
    char pad[0xd8];
    Comp* comp;
};

extern "C" void fn_96_17830(void*, Fighter* f) {
    int r = f->comp->m70->v16();
    switch (r) {
    case 0x119:
        f->comp->m3c->v5(-1);
        break;
    case 0x11a:
        f->comp->m20->v25(0);
        break;
    }
}
