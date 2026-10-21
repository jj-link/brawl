#pragma force_active on
struct Target {
    virtual void v0(int);
    virtual void v1(int);
    virtual void v2(int);
    virtual void v3(int);
    virtual void v4(int);
    virtual void v5(int);
    virtual void v6(int);
    virtual void v7(int);
    virtual void v8(int);
    virtual void v9(int);
    virtual void v10(int);
    virtual void v11(int);
    virtual void v12(int);
    virtual void v13(int);
    virtual void v14(int);
    virtual void v15(int);
    virtual void v16(int);
    virtual void v17(int);
    virtual void v18(int);
    virtual void v19(int);
    virtual void v20(int);
    virtual void v21(int);
    virtual void v22(int);
    virtual void v23(int);
    virtual void v24(int);
    virtual void v25(int);
    virtual void v26(int);
    virtual void v27(int);
};

struct Mid {
    char padding[0x20];
    Target* target;
};

struct Inner {
    char padding[0xD8];
    Mid* mid;
};

struct Obj2184 {
    char padding[0x30];
    int field30;
};

struct Main {
    char pad0[0x6C];
    Inner* inner;
    char pad1[0x2114];
    Obj2184* ptr2184;
    char pad2[0x30];
    unsigned char flag;
};

extern "C" void fn_41_31464(Main* arg0) {
    Target* t = arg0->inner->mid->target;
    if (arg0->flag) {
        if (arg0->ptr2184->field30) {
            t->v24(0);
            t->v11(0);
            t->v26(0);
        } else {
            t->v25(0);
        }
    } else {
        t->v25(0);
    }
}
