#pragma force_active on
typedef unsigned int u32;

struct Sub1 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual int v3();
};

struct Sub2 {
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
    virtual int v17(u32 arg);
};

struct Mid {
    char pad0[0x14];
    Sub1* s1;
    char pad1[0x64 - 0x18];
    Sub2* s2;
};

struct Obj {
    char pad[0xd8];
    Mid* mid;
};

struct Top {
    char pad[0x60];
    Obj* obj;
};

extern "C" {
int fn_27_12D1A8(Top* self) {
    Obj* o = self->obj;
    if (o->mid->s1->v3() == 5) {
        return 0;
    }
    return o->mid->s2->v17(0x12000006) != 1;
}
}
