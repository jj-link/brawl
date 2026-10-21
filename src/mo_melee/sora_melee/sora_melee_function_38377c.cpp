#pragma force_active on
typedef unsigned int u32;

struct Mid;
struct Obj;

struct F14 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual int v3();
};

struct F64 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual int v4(u32, Mid*);
    virtual void v5(u32, u32);
};

struct F70 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3(u32, Obj*);
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
    virtual int v16();
};

struct Mid {
    char pad0[0x14];
    F14* f14;
    char pad1[0x64 - 0x18];
    F64* f64;
    char pad2[0x70 - 0x68];
    F70* f70;
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
void fn_27_38377C(Top* self) {
    Obj* o = self->obj;
    if (o->mid->f14->v3() == 5) {
        return;
    }
    if (o->mid->f70->v16() != 0x119) {
        return;
    }
    if (o->mid->f64->v4(0x10000042, o->mid) != 0) {
        return;
    }
    o->mid->f64->v5(0x1e8, 0x20000000);
    o->mid->f70->v3(0x122, o);
}
}
