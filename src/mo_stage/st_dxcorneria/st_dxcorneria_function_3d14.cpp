#pragma force_active on
struct Pad {
    char p[0x3c];
};

struct Inner : Pad {
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
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27(int);
};

struct Outer {
    char pad[0x1040];
    Inner* inner;
};

extern "C" void fn_82_3D14(Outer* o)
{
    if (o->inner) {
        o->inner->v27(1);
    }
}
